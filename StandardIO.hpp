//
//
//
#ifndef AP_EX4_DEFAULTIO_H
#define AP_EX4_DEFAULTIO_H

#include <iostream>
#include <string>
#include "DefaultIO.hpp"

using namespace std;

class StandardIO: public DefaultIO {
private:
    const std::string type = "standard";
public:
    string read();
    void write(std::string str);
    string IOType();
};

#endif //AP_EX4_DEFAULTIO_H