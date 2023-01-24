#include "Writer.hpp"

Writer::Writer(DefaultIO* dio) {
    this->dio = dio;
}

void Writer::writeToFIle(std::string s, int size) {

    std::fstream out;
    out.open("temp.csv", std::ios::app);
    if (out) {
        out << s;
    }
    else {
        std::ofstream newOut;
        if(!newOut) {
            dio->write("Cannot create file temp");
        }
        newOut << s;  
    }
}