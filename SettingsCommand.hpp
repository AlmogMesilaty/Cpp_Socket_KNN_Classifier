//
// Created by Ariel Oscar 209341684 and Almog Mesilaty 314973686
//
#ifndef AP_EX4_SETTINGSCOMMAND_H
#define AP_EX4_SETTINGSCOMMAND_H

#include "InputValidator.hpp"

using namespace std;

class SettingsCommand : public Command {
	//Constructor
	SettingsCommand(DefalutIO* dio, CLI* c) : Command("algorithm settings", dio) { }
	//Execute
	void execute();
};


#endif //AP_EX4_SETTINGSCOMMAND_H
