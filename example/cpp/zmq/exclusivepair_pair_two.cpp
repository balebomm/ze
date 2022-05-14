#include <iostream>
#include <string>

#include "zmq.hpp"

static zmq::context_t ctx;

// sock pair accept only one address connect and ignore the others

int main()
{
    zmq::socket_t sock(ctx, zmq::socket_type::pair);
    sock.bind("tcp://127.0.0.1:5555");

    while (1) {
        zmq::message_t z_in;
        zmq::recv_result_t z_receive_result = sock.recv(z_in, zmq::recv_flags::none);
        if (!z_receive_result.has_value()) {
            std::cout << "Receive failed\n";
            break;
        }

        std::cout << "Received: " << z_in.to_string() << "\n";
    }
    return 0;
}
