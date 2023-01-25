//
// Created by Ariel Oscar 209341684 and Almog Mesilaty 314973686
//

#include "DisplayCommand.hpp"

void DisplayCommand::execute() {

    if(d->getTestVectors().empty() || d->getTrainVectors().empty())
        dio->write("please upload data\n");
    else if(d->getClassified().empty())
        dio->write("please classify the data\n");
    else
    {
        string result = "";
        int max = (d->getClassified().size());
        for (int i = 0; i < max; i++) {
            result+= d->getClassified()[i];

        }

        //cout << "Original size: " << result.size() << endl;

        //Sends the data in chunks buffer size
        int packets = ((result.size()) / 4096);
        for (int i = 0; i < packets; i++) {
            std::string packet = result.substr(0, 4095);
            dio->write(packet);
            result = result.substr(4095);
            dio->write(packet);
        }

        //cout << "Reduced size: " << result.size() << endl;

        dio->write(result+"Done.\n" + "#");

        return;
    }

    std::string userInput = dio->read();

    //Checks if user enter's enter
	if (userInput[0] == '!') {
		return;
	}

}
