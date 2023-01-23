//
// Created by Ariel Oscar 209341684 and Almog Mesilaty 314973686
//
#ifndef AP_EX4_CLASSIFY_H
#define AP_EX4_CLASSIFY_H

#include <iostream>
#include <list>
#include "Command.hpp"

using namespace std;

class ClassifyCommand: public Command {
private:
    std::list<string> classified; //an array of all the classified types of the vectors
public:
    ClassifyCommand();
};


#endif //AP_EX4_CLASSIFY_H
