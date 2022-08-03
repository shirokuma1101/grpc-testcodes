#include <iostream>
#include <string>

#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/grpcpp.h>
#include <grpcpp/health_check_service_interface.h>
#include "Proto/ping-pong.grpc.pb.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

using ::PingPong;
using ::Ping;
using ::Pong;

class ServicesImpl final : public PingPong::Service {
    // インターフェース実装
    Status SendPing(ServerContext* ctx, const Ping* ping, Pong* pong) override {
        UINT64 rt = common::GetRealTime();
        pong->set_time(rt);
        UINT64 latency = rt - ping->time();
        auto st = common::GetSystemTime(latency);
        std::cout << "Latency:" << st.wMilliseconds << "ms" << std::endl;
        return Status::OK;
    }
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
