//
// Created by Ariel Oscar 209341684 and Almog Mesilaty 314973686
//
#ifndef AP_EX4_SETTINGS_H
#define AP_EX4_SETTINGS_H

#include <iostream>
#include "Command.hpp"

using namespace std;

class SettingsCommand : public Command {
private:
    int k; //the desired K
    string distance; //the desired distance

public:
    SettingsCommand(); //Default Constractor
};


#endif //AP_EX4_SETTINGS_H
