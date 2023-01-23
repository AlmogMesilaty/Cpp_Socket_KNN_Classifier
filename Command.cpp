//
//
//
#include "Command.hpp"
//Default constractor
Command::Command(DefaultIO* dio, CLI* cli, string description) {
    this->dio = dio;
    this->cli = cli;
    this->description = description;
}

//Get dio
const DefaultIO* Command::getDio() {
    return this->dio;
}
//Get description
const std::string Command::getDescription() {
    return this->description;
}
