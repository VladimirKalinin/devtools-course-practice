// Copyright 2017 Kulygina Julia, Zhorin Sergey

#ifndef MODULES_AREA_OF_THREE_DIMENSIONAL_FIGURES_INCLUDE_CALCULATOR_H_
#define MODULES_AREA_OF_THREE_DIMENSIONAL_FIGURES_INCLUDE_CALCULATOR_H_
#define _USE_MATH_DEFINES

#include <cmath>
#include <string>

class Calculator {
 public:
     Calculator();

     double Calculate_Sphere(double r);
     double Calculate_Cone(double r, double l);
     double Calculate_Conoid(double r1, double r2, double l);
     double Calculate_Cube(double h);
     double Calculate_Cylinder(double r, double h);
     double Calculate_Parallelepiped(double a, double b, double c);
     double Calculate_Prism(double a, double b, double c, double h);
     double Calculate_Pyramid(double a, double b, double l);
     double Calc_Tetra(double a, double b, double c, double l);

 private:
     double S_;

     bool Is_Positive_Parameter(double a);
     bool Check_For_Heron(double a, double b, double c);
     bool Check_Positives(double massive_parameters[], int size);
     double Calc_Heron(double a, double b, double c);
};

#endif  // MODULES_AREA_OF_THREE_DIMENSIONAL_FIGURES_INCLUDE_CALCULATOR_H_
