#include "Knn.hpp"

/**
 * Function finds median of a vector
 * @param vec
 * @return median of a vector
 */
TypedVector Knn::findMedian(vector<TypedVector> vec) {
    size_t size = vec.size();
    TypedVector median = vec[(size / 2)];
    return median;
}

/**
 * Function finds median os the medians
 * @param values
 * @return median os the medians
 */
TypedVector Knn::findMedianOfMedians(vector <vector<TypedVector>> values) {
    vector<TypedVector> medians;

        for (int i = 0; i < values.size(); i++) {
            TypedVector m = findMedian(values[i]);
            medians.push_back(m);
        }

        return findMedian(medians);
    }

/**
 * Function sorting according to the median of the medians by Dividing the list into n/5 lists of 5
 * elements each.
 * @param values
 * @param k
 * @return the k size TypedVector
 */
TypedVector Knn::selectionByMedianOfMedians(const vector<TypedVector> values, int k) {

    vector<vector<TypedVector>> vec2D;

    int count = 0;
    while (count != values.size()) {
        int countRow = 0;
        vector<TypedVector> row;

        while ((countRow < 5) && (count < values.size())) {
            row.push_back(values[count]);
            count++;
            countRow++;
        }
        vec2D.push_back(row);
    }

    //Calculating a new pivot for making splits
    TypedVector m = findMedianOfMedians(vec2D);

    //Partition the list into unique elements larger than 'm' (call this sublist L1) and those smaller
    // them 'm' (call this sublist L2)
    vector<TypedVector> L1, L2;

    int countEqual = 0;

    for (int i = 0; i < vec2D.size(); i++) {
        for (int j = 0; j < vec2D[i].size(); j++) {
            if (vec2D[i][j].getDistance() > m.getDistance()) {
                L1.push_back(vec2D[i][j]);
            }
            else if (vec2D[i][j].getDistance() < m.getDistance()) {
                L2.push_back(vec2D[i][j]);
            }
            else if (vec2D[i][j].getDistance() == m.getDistance() && &vec2D[i][j] != &m) {
                countEqual++;
            }
        }
    }

    //Recursive calls
    if ((k - 1) == L2.size()) {
        return m;
    }
    else if (k > L2.size() && k <= (L2.size() + countEqual)) {
        return m;
    }
    else if (k <= L2.size()) {
        return selectionByMedianOfMedians(L2, k);
    }
    else if (k > ((int)L2.size() + countEqual)) {
        return selectionByMedianOfMedians(L1, (k - (int)L2.size() - countEqual));
    }
    cout << "Something went wrong!" << endl;
    exit(1);
    return m;
}

// Merges two subarrays of array[].
// First subarray is arr[begin..mid]
// Second subarray is arr[mid+1..end]
void Knn::merge(string array[], int const left, int const mid, int const right) {
    int const subArrayOne = mid - left + 1;
    int const subArrayTwo = right - mid;

    // Create temp arrays
    string* leftArray = new string[subArrayOne],
        * rightArray = new string[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (int i = 0; i < subArrayOne; i++)
        leftArray[i] = array[left + i];
    for (int j = 0; j < subArrayTwo; j++)
        rightArray[j] = array[mid + 1 + j];

    int indexOfSubArrayOne = 0, // Initial index of first sub-array
        indexOfSubArrayTwo = 0; // Initial index of second sub-array
    int indexOfMergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
            indexOfSubArrayOne++;
        }
        else {
            array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
            indexOfSubArrayTwo++;
        }
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        array[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }
    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        array[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }
    delete[] leftArray;
    delete[] rightArray;
}

// begin is for left index and end is
// right index of the sub-array
// of arr to be sorted */
void Knn::mergeSort(string array[], int const begin, int const end) {
    if (begin >= end)
        return; // Returns recursively

    int mid = begin + (end - begin) / 2;
    mergeSort(array, begin, mid);
    mergeSort(array, mid + 1, end);
    merge(array, begin, mid, end);
}


/**
 * Function finds the type in the k place
 * @param vectors
 * @param k
 * @return the k size TypedVector
 */
string Knn::findType(const vector<TypedVector> vectors, int k) {

    TypedVector pivot = Knn::selectionByMedianOfMedians(vectors, k);

    //Creating array K size with the k closest vectors.
    string kVectors[k];

    int counter = 0;
    for (int i = 0; i < vectors.size(); i++) { //inserting the values smaller than pivot
        if (vectors[i].getDistance() < pivot.getDistance()) {
            kVectors[counter] = vectors[i].getType();
            counter++;
        }
    }

    for (int i = 0; i < vectors.size() && counter < k; i++) {
        if (vectors[i].getDistance() == pivot.getDistance()) { //inserting the values equal to pivot
            kVectors[counter] = vectors[i].getType();
            counter++;
        }
    }

    mergeSort(kVectors, 0, k - 1); //sorting the array alphabetical

    //finding the most common string
    counter = 1;
    int max = 0;
    string maxString = kVectors[0];
    for (int i = 1; i < k; i++) {
        if (kVectors[i] == kVectors[i - 1]) {
            counter++;
        }
        else {
            if (counter > max) {
                maxString = kVectors[i - 1];
                max = counter;
            }
            counter = 1;
        }
    }
    if (counter > max) {
        maxString = kVectors[(k) - 1];
    }

    //Retruns the most common type in the array
    return maxString;

}
