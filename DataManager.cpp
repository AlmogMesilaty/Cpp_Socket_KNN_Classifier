#include "DataManager.hpp"

std::vector<TypedVector>* DataManager::getTrainVectors2() {
    return &trainVectors;
}

std::vector<vector<float>>* DataManager::getTestVectors2() {
    return &testVectors;
}

std::vector<TypedVector> DataManager::getTrainVectors() {
    return trainVectors;
}

std::vector<vector<float>> DataManager::getTestVectors() {
    return testVectors;
}

int DataManager::getK(){
    return k;
}

int DataManager::getMaximumK(){
   return maxK;
}

string DataManager::getDistance(){
    return distance;
}

std::vector<string> DataManager::getClassified(){
    return classified;
}

std::vector<string>* DataManager::getClassified2(){
    return &classified;
}

//setters
void DataManager::setTrainFile(std::vector<TypedVector> trainFile){
    this->trainVectors = trainFile;
}
void DataManager::setTestFile(std::vector<vector<float>> testFile){
    this->testVectors = testFile;
}
void DataManager::setK(int k){
    this->k = k;
}
void DataManager::setMaximumK(int maxK){
    this->maxK = maxK;
}
void DataManager::setDistance(string distance){
    this->distance = distance;
}
void DataManager::setClassified(std::vector<string> classified){
    this->classified = classified;
}