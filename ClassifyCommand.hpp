//
// Created by Ariel Oscar 209341684 and Almog Mesilaty 314973686
//
#ifndef AP_EX4_CLASSIFYCOMMAND_H
#define AP_EX4_CLASSIFYCOMMAND_H

#include <vector>
#include "TypedVector.hpp"
#include "Knn.hpp"

using namespace std;

class ClassifyCommand: public Command {
	//Constructor
	ClassifyCommand(DefalutIO* dio, CLI* c) : Command("classify data", dio, c) { }
	//Execute
	void execute();
};


#endif //AP_EX4_CLASSIFY_H
