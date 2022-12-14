// Generated by the gRPC C++ plugin.
// If you make any local change, they will be lost.
// source: bidirectional-streaming-rpc.proto
// Original file comments:
// バージョン 
#ifndef GRPC_bidirectional_2dstreaming_2drpc_2eproto__INCLUDED
#define GRPC_bidirectional_2dstreaming_2drpc_2eproto__INCLUDED

#include "bidirectional-streaming-rpc.pb.h"

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

// パッケージ 
//
// インポート 
//
// サービス 
class Chat final {
 public:
  static constexpr char const* service_full_name() {
    return "Chat";
  }
  class StubInterface {
   public:
    virtual ~StubInterface() {}
    // RPC 
    std::unique_ptr< ::grpc::ClientReaderWriterInterface< ::ChatDetail, ::ChatDetail>> ChatStream(::grpc::ClientContext* context) {
      return std::unique_ptr< ::grpc::ClientReaderWriterInterface< ::ChatDetail, ::ChatDetail>>(ChatStreamRaw(context));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::ChatDetail, ::ChatDetail>> AsyncChatStream(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::ChatDetail, ::ChatDetail>>(AsyncChatStreamRaw(context, cq, tag));
    }
    std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::ChatDetail, ::ChatDetail>> PrepareAsyncChatStream(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriterInterface< ::ChatDetail, ::ChatDetail>>(PrepareAsyncChatStreamRaw(context, cq));
    }
    class async_interface {
     public:
      virtual ~async_interface() {}
      // RPC 
      virtual void ChatStream(::grpc::ClientContext* context, ::grpc::ClientBidiReactor< ::ChatDetail,::ChatDetail>* reactor) = 0;
    };
    typedef class async_interface experimental_async_interface;
    virtual class async_interface* async() { return nullptr; }
    class async_interface* experimental_async() { return async(); }
   private:
    virtual ::grpc::ClientReaderWriterInterface< ::ChatDetail, ::ChatDetail>* ChatStreamRaw(::grpc::ClientContext* context) = 0;
    virtual ::grpc::ClientAsyncReaderWriterInterface< ::ChatDetail, ::ChatDetail>* AsyncChatStreamRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) = 0;
    virtual ::grpc::ClientAsyncReaderWriterInterface< ::ChatDetail, ::ChatDetail>* PrepareAsyncChatStreamRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) = 0;
  };
  class Stub final : public StubInterface {
   public:
    Stub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());
    std::unique_ptr< ::grpc::ClientReaderWriter< ::ChatDetail, ::ChatDetail>> ChatStream(::grpc::ClientContext* context) {
      return std::unique_ptr< ::grpc::ClientReaderWriter< ::ChatDetail, ::ChatDetail>>(ChatStreamRaw(context));
    }
    std::unique_ptr<  ::grpc::ClientAsyncReaderWriter< ::ChatDetail, ::ChatDetail>> AsyncChatStream(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriter< ::ChatDetail, ::ChatDetail>>(AsyncChatStreamRaw(context, cq, tag));
    }
    std::unique_ptr<  ::grpc::ClientAsyncReaderWriter< ::ChatDetail, ::ChatDetail>> PrepareAsyncChatStream(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) {
      return std::unique_ptr< ::grpc::ClientAsyncReaderWriter< ::ChatDetail, ::ChatDetail>>(PrepareAsyncChatStreamRaw(context, cq));
    }
    class async final :
      public StubInterface::async_interface {
     public:
      void ChatStream(::grpc::ClientContext* context, ::grpc::ClientBidiReactor< ::ChatDetail,::ChatDetail>* reactor) override;
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
    ::grpc::ClientReaderWriter< ::ChatDetail, ::ChatDetail>* ChatStreamRaw(::grpc::ClientContext* context) override;
    ::grpc::ClientAsyncReaderWriter< ::ChatDetail, ::ChatDetail>* AsyncChatStreamRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq, void* tag) override;
    ::grpc::ClientAsyncReaderWriter< ::ChatDetail, ::ChatDetail>* PrepareAsyncChatStreamRaw(::grpc::ClientContext* context, ::grpc::CompletionQueue* cq) override;
    const ::grpc::internal::RpcMethod rpcmethod_ChatStream_;
  };
  static std::unique_ptr<Stub> NewStub(const std::shared_ptr< ::grpc::ChannelInterface>& channel, const ::grpc::StubOptions& options = ::grpc::StubOptions());

  class Service : public ::grpc::Service {
   public:
    Service();
    virtual ~Service();
    // RPC 
    virtual ::grpc::Status ChatStream(::grpc::ServerContext* context, ::grpc::ServerReaderWriter< ::ChatDetail, ::ChatDetail>* stream);
  };
  template <class BaseClass>
  class WithAsyncMethod_ChatStream : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithAsyncMethod_ChatStream() {
      ::grpc::Service::MarkMethodAsync(0);
    }
    ~WithAsyncMethod_ChatStream() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ChatStream(::grpc::ServerContext* /*context*/, ::grpc::ServerReaderWriter< ::ChatDetail, ::ChatDetail>* /*stream*/)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestChatStream(::grpc::ServerContext* context, ::grpc::ServerAsyncReaderWriter< ::ChatDetail, ::ChatDetail>* stream, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncBidiStreaming(0, context, stream, new_call_cq, notification_cq, tag);
    }
  };
  typedef WithAsyncMethod_ChatStream<Service > AsyncService;
  template <class BaseClass>
  class WithCallbackMethod_ChatStream : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithCallbackMethod_ChatStream() {
      ::grpc::Service::MarkMethodCallback(0,
          new ::grpc::internal::CallbackBidiHandler< ::ChatDetail, ::ChatDetail>(
            [this](
                   ::grpc::CallbackServerContext* context) { return this->ChatStream(context); }));
    }
    ~WithCallbackMethod_ChatStream() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ChatStream(::grpc::ServerContext* /*context*/, ::grpc::ServerReaderWriter< ::ChatDetail, ::ChatDetail>* /*stream*/)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerBidiReactor< ::ChatDetail, ::ChatDetail>* ChatStream(
      ::grpc::CallbackServerContext* /*context*/)
      { return nullptr; }
  };
  typedef WithCallbackMethod_ChatStream<Service > CallbackService;
  typedef CallbackService ExperimentalCallbackService;
  template <class BaseClass>
  class WithGenericMethod_ChatStream : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithGenericMethod_ChatStream() {
      ::grpc::Service::MarkMethodGeneric(0);
    }
    ~WithGenericMethod_ChatStream() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ChatStream(::grpc::ServerContext* /*context*/, ::grpc::ServerReaderWriter< ::ChatDetail, ::ChatDetail>* /*stream*/)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
  };
  template <class BaseClass>
  class WithRawMethod_ChatStream : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawMethod_ChatStream() {
      ::grpc::Service::MarkMethodRaw(0);
    }
    ~WithRawMethod_ChatStream() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ChatStream(::grpc::ServerContext* /*context*/, ::grpc::ServerReaderWriter< ::ChatDetail, ::ChatDetail>* /*stream*/)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    void RequestChatStream(::grpc::ServerContext* context, ::grpc::ServerAsyncReaderWriter< ::grpc::ByteBuffer, ::grpc::ByteBuffer>* stream, ::grpc::CompletionQueue* new_call_cq, ::grpc::ServerCompletionQueue* notification_cq, void *tag) {
      ::grpc::Service::RequestAsyncBidiStreaming(0, context, stream, new_call_cq, notification_cq, tag);
    }
  };
  template <class BaseClass>
  class WithRawCallbackMethod_ChatStream : public BaseClass {
   private:
    void BaseClassMustBeDerivedFromService(const Service* /*service*/) {}
   public:
    WithRawCallbackMethod_ChatStream() {
      ::grpc::Service::MarkMethodRawCallback(0,
          new ::grpc::internal::CallbackBidiHandler< ::grpc::ByteBuffer, ::grpc::ByteBuffer>(
            [this](
                   ::grpc::CallbackServerContext* context) { return this->ChatStream(context); }));
    }
    ~WithRawCallbackMethod_ChatStream() override {
      BaseClassMustBeDerivedFromService(this);
    }
    // disable synchronous version of this method
    ::grpc::Status ChatStream(::grpc::ServerContext* /*context*/, ::grpc::ServerReaderWriter< ::ChatDetail, ::ChatDetail>* /*stream*/)  override {
      abort();
      return ::grpc::Status(::grpc::StatusCode::UNIMPLEMENTED, "");
    }
    virtual ::grpc::ServerBidiReactor< ::grpc::ByteBuffer, ::grpc::ByteBuffer>* ChatStream(
      ::grpc::CallbackServerContext* /*context*/)
      { return nullptr; }
  };
  typedef Service StreamedUnaryService;
  typedef Service SplitStreamedService;
  typedef Service StreamedService;
};


#endif  // GRPC_bidirectional_2dstreaming_2drpc_2eproto__INCLUDED
