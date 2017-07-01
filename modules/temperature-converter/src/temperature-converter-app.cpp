// Copyright 2017 Kulygina Julia

#include "include/temperature_converter.h"
#include "include/temperature-converter-app.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

TemperatureConverterApp::TemperatureConverterApp() {}
void TemperatureConverterApp::help(const char* message) {
    message_ =
        std::string(message) +
        "This is a temperature converter app\n" +
        "Use this converter <Input> <Number using ,> <Output>\n" +
        "Where <Input> is temperature scale what you have, \n" +
        "<Output> is temperature scale what you found and \n" +
        "<Number> is a number, that you want convert\n" +
        "for example: C - Celsius, F - Fahrenheit, K - Kelvin, N - Newton\n" +
        "Please provide arguments in the following format: C 23,0 F";
}

bool TemperatureConverterApp::validateNumberOfArguments(int argc,
    const char** argv) {
    if (argc == 1) {
        help();
        return false;
    }

    if ((argc == 2) || (argc == 3)) {
        help("ERROR: Should be 3 arguments\n");
        return false;
    }

    return true;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong format!");
    }

    return value;
}

char parseChar(const char* arg) {
    char scale;
    if (strcmp(arg, "C") == 0) {
        scale = 'C';
    } else if (strcmp(arg, "F") == 0) {
        scale = 'F';
    } else if (strcmp(arg, "N") == 0) {
        scale = 'N';
    } else if (strcmp(arg, "K") == 0) {
        scale = 'K';
    } else {
        throw std::string("Wrong format!");
    }
    return scale;
}

std::string TemperatureConverterApp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.Scale1 = parseChar(argv[1]);
        args.number = parseDouble(argv[2]);
        args.Scale2 = parseChar(argv[3]);
    }
    catch (std::string& str) {
        return str;
    }

    double result;

    std::ostringstream stream;
    switch (args.Scale1) {
    case 'C':
        try {
        switch (args.Scale2) {
        case 'F':
            result = TemperatureConverter::CelsiusToFahrenheit(args.number);
            break;
        case 'K':
            result = TemperatureConverter::CelsiusToKelvin(args.number);
            break;
        case 'N':
            result = TemperatureConverter::CelsiusToNewton(args.number);
            break;
        }
        stream << "Result = " << result;
        break;
        } catch (std::string& str) {
            return str;
        }
    case 'F':
        try {
        switch (args.Scale2) {
        case 'C':
            result = TemperatureConverter::FahrenheitToCelsius(args.number);
            break;
        case 'K':
            result = TemperatureConverter::FahrenheitToKelvin(args.number);
            break;
        case 'N':
            result = TemperatureConverter::FahrenheitToNewton(args.number);
            break;
        }
        stream << "Result = " << result;
        break;
        }
        catch (std::string& str) {
            return str;
        }
    case 'K':
        try {
        switch (args.Scale2) {
        case 'C':
            result = TemperatureConverter::KelvinToCelsius(args.number);
            break;
        case 'F':
            result = TemperatureConverter::KelvinToFahrenheit(args.number);
            break;
        case 'N':
            result = TemperatureConverter::KelvinToNewton(args.number);
            break;
        }
        stream << "Result = " << result;
        break;
        }
        catch (std::string& str) {
            return str;
        }
    case 'N':
        try {
        switch (args.Scale2) {
        case 'C':
            result = TemperatureConverter::NewtonToCelsius(args.number);
            break;
        case 'F':
            result = TemperatureConverter::NewtonToFahrenheit(args.number);
            break;
        case 'K':
            result = TemperatureConverter::NewtonToKelvin(args.number);
            break;
        }
        stream << "Result = " << result;
        break;
        }
        catch (std::string& str) {
            return str;
        }
    }

    message_ = stream.str();

    return message_;
}

TemperatureConverterApp::~TemperatureConverterApp() {
    message_.clear();
}
