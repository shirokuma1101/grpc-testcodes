#include "client.h"

int main() {
    // コマンドライン引数
    auto vm = common::GetCmdLine();

    auto& host = vm["host"].as<std::string>();
    auto& port = vm["port"].as<std::string>();

    std::string server_addr = host + ":" + port;
    auto client = std::make_shared<Client>(server_addr);

    auto file_path = client->GetFilePath(AssetType::JSON, "test");
    
    // save the file to file_path
    std::cout << file_path << std::endl;

    //TODO: async
    client->HotReload(AssetType::JSON, "test");

    return 0;
}
