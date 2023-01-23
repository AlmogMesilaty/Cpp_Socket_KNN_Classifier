//
// Created by Ariel Oscar 209341684 and Almog Mesilaty 314973686
//


using namespace std;

#ifndef AP_EX4_UPLOADE_H
#define AP_EX4_UPLOADE_H

#include <iostream>
#include "Command.hpp"

class UploadCommand : public Command {

private:
    string trainFileRoot; //root of server train CSV file
    string testFileRoot; //root of server test CSV file

public:
    UploadCommand(); //default constractor

};


#endif //AP_EX4_UPLOADE_H
