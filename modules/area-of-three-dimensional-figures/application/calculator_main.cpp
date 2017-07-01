// Copyright 2017 Zhorin Sergey

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/calculator_app.h"

int main(int argc, const char** argv) {
    CalculatorApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
