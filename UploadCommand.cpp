#include "UploadeCommand.hpp"

void UploadeCommand::execute() {
	
	//Creates the test and classified vectors of the specific client
	std::vector<TypedVector> trainVectors;
	std::vector<TypedVector> testVectors;
	
	//Prints massage to the user
	m_dio->write("\nPlease upload your local train CSV file.\n");
	
	//Read the train file path
	std::string trainPath = m_dio->read();

	//Read from local file into vector of TypedVectors
	Reader reader = Reader(trainPath, c->getMetric());
	reader.read(trainVectors);

	m_dio->write("Upload complete.\nPlease upload your local test CSV file.");

	//Read the test file path
	std::string testPath = m_dio->read();

	//Read from local file into vector of TypedVectors
	Reader testReader = Reader(testVectors, c->getMetric());
	reader.read(testVectors);

	m_dio->write("\nUploade complete.");

	//Updates the client train and test data
	c->setTrainData(trainVectors);
	c->setTestData(testVectors);
	
	//Set an empty vector for the classified data
	std::vector<std::shared_ptr<TypedVector>> classifiedVectors;
	c->setClassifiedData(classifiedVectors);
}