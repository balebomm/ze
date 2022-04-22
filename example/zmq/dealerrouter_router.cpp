#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <vector>

#include "nlohmann/json.hpp"
#include "zmq.hpp"
#include "zmq_addon.hpp"

using namespace std::chrono_literals;

static zmq::context_t ctx;

void sync_dealer_to_router() {
    zmq::socket_t sock(ctx, zmq::socket_type::router);
    sock.bind("tcp://127.0.0.1:5555");

    while (1) {
        std::vector<zmq::message_t> recv_msgs;
        auto res = zmq::recv_multipart(sock, std::back_inserter(recv_msgs));

        if (!res.has_value()) {
            std::cout << "no have value\n";
            break;
        }

        for (auto&& msg : recv_msgs) {
            std::cout << msg.to_string() << "\n";
        }
    }
}

void async_dealer_to_router_PULL_OUT()
{
    zmq::socket_t sock(ctx, zmq::socket_type::router);
    sock.bind("tcp://127.0.0.1:5555");

    while (1) {
        std::vector<zmq::message_t> recv_msgs;
        auto res = zmq::recv_multipart(sock, std::back_inserter(recv_msgs));

        if (!res.has_value()) {
            std::cout << "no have value\n";
            break;
        }

        for (auto&& msg : recv_msgs) {
            std::cout << msg.to_string() << "\n";
        }
        
        std::this_thread::sleep_for(100ms);
    }
}

void sync_multi_dealer_router() {
    zmq::socket_t sock(ctx, zmq::socket_type::router);
    sock.bind("tcp://127.0.0.1:5555");

    while (1) {
        std::vector<zmq::message_t> z_msgs;
        auto res = zmq::recv_multipart(sock, std::back_inserter(z_msgs));
        if (!res.has_value()) {
            std::cout << "Router recv multipart failed";
            break;
        }

        for (auto&& msg : z_msgs) {
            std::cout << msg.to_string() << "\n";
        }

        sock.send(zmq::str_buffer("strat_B"), zmq::send_flags::sndmore);
        sock.send(z_msgs[1], zmq::send_flags::none);
    }
}

int main()
{
    async_dealer_to_router_PULL_OUT();
    return 0;
}
