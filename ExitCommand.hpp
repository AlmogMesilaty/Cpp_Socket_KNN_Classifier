//
// Created by ariel_7za0dpc on 22/01/2023.
//

#ifndef AP_EX4_EXITCOMMAND_H
#define AP_EX4_EXITCOMMAND_H

#include "Command.hpp"
#include "DefaultIO.hpp"
#include "DataManager.hpp"

class ExitCommand: public Command {
public:
    //Constructor
    ExitCommand(DefaultIO* dio, DataManager* d) : Command(dio, d, "exit") { }
    //execute
    void execute();
};


#endif //AP_EX4_EXITCOMMAND_H
