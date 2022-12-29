// Created by Almog Mesilaty 314973686 and Ariel Oscar 209341684.
#include "VectorDistances.hpp"
/*
* DifferanceVector
* Calculates the difference between every corresponding elemnts.
* Returns: vector contains all the difference in absolute value.
*/
std::vector<float> VectorDistances::DifferenceVector(std::vector<float> vec1, std::vector<float> vec2) {
    // Check the validity of the input, the two vectors are the same size
    if (vec1.size() == vec2.size()) {
        std::vector<float> result;
        std::vector<float>::iterator ptr1 = vec1.begin();
        std::vector<float>::iterator ptr2 = vec2.begin();
        // Iterates all elemnts and subtract the greater from the smaller
        for (; ptr1 < vec1.end(); ptr1++) {
            if (*ptr1 >= *ptr2) {
                result.push_back(*ptr1 - *ptr2);
            }
            else {
                result.push_back(*ptr2 - *ptr1);
            }
            ptr2++;
        }
        return result;
    }
    // Dependes main function  to check the vectors size
    cout << "vectors must be the same size";
    exit(1);
    std::vector<float> empty;
    return empty;
}
/*
* EuclideanDistance
* Calculates the Euclidian distance between vec1 and vec2.
* Returns: float indicating the distance value.
*/
float VectorDistances::EuclideanDistance(std::vector<float> vec1, std::vector<float> vec2) {
    std::vector<float> diffVec = DifferenceVector(vec1, vec2);
    std::vector<float>::iterator ptr;
    float sum = 0;
    // Adding all diffrences squared
    for (ptr = diffVec.begin(); ptr < diffVec.end(); ptr++) {
        sum += *ptr * *ptr;
    }
    // Returns the square root of the sum
    return sqrt(sum);
}
/*
* TaxicabGeometry
* Calculates the TaxicabGeometry distance between vec1 and vec2.
* Returns: float indicating the distance value.
*/
float VectorDistances::TaxicabGeometry(std::vector<float> vec1, std::vector<float> vec2) {
    std::vector<float> diffVec = DifferenceVector(vec1, vec2);
    std::vector<float>::iterator ptr;
    float sum = 0;
    // Sums all the differences
    for (ptr = diffVec.begin(); ptr < diffVec.end(); ptr++) {
        sum += *ptr;
    }
    return sum;
}
/*
* ChebyshevDistance
* Calculates the ChebyshevDistance between vec1 and vec2.
* Returns: float indicating the distance value.
*/
float VectorDistances::ChebyshevDistance(std::vector<float> vec1, std::vector<float> vec2) {
    std::vector<float> diffVec = DifferenceVector(vec1, vec2);
    std::vector<float>::iterator ptr;
    float max = 0;
    // Finds the largest difference
    for (ptr = diffVec.begin(); ptr < diffVec.end(); ptr++) {
        if (max < *ptr) {
            max = *ptr;
        }
    }
    return max;
}
/*
* CanberraDistance
* Calculates the CanberraDistance between vec1 and vec2.
* Returns: float indicating the distance value.
*/
float VectorDistances::CanberraDistance(std::vector<float> vec1, std::vector<float> vec2) {
    std::vector<float> diffVec = DifferenceVector(vec1, vec2);
    // Initialize an iterator for the difference vector
    std::vector<float>::iterator ptr;
    // Initialize an iterator for the vec1 and vec2
    std::vector<float>::iterator ptr1 = vec1.begin();
    std::vector<float>::iterator ptr2 = vec2.begin();
    float sum = 0;
    // Iterates throught all the vectors at the same time
    for (ptr = diffVec.begin(); ptr < diffVec.end(); ptr++) {
        // For all elemnts that at least one of them nonzero calculates according to the canberra equasion
        if (*ptr1 != 0) {
            sum += *ptr / (abs(*ptr1) + abs(*ptr2));
        }
        ptr1++;
        ptr2++;
    }
    return sum;
}
/*
* MinkowskiDistance
* Calculates the MinkowskiDistance between vec1 and vec2.
* Returns: float indicating the distance value.
*/
float VectorDistances::MinkowskiDistance(std::vector<float> vec1, std::vector<float> vec2) {
    std::vector<float> diffVec = DifferenceVector(vec1, vec2);
    std::vector<float>::iterator ptr;
    float sum = 0;
    // Adds the power of all differences each to the power of constant P
    for (ptr = diffVec.begin(); ptr < diffVec.end(); ptr++) {
        sum += pow(*ptr, P);
    }
    return pow(sum, 1.0 / P);
}

