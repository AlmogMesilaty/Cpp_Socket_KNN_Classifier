#ifndef AP_EX4_CLI
#define AP_EX4_CLI

#include <iostream>
#include <vector>
#include <regex>
#include <string>
#include "TypedVector.hpp"
#include "Command.hpp"
#include "UploadCommand.hpp"
#include "SettingsCommand.hpp"
#include "ClassifyCommand.hpp"
#include "DisplayCommand.hpp"
#include "DownloadCommand.hpp"
#include "ExitCommand.hpp"
#include "DefaultIO.hpp"
#include "InputValidator.hpp"
#include "StandardIO.hpp"

class CLI {
private:
	DefaultIO* dio; //DefaultIO to read and write
    std::vector<TypedVector> trainVectors; //vectors of server train CSV file
    std::vector<vector<float>> testVectors; //vectors of server test CSV file
    int k = 5; //the desired K
    int maxK; //maximum K
    string distance = "AUC"; //the desired distance
    std::vector<string> classified; //an array of all the classified types of the vectors

public:
    std::vector<Command*> commands; //array of the 6 different commands

    CLI(DefaultIO* dio); //Constructor

    //getters
    DefaultIO* getDio();
    std::vector<TypedVector> getTrainVectors();
    std::vector<vector<float>> getTestVectors();
    int getK();
    int getMaximumK();
    string getDistance();
    std::vector<string> getClassified();

    //setters
    void setTrainFile(std::vector<TypedVector> trainFile);
    void setTestFile(std::vector<vector<float>> testFile);
    void setK(int k);
    void setMaximumK(int maxK);
    void setDistance(string distance);
    void setClassified(std::vector<string> classified);

    std::string menuToString(); //Returns a string representation of the menu
	void printMenu(); //Writes the manu of the commands

    void serveUser(); //serving the user

    void start(); //Write the start message
};


#endif //AP_EX4_CLI