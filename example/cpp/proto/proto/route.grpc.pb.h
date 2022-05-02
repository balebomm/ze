// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: route.proto
#ifndef GRPC_route_2eproto__INCLUDED
#define GRPC_route_2eproto__INCLUDED

#include "route.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_generic_service.h>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/client_context.h>
#include <grpcpp/impl/codegen/completion_queue.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/proto_utils.h>
#include <grpcpp/impl/codegen/rpc_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/status.h>
#include <grpcpp/impl/codegen/stub_options.h>
#include <grpcpp/impl/codegen/sync_stream.h>

namespace proto {

class Route final {
 public:
  static constexpr char const* service_full_name() {
    return "proto.Route";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    virtual ::grpc::Status GetFeature(::grpc::ClientContext* context, const ::proto::Point& request, ::proto::Feature* response) = 0;
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::proto::Feature>> AsyncGetFeature(::grpc::ClientContext* context, const ::proto::Point& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::proto::Feature>>(AsyncGetFeatureRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::proto::Feature>> PrepareAsyncGetFeature(::grpc::ClientContext* context, const ::proto::Point& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReaderInterface< ::proto::Feature>>(PrepareAsyncGetFeatureRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientReaderInterface< ::proto::Feature>> ListFeatures(::grpc::ClientContext* context, const ::proto::Rectangle& request) {
      return std::unique_ptr< ::grpc::ClientReaderInterface< ::proto::Feature>>(ListFeaturesRaw(context, request));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::proto::Feature>> AsyncListFeatures(::grpc::ClientContext* context, const ::proto::Rectangle& request, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::proto::Feature>>(AsyncListFeaturesRaw(context, request, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::proto::Feature>> PrepareAsyncListFeatures(::grpc::ClientContext* context, const ::proto::Rectangle& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderInterface< ::proto::Feature>>(PrepareAsyncListFeaturesRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientWriterInterface< ::proto::Point>> RecordRoute(::grpc::ClientContext* context, ::proto::RouteSummary* response) {
      return std::unique_ptr< ::grpc::ClientWriterInterface< ::proto::Point>>(RecordRouteRaw(context, response));
    }
    std::unique_ptr< ::grpc::ClientAsyncWriterInterface< ::proto::Point>> AsyncRecordRoute(::grpc::ClientContext* context, ::proto::RouteSummary* response, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncWriterInterface< ::proto::Point>>(AsyncRecordRouteRaw(context, response, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncWriterInterface< ::proto::Point>> PrepareAsyncRecordRoute(::grpc::ClientContext* context, ::proto::RouteSummary* response, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncWriterInterface< ::proto::Point>>(PrepareAsyncRecordRouteRaw(context, response, cq));
    }
    std::unique_ptr< ::grpc::ClientReaderWriterInterface< ::proto::RouteNote, ::proto::RouteNote>> RouteChat(::grpc::ClientContext* context) {
      return std::unique_ptr< ::grpc::ClientReaderWriterInterface< ::proto::RouteNote, ::proto::RouteNote>>(RouteChatRaw(context));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::proto::RouteNote, ::proto::RouteNote>> AsyncRouteChat(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::proto::RouteNote, ::proto::RouteNote>>(AsyncRouteChatRaw(context, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::proto::RouteNote, ::proto::RouteNote>> PrepareAsyncRouteChat(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::proto::RouteNote, ::proto::RouteNote>>(PrepareAsyncRouteChatRaw(context, cq));
    }
    class async_interface {
     public:
      virtual ~async_interface() {}
      virtual void GetFeature(::grpc::ClientContext* context, const ::proto::Point* request, ::proto::Feature* response, std::function<void(::grpc::Status)>) = 0;
      virtual void GetFeature(::grpc::ClientContext* context, const ::proto::Point* request, ::proto::Feature* response, ::grpc::ClientUnaryReactor* reactor) = 0;
      virtual void ListFeatures(::grpc::ClientContext* context, const ::proto::Rectangle* request, ::grpc::ClientReadReactor< ::proto::Feature>* reactor) = 0;
      virtual void RecordRoute(::grpc::ClientContext* context, ::proto::RouteSummary* response, ::grpc::ClientWriteReactor< ::proto::Point>* reactor) = 0;
      virtual void RouteChat(::grpc::ClientContext* context, ::grpc::ClientBidiReactor< ::proto::RouteNote,::proto::RouteNote>* reactor) = 0;
    };
    typedef class async_interface experimental_async_interface;
    virtual class async_interface* async() { return nullptr; }
    class async_interface* experimental_async() { return async(); }
   private:
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::proto::Feature>* AsyncGetFeatureRaw(::grpc::ClientContext* context, const ::proto::Point& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientAsyncResponseReaderInterface< ::proto::Feature>* PrepareAsyncGetFeatureRaw(::grpc::ClientContext* context, const ::proto::Point& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientReaderInterface< ::proto::Feature>* ListFeaturesRaw(::grpc::ClientContext* context, const ::proto::Rectangle& request) = 0;
    virtual ::grpc::ClientAsyncReaderInterface< ::proto::Feature>* AsyncListFeaturesRaw(::grpc::ClientContext* context, const ::proto::Rectangle& request, ::grpc::CompletionQueue* cq, void* tag) = 0;
    virtual ::grpc::ClientAsyncReaderInterface< ::proto::Feature>* PrepareAsyncListFeaturesRaw(::grpc::ClientContext* context, const ::proto::Rectangle& request, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientWriterInterface< ::proto::Point>* RecordRouteRaw(::grpc::ClientContext* context, ::proto::RouteSummary* response) = 0;
    virtual ::grpc::ClientAsyncWriterInterface< ::proto::Point>* AsyncRecordRouteRaw(::grpc::ClientContext* context, ::proto::RouteSummary* response, ::grpc::CompletionQueue* cq, void* tag) = 0;
    virtual ::grpc::ClientAsyncWriterInterface< ::proto::Point>* PrepareAsyncRecordRouteRaw(::grpc::ClientContext* context, ::proto::RouteSummary* response, ::grpc::CompletionQueue* cq) = 0;
    virtual ::grpc::ClientReaderWriterInterface< ::proto::RouteNote, ::proto::RouteNote>* RouteChatRaw(::grpc::ClientContext* context) = 0;
    virtual ::grpc::ClientAsyncReaderWriterInterface< ::proto::RouteNote, ::proto::RouteNote>* AsyncRouteChatRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) = 0;
    virtual ::grpc::ClientAsyncReaderWriterInterface< ::proto::RouteNote, ::proto::RouteNote>* PrepareAsyncRouteChatRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    ::grpc::Status GetFeature(::grpc::ClientContext* context, const ::proto::Point& request, ::proto::Feature* response) override;
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::proto::Feature>> AsyncGetFeature(::grpc::ClientContext* context, const ::proto::Point& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::proto::Feature>>(AsyncGetFeatureRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::proto::Feature>> PrepareAsyncGetFeature(::grpc::ClientContext* context, const ::proto::Point& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncResponseReader< ::proto::Feature>>(PrepareAsyncGetFeatureRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientReader< ::proto::Feature>> ListFeatures(::grpc::ClientContext* context, const ::proto::Rectangle& request) {
      return std::unique_ptr< ::grpc::ClientReader< ::proto::Feature>>(ListFeaturesRaw(context, request));
    }
    std::unique_ptr< ::grpc::ClientAsyncReader< ::proto::Feature>> AsyncListFeatures(::grpc::ClientContext* context, const ::proto::Rectangle& request, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReader< ::proto::Feature>>(AsyncListFeaturesRaw(context, request, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReader< ::proto::Feature>> PrepareAsyncListFeatures(::grpc::ClientContext* context, const ::proto::Rectangle& request, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReader< ::proto::Feature>>(PrepareAsyncListFeaturesRaw(context, request, cq));
    }
    std::unique_ptr< ::grpc::ClientWriter< ::proto::Point>> RecordRoute(::grpc::ClientContext* context, ::proto::RouteSummary* response) {
      return std::unique_ptr< ::grpc::ClientWriter< ::proto::Point>>(RecordRouteRaw(context, response));
    }
    std::unique_ptr< ::grpc::ClientAsyncWriter< ::proto::Point>> AsyncRecordRoute(::grpc::ClientContext* context, ::proto::RouteSummary* response, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncWriter< ::proto::Point>>(AsyncRecordRouteRaw(context, response, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncWriter< ::proto::Point>> PrepareAsyncRecordRoute(::grpc::ClientContext* context, ::proto::RouteSummary* response, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncWriter< ::proto::Point>>(PrepareAsyncRecordRouteRaw(context, response, cq));
    }
    std::unique_ptr< ::grpc::ClientReaderWriter< ::proto::RouteNote, ::proto::RouteNote>> RouteChat(::grpc::ClientContext* context) {
      return std::unique_ptr< ::grpc::ClientReaderWriter< ::proto::RouteNote, ::proto::RouteNote>>(RouteChatRaw(context));
    }
    std::unique_ptr<  ::grpc::ClientAsyncReaderWriter< ::proto::RouteNote, ::proto::RouteNote>> AsyncRouteChat(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriter< ::proto::RouteNote, ::proto::RouteNote>>(AsyncRouteChatRaw(context, cq, tag));
    }
    std::unique_ptr<  ::grpc::ClientAsyncReaderWriter< ::proto::RouteNote, ::proto::RouteNote>> PrepareAsyncRouteChat(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriter< ::proto::RouteNote, ::proto::RouteNote>>(PrepareAsyncRouteChatRaw(context, cq));
    }
    class async final :
      public StubInterface::async_interface {
     public:
      void GetFeature(::grpc::ClientContext* context, const ::proto::Point* request, ::proto::Feature* response, std::function<void(::grpc::Status)>) override;
      void GetFeature(::grpc::ClientContext* context, const ::proto::Point* request, ::proto::Feature* response, ::grpc::ClientUnaryReactor* reactor) override;
      void ListFeatures(::grpc::ClientContext* context, const ::proto::Rectangle* request, ::grpc::ClientReadReactor< ::proto::Feature>* reactor) override;
      void RecordRoute(::grpc::ClientContext* context, ::proto::RouteSummary* response, ::grpc::ClientWriteReactor< ::proto::Point>* reactor) override;
      void RouteChat(::grpc::ClientContext* context, ::grpc::ClientBidiReactor< ::proto::RouteNote,::proto::RouteNote>* reactor) override;
     private:
      friend class Stub;
      explicit async(Stub* stub): stub_(stub) { }
      Stub* stub() { return stub_; }
      Stub* stub_;
    };
    class async* async() override { return &async_stub_; }

   private:
    std::shared_ptr< ::grpc::ChannelInterface> channel_;
    class async async_stub_{this};
    ::grpc::ClientAsyncResponseReader< ::proto::Feature>* AsyncGetFeatureRaw(::grpc::ClientContext* context, const ::proto::Point& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientAsyncResponseReader< ::proto::Feature>* PrepareAsyncGetFeatureRaw(::grpc::ClientContext* context, const ::proto::Point& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientReader< ::proto::Feature>* ListFeaturesRaw(::grpc::ClientContext* context, const ::proto::Rectangle& request) override;
    ::grpc::ClientAsyncReader< ::proto::Feature>* AsyncListFeaturesRaw(::grpc::ClientContext* context, const ::proto::Rectangle& request, ::grpc::CompletionQueue* cq, void* tag) override;
    ::grpc::ClientAsyncReader< ::proto::Feature>* PrepareAsyncListFeaturesRaw(::grpc::ClientContext* context, const ::proto::Rectangle& request, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientWriter< ::proto::Point>* RecordRouteRaw(::grpc::ClientContext* context, ::proto::RouteSummary* response) override;
    ::grpc::ClientAsyncWriter< ::proto::Point>* AsyncRecordRouteRaw(::grpc::ClientContext* context, ::proto::RouteSummary* response, ::grpc::CompletionQueue* cq, void* tag) override;
    ::grpc::ClientAsyncWriter< ::proto::Point>* PrepareAsyncRecordRouteRaw(::grpc::ClientContext* context, ::proto::RouteSummary* response, ::grpc::CompletionQueue* cq) override;
    ::grpc::ClientReaderWriter< ::proto::RouteNote, ::proto::RouteNote>* RouteChatRaw(::grpc::ClientContext* context) override;
    ::grpc::ClientAsyncReaderWriter< ::proto::RouteNote, ::proto::RouteNote>* AsyncRouteChatRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) override;
    ::grpc::ClientAsyncReaderWriter< ::proto::RouteNote, ::proto::RouteNote>* PrepareAsyncRouteChatRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_GetFeature_;
    const ::grpc::internal::RpcMethod rpcmethod_ListFeatures_;
    const ::grpc::internal::RpcMethod rpcmethod_RecordRoute_;
    const ::grpc::internal::RpcMethod rpcmethod_RouteChat_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    virtual ::grpc::Status GetFeature(::grpc::ServerContext* context, const ::proto::Point* request, ::proto::Feature* response);
    virtual ::grpc::Status ListFeatures(::grpc::ServerContext* context, const ::proto::Rectangle* request, ::grpc::ServerWriter< ::proto::Feature>* writer);
    virtual ::grpc::Status RecordRoute(::grpc::ServerContext* context, ::grpc::ServerReader< ::proto::Point>* reader, ::proto::RouteSummary* response);
    virtual ::grpc::Status RouteChat(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::proto::RouteNote, ::proto::RouteNote>* stream);
  };
  template <class BaseClass>
  class WithAsyncMethod_GetFeature : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_GetFeature() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_GetFeature() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetFeature(::grpc::ServerContext* /*context*/, const ::proto::Point* /*request*/, ::proto::Feature* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetFeature(::grpc::ServerContext* context, ::proto::Point* request, ::grpc::ServerAsyncResponseWriter< ::proto::Feature>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_ListFeatures : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_ListFeatures() {
      ::grpc::Service::MarkMethodAsync(1);
    }
    ~WithAsyncMethod_ListFeatures() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ListFeatures(::grpc::ServerContext* /*context*/, const ::proto::Rectangle* /*request*/, ::grpc::ServerWriter< ::proto::Feature>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestListFeatures(::grpc::ServerContext* context, ::proto::Rectangle* request, ::grpc::ServerAsyncWriter< ::proto::Feature>* writer, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncServerStreaming(1, context, request, writer, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_RecordRoute : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_RecordRoute() {
      ::grpc::Service::MarkMethodAsync(2);
    }
    ~WithAsyncMethod_RecordRoute() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status RecordRoute(::grpc::ServerContext* /*context*/, ::grpc::ServerReader< ::proto::Point>* /*reader*/, ::proto::RouteSummary* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestRecordRoute(::grpc::ServerContext* context, ::grpc::ServerAsyncReader< ::proto::RouteSummary, ::proto::Point>* reader, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncClientStreaming(2, context, reader, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithAsyncMethod_RouteChat : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_RouteChat() {
      ::grpc::Service::MarkMethodAsync(3);
    }
    ~WithAsyncMethod_RouteChat() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status RouteChat(::grpc::ServerContext* /*context*/, ::grpc::ServerReaderWriter< ::proto::RouteNote, ::proto::RouteNote>* /*stream*/)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestRouteChat(::grpc::ServerContext* context, ::grpc::ServerAsyncReaderWriter< ::proto::RouteNote, ::proto::RouteNote>* stream, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncBidiStreaming(3, context, stream, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_GetFeature<WithAsyncMethod_ListFeatures<WithAsyncMethod_RecordRoute<WithAsyncMethod_RouteChat<Service > > > > AsyncService;
  template <class BaseClass>
  class WithCallbackMethod_GetFeature : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_GetFeature() {
      ::grpc::Service::MarkMethodCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::proto::Point, ::proto::Feature>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::proto::Point* request, ::proto::Feature* response) { return this->GetFeature(context, request, response); }));}
    void SetMessageAllocatorFor_GetFeature(
        ::grpc::MessageAllocator< ::proto::Point, ::proto::Feature>* allocator) {
      ::grpc::internal::MethodHandler* const handler = ::grpc::Service::GetHandler(0);
      static_cast<::grpc::internal::CallbackUnaryHandler< ::proto::Point, ::proto::Feature>*>(handler)
              ->SetMessageAllocator(allocator);
    }
    ~WithCallbackMethod_GetFeature() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetFeature(::grpc::ServerContext* /*context*/, const ::proto::Point* /*request*/, ::proto::Feature* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* GetFeature(
      ::grpc::CallbackServerContext* /*context*/, const ::proto::Point* /*request*/, ::proto::Feature* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithCallbackMethod_ListFeatures : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_ListFeatures() {
      ::grpc::Service::MarkMethodCallback(1,
          new ::grpc::internal::CallbackServerStreamingHandler< ::proto::Rectangle, ::proto::Feature>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::proto::Rectangle* request) { return this->ListFeatures(context, request); }));
    }
    ~WithCallbackMethod_ListFeatures() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ListFeatures(::grpc::ServerContext* /*context*/, const ::proto::Rectangle* /*request*/, ::grpc::ServerWriter< ::proto::Feature>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerWriteReactor< ::proto::Feature>* ListFeatures(
      ::grpc::CallbackServerContext* /*context*/, const ::proto::Rectangle* /*request*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithCallbackMethod_RecordRoute : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_RecordRoute() {
      ::grpc::Service::MarkMethodCallback(2,
          new ::grpc::internal::CallbackClientStreamingHandler< ::proto::Point, ::proto::RouteSummary>(
            [this](
                   ::grpc::CallbackServerContext* context, ::proto::RouteSummary* response) { return this->RecordRoute(context, response); }));
    }
    ~WithCallbackMethod_RecordRoute() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status RecordRoute(::grpc::ServerContext* /*context*/, ::grpc::ServerReader< ::proto::Point>* /*reader*/, ::proto::RouteSummary* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerReadReactor< ::proto::Point>* RecordRoute(
      ::grpc::CallbackServerContext* /*context*/, ::proto::RouteSummary* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithCallbackMethod_RouteChat : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_RouteChat() {
      ::grpc::Service::MarkMethodCallback(3,
          new ::grpc::internal::CallbackBidiHandler< ::proto::RouteNote, ::proto::RouteNote>(
            [this](
                   ::grpc::CallbackServerContext* context) { return this->RouteChat(context); }));
    }
    ~WithCallbackMethod_RouteChat() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status RouteChat(::grpc::ServerContext* /*context*/, ::grpc::ServerReaderWriter< ::proto::RouteNote, ::proto::RouteNote>* /*stream*/)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerBidiReactor< ::proto::RouteNote, ::proto::RouteNote>* RouteChat(
      ::grpc::CallbackServerContext* /*context*/)
      { return nullptr; }
  };
  typedef WithCallbackMethod_GetFeature<WithCallbackMethod_ListFeatures<WithCallbackMethod_RecordRoute<WithCallbackMethod_RouteChat<Service > > > > CallbackService;
  typedef CallbackService ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_GetFeature : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_GetFeature() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_GetFeature() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetFeature(::grpc::ServerContext* /*context*/, const ::proto::Point* /*request*/, ::proto::Feature* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_ListFeatures : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_ListFeatures() {
      ::grpc::Service::MarkMethodGeneric(1);
    }
    ~WithGenericMethod_ListFeatures() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ListFeatures(::grpc::ServerContext* /*context*/, const ::proto::Rectangle* /*request*/, ::grpc::ServerWriter< ::proto::Feature>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_RecordRoute : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_RecordRoute() {
      ::grpc::Service::MarkMethodGeneric(2);
    }
    ~WithGenericMethod_RecordRoute() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status RecordRoute(::grpc::ServerContext* /*context*/, ::grpc::ServerReader< ::proto::Point>* /*reader*/, ::proto::RouteSummary* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithGenericMethod_RouteChat : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_RouteChat() {
      ::grpc::Service::MarkMethodGeneric(3);
    }
    ~WithGenericMethod_RouteChat() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status RouteChat(::grpc::ServerContext* /*context*/, ::grpc::ServerReaderWriter< ::proto::RouteNote, ::proto::RouteNote>* /*stream*/)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_GetFeature : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_GetFeature() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_GetFeature() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetFeature(::grpc::ServerContext* /*context*/, const ::proto::Point* /*request*/, ::proto::Feature* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestGetFeature(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncResponseWriter< ::grpc::ByteBuffer>* response, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncUnary(0, context, request, response, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_ListFeatures : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_ListFeatures() {
      ::grpc::Service::MarkMethodRaw(1);
    }
    ~WithRawMethod_ListFeatures() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ListFeatures(::grpc::ServerContext* /*context*/, const ::proto::Rectangle* /*request*/, ::grpc::ServerWriter< ::proto::Feature>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestListFeatures(::grpc::ServerContext* context, ::grpc::ByteBuffer* request, ::grpc::ServerAsyncWriter< ::grpc::ByteBuffer>* writer, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncServerStreaming(1, context, request, writer, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_RecordRoute : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_RecordRoute() {
      ::grpc::Service::MarkMethodRaw(2);
    }
    ~WithRawMethod_RecordRoute() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status RecordRoute(::grpc::ServerContext* /*context*/, ::grpc::ServerReader< ::proto::Point>* /*reader*/, ::proto::RouteSummary* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestRecordRoute(::grpc::ServerContext* context, ::grpc::ServerAsyncReader< ::grpc::ByteBuffer, ::grpc::ByteBuffer>* reader, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncClientStreaming(2, context, reader, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawMethod_RouteChat : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_RouteChat() {
      ::grpc::Service::MarkMethodRaw(3);
    }
    ~WithRawMethod_RouteChat() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status RouteChat(::grpc::ServerContext* /*context*/, ::grpc::ServerReaderWriter< ::proto::RouteNote, ::proto::RouteNote>* /*stream*/)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestRouteChat(::grpc::ServerContext* context, ::grpc::ServerAsyncReaderWriter< ::grpc::ByteBuffer, ::grpc::ByteBuffer>* stream, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncBidiStreaming(3, context, stream, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_GetFeature : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_GetFeature() {
      ::grpc::Service::MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackUnaryHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const ::grpc::ByteBuffer* request, ::grpc::ByteBuffer* response) { return this->GetFeature(context, request, response); }));
    }
    ~WithRawCallbackMethod_GetFeature() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status GetFeature(::grpc::ServerContext* /*context*/, const ::proto::Point* /*request*/, ::proto::Feature* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerUnaryReactor* GetFeature(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_ListFeatures : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_ListFeatures() {
      ::grpc::Service::MarkMethodRawCallback(1,
          new ::grpc::internal::CallbackServerStreamingHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, const::grpc::ByteBuffer* request) { return this->ListFeatures(context, request); }));
    }
    ~WithRawCallbackMethod_ListFeatures() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ListFeatures(::grpc::ServerContext* /*context*/, const ::proto::Rectangle* /*request*/, ::grpc::ServerWriter< ::proto::Feature>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerWriteReactor< ::grpc::ByteBuffer>* ListFeatures(
      ::grpc::CallbackServerContext* /*context*/, const ::grpc::ByteBuffer* /*request*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_RecordRoute : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_RecordRoute() {
      ::grpc::Service::MarkMethodRawCallback(2,
          new ::grpc::internal::CallbackClientStreamingHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context, ::grpc::ByteBuffer* response) { return this->RecordRoute(context, response); }));
    }
    ~WithRawCallbackMethod_RecordRoute() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status RecordRoute(::grpc::ServerContext* /*context*/, ::grpc::ServerReader< ::proto::Point>* /*reader*/, ::proto::RouteSummary* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerReadReactor< ::grpc::ByteBuffer>* RecordRoute(
      ::grpc::CallbackServerContext* /*context*/, ::grpc::ByteBuffer* /*response*/)  { return nullptr; }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_RouteChat : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_RouteChat() {
      ::grpc::Service::MarkMethodRawCallback(3,
          new ::grpc::internal::CallbackBidiHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context) { return this->RouteChat(context); }));
    }
    ~WithRawCallbackMethod_RouteChat() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status RouteChat(::grpc::ServerContext* /*context*/, ::grpc::ServerReaderWriter< ::proto::RouteNote, ::proto::RouteNote>* /*stream*/)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerBidiReactor< ::grpc::ByteBuffer, ::grpc::ByteBuffer>* RouteChat(
      ::grpc::CallbackServerContext* /*context*/)
      { return nullptr; }
  };
  template <class BaseClass>
  class WithStreamedUnaryMethod_GetFeature : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithStreamedUnaryMethod_GetFeature() {
      ::grpc::Service::MarkMethodStreamed(0,
        new ::grpc::internal::StreamedUnaryHandler<
          ::proto::Point, ::proto::Feature>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerUnaryStreamer<
                     ::proto::Point, ::proto::Feature>* streamer) {
                       return this->StreamedGetFeature(context,
                         streamer);
                  }));
    }
    ~WithStreamedUnaryMethod_GetFeature() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status GetFeature(::grpc::ServerContext* /*context*/, const ::proto::Point* /*request*/, ::proto::Feature* /*response*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with streamed unary
    virtual ::grpc::Status StreamedGetFeature(::grpc::ServerContext* context, ::grpc::ServerUnaryStreamer< ::proto::Point,::proto::Feature>* server_unary_streamer) = 0;
  };
  typedef WithStreamedUnaryMethod_GetFeature<Service > StreamedUnaryService;
  template <class BaseClass>
  class WithSplitStreamingMethod_ListFeatures : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithSplitStreamingMethod_ListFeatures() {
      ::grpc::Service::MarkMethodStreamed(1,
        new ::grpc::internal::SplitServerStreamingHandler<
          ::proto::Rectangle, ::proto::Feature>(
            [this](::grpc::ServerContext* context,
                   ::grpc::ServerSplitStreamer<
                     ::proto::Rectangle, ::proto::Feature>* streamer) {
                       return this->StreamedListFeatures(context,
                         streamer);
                  }));
    }
    ~WithSplitStreamingMethod_ListFeatures() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable regular version of this method
    ::grpc::Status ListFeatures(::grpc::ServerContext* /*context*/, const ::proto::Rectangle* /*request*/, ::grpc::ServerWriter< ::proto::Feature>* /*writer*/) override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    // replace default version of method with split streamed
    virtual ::grpc::Status StreamedListFeatures(::grpc::ServerContext* context, ::grpc::ServerSplitStreamer< ::proto::Rectangle,::proto::Feature>* server_split_streamer) = 0;
  };
  typedef WithSplitStreamingMethod_ListFeatures<Service > SplitStreamedService;
  typedef WithStreamedUnaryMethod_GetFeature<WithSplitStreamingMethod_ListFeatures<Service > > StreamedService;
};

}  // namespace proto


#endif  // GRPC_route_2eproto__INCLUDED