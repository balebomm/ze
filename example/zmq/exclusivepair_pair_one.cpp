#include <iostream>
#include <thread>
#include <chrono>
#include <random>

#include "nlohmann/json.hpp"
#include "zmq.hpp"

using namespace std::chrono_literals;

static zmq::context_t ctx;

auto func = [&](std::string thread_id) {
    zmq::socket_t sock(ctx, zmq::socket_type::pair);
    sock.connect("tcp://127.0.0.1:5555");

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> udist(0, 100);

    while (1) {
        nlohmann::json jmsg;
        jmsg["randint"] = udist(mt);
        jmsg["thread_id"] = thread_id;

        zmq::message_t z_out(jmsg.dump());
        sock.send(z_out, zmq::send_flags::none);

        std::this_thread::sleep_for(500ms);
    }
};

int main()
{
    std::thread thread_1 = std::thread(func, "thread_1");
    std::thread thread_2 = std::thread(func, "thread_2");

    thread_1.join();
    thread_2.join();

    return 0;
}
