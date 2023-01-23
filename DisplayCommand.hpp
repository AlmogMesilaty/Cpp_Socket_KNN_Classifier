//
// Created by Ariel Oscar 209341684 and Almog Mesilaty 314973686
//

#ifndef AP_EX4_DISPLAYCOMMAND_H
#define AP_EX4_DISPLAYCOMMAND_H

#include <iostream>
#include "Command.hpp"
#include "DefaultIO.hpp"
#include "DataManager.hpp"

class DisplayCommand: public Command{

public:
    //Constructor
    DisplayCommand(DefaultIO* dio, DataManager* d) : Command(dio, d, "display results") { }
    //execute
    void execute();
};


#endif //AP_EX4_DISPLAYCOMMAND_H
