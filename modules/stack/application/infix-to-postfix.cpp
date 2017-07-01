// Copyright 2017 Gvozdeva Viktoria

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/infix_to_postfix_converter.h"

int main(int argc, const char** argv) {
    InfixToPostfixConverter app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
