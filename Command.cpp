//
//
//
#include "Command.hpp"
//Default constractor
Command::Command() {}

//Constructor
Command::Command(std::string description, DefaultIO dio) {
    this->m_description = std::move(description);
    this->m_dio = dio;
}

//Get dio
const DefaultIO Command::getDio() {
    return this->m_dio;
}
//Get description
const std::string& Command::getDescription() {
    return m_description;
}
