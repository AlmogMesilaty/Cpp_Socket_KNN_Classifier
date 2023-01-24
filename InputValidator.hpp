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
    static bool validK(string s, int max);
	static bool validMetric(string s);
	static bool validSettings(string s);
};


#endif //AP_EX4_INPUTVALIDATOR_H
