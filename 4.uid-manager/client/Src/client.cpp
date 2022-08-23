#include "client.h"

int main() {
    // コマンドライン引数
    auto vm = common::GetCmdLine();

    auto& host = vm["host"].as<std::string>();
    auto& port = vm["port"].as<std::string>();

    std::string server_addr = host + ":" + port;
    auto client = std::make_shared<Client>(server_addr);

    auto uid_manager = std::make_shared<UidManager>(client);

    while (true) {
        static bool is_up_push = false;
        if (GetAsyncKeyState(VK_UP)) {
            if (!is_up_push) {
                is_up_push = true;
                std::cout << "client: " << uid_manager->GetUID() << std::endl;
            }
        }
        else {
            is_up_push = false;
        }
        
        if (GetAsyncKeyState(VK_SPACE)) {
            break;
        }
    }
    
    return 0;
}
