//
// Created by Ariel Oscar 209341684 and Almog Mesilaty 314973686
//
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <algorithm>
#include <regex>
// Macros for the parameters places in argv
#define IP 1
#define PORT 2
#define DELIMITER '#'

using namespace std;

///Insertes delimiters between the the different patameters
string insertDelimiter(string s) {
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
// Checks user input validation
int isValid(string s) {
	// Regex expression
	string pattern("(((-){0,1}[0-9])*(\\.){0,1}([0-9])+( )+)+([A-Z]){3}( )+[0-9]+");
	// Getting the regex object
	regex rx(pattern);
	return regex_match(s, rx);
}
// Checks IP validation
int IPIsValid(string s) {
	// Regex expression
	string pattern("(((-){0,1}[0-9])*(\\.){0,1}([0-9])* )+([A-Z]){3} [0-9]+");
	// Getting the regex object
	regex rx(pattern);
	return regex_match(s, rx);
}
// Checks PORT validation
int PortIsValid(string s) {
	// Regex expression
	string pattern("(((-){0,1}[0-9])*(\\.){0,1}([0-9])*( )+))+([A-Z]){3}( )+[0-9]+");
	// Getting the regex object
	regex rx(pattern);
	return regex_match(s, rx);
}
// The main function
int main(int argc, char* argv[]) {
	//Create socket with ipv4 in TCP protocol
	int sock = socket(AF_INET, SOCK_STREAM, 0);
	//If socket creation had a problem
	if (sock < 0) {
		perror("error creating socket");
	}
	//Create new sockaddr_in struct for the reciving socket
	struct sockaddr_in sin;
	memset(&sin, 0, sizeof(sin));
	sin.sin_family = AF_INET;
	//Saves the recived ip address
	sin.sin_addr.s_addr = inet_addr(argv[IP]);
	//Saves the recived port
	sin.sin_port = htons(std::stoi(argv[PORT]));
	//Checks if the connection succeded
	if (connect(sock, (struct sockaddr*)&sin, sizeof(sin)) < 0) {
		perror("error connecting to server");
		exit(1);
	}
	//Recives input from user
	string userInput = "";
	//Constatnly waiting for input from user.
	while (true) {
		//Indicates if user enters -1
		int endFlag = 0;
		//Get input from user
		getline(cin, userInput, '\n');
		//Checks if user enters -1
		if (userInput == "-1") {
			userInput = "-1#";
			endFlag = 1;
		}
		//Input is not valid
		else if (!(isValid(userInput))) {
			cout << "Invalid input" << endl;
			continue;
		} 
		//Valid input that is not -1
		else {
			userInput = insertDelimiter(userInput);
			cout << "user input after delim: " << userInput << endl;
		}
		//Saves string length
		int length = userInput.length();
		// declaring character array (+1 for null terminator)
		char char_array[4096];
		// copying the contents of the string to char array
		for (int i = 0; i <= length; i++) {
			char_array[i] = userInput[i];
		}
		//Adds end of string to the char array
		char_array[length + 1] = '\0';
		int data_len = length + 1;
		int sent_bytes = send(sock, char_array, data_len, 0);
		//Checks if the server recived the information
		if (sent_bytes < 0) {
			cout << "Sent bytes = 0" << endl;
		}
		char buffer[4096];
		int expected_data_len = sizeof(buffer);
		int read_bytes = recv(sock, buffer, expected_data_len, 0);
		//Checks if the connection is on
		if (read_bytes == 0) {
			cout << "connection is closed" << endl;
		}
		//Checks if the recived information from server is valid
		else if (read_bytes < 0) {
			cout << "error" << endl;
		}
		else if (buffer[0] == '-' && buffer[1] == '1') {
			cout << "Socket is closing" << endl;
			//close(sock);
			cout << "Program is shutting down.." << endl;
			break;
		}
		//Prints server answer
		else {
			cout << buffer << endl;
		}
	}

}