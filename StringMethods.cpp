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

//Turnes csv line into a typed vector
TypedVector StringMethods::stringToTypedVector(string s) {
	//Endls carrige return character
	replace(s.begin(), s.end(), '\r', ' ');
	//Finds index of last comma
	int index = s.find_last_of(',');
	string type = s.substr(index + 1);
	string attr = s.substr(0, index);
	//Replace all commas with space
	replace(attr.begin(), attr.end(), ',', ' ');
	vector<float> vec = VectorDistances::stringToVector(attr); // Throw an exception when a problem arise
	TypedVector tVec(type, vec);
	return tVec;
}

//Turnes csv line into a typed vector
std::vector<float> StringMethods::stringToFloatVector(string s) {
	//Endls carrige return character
	//replace(s.begin(), s.end(), '\r', ' ');
	//Finds index of last comma
	int index = s.find('\r');
	//string type = s.substr(index + 1);
	string attr = s.substr(0, index);
	//Replace all commas with space
	replace(attr.begin(), attr.end(), ',', ' ');
	vector<float> vec = VectorDistances::stringToVector(attr); // Throw an exception when a problem arise
	//TypedVector tVec(type, vec);
	return vec;
}