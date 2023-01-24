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
protected:
    //std::string path;
    //DataManager* d;
public:
    //Constructor
    //Reader(std::string path, DataManager* d);
    void read(std::string path, std::vector<TypedVector>* vectors);
    void readToFloat(std::string path, std::vector<vector<float>>* vectors);
};


#endif //AP_EX4_READER_H
