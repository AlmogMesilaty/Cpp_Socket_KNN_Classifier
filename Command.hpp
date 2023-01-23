//
// Created by ariel_7za0dpc on 19/01/2023.
//
#ifndef AP_EX4_COMMAND_H
#define AP_EX4_COMMAND_H

#include <iostream>
#include "DefaultIO.hpp"
#include "DataManager.hpp"

//Command class description
class Command {
protected:
    DefaultIO* dio;
    DataManager* d;
    std::string description;

public:
    //Default Constructor
    Command(DefaultIO* dio, DataManager* d, std::string description);
    //Execute the commansd
    virtual void execute();
    //Returns the IO
    const DefaultIO* getDio();
    //Returns the command description
    const std::string getDescription();
};


#endif //AP_EX4_COMMAND_H
