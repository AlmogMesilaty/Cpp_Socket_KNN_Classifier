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
bool InputValidator::validK(int k, int max) {
    if(k>0 && k<max)
        return true;
    return false;
}
/*
*
*/
bool validMetric(string s) {
	return true;
}

/*
int InputValidator::validK(char[] buffer) {
	// else:
	//finding the required k from the client, or -1 to close the client socket.
	int k = 0;
	int i = 0;
	bool flagMinus = false;
	if (buffer[i] == '-') {
		flagMinus = true;
		i++;
	}
	while (buffer[i] != '#') {
		k = k * 10 + (buffer[i] - '0');
		i++;
	}
	if (flagMinus) {
		k = k * (-1);
	}
	if (k == -1) {
		char bufferToClient[] = "-1";
		int sent_bytes = send(client_sock, bufferToClient, read_bytes, 0);
		if (sent_bytes < 0) {
			perror("error sending to client");
		}
		close(client_sock);
		break;
	}
	if (k <= 0 || k > vectors.size()) {
		char bufferToClient[] = "invalid input";
		int sent_bytes = send(client_sock, bufferToClient, read_bytes, 0);
		if (sent_bytes < 0) {
			perror("error sending to client");
		}
	}
}
*/