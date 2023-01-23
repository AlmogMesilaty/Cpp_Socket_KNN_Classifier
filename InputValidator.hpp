//
// Created by Ariel Oscar 209341684 and Almog Mesilaty 314973686
//
#include <string.h>
#include <iostream>
#include <regex>

using namespace std;

#ifndef AP_EX4_INPUTVALIDATOR_H
#define AP_EX4_INPUTVALIDATOR_H

class InputValidator {
public:
	static int isValid(string s);
	static int IPIsValid(string s);
	static int PortIsValid(string s);
    static int inputIsValid(string s);
    bool validK(int k, int max);
};


#endif //AP_EX4_INPUTVALIDATOR_H
