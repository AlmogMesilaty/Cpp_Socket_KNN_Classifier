//
// Created by Ariel Oscar 209341684 and Almog Mesilaty 314973686
//
#include <string.h>
#include <iostream>
#include <algorithm>
#include "TypedVector.hpp"
#include "VectorDistances.hpp"
#include "VectorDistances.hpp"

#define DELIMITER '#'

using namespace std;

#ifndef AP_EX4_STRINGMETHODS_H
#define AP_EX4_STRINGMETHODS_H

class StringMethods {
	public:
		static string insertDelimiter(string s);
		static TypedVector stringToTypedVector(string s);
};


#endif //AP_EX4_STRINGMETHODS_H
