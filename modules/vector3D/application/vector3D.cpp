// Copyright 2017 Bevzuk Semen

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/vector3D-app.h"

int main(int argc, const char** argv) {
    Vector3DApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
