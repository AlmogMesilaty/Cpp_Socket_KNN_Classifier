#include "Reader.hpp"

void Reader::read(std::string path, std::vector<TypedVector>* vectors) {
    string line = "";
    std::ifstream inputFile;
    inputFile.open(path);
    if (inputFile.is_open()) {
        //Converts the csv lines into vectors.
        while (getline(inputFile, line)) {
            TypedVector vec = StringMethods::stringToTypedVector(line);
            vectors->push_back(vec);
        }
        inputFile.close();
    }
}

void Reader::readToFloat(std::string path, std::vector<vector<float>>* vectors) {
    std::string line = "";
    std::ifstream inputFile;
    inputFile.open(path);
    if (inputFile.is_open()) {
        //Converts the csv lines into vectors.
        while (getline(inputFile, line)) {
            std::vector<float> vec = VectorDistances::stringToVector(line);
            vectors->push_back(vec);
        }
        inputFile.close();
    }
}