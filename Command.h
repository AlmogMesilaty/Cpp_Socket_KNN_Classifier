//
// Created by ariel_7za0dpc on 19/01/2023.
//
#include <string.h>
#include <iostream>
#include "DefaultIO.h"
#ifndef AP_EX4_COMMAND_H
#define AP_EX4_COMMAND_H


class Command {
protected:
    std::string description;
    DefaultIO dio;
public:
    Command();
    virtual void execute();
};


#endif //AP_EX4_COMMAND_H
