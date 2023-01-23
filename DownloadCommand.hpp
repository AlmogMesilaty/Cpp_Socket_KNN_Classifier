//
// Created by Ariel Oscar 209341684 and Almog Mesilaty 314973686
//

#ifndef AP_EX4_DOWNLOADCOMMAND_H
#define AP_EX4_DOWNLOADCOMMAND_H

#include "Command.hpp"
#include "DefaultIO.hpp"
#include "DataManager.hpp"

class DownloadCommand: public Command {
public:
    //Constructor
    DownloadCommand(DefaultIO* dio, DataManager* d) : Command(dio, d, "download results") { }
    void execute();
    };


#endif //AP_EX4_DOWNLOADCOMMAND_H
