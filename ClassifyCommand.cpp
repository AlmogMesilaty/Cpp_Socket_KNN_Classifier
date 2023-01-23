#include "ClassifyCommand.hpp"

void ClassifyCommand::execute() {

    //Checks if files were uploaded
    std::vector<TypedVector> train = c->getTrainVectors();

    if (train.empty()) {
        m_dio->write("\nplease upload train data, press ENTER to return to main menu\n");
        return;
    }

    //Classify the data
    std::vector<vector<float>> testVectors =c->getTestVectors;
    
    //If already classified, dont classify again
    if (!testVectors.empty()) {
        m_dio->write("classifying data complete");
        return;
    }

    bool invalidDistance = false;
    int k = c->getK();

    //Calculates the distance to the current vector of user.
    for (int i = 0; i < testVectors.size(); i++) {
        for (int j = 0; j < vectors.size(); j++) {
            float dis = VectorDistances::distanceByName(k, train[j].getVector(), testVectors[i]);
            if (dis < 0.0) {
                m_dio->write("Invalid input");
                invalidDistance = true;
                break;
            }
            train[j].setDistance(dis);
        }
        // Continue to another input if the distance was invalid
        if (invalidDistance) { continue; };

        //Calling the KNN to check the type.
        string s = Knn::findType(train, k);

        std::vector<string> classified = c->getClassified();

        classified.push_back(i + " " + s + '\n');
    }

}