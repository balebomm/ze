#include <iostream>
#include <chrono>
#include <string>
#include <random>
#include <thread>

#include "zmq.hpp"
#include "nlohmann/json.hpp"

using namespace std::chrono_literals;

static zmq::context_t ctx;

auto func = [&](std::string thread_id) {
    zmq::socket_t sock(ctx, zmq::socket_type::req);
    sock.connect("tcp://127.0.0.1:5555");

    std::random_device rd;
    std::mt19937 mt(rd());
    std::uniform_int_distribution<int> udist(0, 100);

    while (1) {
        nlohmann::json jmsg_out;
        jmsg_out["thread_id"] = thread_id;
        jmsg_out["randint"] = udist(mt);
        zmq::message_t z_out(jmsg_out.dump());
        sock.send(z_out, zmq::send_flags::none);

        zmq::message_t z_in;
        zmq::recv_result_t z_recv_result = sock.recv(z_in);
        if (!z_recv_result.has_value()) {
            std::cout << "Recv failed, exit req\n";
            break;
        }

        std::cout << "Sending: " << jmsg_out << " received: " << z_in.to_string() << "\n";

        std::this_thread::sleep_for(500ms);
    }
};

int main()
{
    std::thread thr_0 = std::thread(func, "thread_0");
    std::thread thr_1 = std::thread(func, "thread_1");

    thr_0.join();
    thr_1.join();

    return 0;
}
