// Copyright 2017 Simonyan Vaginak

#include "include/weight_converter_app.h"

#include <map>
#include <string>

int main(int argc, const char** argv) {
    Application app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
