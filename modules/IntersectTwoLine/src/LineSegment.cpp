// Copyright 2017 Lobanov Andrey

#include "include/LineSegment.h"
#include <iostream>
#include <string>

using std::string;
using std::stringstream;

LineSegment2D::LineSegment2D(double X1, double Y1, double X2, double Y2) {
  if (X1 == X2 && Y1 == Y2) {
    throw "Error, points can not coincide";
  } else if (X1 > X2) {
    X1_ = X2;
    Y1_ = Y2;
    X2_ = X1;
    Y2_ = Y1;
  } else {
    X1_ = X1;
    Y1_ = Y1;
    X2_ = X2;
    Y2_ = Y2;
  }
}

double LineSegment2D::GetCoord(int count) {
  switch (count) {
    case 1: return X1_;
    case 2: return Y1_;
    case 3: return X2_;
    case 4: return Y2_;
    default: throw "Invalid value";
  }
}

double LineSegment2D::GetCoeff(int count) {
  switch (count) {
    case 1: return Y1_ - Y2_;
    case 2: return X2_ - X1_;
    case 3: return X1_ * Y2_ - X2_ * Y1_;
    default: throw "Invalid value";
  }
}

string LineSegment2D::CheckIntersection(LineSegment2D lineSegment) {
  string str, str1;
  double A1 = GetCoeff(1);
  double A2 = lineSegment.GetCoeff(1);
  double B1 = GetCoeff(2);
  double B2 = lineSegment.GetCoeff(2);
  double C1 = GetCoeff(3);
  double C2 = lineSegment.GetCoeff(3);
  stringstream stream;

  if (A1 * B2 == B1 * A2) {
    if (C2 / C1 == B2 / B1 || C2 / C1 == A2 / A1) {
      str = "The segments are on the same line";
      return str;
    } else {
      str = "Segments are parallel";
      return str;
    }
  } else {
    double coord_X = (-1) * (C1 * B2 - C2 * B1) / (A1 * B2 - B1 * A2);
    double coord_Y = (-1) * (A1 * C2 - A2 * C1) / (A1 * B2 - A2 * B1);

    if (BelongingToSegment(lineSegment)) {
      str = "Intersection point: (";
      stream << coord_X << ";" << coord_Y << ")";
      stream >> str1;
      str = str + str1;
    } else {
      str = "Segments do not intersect";
    }
    return str;
  }
}

bool LineSegment2D::BelongingToSegment(LineSegment2D segment) {
  if (GetCoord(1) <= segment.GetCoord(3) &&
      segment.GetCoord(3) <= GetCoord(3))
      return true;
  if (GetCoord(1) <= segment.GetCoord(1) &&
      segment.GetCoord(1) <= GetCoord(3))
      return true;
  return false;
}
