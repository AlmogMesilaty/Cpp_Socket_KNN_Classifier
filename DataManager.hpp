#ifndef AP_EX4_DATAMANAGER
#define AP_EX4_DATAMANAGER

#include <iostream>
#include <vector>
#include <regex>
#include <string>
#include "TypedVector.hpp"
#include "InputValidator.hpp"
#include "StandardIO.hpp"

class DataManager {
private:
    std::vector<TypedVector> trainVectors; //vectors of server train CSV file
    std::vector<vector<float>> testVectors; //vectors of server test CSV file
    int k = 5; //the desired K
    int maxK = 5; //maximum K
    string distance = "AUC"; //the desired distance
    std::vector<string> classified; //an array of all the classified types of the vectors

public:

    std::vector<TypedVector> getTrainVectors();
    std::vector<vector<float>> getTestVectors();
    int getK();
    int getMaximumK();
    string getDistance();
    std::vector<string> getClassified();

    //setters
    void setTrainFile(std::vector<TypedVector> trainFile);
    void setTestFile(std::vector<vector<float>> testFile);
    void setK(int k);
    void setMaximumK(int maxK);
    void setDistance(string distance);
    void setClassified(std::vector<string> classified);
};


#endif //AP_EX4_DATAMANAGER






