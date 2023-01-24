//
// Created by ariel_7za0dpc on 19/01/2023.
//
#ifndef AP_EX4_DEFAULTIO_H
#define AP_EX4_DEFAULTIO_H

#include <string>

class DefaultIO {
    public:
        virtual std::string read()=0;
        virtual void write(std::string str)=0;
        virtual std::string IOType()=0;
    };

#endif //AP_EX4_DEFAULTIO_H
