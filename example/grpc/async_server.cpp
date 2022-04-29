#include <iostream>
#include <memory>
#include <string>
#include <thread>

#include "grpc/support/log.h"
#include "grpcpp/grpcpp.h"
#include "grpcpp/server.h"
#include "grpcpp/security/server_credentials.h"
#include "grpcpp/server_builder.h"
#include "grpcpp/server_context.h"
#include "grpcpp/completion_queue.h"

#include "proto/greet.grpc.pb.h"

class ServerImpl final {
private:
    std::unique_ptr<grpc::ServerCompletionQueue> cq_;
    proto::Greeting::AsyncService service_;
    std::unique_ptr<grpc::Server> server_;

    class CallData {
    private:
        proto::Greeting::AsyncService* service_;
        grpc::ServerCompletionQueue* cq_;

        grpc::ServerContext ctx_;
        proto::GreetRequest request_;
        proto::GreetResponse response_;

        grpc::ServerAsyncResponseWriter<proto::GreetResponse> responder_;

        enum CallStatus {CREATE, PROCESS, FINISH};
        CallStatus status_;

    public:
        CallData(proto::Greeting::AsyncService* service, grpc::ServerCompletionQueue* cq)
            : service_(service), cq_(cq), responder_(&ctx_), status_(CREATE) {
            Process();
        }

        void Process() {
            if (status_ == CREATE) {
                status_ = PROCESS;

                service_->RequestGreetPing(&ctx_, &request_, &responder_, cq_, cq_, this);
            }
            else if (status_ == PROCESS) {
                new CallData(service_, cq_);

                std::cout << "Server received: " << request_.greet_msg();
                std::string prefix {"Hello "};
                response_.set_greet_msg(prefix + request_.name());

                status_ = FINISH;
                responder_.Finish(response_, grpc::Status::OK, this);
            }
            else {
                GPR_ASSERT(status_ == FINISH);

                delete this;
            }
        }
    };

    void HandleRpcs() {
        new CallData(&service_, cq_.get());
        void *tag;
        bool ok;

        while (true) {
            GPR_ASSERT(cq_->Next(&tag, &ok));
            GPR_ASSERT(ok);

            static_cast<CallData*>(tag)->Process();
        }
    }

public:
    ~ServerImpl() {
        server_->Shutdown();
        cq_->Shutdown();
    }

    void Run() {
        // auto opts = grpc::SslServerCredentialsOptions();
        // auto creds = grpc::SslServerCredentials(opts);
        auto creds = grpc::InsecureServerCredentials();
        std::string server_address{"127.0.0.1:50051"};
        grpc::ServerBuilder builder;
        builder.AddListeningPort(server_address, creds);
        builder.RegisterService(&service_);

        cq_ = builder.AddCompletionQueue();
        server_ = builder.BuildAndStart();
        std::cout << "Server listening on " << server_address << "\n";

        HandleRpcs();
    }
};

int main()
{
    ServerImpl server;
    server.Run();

    return 0;
}
