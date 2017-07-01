// Copyright 2017 Lobanov Andrey

#ifndef MODULES_INTERSECTTWOLINE_INCLUDE_LINESEGMENT_H_
#define MODULES_INTERSECTTWOLINE_INCLUDE_LINESEGMENT_H_

#include <string>
#include <sstream>

using std::string;

class LineSegment2D {
 public:
  LineSegment2D(double X1, double Y1, double X2, double Y2);

  LineSegment2D() : X1_(0), X2_(0), Y1_(0), Y2_(0) {}

  void SetX1(double X) {
    X1_ = X;
  }
  void SetX2(double X) {
    X2_ = X;
  }
  void SetY1(double Y) {
    Y1_ = Y;
  }
  void SetY2(double Y) {
    Y2_ = Y;
  }

  double GetCoord(int count);

  double GetCoeff(int count);

  string CheckIntersection(LineSegment2D lineSegment);
  bool BelongingToSegment(LineSegment2D segment);

 protected:
  double X1_;
  double X2_;
  double Y1_;
  double Y2_;
};
#endif  // MODULES_INTERSECTTWOLINE_INCLUDE_LINESEGMENT_H_
