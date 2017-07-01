// Copyright 2017 Simonyan Vaginak

#include "include/weight_converter.h"
#include "include/weight_converter_app.h"

#include <map>
#include <string>
#include <cstring>
#include <sstream>

Application::Application() : message_("") {}

void Application::Help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a weight converter application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <weight> <type_from> " +
          "<type_to>\n\n" +

          "Where the first argument is a positive double-precision number \n" +
          "and <type_from> and <type_to> are one of  'KG', 'MG', 'G', 'GR'," +
          "'DR', 'OZ', 'LB', 'CR' \n";
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

double parseWeight(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0] || value < 0.0) {
        throw std::string("Wrong number format!");
    }

    return value;
}

Weights parseWeightType(const char* arg) {
    if (strcmp(arg, "KG") == 0) {
        return Weights::KG;
    } else if (strcmp(arg, "MG") == 0) {
        return Weights::MG;
    } else if (strcmp(arg, "G") == 0) {
        return Weights::G;
    } else if (strcmp(arg, "GR") == 0) {
        return Weights::GR;
    } else if (strcmp(arg, "DR") == 0) {
        return Weights::DR;
    } else if (strcmp(arg, "OZ") == 0) {
        return Weights::OZ;
    } else if (strcmp(arg, "LB") == 0) {
        return Weights::LB;
    } else if (strcmp(arg, "CR") == 0) {
        return Weights::CR;
    } else {
        throw std::string("Wrong weight's type format!");
    }
}

std::string Application::operator()(int argc, const char** argv) {
    Arguments args;
    Weights type_from;
    Weights type_to;
    if (!ValidateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.weight = parseWeight(argv[1]);
        type_from = parseWeightType(argv[2]);
        type_to = parseWeightType(argv[3]);
    }
    catch (std::string& str) {
        return str;
    }

    WeightConverter weight_converter(0.001, KG);

    std::ostringstream stream;
    stream << "Weight = " << weight_converter.Convert(args.weight,
        type_from, type_to) << " ";

    message_ = stream.str();

    return message_;
}
