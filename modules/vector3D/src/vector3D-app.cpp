// Copyright 2017 Bevzuk Semen

#include "include/vector3D.h"
#include "include/vector3D-app.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

Vector3DApp::Vector3DApp() : message_("") {}

void Vector3DApp::Help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
          "This is a vector calculator application.\n\n" +
          "Please provide arguments in the following format:\n\n"+

          "  $ " + appname + " <v1_x> <v1_y> <v1_z>" +
          "<v2_x> <v2_y> <v2_z> <operation>\n\n" + " or "
          "  $ " + appname + " <v1_x> <v1_y> <v1_z>" +
          " <operation>\n\n" +

          "Where all arguments are double-precision numbers, " +
          "and <operation> is one of '+', '-', '*', '^', 'n', 'N'.\n" +
          "n - norm vector, N - normalize vector.\n";
}

bool Vector3DApp::ValidateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (!(argc == 5 || argc == 8)) {
        Help(argv[0], "ERROR: Should be 7 or 4 arguments.\n\n");
        return false;
    }
    return true;
}

double parseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

char parseOperationBinary(const char* arg) {
    char op;
    if (strcmp(arg, "+") == 0) {
        op = '+';
    } else if (strcmp(arg, "-") == 0) {
        op = '-';
    } else if (strcmp(arg, "*") == 0) {
        op = '*';
    } else if (strcmp(arg, "^") == 0) {
        op = '^';
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

char parseOperationUnary(const char* arg) {
    char op;
    if (strcmp(arg, "n") == 0) {
        op = 'n';
    } else if (strcmp(arg, "N") == 0) {
        op = 'N';
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string Vector3DApp::operator()(int argc, const char** argv) {
    ArgumentsBinary args_binary;
    ArgumentsUnary args_unary;

    if (!ValidateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        if (argc == 8) {
            args_binary.v1_x = parseDouble(argv[1]);
            args_binary.v1_y = parseDouble(argv[2]);
            args_binary.v1_z = parseDouble(argv[3]);
            args_binary.v2_x = parseDouble(argv[4]);
            args_binary.v2_y = parseDouble(argv[5]);
            args_binary.v2_z = parseDouble(argv[6]);
            args_binary.operation = parseOperationBinary(argv[7]);
        }
        if (argc == 5) {
            args_unary.v1_x = parseDouble(argv[1]);
            args_unary.v1_y = parseDouble(argv[2]);
            args_unary.v1_z = parseDouble(argv[3]);
            args_unary.operation = parseOperationUnary(argv[4]);
        }
    }
    catch (std::string& str) {
        return str;
    }

    std::ostringstream stream;

    if (argc == 5) {
        Vector3D v1(args_unary.v1_x, args_unary.v1_y, args_unary.v1_z);
        switch (args_unary.operation) {
            case 'n':
                stream << "Norm = " << v1.Norm();
                break;
            case 'N':
                Vector3D resultVector = v1.Normalize();
                stream << "Normalization vector = <" <<
                            resultVector.GetX() <<
                    "; " << resultVector.GetY() <<
                    "; " << resultVector.GetZ() << ">";
                break;
        }
    }

    if (argc == 8) {
        Vector3D v1(args_binary.v1_x, args_binary.v1_y, args_binary.v1_z);
        Vector3D v2(args_binary.v2_x, args_binary.v2_y, args_binary.v2_z);
        Vector3D result_vector;
        switch (args_binary.operation) {
            case '+':
                result_vector = v1 + v2;
                stream << "Sum = <" <<
                            result_vector.GetX() <<
                    "; " << result_vector.GetY() <<
                    "; " << result_vector.GetZ() << ">";
                break;
            case '-':
                result_vector = v1 - v2;
                stream << "Difference = <" <<
                            result_vector.GetX() <<
                    "; " << result_vector.GetY() <<
                    "; " << result_vector.GetZ() << ">";
                break;
            case '*':
                stream << "Scalar multiplication = " << v1 * v2;
                break;
            case '^':
                result_vector = v1 ^ v2;
                stream << "Vector multiplication = <" <<
                            result_vector.GetX() <<
                    "; " << result_vector.GetY() <<
                    "; " << result_vector.GetZ() << ">";
                break;
        }
    }

    message_ = stream.str();

    return message_;
}
