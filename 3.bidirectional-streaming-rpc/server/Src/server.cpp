#include <map>

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include "Proto/bidirectional-streaming-rpc.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

using ::Chat;
using ::ChatDetail;

class ServicesImpl final : public Chat::Service {
    Status ChatStream(ServerContext* ctx, grpc::ServerReaderWriter<ChatDetail, ChatDetail>* stream) override {
        ChatDetail recv_chat;
        ChatDetail broadcast_chat;

        clients.emplace(ctx->peer(), *stream);

        while (stream->Read(&recv_chat)) {
            broadcast_chat.set_name(recv_chat.name());
            broadcast_chat.set_text(recv_chat.text());
            for (auto&& e : clients) {
                e.second.Write(broadcast_chat);
            }
        }

        clients.erase(ctx->peer());

        return Status::OK;
    }

private:

    std::map<std::string, grpc::ServerReaderWriter<ChatDetail, ChatDetail>> clients;

};

void RunServer(const std::string& server_addr) {
    ServicesImpl services;
    ServerBuilder builder;

    grpc::EnableDefaultHealthCheckService(true);
    grpc::reflection::InitProtoReflectionServerBuilderPlugin();

    builder.AddListeningPort(server_addr, grpc::InsecureServerCredentials());
    builder.RegisterService(&services);

    std::unique_ptr<Server> server(builder.BuildAndStart());
    std::cout << "Server listening on:" << server_addr << std::endl;

    server->Wait();
}

int main()
{
    RunServer("localhost:8080");
    
    return 0;
}
