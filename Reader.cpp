#include "Reader.hpp"

void Reader::read(std::string path, std::vector<TypedVector>* vectors) {
    string line = "";
    std::ifstream inputFile;
    inputFile.open(path);
    if (!(inputFile.is_open())) {
        cout << "error open file " << path << endl;
    }
    else {
        //Converts the csv lines into vectors.
        while (getline(inputFile, line, '\r')) {
            TypedVector vec = StringMethods::stringToTypedVector(line);
            vectors->push_back(vec);
        }
        inputFile.close();
    }
    //remove("${workspaceFolder}/temp.csv");
}

void Reader::readToFloat(std::string path, std::vector<vector<float>>* vectors) {
    std::string line = "";
    std::ifstream inputFile;
    inputFile.open(path);
    if (!(inputFile.is_open())) {
        cout << "error open file " << path << endl;
    }
    else {
        //Converts the csv lines into vectors.
        while (getline(inputFile, line, '\r')) {
            std::vector<float> vec = StringMethods::stringToFloatVector(line);
            vectors->push_back(vec);
        }
        inputFile.close();
    }
    //remove("${workspaceFolder}/temp.csv");
}
