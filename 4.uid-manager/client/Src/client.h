#pragma once

#include "uid-manager.h"
#include "uid-pool.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

using ::UidService;
using ::RequestUidPoolSize;
using ::ResponseUidPool;

class Client {
public:

    Client(const std::string& host)
        : m_upStub(UidService::NewStub(grpc::CreateChannel(host, grpc::InsecureChannelCredentials())))
    {}

    std::pair<UID, UID> GetUidPool(size_t size) {
        ClientContext ctx;
        RequestUidPoolSize uid_pool_size;
        uid_pool_size.set_size(size);
        ResponseUidPool uid_pool;
        CheckStatus(m_upStub->GetUidPool(&ctx, uid_pool_size, &uid_pool));
        return { uid_pool.start_uid(), uid_pool.end_uid() };
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

    std::unique_ptr<UidService::Stub> m_upStub;

};
