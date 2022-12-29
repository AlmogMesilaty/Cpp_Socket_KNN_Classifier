//
// Created by ariel_7za0dpc on 17/11/2022.
//
#include <iostream>
#include <vector>
#include <cmath>
#include <iomanip>
#define P 2
using namespace std;

#ifndef AP_AA_VECTORDISTANCES_H
#define AP_AA_VECTORDISTANCES_H
/*
* class VectorDistances
* class that has no members, only 5 different functions for different distances calculations
* on vectors.
*/
class VectorDistances {
private:
	static std::vector<float> DifferenceVector(std::vector<float> vec1, std::vector<float> vec2);
public:
	static float EuclideanDistance(std::vector<float> vec1, std::vector<float> vec2);
	static float TaxicabGeometry(std::vector<float> vec1, std::vector<float> vec2);
	static float ChebyshevDistance(std::vector<float> vec1, std::vector<float> vec2);
	static float CanberraDistance(std::vector<float> vec1, std::vector<float> vec2);
	static float MinkowskiDistance(std::vector<float> vec1, std::vector<float> vec2);
	static vector<float> stringToVector(string s);
	static void printFloatWithDot(float f);
	static float distanceByName(string s, std::vector<float> vec1, std::vector<float> vec2);
};


#endif //AP_AA_VECTORDISTANCES_H
