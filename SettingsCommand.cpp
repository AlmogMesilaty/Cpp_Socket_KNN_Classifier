#define DELIMITER '#'

//Prints the current dis matric and k value
void SettingsCommand::execute() {
	m_dio->write("\nThe current KNN parameters are: k = " + c.getK() + ", distance metric = " + c.getDis() + "\n");
	string userInput = m_dio->read();
	//Finds the first delimiter index
	int delimiterIndex = userInput.find(DELIMITER);
	string firstParam = userInput.substr(0, delimiterIndex);
	//Checks if user enter's enter
	if (firstParam == "\n") {
		return;
	}
	//Finds last delimiter
	string end = userInput.find_last_of(DELIMITER);
	string secondParam = userInput.substr(delimiterIndex + 1, end - 1);
	//Checks the validity of the first index
	//TODO: we need to add max K value to CLI - the minimun number of lines in all files
	if (!InputValidator::validK(firstParam)) {
		m_dio->write("\ninvalid value for K")
	}
	else if (!InputValidator::validMetric(secondParam)) {
		m_dio->write("\ninvalid value for metric")
	}
	//Updates the k and metric values
	else {
		int k = stoi(firstParam);
		c->setK(k);
		c->setMetric(secondParam);
	}
	return;
}