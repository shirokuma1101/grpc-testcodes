#include <grpcpp/ext/proto_server_reflection_plugin.h>
#include <grpcpp/health_check_service_interface.h>
#include "Proto/uid-manager.grpc.pb.h"

#include "uid-manager.h"
#include "uid-pool.h"

//using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

using ::UidService;
using ::RequestUidPoolSize;
using ::ResponseUidPool;

class ServicesImpl final : public UidService::Service {
public:

    void Init(std::shared_ptr<UidPool> uid_pool) {
        m_wpUidPool = uid_pool;
    }

private:

    Status GetUidPool(ServerContext* ctx, const RequestUidPoolSize* size, ResponseUidPool* uid_pool) override {
        auto [start_uid, end_uid] = m_wpUidPool.lock()->GetIDs(size->size());
        uid_pool->set_start_uid(start_uid);
        uid_pool->set_end_uid(end_uid);
        return Status::OK;
    }

    std::weak_ptr<UidPool> m_wpUidPool;

};

class Server {
public:

    Server(const std::string& server_addr, const std::shared_ptr<UidPool>& uid_pool) {
        m_services.Init(uid_pool);

        grpc::EnableDefaultHealthCheckService(true);
        grpc::reflection::InitProtoReflectionServerBuilderPlugin();

        m_builder.AddListeningPort(server_addr, grpc::InsecureServerCredentials());
        m_builder.RegisterService(&m_services);

        m_upServer = m_builder.BuildAndStart();
        
        std::cout << "Server listening on:" << server_addr << std::endl;
    }

    void Run() {
        m_upServer->Wait();
    }

    void Shutdown() {
        m_upServer->Shutdown();
    }

private:

    ServicesImpl                  m_services;
    ServerBuilder                 m_builder;
    std::unique_ptr<grpc::Server> m_upServer;

};

int main()
{
    // コマンドライン引数
    auto vm = common::GetCmdLine();

    auto& host = vm["host"].as<std::string>();
    auto& port = vm["port"].as<std::string>();

    std::string server_addr = host + ":" + port;
    auto uid_pool = std::make_shared<UidPool>();
    auto server = std::make_shared<Server>(server_addr, uid_pool);
    auto server_thread = std::make_unique<boost::thread>(&Server::Run, server);

    auto uid_manager = std::make_shared<UidManager>(uid_pool);

    while (true) {
        static bool is_down_push = false;
        if (GetAsyncKeyState(VK_DOWN)) {
            if (!is_down_push) {
                is_down_push = true;
                std::cout << "server: " << uid_manager->GetUID() << std::endl;
            }
        }
        else {
            is_down_push = false;
        }

        if (GetAsyncKeyState(VK_SPACE)) {
            server->Shutdown();
            break;
        }
    }
    
    return 0;
}
