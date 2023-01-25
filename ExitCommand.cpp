//
// Created by ariel_7za0dpc on 22/01/2023.
//

#include "ExitCommand.hpp"

void ExitCommand::execute() {
    //Socket
    dio->write("8");
}