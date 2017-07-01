// Copyright 2017 Korniakov Kirill

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/ColorConverter.h"

int main(int argc, const char** argv) {
    ColorConverter app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