/**
 * Function gets a string and puts its values to a vector. If the string is invalid, the function stops
 * the system.
 * @param s - A string
 * @return v - A vector
 */
std::vector<float> VectorDistances::stringToVector(string s) {
    std::vector<float> v; //the vector.
    std::string numS = ""; //a single number to insert to the vector
    bool flagDot = false; //flag to assure there are at most 1 dot.
    bool flagMinus = false; //flag to assure there are at most 1 minus at the beginning.
    bool flagE = false;  //flag to assure there are at most 1 'e'
    for (int i = 0; i < s.length(); i++) {
        if (s[i] == ' ') { //if there is a space
            while (i < s.length() && s[i] == ' ')
                i++;
            if (i == s.length())
                break;
            if (numS != "") {
                v.push_back(std::stof(numS));
                numS = "";
                flagDot = false;
                flagMinus = false;
                flagE = false;
            }
        }
        if (s[i] == '-') { //if there is a minus
            if (!flagMinus && numS == "" || numS[(numS.size() - 1)] == 'E' || numS[(numS.size() - 1)] == 'e') {
                flagMinus = true;
            }
            else {
                cout << " Invalid input minus sign" << endl;
                exit(1);
            }
        }
        if (s[i] == 'e' || s[i] == 'E') {
            if (!flagE && numS != "" && i != (numS.length() - 1) && flagDot) {
                flagE = true;
            }
            else {
                cout << " Invalid input e" << endl;
                exit(1);
            }
        }
        if (s[i] == '.') { //if there is a dot
            if (!flagDot) {
                flagDot = true;
            }
            else {
                cout << " Invalid input dot" << endl;
                exit(1);
            }
        }
        if (isdigit(s[i]) || s[i] == '.' || s[i] == '-' || s[i] == 'e' || s[i] == 'E') //inserting valid character to numS
            numS += s[i];
        else {
            cout << "Invalid input: " << numS << endl;
            cout << "s[i]: " << s[i] << endl;
            exit(1);
        }
    }
    if (numS != "")
        v.push_back(std::stof(numS));
    return v;
}
/**
 * Function gets a float and print it with ".0" if it int, otherwise print it regularly.
 * @param f
 */
void VectorDistances::printFloatWithDot(float f) {
    cout << fixed;
    string s(to_string(f));
    int x = 0;
    if ((int)f == f)
        cout << setprecision(1);
    else {
        float temp = f;
        while ((int)temp != temp) {
            x++;
            temp *= 10;
        }
        if (x > 16)
            x = 16;
        cout << setprecision(x);
    }
    cout << f << endl;
}
/**
 * Sends vectors to specific distance function depending sting s.
 * @param s - string represents the distance fuanction
 * @param vec1, vec2 - Vectors with floats
 * @return distance value as float
 */
float VectorDistances::distanceByName(string s, vector<float> vec1, vector<float> vec2) {
    if (!s.empty()) {
        if (s == "AUC") { return EuclideanDistance(vec1, vec2); }
        if (s == "MAN") { return TaxicabGeometry(vec1, vec2); }
        if (s == "CHB") { return ChebyshevDistance(vec1, vec2); }
        if (s == "CAN") { return CanberraDistance(vec1, vec2); }
        if (s == "MIN") { return MinkowskiDistance(vec1, vec2); }
        cout << "Invalide distance name" << endl;
    }
    cout << "No distance specified";
    return 0.0;
}
