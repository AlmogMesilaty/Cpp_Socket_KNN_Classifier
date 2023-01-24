#include "SocketIO.hpp"

//Read
std::string SocketIO::read() {
	//char buffer[] = {0};
	return "Hey!";
}
//Write
void SocketIO::write(std::string s) {
	//char bufferToClient[] = s;
	//int sent_bytes = send(client_sock, bufferToClient, read_bytes, 0);
	//if (sent_bytes < 0) {
	//	perror("error sending to client");
	
	//}
}
//IOType
std::string SocketIO::IOType() {
	return "socket";
}