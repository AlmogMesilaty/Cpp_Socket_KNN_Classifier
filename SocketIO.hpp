//
//
//
#ifndef AP_EX4_SOCKETIO_H
#define AP_EX4_SOCKETIO_H

#include <string>
#include <iostream>
#include <sys/socket.h>
#include "DefaultIO.hpp"

class SocketIO : public DefaultIO {
private:
    const std::string type = "socket";
    int sock;

public:
    SocketIO(int sock);
    std::string read();
    void write(std::string str);
    std::string IOType();
};

#endif //AP_EX4_SOCKETIO_H