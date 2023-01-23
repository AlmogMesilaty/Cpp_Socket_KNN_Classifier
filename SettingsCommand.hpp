//
// Created by Ariel Oscar 209341684 and Almog Mesilaty 314973686
//
#ifndef AP_EX4_SETTINGSCOMMAND_H
#define AP_EX4_SETTINGSCOMMAND_H

#include "Command.hpp"
#include "DefaultIO.hpp"
#include "CLI.hpp"
#include "InputValidator.hpp"

using namespace std;

class SettingsCommand : public Command {
public:
    //Constructor
    SettingsCommand(DefaultIO* dio, CLI* cli) : Command(dio, cli, "2. algorithm settings") { }
	//Execute
	void execute();
};


#endif //AP_EX4_SETTINGSCOMMAND_H
