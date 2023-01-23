

    else {
    //finding the vector, first as a String and then to a vector<float>
    std::string userVector = "";
    i++;
    while (buffer[i] != '#') {
        userVector += buffer[i];
        i++;
    }
    vector<float> userVec = VectorDistances::stringToVector(userVector);
    if (userVector.empty()) {
        char bufferToClient[] = "Invalid vector";
        int sent_bytes = send(client_sock, bufferToClient, read_bytes, 0);
        if (sent_bytes < 0) {
            perror("error sending to client");
        }
    }

/*
//Finding the type of the distance
std::string userTypeOfDis = "";
i++;
while (buffer[i] != '#') {
    userTypeOfDis += buffer[i];
    i++;
}*/

/*
bool invalidDistance = false;
//Calculates the distance to the current vector of user.
for (int i = 0; i < vectors.size(); i++) {
    float dis = VectorDistances::distanceByName(userTypeOfDis, vectors[i].getVector(), userVec);
    if (dis < 0.0) {
        char bufferToClient[] = "invalid input";
        int sent_bytes = send(client_sock, bufferToClient, read_bytes, 0);
        if (sent_bytes < 0) {
            perror("error sending to client");
        }

        invalidDistance = true;
        break;
    }
    vectors[i].setDistance(dis);
}*/

// Continue to another input if the distance was invalid
if (invalidDistance) { continue; };
//Calling the KNN to check the type.
string s = Knn::findType(vectors, k);
char bufferToClient[s.size() + 1] = "";
for (i = 0; i < s.size(); i++) {
    bufferToClient[i] = s[i];
}
bufferToClient[s.size() + 1] = '\0';
int sent_bytes = send(client_sock, bufferToClient, read_bytes, 0);
if (sent_bytes < 0) {
    perror("error sending to client");
}