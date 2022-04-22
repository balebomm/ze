#include <iostream>
#include <thread>
#include <chrono>
#include <random>
#include <string>
#include <vector>

#include "nlohmann/json.hpp"
#include "zmq.hpp"
#include "zmq_addon.hpp"

using namespace std::chrono_literals;
static zmq::context_t ctx;

void sync_dealer_to_router() {
    zmq::socket_t sock(ctx, zmq::socket_type::dealer);
    sock.connect("tcp://127.0.0.1:5555");

    std::random_device rd;
    std::mt19937 mt(rd());
    std::normal_distribution<double> normdist(0., 1.);

    while (1) {
        nlohmann::json jmsg;
        jmsg["randdoub"] = normdist(mt);
        zmq::message_t z_out(jmsg.dump());
        sock.send(z_out, zmq::send_flags::none);

        std::this_thread::sleep_for(500ms);
    }
}

void async_dealer_to_router_PULL_OUT() {
    zmq::socket_t sock(ctx, zmq::socket_type::dealer);
    sock.set(zmq::sockopt::routing_id, "Strat_AB");
    sock.connect("tcp://127.0.0.1:5555");

    zmq::pollitem_t items[] = {
        {sock, 0, ZMQ_POLLOUT, 0}
    };

    std::random_device rd;
    std::mt19937 mt(rd());
    std::normal_distribution<double> normdist(0., 1.);

    size_t iter = 0;
    while (1) {
        auto rc = zmq::poll(items, 1, 0ms); // 0: return imediately
        if (iter++ % 1000000)
            std::cout << rc << "\n";

        if (items[0].revents & ZMQ_POLLOUT) {
            nlohmann::json jmsg;
            jmsg["randdoub"] = normdist(mt);
            zmq::message_t z_out(jmsg.dump());
            sock.send(z_out, zmq::send_flags::none);
        }
    }
}

void sync_multi_dealer_router() {
    auto func_A = []() {
        zmq::socket_t sock(ctx, zmq::socket_type::dealer);
        sock.set(zmq::sockopt::routing_id, "strat_A");
        sock.connect("tcp://127.0.0.1:5555");

        std::random_device rd;
        std::mt19937 mt(rd());
        std::normal_distribution<double> normdist(0., 1.);

        while (1) {
            nlohmann::json jmsg;
            jmsg["randdoub"] = normdist(mt);
            zmq::message_t z_out(jmsg.dump());
            sock.send(z_out, zmq::send_flags::none);

            std::this_thread::sleep_for(500ms);
        }
    };

    auto func_B = []() {
        zmq::socket_t sock(ctx, zmq::socket_type::dealer);
        sock.set(zmq::sockopt::routing_id, "strat_B");
        sock.connect("tcp://127.0.0.1:5555");

        std::random_device rd;
        std::mt19937 mt(rd());
        std::normal_distribution<double> normdist(0., 1.);

        while (1) {
            std::vector<zmq::message_t> recv_msgs;
            auto res = zmq::recv_multipart(sock, std::back_inserter(recv_msgs));
            if (!res.has_value()) {
                std::cout << "strat_B recv socket failed\n";
                break;
            }

            for (auto && msg : recv_msgs) {
                std::cout << "strat_B " << msg.to_string() << "\n";
            }

            std::this_thread::sleep_for(500ms);
        }
    };

    std::thread thread_1 = std::thread(func_A);
    std::thread thread_2 = std::thread(func_B);

    thread_1.join();
    thread_2.join();
}

int main()
{
    async_dealer_to_router_PULL_OUT();
    return 0;
}
