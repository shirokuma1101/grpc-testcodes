#include "protocpp/quick-start.grpc.pb.h"

using grpc::Channel;
using grpc::ClientContext;
using grpc::Status;

using quick_start::QuickStartServices;
using quick_start::HelloRequest;
using quick_start::HelloResponse;

class Client
{
public:
    
    Client(std::shared_ptr<Channel> channel)
        : stub(QuickStartServices::NewStub(channel))
    {}

    std::string SayHello(const std::string& prefix, const std::string& message) {
        ClientContext context;
        HelloRequest request;
        request.set_prefix(prefix);
        request.set_message(message);
        HelloResponse response;

        Status status = stub->SayHello(&context, request, &response);

        if (status.ok()) {
            return response.message();
        }
        else {
            std::cout << status.error_code() << ":" << status.error_message() << std::endl;
            return "RPC failed";
        }
    }

private:

    std::unique_ptr<QuickStartServices::Stub> stub;

};

int main()
{
    std::string server_addr = "localhost:8080";
    Client client(grpc::CreateChannel(server_addr, grpc::InsecureChannelCredentials()));
    
    std::string response = client.SayHello("client:", "Hello!");
    std::cout << "Received:<" << response << ">" << std::endl;

    return 0;
}
