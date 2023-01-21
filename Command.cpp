//
//
//
#include "Command.h"
//Constructor
Command::Command(std::string description, DefalutIO* dio) {
    m_description = std::move(description);
    m_dio = dio;
}
//Get dio
DefaultIO* Command::getDio() {
    return m_dio;
}
//Get description
std::string& Command::getDescription() {
    return m_description;
}
