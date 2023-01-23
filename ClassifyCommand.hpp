//
// Created by Ariel Oscar 209341684 and Almog Mesilaty 314973686
//
#ifndef AP_EX4_CLASSIFYCOMMAND_H
#define AP_EX4_CLASSIFYCOMMAND_H

#include "DefaultIO.hpp"
#include "Knn.hpp"
#include "VectorDistances.hpp"
#include "DataManager.hpp"
#include "Command.hpp"

class ClassifyCommand: public Command {
public:
    //Constructor
    ClassifyCommand(DefaultIO* dio, DataManager* d);
	//Execute
	void execute();
};


#endif //AP_EX4_CLASSIFY_H
