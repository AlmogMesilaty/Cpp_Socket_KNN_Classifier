#ifndef AP_EX4_CLI
#define AP_EX4_CLI

#include "Command.hpp"
#include "DefaultIO.hpp"
#include "InputValidator.hpp"

class CLI {
private:
	DefaultIO* m_dio;
	std::vector<std::shared_ptr<Command>> m_commands;
public:
	//Constructor
	CLI(DefaultIO* dio);
	//Constructor that gets commands vector
	CLI(DefaultIO* dio, std::vector<std::shared_ptr<Command>> commads);
	//Returns a string representation of the menu
	std::string menuToString();
	//Writes the manu of the commands
	void printMenu();
	//Write the start message
	voit start();
	//Serve user
	void serveUser();
};


#endif //AP_EX4_CLI