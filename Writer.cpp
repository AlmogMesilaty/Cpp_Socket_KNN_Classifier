#include "Writer.hpp"
#define END "#"

Writer::Writer(DefaultIO* dio) {
    this->dio = dio;
}

void Writer::writeToFIle() {
    std::string s = this->dio->read();
    std::ofstream out("temp.csv");
    int endFlag = 0;
    if (!out) {
        dio->write("Cannot create file temp");
    }
    while(true) {
        int index = s.find(END);
        if (index != -1) {
            endFlag = 1;
            s.erase(index);
        }
        out << s;
        if(endFlag) {
            break;
        }
        s = this->dio->read();
    }
    out.close();
}