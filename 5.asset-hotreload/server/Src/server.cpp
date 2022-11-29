#include "grpcpp/ext/proto_server_reflection_plugin.h"
#include "grpcpp/health_check_service_interface.h"

#include "asset-manager.h"

using grpc::Server;
using grpc::ServerBuilder;
using grpc::ServerContext;
using grpc::Status;

using ::HotReloadService;
using ::Request;
using ::FilePath;
using ::Successed;

class ServicesImpl final : public HotReloadService::Service
{
public:

    void Init(std::shared_ptr<AssetManager> asset_mgr) {
        m_wpAssetMgr = asset_mgr;
    }

private:

    Status GetFilePath(ServerContext* ctx, const Request* request, FilePath* file_path) override {
        file_path->set_file_path(
            m_wpAssetMgr.lock()->GetFilePath(
                static_cast<AssetManager::AssetType>(request->asset_type()),
                request->name()
            )
        );
        return Status::OK;
    }

    Status HotReload(ServerContext* ctx, const Request* request, Successed* successed) override {
        m_wpAssetMgr.lock()->Load(
            static_cast<AssetManager::AssetType>(request->asset_type()),
            request->name()
        );
        successed->set_successed(true);

        /* DEBUG */
        std::cout << "DEBUG: " << m_wpAssetMgr.lock()->GetJsonMgr()->GetData(request->name())->dump() << std::endl;
        /* END */
        
        return Status::OK;
    }

    Status Async_HotReload(ServerContext* ctx, const Request* request, Successed* successed) override {
        m_wpAssetMgr.lock()->AsyncLoad(
            static_cast<AssetManager::AssetType>(request->asset_type()),
            request->name()
        );
        successed->set_successed(true);
        return Status::OK;
    }

    std::weak_ptr<AssetManager> m_wpAssetMgr;

};

class GrpcServer
{
public:

    GrpcServer(const std::string& server_addr, std::shared_ptr<AssetManager> asset_mgr) {
        m_services.Init(asset_mgr);
        
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

    auto asset_mgr = std::make_shared<AssetManager>();
    asset_mgr->Register(AssetManager::AssetType::Json, "../asset/json/asset.json");
    asset_mgr->Load(AssetManager::AssetType::Json, "test");

    std::string server_addr = host + ":" + port;
    auto server = std::make_shared<GrpcServer>(server_addr, asset_mgr);
    auto server_thread = std::make_unique<boost::thread>(&GrpcServer::Run, server);

    while (true) {
        if (GetAsyncKeyState(VK_ESCAPE)) {
            server->Shutdown();
            server_thread->join();
            break;
        }
    }
    
    return 0;
}
