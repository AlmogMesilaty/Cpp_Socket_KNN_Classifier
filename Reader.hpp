//
//
#ifndef AP_EX4_READER_H
#define AP_EX4_READER_H

#include <iostream>
#include <fstream>
#include <vector>
#include "DataManager.hpp"
#include "StringMethods.hpp"
#include "VectorDistances.hpp"

//Command class description
class Reader {
public:
    void read(std::string path, std::vector<TypedVector>* vectors);
    void readToFloat(std::string path, std::vector<vector<float>>* vectors);
};


#endif //AP_EX4_READER_H
