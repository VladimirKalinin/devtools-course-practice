// Copyright 2017 Karev Boris

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/ConverterCurrencyApp.h"

int main(int argc, const char** argv) {
    ConverterCurrencyApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
