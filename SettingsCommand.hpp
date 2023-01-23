//
// Created by Ariel Oscar 209341684 and Almog Mesilaty 314973686
//
#ifndef AP_EX4_SETTINGSCOMMAND_H
#define AP_EX4_SETTINGSCOMMAND_H

#include "DefaultIO.hpp"
#include "DataManager.hpp"
#include "InputValidator.hpp"
#include "Command.hpp"

using namespace std;

class SettingsCommand : public Command {
public:
    //Constructor
    SettingsCommand(DefaultIO* dio, DataManager* d);
	//Execute
	void execute();
};


#endif //AP_EX4_SETTINGSCOMMAND_H
