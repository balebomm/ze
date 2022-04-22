#include <iostream>
#include <thread>
#include <chrono>

#include "nlohmann/json.hpp"
#include "zmq.hpp"

using namespace std::chrono_literals;

static zmq::context_t ctx;

auto func = [](std::string thread_name) {
    zmq::socket_t sock(ctx, zmq::socket_type::pull);
    sock.connect("tcp://127.0.0.1:5555");

    while (1) {
        zmq::message_t z_in;
        zmq::recv_result_t z_recv_result = sock.recv(z_in, zmq::recv_flags::none);
        if (!z_recv_result.has_value()) {
            std::cout << "Recv failed";
            break;
        }

        std::cout << "Thread_name " << thread_name << " received: " << z_in.to_string() << "\n";
        std::this_thread::sleep_for(500ms);
    }
};

int main()
{
    std::thread thread_1 = std::thread(func, "thread_1");
    std::thread thread_2 = std::thread(func, "thread_2");
    std::thread thread_3 = std::thread(func, "thread_3");

    thread_1.join();
    thread_2.join();
    thread_3.join();

    return 0;
}
