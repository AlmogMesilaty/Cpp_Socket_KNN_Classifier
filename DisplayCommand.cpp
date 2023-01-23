//
// Created by Ariel Oscar 209341684 and Almog Mesilaty 314973686
//

#include "DisplayCommand.hpp"

void DisplayCommand::execute() {

    if((*cli).getTestFile().empty() || (*cli).getTrainFile().empty())
        dio->write("please upload data\n");
    else if((*cli).getClassified().empty())
        dio->write("please classify the data\n");
    else
    {
        string result = "";
        int max = (*cli).getClassified().size();
        for (int i = 0; i < max; i++) {
            result+= std::to_string(i+1)+" "+(*cli).getClassified()[i]+"\n";

        }
        dio->write(result+"Done.\n");
    }


}