#include "CLI.hpp"

//Constructor
CLI::CLI(DefaultIO* dio, DataManager* data) {
	this->dio = dio;
    //Initialize commands array
    this->commands[0] = new UploadCommand(dio, data); //Command when typing "1"
    this->commands[1] = new SettingsCommand(dio, data); //Command when typing "2"
    this->commands[2] = new ClassifyCommand(dio, data); //Command when typing "3"
    this->commands[3] = new DisplayCommand(dio, data); //Command when typing "4"
    this->commands[4] = new DownloadCommand(dio, data); //Command when typing "5"
    this->commands[5] = new ExitCommand(dio, data); //Command when typing "8"
}

//getters
DefaultIO* CLI::getDio(){
    return this->dio;
}

//Returns string representation of the menu
std::string CLI::menuToString() {
    std::string menuStr = "";
    int max = commands.size();
    for(int i = 0; i < max-1; i++) {
        menuStr += std::to_string(i+1) + " " + commands[i]->getDescription() + "\n";
    }
    menuStr += "8. "+ commands[max-1]->getDescription();
    return menuStr;
}

//Prints menu
void CLI::printMenu() {
    dio->write(menuToString());
}

//Serve the user
void CLI::serveUser() {
    while (true) {
        std::string input = dio->read();
        //Checks if the input is valid
        if (InputValidator::inputIsValid(input)) {
            int choice = std::stoi(input);
            //Checks if user wants to exit
            if (choice == 8) {
                break;
            }
            commands[choice - 1]->execute();
            printMenu();
        }
        else {
            dio->write("Please Enter a valid choice\n");
        }
    }
}

//Prints the start message and the menu
void CLI::start() {
    dio->write("Welcome to the KNN Classifier Server. Please choose an option:\n" + menuToString());
    serveUser();
}

/*
int main() {
    DefaultIO* dio = new StandardIO();
    DataManager* d = new DataManager();
    CLI* cli = new CLI(dio, d);
    cli->start();
    return 0;
}*/