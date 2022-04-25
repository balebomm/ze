#include <iostream>
#include <fstream>
#include <sstream>

#include "google/protobuf/util/json_util.h"
#include "grpc/grpc.h"
#include "grpcpp/security/server_credentials.h"
#include "grpcpp/server.h"
#include "grpcpp/server_builder.h"
#include "grpcpp/server_context.h"

#include "proto/route.grpc.pb.h"

class RouteImpl final : public proto::Route::Service {
public:
    explicit RouteImpl(std::string value) {
        std::cout << "constructing... \n";
        std::ifstream infile("route_db.json");
        if (!infile.is_open()) {
            std::cout << "file not exist\n";
            return;
        }
        std::stringstream ss;
        ss << infile.rdbuf();

        std::cout << ss.str();
        return;
    }

    grpc::Status GetFeature(grpc::ServerContext* context, const proto::Point * request, proto::Feature* resposne) override {
        return grpc::Status::OK;
    }

    grpc::Status ListFeatures(grpc::ServerContext* context, const proto::Rectangle* request, grpc::ServerWriter<proto::Feature>* writer) override {
        return grpc::Status::OK;
    }

    grpc::Status RecordRoute(grpc::ServerContext* context, grpc::ServerReader<proto::Point>* reader, proto::RouteSummary* response) override {
        return grpc::Status::OK;
    }

    grpc::Status RouteChat(grpc::ServerContext* context, grpc::ServerReaderWriter<proto::RouteNote, proto::RouteNote>* stream) {
        return grpc::Status::OK;
    }
};

int main(int argc, char* argv[])
{
    RouteImpl route_imple("balebom");
    return 0;
}
