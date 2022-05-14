#include <iostream>
#include <memory>
#include <string>

#include "grpcpp/ext/proto_server_reflection_plugin.h"
#include "grpcpp/grpcpp.h"
#include "grpcpp/health_check_service_interface.h"

#include "proto/greet.grpc.pb.h"

class GreetServiceImpl final : public proto::Greeting::CallbackService {

    grpc::ServerUnaryReactor* AskName(grpc::CallbackServerContext* context, const proto::AskNameRequest * request, proto::AskNameResponse * response) override {
        std::string prefix{"Give name: "};
        response->set_name(prefix + request->ask_num());

        grpc::ServerUnaryReactor* reactor = context->DefaultReactor();
        reactor->Finish(grpc::Status::OK);

        return reactor;
    }

    grpc::ServerUnaryReactor* GreetPing(grpc::CallbackServerContext* context, const proto::GreetRequest * request, proto::GreetResponse* response) override {
        std::string prefix{"Hello "};
        response->set_greet_msg(prefix + request->name());

        grpc::ServerUnaryReactor* reactor = context->DefaultReactor();
        reactor->Finish(grpc::Status::OK);

        return reactor;
    }
};

int main()
{
    std::string server_address{"0.0.0.0:50051"};
    GreetServiceImpl service;

    grpc::EnableDefaultHealthCheckService(true);
    grpc::reflection::InitProtoReflectionServerBuilderPlugin();
    grpc::ServerBuilder builder;
    builder.AddListeningPort(server_address, grpc::InsecureServerCredentials());
    builder.RegisterService(&service);
    std::unique_ptr<grpc::Server> server(builder.BuildAndStart());

    std::cout << "Server listening on port " << server_address << "\n";
    server->Wait(); 

    return 0;
}
