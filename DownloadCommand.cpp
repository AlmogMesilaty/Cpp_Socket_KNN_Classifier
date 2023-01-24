//
// Created by Ariel Oscar 209341684 and Almog Mesilaty 314973686
//

#include "DownloadCommand.hpp"

void DownloadCommand::execute() {

    if(d->getTestVectors().empty() || d->getTrainVectors().empty())
        dio->write("please upload data\n");
    else if(d->getClassified().empty())
        dio->write("please classify the data\n");
    else
    {
        string result = "";
        int max = d->getClassified().size();
        for (int i = 0; i < max; i++) {
            result+= d->getClassified()[i];
        }
       dio->write(result);
    }
}
