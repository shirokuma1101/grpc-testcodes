#pragma once

#include "Proto/asset-hotreload.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

using ::HotReloadService;
using ::Request;
using ::FilePath;
using ::Successed;
using ::AssetType;

class Client {
public:

    Client(const std::string& host)
        : m_upStub(HotReloadService::NewStub(grpc::CreateChannel(host, grpc::InsecureChannelCredentials())))
    {}

    std::string GetFilePath(AssetType asset_type, std::string_view asset_name) {
        ClientContext ctx;
        Request request;
        request.set_name(asset_name.data());
        request.set_asset_type(asset_type);
        FilePath file_path;
        CheckStatus(m_upStub->GetFilePath(&ctx, request, &file_path));
        return file_path.file_path();
    }

    bool HotReload(AssetType asset_type, std::string_view asset_name) {
        ClientContext ctx;
        Request request;
        request.set_asset_type(asset_type);
        request.set_name(asset_name.data());
        Successed successed;
        CheckStatus(m_upStub->HotReload(&ctx, request, &successed));
        return successed.successed();
    }

    bool HotReload(AssetType asset_type, std::string_view asset_name) {
        ClientContext ctx;
        Request request;
        request.set_asset_type(asset_type);
        request.set_name(asset_name.data());
        Successed successed;
        CheckStatus(m_upStub->Async_HotReload(&ctx, request, &successed));
        return successed.successed();
    }

private:

    bool CheckStatus(const Status& status, std::string detail = {}) {
        if (status.ok()) return true;
        else {
            detail = status.error_code() + ":" + status.error_message();
            assert(0);
            return false;
        }
    }

    std::unique_ptr<HotReloadService::Stub> m_upStub;

};
