#include "ClassifyCommand.hpp"

ClassifyCommand::ClassifyCommand(DefaultIO *dio, DataManager *d) : Command(dio, d, "classify data") {}

void ClassifyCommand::execute() {

    //Checks if files were uploaded
    std::vector<TypedVector> train = d->getTrainVectors();
    std::vector<vector<float>> testVectors = d->getTestVectors();

    if (train.empty() || testVectors.empty()) {
        dio->write("please upload data\n");
        return;
    }

    //Classify the data
    std::vector<string>* classified = d->getClassified2();

    //If already classified, dont classify again
    if (!classified->empty()) {
        dio->write("classifying data complete\n");
        return;
    }

    bool invalidDistance = false;
    string metric = d->getDistance();

    int testVectorSize = testVectors.size(); 
    int trainVectorSize = train.size();

    //Calculates the distance to the current vector of user.
    for (int i = 0; i < testVectorSize; i++) {
        for (int j = 0; j < trainVectorSize; j++) {
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
        string res = std::to_string(i + 1) + " " + s + '\n';
        //cout << res;
        classified->push_back(res);
    }
    dio->write("classifying data complete\n");
}