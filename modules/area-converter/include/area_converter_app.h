// Copyright 2017 Lapin Artem

#ifndef MODULES_AREA_CONVERTER_INCLUDE_AREA_CONVERTER_APP_H_
#define MODULES_AREA_CONVERTER_INCLUDE_AREA_CONVERTER_APP_H_

#include "include/area_converter.h"
#include <string>

class Application {
 public:
    Application();
    std::string operator()(int argc, const char** argv);

 private:
    void Help(const char* appname, const char* message = "");
    bool ValidateNumberOfArguments(int argc, const char** argv);
    struct Arguments{
        double area_size;
        double from_area_coeff;
        double to_area_coeff;
    };
    std::string message_;
};

#endif  // MODULES_AREA_CONVERTER_INCLUDE_AREA_CONVERTER_APP_H_
