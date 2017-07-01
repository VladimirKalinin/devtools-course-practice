// Copyright 2017 Komarov Nikolay

#include <stdlib.h>
#include <string.h>
#include <string>
#include <sstream>

#include "include/integration_methods_app.h"
#include "include/integration_methods.h"

Application::Application() : message_("") {}

void Application::Help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a Integration Methods application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <integrand> <low_limit> " +
        "<upper_limit> <integration_method> <option>\n\n" +

        "<integrand> - string of integrand\n" +
        "<low_limit>, <upper_limit> - low and upper integration" +
        " limits which are double-precision\n" +
        "<integration_method> - input 'r' for rectangle method, " +
        "'t' for trapezoid method or 's' for Simpson method\n" +
        "<option> - input a quantity of steps for rectangle and " +
        "trapezoid methods or precision for Simpson method\n";
}

bool Application::ValidateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc != 6) {
        Help(argv[0], "ERROR: Should be 5 arguments.\n\n");
        return false;
    }
    return true;
}

double Application::ParseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

int Application::ParseInteger(const char* arg) {
    char* end;
    int value = std::strtol(arg, &end, 10);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

bool Application::ValidateOperationName(const char* arg) {
    if (!(strcmp(arg, "r") == 0 || strcmp(arg, "t") == 0 ||
        strcmp(arg, "s") == 0)) {
        Help("Wrong method name!");
        return false;
    }
    return true;
}

std::string Application::operator()(int argc, const char** argv) {
    Arguments args;

    if (!ValidateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.integrand = argv[1];
        args.low_limit = ParseDouble(argv[2]);
        args.upper_limit = ParseDouble(argv[3]);
        if (!ValidateOperationName(argv[4])) {
            return message_;
        }
        args.method_name = argv[4];
        if (strcmp(args.method_name, "s") == 0) {
            args.epsilon = ParseDouble(argv[5]);
        } else {
            args.quantity_of_steps = ParseInteger(argv[5]);
        }
    }
    catch (std::string& str) {
        return str;
    }

    IntegrationMethod integration_method;

    std::ostringstream stream;
    try {
        double result;
        if (strcmp(args.method_name, "r") == 0) {
            result = integration_method.RectangleMethod(args.integrand,
                args.low_limit, args.upper_limit, args.quantity_of_steps);
            stream << "The integration value of rectangle method equals " <<
                result;
        } else if (strcmp(args.method_name, "t") == 0) {
            result = integration_method.TrapezoidMethod(args.integrand,
                args.low_limit, args.upper_limit, args.quantity_of_steps);
            stream << "The integration value of trapezoid method equals " <<
                result;
        } else if (strcmp(args.method_name, "s") == 0) {
            result = integration_method.SimpsonMethod(args.integrand,
                args.low_limit, args.upper_limit, args.epsilon);
            stream << "The integration value of Simpson method equals " <<
                result;
        }
    }
    catch(std::exception& e) {
        return e.what();
    }

    message_ = stream.str();

    return message_;
}
