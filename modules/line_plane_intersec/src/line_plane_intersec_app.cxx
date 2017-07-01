// Copyright 2017 Pletnev Nikita

#include "include/line_plane_intersec.h"
#include "include/line_plane_intersec_app.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include <vector>

Application::Application() : message_("") {}

void Application::Help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is an application " +
        "of calculating the intersection of line and plane.\n\n" +
        "Please provide arguments in one of the following formats:\n\n" +

        "Format #1:\n" +
        "  $ " + appname + " <line_x> <line_y> <line_z> " +
        "<dir_x> <dir_y> <dir_z> " +
        "<plane_a> <plane_b> <plane_c> <plane_d>\n\n" +

        "Where all arguments are double-precision numbers,\n" +
        "<line_x>, <line_y>, <line_z> are coordinates of point of line,\n" +
        "<dir_x>, <dir_y>, <dir_z> " +
        "are coordinates of line direction vector,\n" +
        "<plane_a>, <plane_b>, <plane_c>, <plane_d> " +
        "are coefficients of plane ax+by+cz+d=0.\n\n" +

        "Format #2:\n" +
        "  $ " + appname + " <line_p1_x> <line_p1_y> <line_p1_z> " +
        "<line_p1_x> <line_p1_y> <line_p1_z> " +
        "<plane_p1_x> <plane_p1_y> <plane_p1_z> " +
        "<plane_p2_x> <plane_p2_y> <plane_p2_z> " +
        "<plane_p3_x> <plane_p3_y> <plane_p3_z>\n\n" +

        "Where all arguments are double-precision numbers,\n" +
        "The first 6 arguments are coordinates of 2 points " +
        "that set the line. The last 9 arguments are coordinates " +
        "of 3 points that set the plane\n";
}

bool Application::ValidateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if ((argc != 11) && (argc != 16)) {
        Help(argv[0], "ERROR: Should be 10 or 15 arguments.\n\n");
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

std::string Application::operator()(int argc, const char** argv) {
    Intersection intersection;

    if (!ValidateNumberOfArguments(argc, argv)) {
        return message_;
    }

    if (argc == 11) {
        try {
            intersection.SetLine(
                ParseDouble(argv[1]),
                ParseDouble(argv[2]),
                ParseDouble(argv[3]),
                ParseDouble(argv[4]),
                ParseDouble(argv[5]),
                ParseDouble(argv[6]));
            intersection.SetPlane(
                ParseDouble(argv[7]),
                ParseDouble(argv[8]),
                ParseDouble(argv[9]),
                ParseDouble(argv[10]));
        }
        catch (std::string& str) {
            return str;
        }
    } else {
        try {
            std::vector<double> line_point1(3), line_point2(3);
            line_point1[0] = ParseDouble(argv[1]);
            line_point1[1] = ParseDouble(argv[2]);
            line_point1[2] = ParseDouble(argv[3]);

            line_point2[0] = ParseDouble(argv[4]);
            line_point2[1] = ParseDouble(argv[5]);
            line_point2[2] = ParseDouble(argv[6]);

            std::vector<double> plane_point1(3),
                plane_point2(3), plane_point3(3);
            plane_point1[0] = ParseDouble(argv[7]);
            plane_point1[1] = ParseDouble(argv[8]);
            plane_point1[2] = ParseDouble(argv[9]);

            plane_point2[0] = ParseDouble(argv[10]);
            plane_point2[1] = ParseDouble(argv[11]);
            plane_point2[2] = ParseDouble(argv[12]);

            plane_point3[0] = ParseDouble(argv[13]);
            plane_point3[1] = ParseDouble(argv[14]);
            plane_point3[2] = ParseDouble(argv[15]);

            intersection.SetLineWithTwoPoints(line_point1, line_point2);
            intersection.SetPlaneWithThreePoints(
                plane_point1, plane_point2, plane_point3);
        }
        catch (std::string& str) {
            return str;
        }
    }

    std::vector<double> intersection_result;
    try {
        intersection_result = intersection.CalculateIntersection();
    }
    catch (std::string& str) {
        return str;
    }

    std::ostringstream stream;
    stream << "coordinates of intersection point:\n"
        << " x: " << intersection_result[0] << "\n"
        << " y: " << intersection_result[1] << "\n"
        << " z: " << intersection_result[2];
    message_ = stream.str();

    return message_;
}

