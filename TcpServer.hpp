//
// Created by Ariel Oscar 209341684 and Almog Mesilaty 314973686
//
#ifndef AP_EX4_TCPSERVER_H
#define AP_EX4_TCPSERVER_H

#include <thread>
#include <iostream>
#include <sys/socket.h>
#include <stdio.h>
#include <netinet/in.h>
#include <unistd.h>
#include <string.h>
#include <fstream>
#include <regex>
#include "TypedVector.hpp"
#include "InputValidator.hpp"

class TcpServer {
	void handleClient();
};


#endif //AP_EX4_TCPSERVER_H
