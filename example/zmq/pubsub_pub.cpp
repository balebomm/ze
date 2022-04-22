#include <iostream>
#include <thread>
#include <chrono>
#include <random>

#include "nlohmann/json.hpp"
#include "zmq.hpp"

using namespace std::chrono_literals;

static zmq::context_t ctx;

int main()
{
    zmq::socket_t sock(ctx, zmq::socket_type::pub);
    sock.bind("tcp://127.0.0.1:5555");

    std::random_device rd;
    std::mt19937 mt(rd());
    std::normal_distribution<double> normdist(0., 0.1);
    std::uniform_int_distribution<int> udist(0, 2);

    int pub_count = 0;
    while (true) {
        std::this_thread::sleep_for(50ms);
        std::string name{""};
        nlohmann::json jmsg_out;
        int randint = udist(mt);

        if (randint == 0) {
            name = "mouse";
        }
        else if (randint == 1) {
            name = "cat";
        }
        else {
            name = "dog";
        }

        jmsg_out[name] = normdist(mt);
        jmsg_out["pub_count"] = pub_count ++;

        // zmq::message_t topic(name);
        // sock.send(topic, zmq::send_flags::sndmore);

        zmq::message_t payload(jmsg_out.dump());
        sock.send(payload, zmq::send_flags::none);

        std::cout << "Public msg: " << jmsg_out << "\n";
    }

    return 0;
}
