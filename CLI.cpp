#include "CLI.hpp"

//Constructor
CLI::CLI(DefaultIO dio) {
	this->dio = dio;

    //Initialize commands array
    CLI* p = this;

    this->commands[0] = UploadCommand(&(this->dio), this); //Command when typing "1"
    this->commands[1] = SettingsCommand(&(this->dio), this); //Command when typing "2"
    this->commands[2] = ClassifyCommand(&(this->dio), this); //Command when typing "3"
    this->commands[3] = DisplayCommand(&(this->dio), this); //Command when typing "4"
    this->commands[4] = DownloadCommand(&(this->dio), this); //Command when typing "5"
    this->commands[5] = ExitCommand(&(this->dio), this); //Command when typing "8"
}

//Returns string representation of the menu
std::string CLI::menuToString() {
    std::string menuStr = "";
    int max = commands.size();
    for(int i = 0; i < max-1; i++) {
        menuStr += commands[i].getDescription() + "\n";
    }
    menuStr += commands[max-1].getDescription();
    return menuStr;
}

bool CLI::inputIsValid(string s){
    // Regex expression
    string pattern("^({1,2,3,4,5,8})$");
    // Getting the regex object
    regex rx(pattern);
    return regex_match(s, rx);
}

//Prints menu
void CLI::printMenu() {
    dio.write(menuToString());
}


//Serve the user
void CLI::serveUser() {
    while (true) {
        std::string input = dio.read();
        //Checks if the input is valid
        if (inputIsValid(input)) {
            int choice = std::stoi(input);
            //Checks if user wants to exit
            if (choice == 8) {
                break;
            }
            commands[choice - 1].execute();
            printMenu();
        }
        else {
            dio.write("Please Enter a valid choice\n");
        }
    }
}

//Prints the start message and the menu
void CLI::start() {
    dio.write("Welcome to the KNN Classifier Server. Please choose an option:\n" + menuToString());
    serveUser();
}

