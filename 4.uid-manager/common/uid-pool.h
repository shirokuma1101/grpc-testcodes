#pragma once

class UidPool
{
public:

    UidPool(size_t capacity = 10000) {
        m_uids.reserve(capacity);
    }

    std::pair<UID, UID> GetIDs(size_t size) {
        std::lock_guard<std::mutex> lock(m_mtx);

        UID start_uid = GetID();
        UID end_uid;
        for (size_t i = 0; i < size - 1; ++i) {
            end_uid = GetID();
        }
        return { start_uid, end_uid };
    }

private:

    UID GetID() {
        UID uid = m_uids.size();
        m_uids.push_back(uid);
        return uid;
    }

    std::mutex       m_mtx;
    std::vector<UID> m_uids;

};
