//
// Created by Ariel Oscar 209341684 and Almog Mesilaty 314973686
//
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <unistd.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <string.h>
#include <algorithm>
#include <regex>
#include "StringMethods.hpp"
#include "InputValidator.hpp"
// Macros for the parameters places in argv
#define IP 1
#define PORT 2
using namespace std;
/*
* Client main function
* receives input from user, sends it to the server, prints the answer.
*/
int main(int argc, char* argv[]) {
	// Checks the validation of PORT number and IP address
    string portTest = argv[PORT];
	string ipTest = argv[IP];
    if (!InputValidator::PortIsValid(portTest)) {
        cout << "invalid port number" << endl;
        exit(1);
    }
	if (!InputValidator::IPIsValid(ipTest)) {
        cout << "invalid up address" << endl;
        exit(1);
	}
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
		else if (!(InputValidator::isValid(userInput))) {
			cout << "invalid input" << endl;
			continue;
		} 
		//Valid input that is not -1
		else {
			userInput = StringMethods::insertDelimiter(userInput);
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
		//Creating buffer to recive the response from the server
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
		//If client recives '-1' from server, close the connection
		else if (buffer[0] == '-' && buffer[1] == '1') {
			close(sock);
			break;
		}
		//Prints server answer
		else {
			cout << buffer << endl;
		}
	}

}