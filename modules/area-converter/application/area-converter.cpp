// Copyright 2017 Lapin Artem

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/area_converter_app.h"

int main(int argc, const char** argv) {
    Application app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
