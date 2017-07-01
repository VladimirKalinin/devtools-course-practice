// Copyright 2017 Kildishev Maxim

#ifndef MODULES_DICHOTOMY_METHOD_INCLUDE_DICHOTOMY_H_
#define MODULES_DICHOTOMY_METHOD_INCLUDE_DICHOTOMY_H_


class Dichotomy{
 public:
     double FindMin(double (*func)(double x),
        double left_border, double right_border, double eps);
 private:
     void EnteredCorrectly(double left_border,
         double right_border, double eps);
};

#endif  // MODULES_DICHOTOMY_METHOD_INCLUDE_DICHOTOMY_H_
