#define DELIMITER '#'

#include "SettingsCommand.hpp"

SettingsCommand::SettingsCommand(DefaultIO* dio, DataManager* d) : Command(dio, d, "algorithm settings") {}

//Prints the current dis matric and k value
void SettingsCommand::execute() {
	std::string s = d->getK() + "";
	dio->write("\nThe current KNN parameters are: k = " + s + ", distance metric = " + d->getDistance() + "\n");
	
	std::string userInput = dio->read();
	
	//Finds the first delimiter index
	int delimiterIndex = userInput.find(DELIMITER);
	std::string firstParam = userInput.substr(0, delimiterIndex);
	
	//Checks if user enter's enter
	if (firstParam == "\n") {
		return;
	}
	
	//Finds last delimiter
	int end = userInput.find_last_of(DELIMITER);
	std::string secondParam = userInput.substr(delimiterIndex + 1, end - 1);
	
	//Checks the validity of the first index
	int k = stoi(firstParam);
	int max = d->getMaximumK();

	if (!(InputValidator::validK(k, max))) {
		dio->write("\ninvalid value for K");
	}
	else if (!InputValidator::validMetric(secondParam)) {
		dio->write("\ninvalid value for metric");
	}
	//Updates the k and metric values
	else {
		d->setK(k);
		d->setDistance(secondParam);
	}
	return;
}