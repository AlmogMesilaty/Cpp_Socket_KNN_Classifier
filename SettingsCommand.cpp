#define DELIMITER ' '

#include "SettingsCommand.hpp"

SettingsCommand::SettingsCommand(DefaultIO* dio, DataManager* d) : Command(dio, d, "algorithm settings") {}

//Prints the current dis matric and k value
void SettingsCommand::execute() {
	dio->write("The current KNN parameters are: k = " + std::to_string(d->getK()) + ", distance metric = " + d->getDistance() + "\n");
	
	std::string userInput = dio->read();

	//Checks if user enter's enter
	if (userInput == "") {
		return;
	}

	//Finds the first delimiter index
	int delimiterIndex = userInput.find(DELIMITER);
	std::string firstParam = userInput.substr(0, delimiterIndex);

	//Checks the validity of the first index
	int max = d->getMaximumK();

	if (!(InputValidator::validK(firstParam, max))) {
		dio->write("invalid value for K\n");
	}

	//Finds last delimiter
	std::string secondParam = userInput.substr(delimiterIndex + 1);

	if (!InputValidator::validMetric(secondParam)) {
		dio->write("invalid value for metric\n");
	}
	//Updates the k and metric values
	else {
		int k = stoi(firstParam);
		d->setK(k);
		d->setDistance(secondParam);
		dio->write("The current KNN parameters are: k = " + std::to_string(d->getK()) + ", distance metric = " + d->getDistance() + "\n");
	}
	return;
}