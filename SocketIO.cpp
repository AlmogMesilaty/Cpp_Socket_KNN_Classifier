#include "SocketIO.hpp"

SocketIO::SocketIO(int sock) {
    this->sock = sock;
}
//Read
std::string SocketIO::read() {
    char buffer[4096];
    int expected_data_len = sizeof(buffer);
    int read_bytes = recv(this->sock, buffer, expected_data_len, 0);
    if (read_bytes == 0) {
        perror("connection is close");
    } else if (read_bytes < 0) {
        perror("error receiving information");
    }
    std::string serverString = "";
    int i=0;
    while (buffer[i] != '\0' || i < 4096) {
        serverString += buffer[i];
        i++;
    }
    return serverString;
}
//Write
void SocketIO::write(std::string s) {

    char bufferToClient[4096];
    for(int i=0; i < s.size(); i++){
        bufferToClient[i] = s[i];
    }
    bufferToClient[s.size() + 1] = '\0';
    int sent_bytes = send(this->sock, bufferToClient, s.size() + 1, 0);
    if (sent_bytes < 0) {
        perror("error sending to client");
    }
}
//IOType
std::string SocketIO::IOType() {
	return "socket";
}