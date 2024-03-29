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
#include <fstream>
#include <thread>
#include "StringMethods.hpp"
#include "InputValidator.hpp"
#include "SocketIO.hpp"
#include "DefaultIO.hpp"

// Macros for the parameters places in argv
#define IP 1
#define PORT 2
using namespace std;


void downloadFile(string str){
    int mycounter = 0;
    string pathOfFile = "";
    string infoOfFile = "";
    while(str[mycounter] != ' '){
        pathOfFile += str[mycounter];
        mycounter++;
    }
    mycounter++;
    for(; mycounter < str.length(); mycounter++){
        infoOfFile +=str[mycounter];
    }
    ofstream MyFile(pathOfFile);
    if (!MyFile) {
        cout << "invalid path\n";
    }
    else {
        // Write to the file
        MyFile << infoOfFile;
        // Close the file
        MyFile.close();
    }
}

/*
* Client main function
* receives input from user, sends it to the server, prints the answer.
*/

int main(int argc, char* argv[]) {

    // Checks the validation of PORT number and IP address
    string portTest = argv[PORT];
    const char* ipTest = argv[IP];
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

    sin.sin_addr.s_addr = inet_addr(ipTest);
    //Saves the recived port
    sin.sin_port = htons(std::stoi(portTest));
    //Checks if the connection succeded
    if (connect(sock, (struct sockaddr *) &sin, sizeof(sin)) < 0) {
        perror("error connecting to server");
        exit(1);
    }

    //Recives input from user
    string userInput = "";

    //Creats new socketIO with sercer socket
    DefaultIO* dio = new SocketIO(sock);

    //Initilize flags for program flow logic
    bool flag1A = false, flag1B = false,flag4 = false, flag5 = false, flagMenu = false;

    //Handles user
    while (true) {

        //Reciveis data from server
        std::string buffer = dio->read();

        //Creating buffer to recive the response from the server
        /*
        char buffer[4096] = "\0";
        int expected_data_len = sizeof(buffer);
        int read_bytes = recv(sock, buffer, expected_data_len, 0);
        //Checks if the connection is on
        if (read_bytes == 0) {
            cout << "connection is closed" << endl;
        }
            //Checks if the recived information from server is valid
        else if (read_bytes < 0) {
            cout << "error" << endl;
        }*/

        //If client recives '8' from server, close the connection
        if (buffer[0] == '8') {
            close(sock);
            break;
        }

        //Prints server answer
        if(!flag5 && !flag4) {
            cout << buffer;
        }

        //Checks if another recive is needed
        if(buffer == "invalid input\n" || buffer == "invalid value for K\n" || buffer == "invalid value for metric\n" ||
           buffer == "classifying data complete\n" || buffer == "please upload data\n" || buffer == "please classify the data\n") {
            continue;
        }

        //check if need to print again from server
        if(flagMenu){
            flagMenu = false;
            continue;
        }

        //Checks if user enters 5 or 1

        //Get input from user
        if(!flag4)
            std::getline(cin, userInput, '\n');

        //If the input was \n sends an agreed symbol
        if(userInput.empty()) {
            userInput = '!';
        }

        //User enterd 1
        if(flag1A || flag1B) {

            string myText;
            string allFileText = "";
            try {
                ifstream MyReadFile(userInput);
            }
            catch (const ifstream::failure &e) {
                cout << "invalid input\n";
                flag1A = false;
                continue;
                // Block of code to handle errors
            }
            // Read from the text file
            ifstream MyReadFile;
            MyReadFile.open(userInput);

            // Use a while loop together with the getline() function to read the file line by line
            while (std::getline(MyReadFile, myText)) {
                // Output the text from the file
                myText[myText.length()] = '\n';
                if (myText[myText.size() - 1] != '\r') {
                    myText += '\r';
                }
                allFileText += myText;
            }
            allFileText += '#';

            //cout << "Original size: " << allFileText.size() << endl;
            //Sends the data in chunks buffer size
            int packets = ((allFileText.size()) / 4096);
            for (int i = 0; i < packets; i++) {
                std::string packet = allFileText.substr(0, 4095);
                dio->write(packet);
                allFileText = allFileText.substr(4095);
            }

            //cout << "Reduced size: " << allFileText.size() << endl;

            // Close the file
            MyReadFile.close();
            userInput = allFileText;
            if (flag1A) {
                flag1A = false;
                flag1B = true;
            } else {
                flag1B = false;
                flagMenu = true;
            }

        }

        //User enterd 4
        if(flag4){
            std:string output = buffer;
            int endFlag = output.find('#');
            while(endFlag == -1) {
                cout << output;
                output = dio->read();
                endFlag = output.find('#');
            }
            output.erase(endFlag);
            cout << output;
            flag4 = false;
            //userInput = "";
            continue;

        }

        //User entered 5
        if(flag5){
            string s = userInput+"Classified.csv "+buffer;
            thread t(downloadFile, s);
            t.detach();
            flag5 = false;
            continue;
        }

        //Checks if user enters 1
        if (userInput == "1")
            flag1A = true;
        //Checks if user enters 4
        if (userInput == "4")
            flag4 = true;
        //Checks if user enters 5
        if (userInput == "5")
            flag5 = true;

        //Valid input that is not 8
        //Send the input to the server
        dio->write(userInput);
        /*
        //Saves string length
        int length = userInput.length();
        // declaring character array (+1 for null terminator)
        char char_array[4096] = "";
        // copying the contents of the string to char array
        for (int i = 0; i <= length; i++) {
            char_array[i] = userInput[i];
        }
        char_array[length + 1] = '\0';
        int data_len = length + 1;
        int sent_bytes = send(sock, char_array, data_len, 0);
        //Checks if the server recived the information
        if (sent_bytes < 0) {
            cout << "Sent bytes = 0" << endl;
        }*/
    }
}

