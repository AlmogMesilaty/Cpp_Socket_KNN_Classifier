#include "Writer.hpp"
#define END "#"

Writer::Writer(DefaultIO* dio) {
    this->dio = dio;
}

void Writer::writeToFIle() {
    std::string s = this->dio->read();
    std::ofstream out("temp.csv", std::ios::app);
    if(!out) { dio->write("Cannot create file temp"); }
    int index = s.find(END);
    while(index == -1) {
        out << s;
        s = this->dio->read();
    }
}