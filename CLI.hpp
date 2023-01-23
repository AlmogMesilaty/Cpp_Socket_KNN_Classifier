#ifndef AP_EX4_CLI
#define AP_EX4_CLI

#include <iostream>
#include <vector>
#include <regex>
#include <string>
#include "TypedVector.hpp"
#include "UploadCommand.hpp"
#include "SettingsCommand.hpp"
#include "ClassifyCommand.hpp"
#include "DisplayCommand.hpp"
#include "DownloadCommand.hpp"
#include "ExitCommand.hpp"
#include "DefaultIO.hpp"
#include "InputValidator.hpp"
#include "StandardIO.hpp"
#include "DataManager.hpp"

class CLI {
private:
    DefaultIO* dio;
public:
    std::vector<Command*> commands; //array of the 6 different commands

    CLI(DefaultIO* dio, DataManager* data); //Constructor

    //getters
    DefaultIO* getDio();

    std::string menuToString(); //Returns a string representation of the menu
	void printMenu(); //Writes the manu of the commands

    void serveUser(); //serving the user

    void start(); //Write the start message
};


#endif //AP_EX4_CLI