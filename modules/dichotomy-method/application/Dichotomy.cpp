// Copyright 2017 Mitrokhin Nikita

#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "include/DichotomyApp.h"

int main(int argc, const char** argv) {
    DichotomyApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
