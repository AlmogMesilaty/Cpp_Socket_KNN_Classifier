//
// Created by ariel_7za0dpc on 19/01/2023.
//
#include <string.h>
#include <iostream>
#include "DefaultIO.h"
#include "Command.h"

Command::Command() {
    this->description = "";
    this->dio = DefaultIO();
}

void Command::execute() {}

