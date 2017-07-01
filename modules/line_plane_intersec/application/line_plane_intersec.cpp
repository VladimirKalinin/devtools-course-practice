// Copyright 2017 Pletnev Nikita

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/line_plane_intersec_app.h"

int main(int argc, const char** argv) {
    Application app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
