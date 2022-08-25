// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: asset-hotreload.proto

#include "asset-hotreload.pb.h"
#include "asset-hotreload.grpc.pb.h"

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

static const char* HotReloadService_method_names[] = {
  "/HotReloadService/GetFilePath",
  "/HotReloadService/HotReload",
};

std::unique_ptr< HotReloadService::Stub> HotReloadService::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< HotReloadService::Stub> stub(new HotReloadService::Stub(channel, options));
  return stub;
}

HotReloadService::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_GetFilePath_(HotReloadService_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  , rpcmethod_HotReload_(HotReloadService_method_names[1], options.suffix_for_stats(),::grpc::internal::RpcMethod::NORMAL_RPC, channel)
  {}

::grpc::Status HotReloadService::Stub::GetFilePath(::grpc::ClientContext* context, const ::Request& request, ::FilePath* response) {
  return ::grpc::internal::BlockingUnaryCall< ::Request, ::FilePath, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_GetFilePath_, context, request, response);
}

void HotReloadService::Stub::async::GetFilePath(::grpc::ClientContext* context, const ::Request* request, ::FilePath* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::Request, ::FilePath, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetFilePath_, context, request, response, std::move(f));
}

void HotReloadService::Stub::async::GetFilePath(::grpc::ClientContext* context, const ::Request* request, ::FilePath* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_GetFilePath_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::FilePath>* HotReloadService::Stub::PrepareAsyncGetFilePathRaw(::grpc::ClientContext* context, const ::Request& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::FilePath, ::Request, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_GetFilePath_, context, request);
}

::grpc::ClientAsyncResponseReader< ::FilePath>* HotReloadService::Stub::AsyncGetFilePathRaw(::grpc::ClientContext* context, const ::Request& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncGetFilePathRaw(context, request, cq);
  result->StartCall();
  return result;
}

::grpc::Status HotReloadService::Stub::HotReload(::grpc::ClientContext* context, const ::Request& request, ::Successed* response) {
  return ::grpc::internal::BlockingUnaryCall< ::Request, ::Successed, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), rpcmethod_HotReload_, context, request, response);
}

void HotReloadService::Stub::async::HotReload(::grpc::ClientContext* context, const ::Request* request, ::Successed* response, std::function<void(::grpc::Status)> f) {
  ::grpc::internal::CallbackUnaryCall< ::Request, ::Successed, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_HotReload_, context, request, response, std::move(f));
}

void HotReloadService::Stub::async::HotReload(::grpc::ClientContext* context, const ::Request* request, ::Successed* response, ::grpc::ClientUnaryReactor* reactor) {
  ::grpc::internal::ClientCallbackUnaryFactory::Create< ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(stub_->channel_.get(), stub_->rpcmethod_HotReload_, context, request, response, reactor);
}

::grpc::ClientAsyncResponseReader< ::Successed>* HotReloadService::Stub::PrepareAsyncHotReloadRaw(::grpc::ClientContext* context, const ::Request& request, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncResponseReaderHelper::Create< ::Successed, ::Request, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(channel_.get(), cq, rpcmethod_HotReload_, context, request);
}

::grpc::ClientAsyncResponseReader< ::Successed>* HotReloadService::Stub::AsyncHotReloadRaw(::grpc::ClientContext* context, const ::Request& request, ::grpc::CompletionQueue* cq) {
  auto* result =
    this->PrepareAsyncHotReloadRaw(context, request, cq);
  result->StartCall();
  return result;
}

HotReloadService::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      HotReloadService_method_names[0],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< HotReloadService::Service, ::Request, ::FilePath, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](HotReloadService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::Request* req,
             ::FilePath* resp) {
               return service->GetFilePath(ctx, req, resp);
             }, this)));
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      HotReloadService_method_names[1],
      ::grpc::internal::RpcMethod::NORMAL_RPC,
      new ::grpc::internal::RpcMethodHandler< HotReloadService::Service, ::Request, ::Successed, ::grpc::protobuf::MessageLite, ::grpc::protobuf::MessageLite>(
          [](HotReloadService::Service* service,
             ::grpc::ServerContext* ctx,
             const ::Request* req,
             ::Successed* resp) {
               return service->HotReload(ctx, req, resp);
             }, this)));
}

HotReloadService::Service::~Service() {
}

::grpc::Status HotReloadService::Service::GetFilePath(::grpc::ServerContext* context, const ::Request* request, ::FilePath* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}

::grpc::Status HotReloadService::Service::HotReload(::grpc::ServerContext* context, const ::Request* request, ::Successed* response) {
  (void) context;
  (void) request;
  (void) response;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


