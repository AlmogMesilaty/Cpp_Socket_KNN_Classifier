#include "SocketIO.hpp"
//Read
string SocketIO::read() {
	char buffer[] = {0};
	
}
//Write
void SocketIO::write(string s) {
	//char bufferToClient[] = s;
	//int sent_bytes = send(client_sock, bufferToClient, read_bytes, 0);
	//if (sent_bytes < 0) {
		perror("error sending to client");
	//}
}
//IOType
string SocketIO::IOType() {
	return "socket";
}