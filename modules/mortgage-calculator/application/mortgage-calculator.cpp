// Copyright 2017 Grechukhin Nikita

#include <iostream>
#include <string>

#include "../include/mortgage_calculator_app.h"

int main(int argc, const char **argv) {
    Application app;
    std::string output = app(argc, argv);
    std::cout << output << std::endl;

    return 0;
}
