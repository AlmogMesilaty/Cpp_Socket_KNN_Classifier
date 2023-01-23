//
//
//
#ifndef AP_EX4_DEFAULTIO_H
#define AP_EX4_DEFAULTIO_H

#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <fstream>
#include <regex>
#include "TypedVector.hpp"
#include "VectorDistances.hpp"
#include "Knn.hpp"
#include "InputValidator.hpp"
#include "StringMethods.hpp"
#define FILE 1
#define PORT 2

class StandardIO : public DefaultIO {
    static const string type = "standard";
public:
    string read();
    void write(std::string str);
    string IOType();
};

#endif //AP_EX4_DEFAULTIO_H