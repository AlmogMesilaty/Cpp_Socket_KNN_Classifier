#include <iostream>
#include "InputValidator.hpp"
/*
* Checks user input validation
* input: raw input from user as string.
* return: false if input its invalid, otherwise true.
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