//
//
#ifndef AP_EX4_WRITER_H
#define AP_EX4_WRITER_H

#include <iostream>
#include "DefaultIO.hpp"


//Command class description
class Writer {
protected:
    std::string path;
    std::string data;
    DefaultIO* dio;
public:
    void write();
};


#endif //AP_EX4_WRITER_H
