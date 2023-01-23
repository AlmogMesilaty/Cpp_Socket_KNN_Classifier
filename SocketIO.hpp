//
//
//
#ifndef AP_EX4_DEFAULTIO_H
#define AP_EX4_DEFAULTIO_H

#include <string>
#include "DefaultIO.hpp"

using namespace std;

class SocketIO: public DefaultIO {
    static const string type = "socket";

public:
    std::string read();
    void write(std::string str);
    string IOType();
};

#endif //AP_EX4_DEFAULTIO_H