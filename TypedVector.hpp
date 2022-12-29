#include <iostream>
#include <vector>
#define P 2
using namespace std;
#pragma once
#ifndef AP_EX2_TYPEDVECTOR
#define AP_EX2_TYPEDVECTOR
/*
* class TypedVector
*/
class TypedVector {
private:
	float distance;
	string type;
	vector<float> vec;
public:
	//Constructor
	TypedVector(string type, vector<float> newVector);
    TypedVector();
        //Copy constructor
	TypedVector(const TypedVector& other);
	//Getters
	float getDistance() const;
	string getType() const;
	vector<float> getVector() const;
	//Setter for distance only, the other parameters don't change
	void setDistance(float newDistance);
	//Return attr vector size
	int size() const;
};


#endif //AP_EX2_TYPEDVECTOR
