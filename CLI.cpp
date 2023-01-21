#include "CLI.hpp"
//Constructor
CLI::CLI(DefaultIO* dio) {
	m_dio = dio;

    //Initialize commands vector
    std::vector<std::shared_ptr<Command>> commands;
    commands.push_back(std::make_shared<UploadCommand>(dio));
    commands.push_back(std::make_shared<SettingsCommand>(dio));
    commands.push_back(std::make_shared<ClassifyCommand>(dio));
    commands.push_back(std::make_shared<DisplayCommand>(dio));
    commands.push_back(std::make_shared<DownloadCommand>(dio));
    commands.push_back(std::make_shared<ConfusionMatrixCommand>(dio));
    commands.push_back(std::make_shared<ExitCommand>(dio));

    m_commands = commands;
}
//Constructor that recives a commands vector
CLI::CLI(DefaultIO* dio, std::vector<shared_ptr<Command>> commands) {
    m_dio = dio;
    m_commands = commands;
}
//Returns string representation of the menu
std::string CLI::menuToString() {
    std::string menuStr = "";
    int index = 1;
    for (const& command : m_commands) {
        menuStr += (std::to_string(index) + ". " + (*command).getDescription() + "\n");
        ++index;
    }
    return menuStr;
}
//Prints menu
void CLI::printMenu() {
    m_dio->write(menuToString());
}
//Prints the start message and the menu
void CLI::start() {
    m_dio->write("\nWelcome to the KNN Classifier Server. Please choose an option:\n" + menuToString());
    serveUser();
}
//Serve the user
void CLI::serveUser() {
    while (true) {
        std::string input = m_dio->read();
        //Checks if the input is valid
        if (InputValidator::inputIsValid(input)) {
            int choice = std::stoi(input);
            //Checks if user wants to exit
            if (choice == 8) {
                break;
            }
            m_commands.at(choise - 1)->execute();
            printMenu();
        }
        else {
            m_dio->("\nPlease Enter a valid choice\n");
        }
    }
}