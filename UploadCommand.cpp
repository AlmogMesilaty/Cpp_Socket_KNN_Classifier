#include "UploadCommand.hpp"
#define TEMP "temp.csv"

UploadCommand::UploadCommand(DefaultIO* dio, DataManager* d) : Command(dio, d, "upload an unclassified csv data file") {}

void UploadCommand::execute() {

	//Prints massage to the user
	dio->write("Please upload your local train CSV file.\n");

	//Write from socket into temp file
	Writer* writer = new Writer(this->dio);
	writer->writeToFIle();

	//Read from local file into vector of TypedVectors
	Reader* reader = new Reader();
	reader->read(TEMP, d->getTrainVectors2());
	
	dio->write("Upload complete.\nPlease upload your local test CSV file.\n");

	//Write from socket into temp file
	writer->writeToFIle();

	//Read from local file into vector of floats

	reader->readToFloat(TEMP, d->getTestVectors2());

	//Set an empty vector for the classified data
	std::vector<std::string> classifiedVectors;
	d->setClassified(classifiedVectors);

	//Set new max K value
	d->setMaximumK(d->getTrainVectors2()->size());

	dio->write("Uploade complete.\n");

}