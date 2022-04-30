#include <chrono>
#include <iostream>
#include <memory>
#include <random>
#include <string>
#include <thread>
#include <fstream>
#include <sstream>

#include "grpc/grpc.h"
#include "grpcpp/channel.h"
#include "grpcpp/client_context.h"
#include "grpcpp/create_channel.h"
#include "grpcpp/security/credentials.h"

#include "proto/route.grpc.pb.h"

class RouteClient
{
private:
    const float kCoordinateFactor_ = 10000000.0;
    std::unique_ptr<proto::Route::Stub> stub_;
    proto::FeatureList feature_list_;

    bool GetOneFeature(const proto::Point& point, proto::Feature* feature) {
        grpc::ClientContext context;
        grpc::Status status = stub_->GetFeature(&context, point, feature);
        if (!status.ok()) {
            std::cout << "Get feature rpc failed\n";
            return false;
        }

        if (!feature->has_location()) {
            std::cout << "Server return incomplete feature\n";
            return false;
        }

        if (feature->name().empty()) {
            std::cout << "Found no feature at " 
                                << feature->location().latitude() / kCoordinateFactor_ << ", "
                                << feature->location().longitude() / kCoordinateFactor_ << "\n";
        }
        else {
            std::cout << "Found feature called " << feature->name() << " at "
                                << feature->location().latitude() / kCoordinateFactor_ << ", "
                                << feature->location().longitude() / kCoordinateFactor_ << "\n";
        }

        return true;
    }

    proto::Point MakePoint(long latitude, long longtitude) {
        proto::Point point;
        point.set_latitude(latitude);
        point.set_longitude(longtitude);

        return point;
    }

    proto::RouteNote MakeRouteNote(const std::string& message, long latitude, long longtitude) {
        proto::RouteNote n;
        n.set_message(message);
        n.mutable_location()->CopyFrom(MakePoint(latitude, longtitude));
        return n;
    }

public:
    RouteClient(std::shared_ptr<grpc::Channel> channel, const std::string& db_path) : stub_(proto::Route::NewStub(channel)) {
        std::cout << "constructing... \n";
        std::ifstream infile(db_path);
        if (!infile.is_open()) {
            std::cout << "file not exist\n";
            return;
        }
        std::stringstream ss;
        ss << infile.rdbuf();

        std::string jfeature_list = std::move(ss.str());
        google::protobuf::util::JsonStringToMessage(jfeature_list, &feature_list_);
    }

    void GetFeature() {
        proto::Point point;
        proto::Feature feature;
        point.set_latitude(409146138);
        point.set_longitude(-746188906);
        GetOneFeature(point, &feature);
        point.set_latitude(0);
        point.set_longitude(0);
        GetOneFeature(point, &feature);
    }

    void ListFeature() {
        proto::Rectangle rect;
        proto::Feature feature;
        grpc::ClientContext context;

        rect.mutable_lo()->set_latitude(400000000);
        rect.mutable_lo()->set_longitude(-750000000);
        rect.mutable_hi()->set_latitude(420000000);
        rect.mutable_hi()->set_longitude(-730000000);

        std::cout << "Looking for feature between 40, -75 and 42, -73\n";

        std::unique_ptr<grpc::ClientReader<proto::Feature>> reader(stub_->ListFeatures(&context, rect));

        while (reader->Read(&feature)) {
            std::cout << "Found feature called " << feature.name() << " at "
                    << feature.location().latitude() / kCoordinateFactor_ << ", "
                    << feature.location().longitude() / kCoordinateFactor_ << "\n";
        }

        grpc::Status status = reader->Finish();
        if (status.ok()) {
            std::cout << "List feature rpc success.\n";
        }
        else {
            std::cout << "List feature rpc failed\n";
        }
    }

    void RecordRoute() {
        proto::Point point;
        proto::RouteSummary stats;
        grpc::ClientContext context;
        const int kPoints = 10;
        unsigned seed = std::chrono::system_clock::now().time_since_epoch().count();

        std::default_random_engine generator(seed);
        std::uniform_int_distribution<int> feature_distribution(0, feature_list_.mutable_features()->size() - 1);
        // std::uniform_int_distribution<int> delay_distribution(500, 1500);

        std::unique_ptr<grpc::ClientWriter<proto::Point>> writer(stub_->RecordRoute(&context, &stats));

        for (int i = 0; i < kPoints; ++i) {
            const proto::Feature& f = feature_list_.mutable_features()->at(feature_distribution(generator));
            std::cout << "Visiting point " << f.location().latitude() / kCoordinateFactor_
                    << ", " << f.location().longitude() / kCoordinateFactor_ << "\n";
            if (!writer->Write(f.location())) {
                break;;
            }

            // std::this_thread::sleep_for(std::chrono::milliseconds(delay_distribution(generator)));
        }

        writer->WritesDone();
        grpc::Status status = writer->Finish();
        if (status.ok()) {
            std::cout << "Finish trip with " << stats.point_count() << "points\n"
                        << "Passed " << stats.feature_count() << " features\n"
                        << "Travelled " << stats.distance() << " metres\n"
                        << "It took " << stats.elapsed_time() << " seconds\n";
        }
        else {
            std::cout << "Record route rpc failed\n";
        }
    }

    void RouteChat() {
        grpc::ClientContext context;

        std::shared_ptr<grpc::ClientReaderWriter<proto::RouteNote, proto::RouteNote>> stream(
            stub_->RouteChat(&context)
        );
        std::thread writer([&]() {
            std::vector<proto::RouteNote> notes {
                MakeRouteNote("First message", 0, 0),
                MakeRouteNote("Second message", 0, 1),
                MakeRouteNote("Third message", 1, 0),
                MakeRouteNote("Four message", 1, 1),
            };

            for (const proto::RouteNote& note : notes) {
                std::cout << "Sending message " << note.message() << " at "
                        << note.location().latitude() << ", "
                        << note.location().longitude() << "\n";
                stream->Write(note);
            }

            stream->WritesDone();
        });

        proto::RouteNote server_note;
        while (stream->Read(&server_note)) {
            std::cout << "Got message " << server_note.message() << " at "
                    << server_note.location().latitude() << ", "
                    << server_note.location().longitude() << "\n";
        }

        writer.join();
        grpc::Status status = stream->Finish();
        if (!status.ok()) {
            std::cout << "RouteChat rpc failed\n";
        }
    }
};

int main(int argc, char ** argv)
{
    if (argc < 2) {
        std::cout << "Usage " << argv[0] << " <database_path>\n";
        return 0;
    }

    grpc::ChannelArguments c_args;
    c_args.SetLoadBalancingPolicyName("round_robin");

    RouteClient guide(grpc::CreateCustomChannel("127.0.0.1:50051", grpc::InsecureChannelCredentials(), c_args), argv[1]);

    std::cout << "------------------------ GetFeature --------------------\n";
    guide.GetFeature();
    std::cout << "------------------------ ListFeatures -------------------\n";
    guide.ListFeature();
    std::cout << "------------------------ RecordRoute ---------------------\n";
    guide.RecordRoute();
    std::cout << "------------------------ RouteChat -----------------------\n";
    guide.RouteChat(); 

    return 0;
}
