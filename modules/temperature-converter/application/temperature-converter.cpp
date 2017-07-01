// Copyright 2017 Kulygina Julia

#include <stdlib.h>
#include <stdio.h>
#include <string>

#include "include/temperature_converter.h"
#include "include/temperature-converter-app.h"

int main(int argc, const char** argv) {
    TemperatureConverterApp app;
    std::string output = app(argc, argv);
    printf("%s\n", output.c_str());
    return 0;
}
