#include "StringMethods.hpp"
/*
* Insertes delimiters between the the different patameters.
* input: raw input from user as string.
* return: the parameters in the order the servers expects with the delimiter between them.
*/
string StringMethods::insertDelimiter(string s) {
	// Finds index of last space
	int spaceIndex = s.find_last_of(' ');
	int i = spaceIndex;
	// Skip access spaces
	while (s[i] == ' ') {
		i--;
	}
	//Saprates the sting into the different parameters
	// Form start to the index of the last space
	string k = s.substr(spaceIndex + 1);
	// From 3 places before the last space, 3 chars
	string distance = s.substr(i - 2, 3);
	i -= 3;
	// Skip access spaces
	while (s[i] == ' ') {
		i--;
	}
	// From start till 3 places before the last space
	string vector = s.substr(0, i);
	// Concatinate the parameters in the agreed order with delimiter between
	string answer = k + DELIMITER + vector + DELIMITER + distance + DELIMITER;
	return answer;
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
//Turnes csv line into a typed vector
TypedVector StringMethods::stringToTypedVector(string s) {

	//Endls carrige return character
	s.replace(s.begin(), s.end(), '\r', ' ');
	//Finds index of last comma
	int index = s.find_last_of(',');
	string type = s.substr(index + 1);
	string attr = s.substr(0, index);
	//Replace all commas with space
	s.replace(attr.begin(), attr.end(), ',', ' ');
	vector<float> vec = VectorDistances::stringToVector(attr); // Throw an exception when a problem arise
	TypedVector tVec(type, vec);
	return tVec;
}