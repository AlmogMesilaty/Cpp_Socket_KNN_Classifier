//
//
//
#ifndef AP_EX4_DEFAULTIO_H
#define AP_EX4_DEFAULTIO_H

#include <string>

using namespace std;

class StandardIO : public DefaultIO {
    static const string type = "standard";
public:
    string read();
    void write(std::string str);
    string IOType();
};

#endif //AP_EX4_DEFAULTIO_H