#include "ClassifyCommand.hpp"

ClassifyCommand::ClassifyCommand(DefaultIO *dio, CLI *cli): Command(dio, cli, "classify data") {}

void ClassifyCommand::execute() {

    //Checks if files were uploaded
    std::vector<TypedVector> train = cli->getTrainVectors();

    if (train.empty()) {
        dio->write("\nplease upload train data, press ENTER to return to main menu\n");
        return;
    }

    //Classify the data
    std::vector<vector<float>> testVectors =c->getTestVectors;
    
    //If already classified, dont classify again
    if (!testVectors.empty()) {
        dio->write("classifying data complete");
        return;
    }

    bool invalidDistance = false;
    string metric = c->getMetric();

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
        string s = Knn::findType(train, c->getK());

        std::vector<string> classified = c->getClassified();

        classified.push_back(i + " " + s + '\n');
    }

}