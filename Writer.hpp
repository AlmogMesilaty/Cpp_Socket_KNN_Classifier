//
//
#ifndef AP_EX4_WRITER_H
#define AP_EX4_WRITER_H

#include <iostream>
#include <fstream>
#include <string>
#include "DefaultIO.hpp"
#include "SocketIO.hpp"


//Command class description
class Writer {
protected:
    std::string path;
    std::string data;
    DefaultIO* dio;
public:
    Writer(DefaultIO* dio);
    void writeToFIle();
};


#endif //AP_EX4_WRITER_H
