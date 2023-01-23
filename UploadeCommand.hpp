//
// Created by Ariel Oscar 209341684 and Almog Mesilaty 314973686
//
#ifndef AP_EX4_UPLOADECOMMAND_H
#define AP_EX4_UPLOADECOMMAND_H

#include "Reader.hpp"
#include "Writer.hpp"
#include "CLI"
#include "TypedVector.hpp"

class UploadeCommand : public Command {
	//Constructor
	UploadeCommand(DefalutIO* dio, CLI* c) : Command("upload an unclassified csv data file", dio) { }
	//Execute
	void execute();
};


#endif //AP_EX4_UPLOADECOMMAND_H
