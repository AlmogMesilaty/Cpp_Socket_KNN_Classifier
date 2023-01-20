//
// Created by ariel_7za0dpc on 19/01/2023.
//
#include <string.h>
#include <iostream>

#ifndef AP_EX4_DEFAULTIO_H
#define AP_EX4_DEFAULTIO_H


class DefaultIO {
    public:
        DefaultIO();   // Constructor.
        virtual std::string read();
        virtual void write(std::string str);

    };



#endif //AP_EX4_DEFAULTIO_H
