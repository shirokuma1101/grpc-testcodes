// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: bidirectional-streaming-rpc.proto

#include "bidirectional-streaming-rpc.pb.h"
#include "bidirectional-streaming-rpc.grpc.pb.h"

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

static const char* Chat_method_names[] = {
  "/Chat/ChatStream",
};

std::unique_ptr< Chat::Stub> Chat::NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options) {
  (void)options;
  std::unique_ptr< Chat::Stub> stub(new Chat::Stub(channel, options));
  return stub;
}

Chat::Stub::Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options)
  : channel_(channel), rpcmethod_ChatStream_(Chat_method_names[0], options.suffix_for_stats(),::grpc::internal::RpcMethod::BIDI_STREAMING, channel)
  {}

::grpc::ClientReaderWriter< ::ChatDetail, ::ChatDetail>* Chat::Stub::ChatStreamRaw(::grpc::ClientContext* context) {
  return ::grpc::internal::ClientReaderWriterFactory< ::ChatDetail, ::ChatDetail>::Create(channel_.get(), rpcmethod_ChatStream_, context);
}

void Chat::Stub::async::ChatStream(::grpc::ClientContext* context, ::grpc::ClientBidiReactor< ::ChatDetail,::ChatDetail>* reactor) {
  ::grpc::internal::ClientCallbackReaderWriterFactory< ::ChatDetail,::ChatDetail>::Create(stub_->channel_.get(), stub_->rpcmethod_ChatStream_, context, reactor);
}

::grpc::ClientAsyncReaderWriter< ::ChatDetail, ::ChatDetail>* Chat::Stub::AsyncChatStreamRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::ChatDetail, ::ChatDetail>::Create(channel_.get(), cq, rpcmethod_ChatStream_, context, true, tag);
}

::grpc::ClientAsyncReaderWriter< ::ChatDetail, ::ChatDetail>* Chat::Stub::PrepareAsyncChatStreamRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
  return ::grpc::internal::ClientAsyncReaderWriterFactory< ::ChatDetail, ::ChatDetail>::Create(channel_.get(), cq, rpcmethod_ChatStream_, context, false, nullptr);
}

Chat::Service::Service() {
  AddMethod(new ::grpc::internal::RpcServiceMethod(
      Chat_method_names[0],
      ::grpc::internal::RpcMethod::BIDI_STREAMING,
      new ::grpc::internal::BidiStreamingHandler< Chat::Service, ::ChatDetail, ::ChatDetail>(
          [](Chat::Service* service,
             ::grpc::ServerContext* ctx,
             ::grpc::ServerReaderWriter<::ChatDetail,
             ::ChatDetail>* stream) {
               return service->ChatStream(ctx, stream);
             }, this)));
}

Chat::Service::~Service() {
}

::grpc::Status Chat::Service::ChatStream(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::ChatDetail, ::ChatDetail>* stream) {
  (void) context;
  (void) stream;
  return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
}


