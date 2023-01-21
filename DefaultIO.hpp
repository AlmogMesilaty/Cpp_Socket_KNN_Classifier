//
// Created by ariel_7za0dpc on 19/01/2023.
//
#ifndef AP_EX4_DEFAULTIO_H
#define AP_EX4_DEFAULTIO_H

#include <string>

class DefaultIO {
    public:
        virtual std::string read();
        virtual void write(std::string str);
        virtual std::string IOType();
    };

#endif //AP_EX4_DEFAULTIO_H
