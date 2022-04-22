#include <iostream>
#include <chrono>
#include <string>

#include "zmq.hpp"
#include "nlohmann/json.hpp"

static zmq::context_t ctx;

int main()
{
    zmq::socket_t sock(ctx, zmq::socket_type::rep);
    sock.bind("tcp://127.0.0.1:5555");

    while (1) {
        zmq::message_t z_in;
        zmq::recv_result_t z_recv_result = sock.recv(z_in);
        if (!z_recv_result.has_value()) {
            std::cout << "Recv failed, exit rep\n";
            break;
        }

        nlohmann::json jmsg_in = nlohmann::json::parse(z_in.to_string());
        if (nlohmann::json::iterator jit = jmsg_in.find("randint"); jit == jmsg_in.end()) {
            std::cout << "Json doest not have ranint value";
            break;
        }

        int x = jmsg_in["randint"].get<int>();
        x *= x;

        nlohmann::json jmsg_out;
        jmsg_out["result"] = x;

        zmq::message_t z_out(jmsg_out.dump());
        sock.send(z_out, zmq::send_flags::none);
    }
 
    return 0;
}
