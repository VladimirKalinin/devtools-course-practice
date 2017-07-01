// Copyright 2017 Mitrokhin Nikita

#include "include/DichotomyApp.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string>
#include <sstream>

#include "include/dichotomy.h"

DichotomyApp::DichotomyApp() : message_("") {}

void DichotomyApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
           "This is a method of dichotomy application.\n\n" +
           "Please provide arguments in the following format:\n\n"+

           " $ " + appname +" <left_board_> <right_board_> <eps_> <func_>\n\n"+

           "Where <func_> int-precision number, " +
           "<left_board_> <right_board_> <eps_> double-precision number, "
           "and <func_> is a choice of the kind of function\n";
}

bool DichotomyApp::validateNumberofArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 5) {
        help(argv[0], "Error: Should be 4 arguments.\n\n");
        return false;
    }
    return true;
}

double func1(double x) {
    return x*x;
}

double func2(double x) {
    return 2*x*x - 3*x;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

double parseInt(const char* arg) {
    char* end = 0;
    int value = strtol(arg, &end, 10);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

std::string DichotomyApp::operator()(int argc, const char** argv) {
    Arguments args;

    if (!validateNumberofArguments(argc, argv)) {
        return message_;
    }
    try {
        args.left_border_  = parseDouble(argv[1]);
        args.right_border_ = parseDouble(argv[2]);
        args.eps_          = parseDouble(argv[3]);
        args.func_         = parseInt(argv[4]);
    }
    catch(std::string& str) {
        return str;
    }

    std::ostringstream stream;
    Dichotomy dich;
    switch (args.func_) {
    case 1:
    double result;
    result = dich.FindMin(*func1,
    args.left_border_, args.right_border_, args.eps_);
    stream << "Min = " << result;
    break;

    case 2:
    result = dich.FindMin(*func2, args.left_border_,
    args.right_border_, args.eps_);
    stream << "Min = " << result;
    break;
    }

    message_ = stream.str();

    return message_;
}
