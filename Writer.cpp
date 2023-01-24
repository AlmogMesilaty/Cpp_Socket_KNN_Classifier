#include "Writer.hpp"

Writer::Writer(DefaultIO* dio) {
    this->dio = dio;
}

void Writer::writeToFIle(char* arr, int size) {
    FILE *out = fopen("temp.csv", "w");
    if (out) {
        int res = fputs(arr, out);
        if (res == EOF) { dio->write("Cannot open file temp"); }
    }
    else {
        std::ofstream newF;
        newF.write(arr, size);
        if (!newF) { dio->write("Cannot create file temp"); }
        newF.write(arr, size);   
    }
}