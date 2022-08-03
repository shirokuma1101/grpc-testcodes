// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: quick-start.proto

#include "quick-start.pb.h"
#include "quick-start.grpc.pb.h"

#include <functional>
#include <grpcpp/impl/codegen/async_stream.h>
#include <grpcpp/impl/codegen/async_unary_call.h>
#include <grpcpp/impl/codegen/channel_interface.h>
#include <grpcpp/impl/codegen/client_unary_call.h>
#include <grpcpp/impl/codegen/client_callback.h>
#include <grpcpp/impl/codegen/message_allocator.h>
#include <grpcpp/impl/codegen/method_handler.h>
#include <grpcpp/impl/codegen/rpc_service_method.h>
#include <grpcpp/impl/codegen/server_callback.h>
#include <grpcpp/impl/codegen/server_callback_handlers.h>
#include <grpcpp/impl/codegen/server_context.h>
#include <grpcpp/impl/codegen/service_type.h>
#include <grpcpp/impl/codegen/sync_stream.h>
namespace quick_start {

static const char* QuickStartServices_method_names[] = {
  "/quick_start.QuickStartServices/SayHello",
};

std::unique_ptr< QuickStartServices::Stub> QuickStartServices::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< QuickStartServices::Stub> stub(new QuickStartServices::Stub(channel, options));
  return stub;
}

QuickStartServices::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_SayHello_(QuickStartServices_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status QuickStartServices::Stub::SayHello(::grpc::ClientContext* context, const ::quick_start::HelloRequest& request, ::quick_start::HelloResponse* response) {
  return ::grpc::internal::BlockingUnaryCall< ::quick_start::HelloRequest, ::quick_start::HelloResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_SayHello_, context, request, response);
}

void QuickStartServices::Stub::async::SayHello(::grpc::ClientContext* context, const ::quick_start::HelloRequest* request, ::quick_start::HelloResponse* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::quick_start::HelloRequest, ::quick_start::HelloResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SayHello_, context, request, response, std::move(f));
}

void QuickStartServices::Stub::async::SayHello(::grpc::ClientContext* context, const ::quick_start::HelloRequest* request, ::quick_start::HelloResponse* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_SayHello_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::quick_start::HelloResponse>* QuickStartServices::Stub::PrepareAsyncSayHelloRaw(::grpc::ClientContext* context, const ::quick_start::HelloRequest& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::quick_start::HelloResponse, ::quick_start::HelloRequest, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_SayHello_, context, request);
}

::grpc::ClientAsyncResponseReader< ::quick_start::HelloResponse>* QuickStartServices::Stub::AsyncSayHelloRaw(::grpc::ClientContext* context, const ::quick_start::HelloRequest& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncSayHelloRaw(context, request, cq);
  result->StartCall();
  return result;
}

QuickStartServices::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      QuickStartServices_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< QuickStartServices::Service, ::quick_start::HelloRequest, ::quick_start::HelloResponse, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](QuickStartServices::Service* service,
             ::grpc::ServerContext* ctx,
             const ::quick_start::HelloRequest* req,
             ::quick_start::HelloResponse* resp) {
               return service->SayHello(ctx, req, resp);
             }, this)));
}

QuickStartServices::Service::~Service() {
}

::grpc::Status QuickStartServices::Service::SayHello(::grpc::ServerContext* context, const ::quick_start::HelloRequest* request, ::quick_start::HelloResponse* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


}  // namespace quick_start
