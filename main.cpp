#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <cmath>
#include <algorithm>
#include "TypedVector.hpp"
#include "VectorDistances.hpp"
#include "Knn.hpp"

#define K 1
#define FILE_NAME 2
#define METRICA 3
/*
using namespace std;

//Turnes csv line into a typed vector 
TypedVector stringToTypedVector(string s) {
    //Endls carrige return character
    replace(s.begin(), s.end(), '\r', ' ');
    //Finds index of last comma
    int index = s.find_last_of(',');
    string type = s.substr(index+1);
    string attr = s.substr(0, index);
    //Replace all commas with space
    replace(attr.begin(), attr.end(), ',', ' ');
    vector<float> vec = VectorDistances::stringToVector(attr); // Throw an exception when a problem arise
    TypedVector tVec(type, vec);
    return tVec;
}
/*
* main function
* Gets the desire propertis from args.
* Constantly reciving user inputs, different vectors.
* Returns the calculated type using knn.
*/
/*
int main(int argc, char* argv[]) {
    vector<TypedVector> vectors;
    string line = "";
    //Takes the file name from args using macro to avoid magic numbers.
    string fName = argv[FILE_NAME];
    ifstream inputFile;
    inputFile.open(fName);
    if (inputFile.is_open()) {
        //Converts the csv lines into vectors.
        while (getline(inputFile, line)) {
            TypedVector vec = stringToTypedVector(line);
            vectors.push_back(vec);
        }
        inputFile.close();
    }
    else {
        cout << "File failed to open" << endl;
    }
    //Converts the k value in args into int
    int k = 0;
    sscanf(argv[K], "%d", &k);
    //Checks if k is valid
    if (k <= 0 || k > vectors.size()) {
        cout << k << "Invalid k, program shutting down" << endl;
        exit(1);
    }

    string userInput = " ";
    //Constatnly eaiting for input from user.
    while (true) {

        getline(cin, userInput, '\n');

        vector<float> userVec = VectorDistances::stringToVector(userInput);
        //Calculates the distance to the current vector of user.
        for (int i = 0; i < vectors.size(); i++) {
            float dis = VectorDistances::distanceByName(argv[METRICA], vectors[i].getVector(), userVec);
            vectors[i].setDistance(dis);
        }
        //Calling the KNN to check the type.
        string t = Knn::findType(vectors, k);
        cout <<  t << endl;
    }
}
*/