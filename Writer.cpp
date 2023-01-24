#include "Writer.hpp"
#define END "#"

Writer::Writer(DefaultIO* dio) {
    this->dio = dio;
}

void Writer::writeToFIle() {
    std::string s = this->dio->read();
    std::ofstream out("temp.csv", std::ios::app);
    if(!out) { dio->write("Cannot create file temp"); }
    while(s != END) {
        if (!out) { dio->write("Cannot open file temp"); }
        out << s;
        s = this->dio->read();
    }
}