#include "ClassifyCommand.hpp"

ClassifyCommand::ClassifyCommand(DefaultIO *dio, DataManager *d): Command(dio, d, "classify data") {}

void ClassifyCommand::execute() {

    //Checks if files were uploaded
    std::vector<TypedVector> train = d->getTrainVectors();

    if (train.empty()) {
        dio->write("\nplease upload train data, press ENTER to return to main menu\n");
        return;
    }

    //Classify the data
    std::vector<vector<float>> testVectors = d->getTestVectors();
    
    //If already classified, dont classify again
    if (!testVectors.empty()) {
        dio->write("classifying data complete");
        return;
    }

    bool invalidDistance = false;
    string metric = d->getDistance();

    //Calculates the distance to the current vector of user.
    for (int i = 0; i < testVectors.size(); i++) {
        for (int j = 0; j < train.size(); j++) {
            float dis = VectorDistances::distanceByName(metric, train[j].getVector(), testVectors[i]);
            if (dis < 0.0) {
                dio->write("Invalid input");
                invalidDistance = true;
                break;
            }
            train[j].setDistance(dis);
        }
        // Continue to another input if the distance was invalid
        if (invalidDistance) { continue; };

        //Calling the KNN to check the type.
        string s = Knn::findType(train, d->getK());

        std::vector<string> classified = d->getClassified();

        classified.push_back(i + " " + s + '\n');
    }

}