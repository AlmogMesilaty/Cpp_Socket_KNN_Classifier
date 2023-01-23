#ifndef AP_EX4_CLI
#define AP_EX4_CLI

#include <iostream>
#include <vector>
#include "Command.hpp"
#include "UploadCommand.hpp"
#include "SettingsCommand.hpp"
#include "ClassifyCommand.hpp"
#include "DisplayCommand.hpp"
#include "DownloadCommand.hpp"
#include "ExitCommand.hpp"
#include "DefaultIO.hpp"
#include "InputValidator.hpp"

class CLI {
private:
	DefaultIO dio; //DefaultIO to read and write
    Command commands[6]; //array of the 6 different commands
    std::vector<vector<float>> trainFile; //vectors of server train CSV file
    std::vector<vector<float>> testFile; //vectors of server test CSV file
    int k; //the desired K
    string distance; //the desired distance
    std::vector<string> classified; //an array of all the classified types of the vectors

public:

	CLI(DefaultIO dio); //Constructor

	CLI(DefaultIO dio, Command commands[6]); //Constructor that gets commands vector

	std::string menuToString(); //Returns a string representation of the menu

	void printsMenu(); //Writes the manu of the commands

	void start(); //Write the start message

	void serveUser(); //Serve user
};


#endif //AP_EX4_CLI