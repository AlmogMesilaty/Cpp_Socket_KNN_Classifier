#include "TypedVector.hpp"
#include <iostream>
#include <algorithm>

using namespace std;

#ifndef AP_EX2_KNN_H
#define AP_EX2_KNN_H

class Knn {
private:
	//Find median of a vector
	static TypedVector findMedian(vector<TypedVector> vec);
	static TypedVector findMedianOfMedians(vector <vector<TypedVector>> values);
public:
	//Divide the list into n/5 lists of 5 elements each
	static TypedVector selectionByMedianOfMedians(const vector<TypedVector> values, int k);

	//Finds the type
	static string findType(const vector<TypedVector> vectors, int k);

	// Merges two subarrays of array[].
	// First subarray is arr[begin..mid]
    // Second subarray is arr[mid+1..end]
	static void merge(string array[], int const left, int const mid, int const right);

	// begin is for left index and end is
	// right index of the sub-array
	// of arr to be sorted */
	static void mergeSort(string array[], int const begin, int const end);
};


#endif //AP_KNN_H
