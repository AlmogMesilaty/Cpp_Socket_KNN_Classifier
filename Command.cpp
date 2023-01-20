//
// Created by ariel_7za0dpc on 19/01/2023.
//
#include "DefaultIO.h"
#include "Command.h"
//Constructor
Command::Command() {
    this->description = "";
    this->dio = DefaultIO();
}
//Execute function, preforms the command
void Command::execute() {}

