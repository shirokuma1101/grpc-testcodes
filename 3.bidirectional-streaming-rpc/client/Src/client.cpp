#include <boost/thread.hpp>
#include <boost/program_options.hpp>
#include <grpcpp/grpcpp.h>
#include "Proto/bidirectional-streaming-rpc.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

using ::Chat;
using ::ChatDetail;
using Stream = grpc::ClientReaderWriter<ChatDetail, ChatDetail>;

class Client {
public:
    Client(std::shared_ptr<Channel> channel)
        : stub(Chat::NewStub(channel))
        , ctx()
        , stream(stub->ChatStream(&ctx))
    {}

    void SendChat(const std::string& name) {
        std::string input_text;
        ChatDetail  send_chat;
        while (true) {
            std::cin >> input_text;

            send_chat.set_name(name);
            send_chat.set_text(input_text);

            stream->Write(send_chat);
        }
    }

    void RecvChat() {
        ChatDetail recv_chat;
        while (true) {
            while (stream->Read(&recv_chat)) {
                std::cout << recv_chat.name() + " : " + recv_chat.text() << std::endl;
            }
        }
    }

private:

    std::unique_ptr<Chat::Stub> stub;
    ClientContext               ctx;
    std::unique_ptr<Stream>     stream;

};

int main() {
    // コマンドライン引数
    std::string argv = wide_to_sjis(GetCommandLine());
    const char* cargv = argv.c_str();
    auto ccargv = const_cast<const char* const*>(&cargv);

    boost::program_options::options_description desc("options");
    desc.add_options()
        ("name,n", boost::program_options::value<std::string>()->default_value("anonymous"), "client name")
        ("host,h", boost::program_options::value<std::string>()->default_value("localhost"), "host")
        ("port,p", boost::program_options::value<std::string>()->default_value("8080"), "port")
        ;
    boost::program_options::variables_map vm;
    boost::program_options::store(boost::program_options::parse_command_line(__argc, __argv, desc), vm);
    boost::program_options::notify(vm);

    auto& name = vm["name"].as<std::string>();
    auto& host = vm["host"].as<std::string>();
    auto& port = vm["port"].as<std::string>();

    std::string server_addr = host + ":" + port;
    Client client(grpc::CreateChannel(server_addr, grpc::InsecureChannelCredentials()));

    boost::thread thread([&] {
            client.RecvChat();
        }
    );

    client.SendChat(name);

    return 0;
}
