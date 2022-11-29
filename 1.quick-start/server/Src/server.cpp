#include "grpcpp/ext/proto_server_reflection_plugin.h"
#include "grpcpp/health_check_service_interface.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

using quick_start::QuickStartServices;
using quick_start::HelloRequest;
using quick_start::HelloResponse;

class ServicesImpl final : public QuickStartServices::Service
{
    // インターフェース実装
    Status SayHello(ServerContext* ctx, const HelloRequest* request, HelloResponse* response) override {
        response->set_message("Hi! Certainly received!:("+ request->prefix() + request->message() + ")");
        return Status::OK;
    }
};

void RunServer(const std::string& server_addr)
{
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
