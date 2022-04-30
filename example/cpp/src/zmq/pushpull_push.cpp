#include <iostream>
#include <thread>
#include <chrono>

#include "zmq.hpp"
#include "nlohmann/json.hpp"

using namespace std::chrono_literals;

static zmq::context_t ctx;

int main()
{
    zmq::socket_t sock(ctx, zmq::socket_type::push);
    sock.bind("tcp://127.0.0.1:5555");

    int count = 0;
    while (1) {
        nlohmann::json jmsg_out;
        jmsg_out["count"] = count++;

        zmq::message_t z_out(jmsg_out.dump());

        sock.send(z_out, zmq::send_flags::none);
    }

    return 0;
}
