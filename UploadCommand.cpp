#include "UploadCommand.hpp"

UploadCommand::UploadCommand(DefaultIO* dio, DataManager* d) : Command(dio, d, "upload an unclassified csv data file") {}

void UploadCommand::execute() {

	//Creates the test and classified vectors of the specific client
	std::vector<TypedVector> trainVectors;
	std::vector<TypedVector> testVectors;

	//Prints massage to the user
	dio->write("Please upload your local train CSV file.\n");

	//Read the train file path
	std::string trainPath = dio->read();

	//Read from local file into vector of TypedVectors
		Reader* reader = new Reader();
		reader->read(trainPath, &(d->getTrainVectors()));
	
	
	dio->write("Upload complete.\nPlease upload your local test CSV file.");

	//Read the test file path
	std::string testPath = dio->read();

	//Read from local file into vector of TypedVectors
	Reader testReader = Reader();
	reader->readToFloat(testPath, &(d->getTestVectors()));

	dio->write("\nUploade complete.");

	//Updates the client train and test data
	//d->setTrainData(trainVectors);
	//cli->setTestData(testVectors);

	//Set an empty vector for the classified data
	std::vector<std::string> classifiedVectors;
	d->setClassified(classifiedVectors);

	dio->write("you choose UplodCommand");
}