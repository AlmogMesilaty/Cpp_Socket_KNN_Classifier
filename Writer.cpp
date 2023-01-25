#include "Writer.hpp"
#define END "#"

Writer::Writer(DefaultIO* dio) {
    this->dio = dio;
}

void Writer::writeToFIle() {
    std::string s = this->dio->read();
    std::ofstream out("temp.csv");
    if (!out) {
        dio->write("Cannot create file temp");
    }
    while(true) {
        out << s;
        int index = s.find(END);
        if(index != -1) {
            break;
        }
        s = this->dio->read();
    }
    out.close();
}