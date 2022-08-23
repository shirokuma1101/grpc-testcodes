#pragma once

#include "common.h"

class UidPool;
class Client;

class UidManager {
public:

    UidManager(std::shared_ptr<UidPool> uid_pool = nullptr)
        : m_wpUidPool(uid_pool)
    {}
    UidManager(std::shared_ptr<Client> client = nullptr)
        : m_wpClient(client)
    {}

    UID GetUID();

private:

    void StockUid(size_t size = 100);

    std::weak_ptr<UidPool> m_wpUidPool;
    std::weak_ptr<Client>  m_wpClient;

    std::mutex             m_mtx;
    std::vector<UID>       m_uids;

};
