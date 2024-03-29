//
// Created by Ariel Oscar 209341684 and Almog Mesilaty 314973686
//
#ifndef AP_EX4_UPLOADECOMMAND_H
#define AP_EX4_UPLOADECOMMAND_H

#include "Reader.hpp"
#include "Writer.hpp"
#include "Command.hpp"
#include "DefaultIO.hpp"
#include "DataManager.hpp"

class UploadCommand : public Command {
public:
	//Constructor
	UploadCommand(DefaultIO* dio, DataManager* d);
	//Execute
	void execute();
};


#endif //AP_EX4_UPLOADECOMMAND_H
