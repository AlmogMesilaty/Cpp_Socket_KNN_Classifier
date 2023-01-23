#include "CLI.hpp"

//Constructor
CLI::CLI(DefaultIO* dio) {
	this->dio = dio;
    //Initialize commands array
    Command com1 = new UploadCommand(dio, this);
    commands.push_back(com1); //Command when typing "1"
    //this->commands[0] = ; //Command when typing "1"
    this->commands[1] = SettingsCommand(&(this->dio), this); //Command when typing "2"
    this->commands[2] = ClassifyCommand(&(this->dio), this); //Command when typing "3"
    this->commands[3] = DisplayCommand(&(this->dio), this); //Command when typing "4"
    this->commands[4] = DownloadCommand(&(this->dio), this); //Command when typing "5"
    this->commands[5] = ExitCommand(&(this->dio), this); //Command when typing "8"
}

//getters
DefaultIO* CLI::getDio(){
    return dio;
}

std::vector<TypedVector> CLI::getTrainVectors() {
    return trainVectors;
}

std::vector<vector<float>> CLI::getTestVectors() {
    return testVectors;
}

int CLI::getK(){
    return k;
}

int CLI::getMaximumK(){
   return maxK;
}

string CLI::getDistance(){
    return distance;
}

std::vector<string> CLI::getClassified(){
    return classified;
}

//setters
void CLI::setTrainFile(std::vector<TypedVector> trainFile){
    this->trainVectors = trainFile;
}
void CLI::setTestFile(std::vector<vector<float>> testFile){
    this->testVectors = testFile;
}
void CLI::setK(int k){
    this->k = k;
}
void CLI::setMaximumK(int maxK){
    this->maxK = maxK;
}
void CLI::setDistance(string distance){
    this->distance = distance;
}
void CLI::setClassified(std::vector<string> classified){
    this->classified = classified;
}

//Returns string representation of the menu
std::string CLI::menuToString() {
    std::string menuStr = "";
    int max = commands.size();
    for(int i = 0; i < max-1; i++) {
        menuStr += std::to_string(i+1) + " " + commands[i].getDescription() + "\n";
    }
    menuStr += "8. "+ commands[max-1].getDescription();
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
            commands[choice - 1].execute();
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

