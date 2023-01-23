//
// Created by Ariel Oscar 209341684 and Almog Mesilaty 314973686
//
#ifndef AP_EX4_CLASSIFYCOMMAND_H
#define AP_EX4_CLASSIFYCOMMAND_H

#include "Command.hpp"
#include "DefaultIO.hpp"
#include "CLI.hpp"
#include "Knn.hpp"
#include "VectorDistances.hpp"

using namespace std;

class ClassifyCommand: public Command {
public:
    //Constructor
    ClassifyCommand(DefaultIO* dio, CLI* cli);
	//Execute
	void execute();
};


#endif //AP_EX4_CLASSIFY_H
