//
// Created by Almog Mesilaty 314973686 and Ariel Oscar 209341684 on 29/12/2022.
//

#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <fstream>
#include <regex>
#include "TypedVector.hpp"
#include "VectorDistances.hpp"
#include "Knn.hpp"
#define FILE 1
#define PORT 2
/*
* Checks Port validation
* input: port address that were given from command line.
* return: false if input its invalid, otherwise true.
*/
int PortIsValid(string s) {
	// Regex expression
	string pattern("^([1-9][0-9]{0,3}|[1-5][0-9]{4}|6[0-4][0-9]{3}|65[0-4][0-9]{2}|655[0-2][0-9]|6553[0-5])$");
	// Getting the regex object
	regex rx(pattern);
	return regex_match(s, rx);
}
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
* Server main function
* receives pharsed input from flient, determine type using KNN, sends back to client.
*/
int main(int argc, char* argv[]){
    // Checks the validation of PORT number
    string portTest = argv[PORT];
    if (!PortIsValid) {
        cout << "invalid port number" << endl;
        exit(1);
    }
    vector<TypedVector> vectors;
    string line = "";
    //Takes the file name from args using macro to avoid magic numbers.
    string fName = argv[FILE];
    std::ifstream inputFile;
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
    const char * ip_address = argv[FILE];
    const int server_port = std::stoi(argv[PORT]);
    
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0 ) {
        perror("error creating socket");
    }
    struct sockaddr_in sin;
    memset( &sin, 0 , sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);
    if (bind(sock, (struct sockaddr * ) &sin, sizeof(sin)) < 0 ) {
        perror("error binding socket");
    }
    while (true) //Server listens to clients
    {
        if (listen(sock, 5 ) < 0 ) {
            perror("error listening to a socket");
        }
        struct sockaddr_in client_sin;
        unsigned int addr_len = sizeof(client_sin);
        int client_sock = accept(sock, (struct sockaddr * ) &client_sin, &addr_len);
        if (client_sock < 0 ) {
            perror("error accepting client");
        }
        char buffer[4096];
        int expected_data_len = sizeof(buffer);
        while (true) { //Server takes care of a specific client
            int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
            if (read_bytes == 0) {
                perror("connection is close");
            } else if (read_bytes < 0) {
                perror("error receiving information");
            }
            // else:
            //finding the required k from the server, or -1 to close the client socket.
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
            else {
                //finding the vector, first as a String and then to a vector<float>
                std::string userVector = "";
                i++;
                while (buffer[i] != '#') {
                    userVector += buffer[i];
                    i++;
                }
                vector<float> userVec = VectorDistances::stringToVector(userVector);
                if(userVector.empty()) {
                    char bufferToClient[] = "Invalid vector";
                    int sent_bytes = send(client_sock, bufferToClient, read_bytes, 0);
                    if (sent_bytes < 0) {
                        perror("error sending to client");
                    }
                }

                //finding the type of the distance
                std::string userTypeOfDis = "";
                i++;
                while (buffer[i] != '#') {
                    userTypeOfDis += buffer[i];
                    i++;
                }
                bool invalidDistance = false;
                //Calculates the distance to the current vector of user.
                for (int i = 0; i < vectors.size(); i++) {
                    float dis = VectorDistances::distanceByName(userTypeOfDis, vectors[i].getVector(), userVec);
                    if(dis < 0.0){
                        char bufferToClient[] = "invalid input";
                        int sent_bytes = send(client_sock, bufferToClient, read_bytes, 0);
                        if (sent_bytes < 0) {
                            perror("error sending to client");
                        }
                        invalidDistance = true;
                        break;
                    }
                    vectors[i].setDistance(dis);
                }
                // Continue to another input if the distance was invalid
                if (invalidDistance) { continue; };
                //Calling the KNN to check the type.
                string s = Knn::findType(vectors, k);
                char bufferToClient[s.size() + 1] = "";
                for(i=0; i < s.size(); i++){
                    bufferToClient[i] = s[i];
                }
                bufferToClient[s.size() + 1] = '\0';
                int sent_bytes = send(client_sock, bufferToClient, read_bytes, 0);
                if (sent_bytes < 0) {
                    perror("error sending to client");
                }
            }
        }
    }
    close(sock);
    return 0;
}
