// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: uid-manager.proto

#include "uid-manager.pb.h"
#include "uid-manager.grpc.pb.h"

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

static const char* UidService_method_names[] = {
  "/UidService/GetUidPool",
};

std::unique_ptr< UidService::Stub> UidService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< UidService::Stub> stub(new UidService::Stub(channel, options));
  return stub;
}

UidService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_GetUidPool_(UidService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status UidService::Stub::GetUidPool(::grpc::ClientContext* context, const ::RequestUidPoolSize& request, ::ResponseUidPool* response) {
  return ::grpc::internal::BlockingUnaryCall< ::RequestUidPoolSize, ::ResponseUidPool, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetUidPool_, context, request, response);
}

void UidService::Stub::async::GetUidPool(::grpc::ClientContext* context, const ::RequestUidPoolSize* request, ::ResponseUidPool* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::RequestUidPoolSize, ::ResponseUidPool, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetUidPool_, context, request, response, std::move(f));
}

void UidService::Stub::async::GetUidPool(::grpc::ClientContext* context, const ::RequestUidPoolSize* request, ::ResponseUidPool* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetUidPool_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::ResponseUidPool>* UidService::Stub::PrepareAsyncGetUidPoolRaw(::grpc::ClientContext* context, const ::RequestUidPoolSize& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::ResponseUidPool, ::RequestUidPoolSize, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetUidPool_, context, request);
}

::grpc::ClientAsyncResponseReader< ::ResponseUidPool>* UidService::Stub::AsyncGetUidPoolRaw(::grpc::ClientContext* context, const ::RequestUidPoolSize& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetUidPoolRaw(context, request, cq);
  result->StartCall();
  return result;
}

UidService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      UidService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< UidService::Service, ::RequestUidPoolSize, ::ResponseUidPool, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](UidService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::RequestUidPoolSize* req,
             ::ResponseUidPool* resp) {
               return service->GetUidPool(ctx, req, resp);
             }, this)));
}

UidService::Service::~Service() {
}

::grpc::Status UidService::Service::GetUidPool(::grpc::ServerContext* context, const ::RequestUidPoolSize* request, ::ResponseUidPool* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


