//
// Created by Almog Mesilaty 314973686 and Ariel Oscar 209341684 on 29/12/2022.
//

#include "tcpServer.h"
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <unistd.h>
#include <string.h>
#include <fstream>
#include "TypedVector.hpp"
#include "VectorDistances.hpp"
#include "Knn.hpp"

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

int myStoi(const char *s)
{
    long i;
    i = 0;
    while(*s >= '0' && *s <= '9')
    {
        i = i * 10 + (*s - '0');
        s++;
    }
    return i;
}

int main(int argc, char* argv[]){
    vector<TypedVector> vectors;
    string line = "";
    //Takes the file name from args using macro to avoid magic numbers.
    string fName = argv[1];
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

    const char * ip_address = "127.0.0.1" ;
    const int server_port = myStoi(argv[2]);

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
                close(client_sock);
                break;
            }
            if (k <= 0 || k > vectors.size()) {
                char bufferToClient[] = "Invalid k, program shutting down";
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

                //Calculates the distance to the current vector of user.
                for (int i = 0; i < vectors.size(); i++) {
                    float dis = VectorDistances::distanceByName(userTypeOfDis, vectors[i].getVector(), userVec);
                    if(dis == 0.0){
                        char bufferToClient[] = "Invalid distance name";
                        int sent_bytes = send(client_sock, bufferToClient, read_bytes, 0);
                        if (sent_bytes < 0) {
                            perror("error sending to client");
                        }
                    }
                    vectors[i].setDistance(dis);
                }

                //Calling the KNN to check the type.
                string s = Knn::findType(vectors, k);
                char bufferToClient[s.size()];
                for(i=0; i < s.size(); i++){
                    bufferToClient[i] = s[i];
                }
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
