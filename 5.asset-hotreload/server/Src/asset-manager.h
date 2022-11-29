#pragma once

#include "ExternalDependencies/Asset/Json/JsonManager.h"

class AssetManager
{
public:

    enum class AssetType {
        Unknown,
        Json,
    };

    AssetManager()
        : m_upJsonMgr(std::make_unique<JsonManager>())
    {}
    ~AssetManager() {}

    void Register(AssetType type, std::string_view path) {
        switch (type) {
        case AssetType::Json:
            m_upJsonMgr->Register(path);
            break;
        }
    }

    void Load(AssetType type, std::string_view name) {
        switch (type) {
        case AssetType::Json:
            m_upJsonMgr->Load(name);
            break;
        }
    }

    void AsyncLoad(AssetType type, std::string_view name, bool force = false) {
        switch (type) {
        case AssetType::Json:
            m_upJsonMgr->AsyncLoad(name, force);
            break;
        }
    }

    std::string GetFilePath(AssetType type, std::string_view name) {
        switch (type) {
        case AssetType::Json:
            return m_upJsonMgr->GetFilePath(name);
            break;
        }
        return "";
    }

    const std::unique_ptr<JsonManager>& GetJsonMgr() const {
        return m_upJsonMgr;
    }

private:

    std::unique_ptr<JsonManager> m_upJsonMgr;

};
