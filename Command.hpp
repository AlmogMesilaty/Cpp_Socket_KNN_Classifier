//
// Created by ariel_7za0dpc on 19/01/2023.
//
#ifndef AP_EX4_COMMAND_H
#define AP_EX4_COMMAND_H

#include <string.h>
#include "DefaultIO.h"

//Command class description
class Command {
private:
    std::string m_description;
    DefaultIO m_dio;
public:
    //Constructor
    Command(std::string description, DefaultIO* dio);
    //Execute the commansd
    virtual void execute();
    //Returns the IO
    const DefaultIO* getDio();
    //Returns the command description
    const std::string& getDescription();
};


#endif //AP_EX4_COMMAND_H
