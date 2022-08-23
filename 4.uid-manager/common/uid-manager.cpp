#include "uid-manager.h"

#include "uid-pool.h"
#include "client/Src/client.h"

UID UidManager::GetUID()
{
    std::lock_guard<std::mutex> lock(m_mtx);

    if (m_uids.size() == 0) {
        StockUid();
    }
    UID uid = m_uids.back();
    m_uids.pop_back();
    return uid;
}

void UidManager::StockUid(size_t size)
{
    if (!m_wpUidPool.expired()) {
        auto [start_uid, end_uid] = m_wpUidPool.lock()->GetIDs(size);
        for (size_t i = start_uid; i < end_uid; ++i) {
            m_uids.push_back(i);
        }
    }
    else if (!m_wpClient.expired()) {
        auto [start_uid, end_uid] = m_wpClient.lock()->GetUidPool(size);
        for (size_t i = start_uid; i < end_uid; ++i) {
            m_uids.push_back(i);
        }
    }
}
