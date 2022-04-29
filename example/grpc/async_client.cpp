#include <iostream>
#include <memory>
#include <string>

#include "grpc/support/log.h"
#include "grpcpp/grpcpp.h"
#include "grpcpp/security/credentials.h"

#include "proto/greet.grpc.pb.h"

class ClientImpl final {
private:
    std::unique_ptr<proto::Greeting::Stub> stub_;

public:
    explicit ClientImpl(std::shared_ptr<grpc::Channel> channel)
        : stub_(proto::Greeting::NewStub(channel)) {

    }

    std::string GreetPing(const std::string& name, const std::string& greet_msg) {
        proto::GreetRequest request;
        request.set_name(name);
        request.set_greet_msg(greet_msg);

        proto::GreetResponse response;
        grpc::ClientContext ctx;
        grpc::CompletionQueue cq;
        grpc::Status status;

        std::unique_ptr<grpc::ClientAsyncResponseReader<proto::GreetResponse>> rpc(
            stub_->PrepareAsyncGreetPing(&ctx, request, &cq)
        );

        rpc->StartCall();
        rpc->Finish(&response, &status, (void*)1);
        void* got_tag;
        bool ok = false;

        GPR_ASSERT(cq.Next(&got_tag, &ok));

        GPR_ASSERT(got_tag == (void*)1);
        GPR_ASSERT(ok);

        if (status.ok()) {
            return response.greet_msg();
        }
        else {
            return "RPC failed";
        }
    }
};

int main()
{
    // auto creds = grpc::SslCredentials(grpc::SslCredentialsOptions());
    auto creds = grpc::InsecureChannelCredentials();
    ClientImpl client(grpc::CreateChannel("127.0.0.1:50051", creds));
    std::string name{"balebom"};
    std::string greet_msg{"Hello server, my name balebom"};
    std::string response = client.GreetPing(name, greet_msg);
    std::cout << "Greet received: " << response << "\n";

    return 0;
}
