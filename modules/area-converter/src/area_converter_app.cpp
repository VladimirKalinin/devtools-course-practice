// Copyright 2017 Lapin Artem

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include "sstream"

#include "include/area_converter_app.h"
#include "include/area_converter.h"

Application::Application() {}

void Application::Help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a square converter application\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <area_size> <from_area_type> " +
        "<to_area_type>,\n" +

        "<Where <area_size> is non-negative rational number,\n" +
        "<from_area_type> and <to_area_type>" +
        "are one of the following word:\n" +
        "Centimeter, Decimeter, Meter, Yard, Inch, Acr, Hectare.";
}

bool Application::ValidateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc != 4) {
        Help(argv[0], "ERROR: Should be 3 arguments.\n\n");
        return false;
    }
    return true;
}

double ParseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);
        if (end[0]) {
        throw std::string("Wrong number format!");
    }
    return value;
}

double ParseAreaType(const char* arg) {
    double area_coeff;
    if (strcmp(arg, "Centimeter") == 0) {
        area_coeff = AreaConverter::kCentimeter;
    } else if (strcmp(arg, "Meter") == 0) {
        area_coeff = AreaConverter::kMeter;
    } else if (strcmp(arg, "Decimeter") == 0) {
        area_coeff = AreaConverter::kDecimeter;
    } else if (strcmp(arg, "Yard") == 0) {
        area_coeff = AreaConverter::kYard;
    } else if (strcmp(arg, "Inch") == 0) {
        area_coeff = AreaConverter::kInch;
    } else if (strcmp(arg, "Acr") == 0) {
        area_coeff = AreaConverter::kAcr;
    } else if (strcmp(arg, "Hectare") == 0) {
        area_coeff = AreaConverter::kHectare;
    } else {
        throw std::string("Wrong area format!");
    }
    return area_coeff;
}

std::string Application::operator()(int argc, const char** argv) {
    Arguments args;
    if (!ValidateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.area_size = ParseDouble(argv[1]);
        args.from_area_coeff = ParseAreaType(argv[2]);
        args.to_area_coeff = ParseAreaType(argv[3]);
    }
    catch (std::string& str) {
        return str;
    }
    AreaConverter converter(args.from_area_coeff, args.to_area_coeff);
    double result;
    try {
        result = converter(args.area_size);
    }
    catch (std::string& str) {
        return str;
    }
    std::ostringstream stream;
    stream << "Converted area size:" << result;
    message_ = stream.str();
    return message_;
}
