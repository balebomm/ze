#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

#include "google/protobuf/util/json_util.h"
#include "grpc/grpc.h"
#include "grpcpp/security/server_credentials.h"
#include "grpcpp/server.h"
#include "grpcpp/server_builder.h"
#include "grpcpp/server_context.h"

#include "proto/route.grpc.pb.h"

class RouteImpl final : public proto::Route::Service {
private:
    float ConvertToRadians(float num) { return num * 3.1415926 / 180; }

    float GetDistance(const proto::Point& start, const proto::Point& end)
    {
        const float kCoordFactor = 10000000.0;
        float lat_1 = start.latitude() / kCoordFactor;
        float lat_2 = end.latitude() / kCoordFactor;
        float lon_1 = start.longitude() / kCoordFactor;
        float lon_2 = end.longitude() / kCoordFactor;
        float lat_rad_1 = ConvertToRadians(lat_1);
        float lat_rad_2 = ConvertToRadians(lat_2);
        float delta_lat_rad = ConvertToRadians(lat_2 - lat_1);
        float delta_lon_rad = ConvertToRadians(lon_2 - lon_1);

        float a = pow(sin(delta_lat_rad / 2), 2) +
                    cos(lat_rad_1) * cos(lat_rad_2) * pow(sin(delta_lon_rad / 2), 2);
        float c = 2 * atan2(sqrt(a), sqrt(1 - a));
        int R = 6371000;  // metres

        return R * c;
    }

    std::string GetFeatureName(const proto::Point& point)
    {
        for (const proto::Feature& f : feature_list_.features())
        {
            if (f.location().latitude() == point.latitude() && f.location().longitude() == point.longitude())
            {
                return f.name();
            }
        }

        return "";
    }

public:
    explicit RouteImpl(std::string db_path) {
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
        return;
    }

    grpc::Status GetFeature(grpc::ServerContext* context, const proto::Point * request, proto::Feature* response) override {
        response->set_name(this->GetFeatureName(*request));
        response->mutable_location()->CopyFrom(*request);
        return grpc::Status::OK;
    }

    grpc::Status ListFeatures(grpc::ServerContext* context, const proto::Rectangle* request, grpc::ServerWriter<proto::Feature>* writer) override {
        proto::Point lo = request->lo();
        proto::Point hi = request->hi();
        int left = std::min(lo.longitude(), hi.longitude());
        int right = std::max(lo.longitude(), hi.longitude());
        int top = std::max(lo.latitude(), hi.latitude());
        int bottom = std::min(lo.latitude(), hi.latitude());
        for (const proto::Feature& f : this->feature_list_.features()) {
            if (f.location().longitude() >= left && f.location().longitude() <= right && f.location().latitude() >= bottom && f.location().latitude() <= top) {
                writer->Write(f);
            }
        }

        return grpc::Status::OK;
    }

    grpc::Status RecordRoute(grpc::ServerContext* context, grpc::ServerReader<proto::Point>* reader, proto::RouteSummary* response) override {
        proto::Point point;
        int point_count = 0;
        int feature_count = 0;
        float distance = 0.f;
        proto::Point previous;

        auto start_time = std::chrono::system_clock::now();
        while (reader->Read(&point)) {
            point_count ++;
            if (!this->GetFeatureName(point).empty()) {
                feature_count++;
            }

            if (point_count != 1) {
                distance += GetDistance(previous, point);
            }
            previous = point;
        }

        auto end_time = std::chrono::system_clock::now();
        response->set_point_count(point_count);
        response->set_feature_count(feature_count);
        response->set_distance(static_cast<int>(distance));
        auto secs = std::chrono::duration_cast<std::chrono::seconds>(end_time - start_time);
        response->set_elapsed_time(secs.count());

        return grpc::Status::OK;
    }

    grpc::Status RouteChat(grpc::ServerContext* context, grpc::ServerReaderWriter<proto::RouteNote, proto::RouteNote>* stream) {
        proto::RouteNote note;
        while (stream->Read(&note)) {
            std::unique_lock<std::mutex> lk(mt_);
            for (const proto::RouteNote& n : recved_notes_) {
                if (n.location().latitude() == note.location().latitude() && n.location().longitude() == note.location().longitude()) {
                    stream->Write(n);
                }
            }

            recved_notes_.push_back(note);
        }

        return grpc::Status::OK;
    }

private:
    proto::FeatureList feature_list_;
    std::mutex mt_;
    std::vector<proto::RouteNote> recved_notes_;
};

int main(int argc, char* argv[])
{
    if (argc < 2) {
        std::cout << "Usage: " << argv[0] << " <route_db_path>\n";
        return 0;
    }

    std::string server_address{"127.0.0.1:50051"};
    RouteImpl service(argv[1]);

    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());
    std::cout << "Server listening on " << server_address << "\n";
    server->Wait();

    return 0;
}
