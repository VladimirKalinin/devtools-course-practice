// Copyright 2017 Kiseleva Olga

#include "include/quadratic_equation.h"
#include "include/quadratic_eq_app.h"

#include <cmath>
#include <limits>
#include <string>
#include <sstream>

QuadrEquationCalc::QuadrEquationCalc() : message_("") {}

void QuadrEquationCalc::Help(const char* appname,
    const char* message) {
    message_ =
        std::string(message) +
        "This is a quadratic equation application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <coefficient a> <coefficient b> " +
        "<coefficient c> \n\n" +

        "Where all arguments " +
        "aren't equals zero\n";
}

bool QuadrEquationCalc::ValidateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc != 4) {
        Help(argv[0], "ERROR: Should be 3 arguments.\n\n");
        return false;
    }
    return true;
}

double ParseCoefficient(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0] || std::abs(value-0)<std::numeric_limits<double>::epsilon()) {
        throw std::string("Wrong number format!");
    }

    return value;
}

std::string QuadrEquationCalc::operator()
(int argc, const char** argv) {
    double coeffA;
    double coeffB;
    double coeffC;
    if (!ValidateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        coeffA = ParseCoefficient(argv[1]);
        coeffB = ParseCoefficient(argv[2]);
        coeffC = ParseCoefficient(argv[3]);
    }
    catch (std::string& str) {
        return str;
    }

    QuadraticEquation quadratic_eq(coeffA, coeffB, coeffC);

    std::ostringstream stream;
    int countSolution = quadratic_eq.NumOfRealSolutions();
        switch (countSolution) {
        case 0:
            stream <<"This equation hasn't solution";
            break;
        case 1:
            stream << "x = " << quadratic_eq.GetRealX1();
            break;
        case 2:
            stream << "x1 = " << quadratic_eq.GetRealX1() << " ";
            stream << "x2 = " << quadratic_eq.GetRealX2();
            break;
        }
    message_ = stream.str();
    return message_;
}

