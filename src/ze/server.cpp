#include "ze/server.hpp"

#include <string>
#include <iostream>
#ifndef _WIN32
#include <unistd.h> 
#else
#include <windows.h>

#define sleep(n) Sleep(n)
#endif

#include "zmq.hpp"

void ze::vrun_server()
{
    zmq::context_t context(2);
    zmq::socket_t socket (context, zmq::socket_type::rep);
    socket.bind("tcp://*:5555");

    while (true) {
        zmq::message_t request;
        
        socket.recv(request, zmq::recv_flags::none);
        std::cout << "Received Hello\n";

        sleep(1);

        zmq::message_t reply(5);
        memcpy (reply.data(), "World", 5);
        socket.send(reply, zmq::send_flags::none);
    }
}