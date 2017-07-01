// Copyright 2017 Maxim Doronin

#include <iostream>
#include <string>
#include "include/newton-method-app.h"

int main(int argc, const char** argv) {
    NewtonMethodApplication app;
    std::string output = app(argc, argv);
    std::cout << output << std::endl;
    return 0;
}
