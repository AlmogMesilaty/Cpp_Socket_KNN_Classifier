#include "InputValidator.hpp"
/*
* Checks user input validation
* input: raw input from user as string.
* return: false if input is invalid, otherwise true.
*/
int InputValidator::isValid(string s) {
	// Regex expression
	string pattern("^(((-){0,1}[0-9])*(\\.){0,1}([0-9])+( )+)+([A-Z]){3}( )+[0-9]+$");
	// Getting the regex object
	regex rx(pattern);
	return regex_match(s, rx);
}
/*
* Checks IP validation
* input: ip address that were given from command line.
* return: false if input its invalid, otherwise true.
*/
int InputValidator::IPIsValid(string s) {
	// Regex expression
	string pattern("\\b((25[0-5]|2[0-4][0-9]|[01]?[0-9][0-9]?)(\\.|$)){4}\\b");
	// Getting the regex object
	regex rx(pattern);
	return regex_match(s, rx);
}
/*
* Checks Port validation
* input: port address that were given from command line.
* return: false if input its invalid, otherwise true.
*/
int InputValidator::PortIsValid(string s) {
	// Regex expression
	string pattern("^([1-9][0-9]{0,4})$");
	// Getting the regex object
	regex rx(pattern);
	return regex_match(s, rx);
}
/*
* Checks user input validation
* input: menu option.
* return: false if input its invalid, otherwise true.
*/
int InputValidator::inputIsValid(string s) {
	// Regex expression
	string pattern("^[1-5]|[8]$");
	// Getting the regex object
	regex rx(pattern);
	return regex_match(s, rx);
}
/*
* validK
* input: K value.
* output: returns 1 if the k value is valid, 0 if not.
*/
bool InputValidator::validK(string s, int max) {
    // Regex expression
	string pattern("^\\d+$");
	// Getting the regex object
	regex rx(pattern);
	if(regex_match(s, rx)) {
		int k = stoi(s);
		return (k < max);
	}
    return false;
}
/*
* Checks if distance that enterd is valid
*/
bool InputValidator::validMetric(string s) {
	// Regex expression
	string pattern("^AUC$|^MAN$|^CHB$|^CAN$|^MIN$");
	// Getting the regex object
	regex rx(pattern);
	return regex_match(s, rx);
}
/*
* Checks the validity of settingsCommand input
*/
bool InputValidator::validSettings(string s) {
	// Regex expression
	string pattern("^\\d+ [A-Z]{3}$");
	// Getting the regex object
	regex rx(pattern);
	return regex_match(s, rx);
}