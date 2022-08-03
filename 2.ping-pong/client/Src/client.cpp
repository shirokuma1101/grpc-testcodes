#include <iostream>
#include <string>

#include <grpcpp/grpcpp.h>
#include "Proto/ping-pong.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

using ::PingPong;
using ::Ping;
using ::Pong;

class Client {
public:
    Client(std::shared_ptr<Channel> channel)
        : stub(PingPong::NewStub(channel))
    {}

    UINT64 SendPing(UINT64 real_time) {
        ClientContext context;
        Ping ping;
        ping.set_time(real_time);
        Pong pong;

        Status status = stub->SendPing(&context, ping, &pong);

        if (status.ok()) {
            return pong.time();
        }
        else {
            std::cout << status.error_code() << ":" << status.error_message() << std::endl;
            return 0;
        }
    }

private:

    std::unique_ptr<PingPong::Stub> stub;

};

int main() {
    UINT64 rt = common::GetRealTime();
    std::string server_addr = "localhost:8080";
    Client client(grpc::CreateChannel(server_addr, grpc::InsecureChannelCredentials()));

    UINT64 response = client.SendPing(rt);
    UINT64 latency = response - rt;
    auto st = common::GetSystemTime(latency);
    std::cout << "Latency:" << st.wMilliseconds << "ms" << std::endl;

    return 0;
}
