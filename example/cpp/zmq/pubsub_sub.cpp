#include <iostream>
#include <thread>
#include <chrono>
#include <vector>

#include "nlohmann/json.hpp"
#include "zmq.hpp"

using namespace std::chrono_literals;
static zmq::context_t ctx;

int main()
{
    zmq::socket_t sock(ctx, zmq::socket_type::sub);
    int set_conflate = 1;
    sock.set(zmq::sockopt::conflate, &set_conflate);
    sock.connect("tcp://127.0.0.1:5555");
    sock.set(zmq::sockopt::subscribe, "");

    // {
    //     std::vector<std::string> topics {"mouse", "cat"};
    //     for (auto&& topic : topics) {
    //         sock.set(zmq::sockopt::subscribe, topic);
    //     }
    // }

    int count = 0;
    while (1) {
        // if (count ++ == 50) {
        //     sock.set(zmq::sockopt::unsubscribe, "mouse");
        //     sock.set(zmq::sockopt::unsubscribe, "cat");

        //     sock.set(zmq::sockopt::subscribe, "dog");
        // }

        std::this_thread::sleep_for(500ms);

        // zmq::message_t topic;
        zmq::message_t payload;
        // zmq::recv_result_t z_recv_topic = sock.recv(topic);
        // if (!z_recv_topic.has_value()) {
        //     std::cout << "Recv topic failed\n";
        //     break;
        // }

        zmq::recv_result_t z_recv_payload = sock.recv(payload);
        if (!z_recv_payload.has_value()) {
            std::cout << "Recv payload failed\n";
            break;
        }

        std::cout << " Payload: " << payload.to_string() << "\n";
    }

    return 0;
}
