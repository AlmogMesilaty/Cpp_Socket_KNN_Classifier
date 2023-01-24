//
// Created by Almog Mesilaty 314973686 and Ariel Oscar 209341684 on 29/12/2022.
//
#include "TcpServer.hpp"

using namespace std;
/*
* Handle client
*/
void handleClient(int sock) {

    //Preforms connection to client
    struct sockaddr_in client_sin;
    unsigned int addr_len = sizeof(client_sin);
    int client_sock = accept(sock, (struct sockaddr*)&client_sin, &addr_len);
    if (client_sock < 0) {
        perror("error accepting client");
    }

    //Creates default io
    //DefaultIO* dio = new StandardIO();
    DefaultIO* dio = new SocketIO(client_sock);
    //Creates data manager
    DataManager* d = new DataManager();

    //Creates new CLI
    CLI* cli = new CLI(dio, d);

    //Prints the start message
    cli->start();

    //Server serves specific client
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    while (true) {
        //Reciving data from client
        int read_bytes = recv(client_sock, buffer, expected_data_len, 0);
        if (read_bytes == 0) {
            perror("connection is close");
        }
        else if (read_bytes < 0) {
            perror("error receiving information");
        }
/*
        // else:
        //Reciving menu choice from user, or 8 to close the client socket.
        int choice = 0;
        int i = 0;

        bool flagMinus = false;
        if (buffer[i] == '-') {
            flagMinus = true;
            i++;
        }
        while (buffer[i] != '#') {
            choice = choice * 10 + (buffer[i] - '0');
            i++;
        }
        if (flagMinus) {
            choice = choice * (-1);
        }
        //Checkes if the user wants to end the connection
        if (choice == 8) {
            char bufferToClient[] = "-1";
            int sent_bytes = send(client_sock, bufferToClient, read_bytes, 0);
            if (sent_bytes < 0) {
                perror("error sending to client");
            }
            close(client_sock);
            break;
        }

        //Checks for invalid input
        if (choice <= 0 || choice >= 6 && choice <= 7 || choice > 8) {
            char bufferToClient[] = "invalid input";
            int sent_bytes = send(client_sock, bufferToClient, read_bytes, 0);
            if (sent_bytes < 0) {
                perror("error sending to client");
            }
        }
*/      
        int choice = stoi(dio->read());
        //Executes the desired command
        cli->commands[choice - 1]->execute();
        cli->printMenu();            
    }
}

/*
* Server main function
* receives pharsed input from flient, determine type using KNN, sends back to client.
*/
int main(int argc, char* argv[]) {

    //Checks the validation of PORT number
    //string portTest = argv[PORT];



    string portTest = argv[PORT];
    if (!(InputValidator::PortIsValid(portTest))) {
        cout << "invalid port number" << endl;
        exit(1);
    }

    //Establish socket
    const int server_port = std::stoi(argv[PORT]);
    //Creates socket
    int sock = socket(AF_INET, SOCK_STREAM, 0);
    if (sock < 0) {
        perror("error creating socket");
    }

    //Binding
    struct sockaddr_in sin;
    memset(&sin, 0, sizeof(sin));
    sin.sin_family = AF_INET;
    sin.sin_addr.s_addr = INADDR_ANY;
    sin.sin_port = htons(server_port);
    if (bind(sock, (struct sockaddr*)&sin, sizeof(sin)) < 0) {
        perror("error binding socket");
    }

    //Handles clients
    while (true) //Server listens to clients
    {
        //Listening to clients
        if (listen(sock, 5 ) < 0 ) {
            perror("error listening to a socket");
        }

        //Creates thread to handle new client
        //std::thread t(handleClient(sock));
        handleClient(sock);

        //Close the thread
        //t.detach();
    }

    //Close client socket
    close(sock);
    return 0;
}
