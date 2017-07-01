// Copyright Kildishev Maxim 2017

#include <include/dichotomy.h>
#include <cmath>
#include <iostream>

void Dichotomy::EnteredCorrectly(double left_border,
     double right_border, double eps) {
         if (right_border < left_border)
             throw "Incorrect borders";
         if (std::abs(right_border-left_border) < 0.0001)
             throw "Too close values";
         if (eps <=0)
             throw "Eps must be higher then zero";
}

double Dichotomy::FindMin(double(*func)(double x), double left_border,
    double right_border, double eps) {
    EnteredCorrectly(left_border, right_border, eps);
    double middle = (left_border + right_border)/2;
    double func_value_middle = func(middle);
    while (right_border - left_border > eps) {
        double x = (left_border + middle)/2;
        double func_value_x = func(x);
        double y = (middle + right_border)/2;
        double func_value_y = func(y);
        if ((func_value_x < func_value_y) &&
         (func_value_x < func_value_middle)) {
                right_border = middle;
                middle = x;
                func_value_middle = func_value_x;
            } else if ( (func_value_middle < func_value_x)
            && (func_value_middle < func_value_y) ) {
                left_border = x;
                right_border = y;
            } else {
                left_border = middle;
                middle = y;
                func_value_middle = func_value_y;
            }
        //Поскольку метод дихотомии должен вернуть отрезок, на котором
        //должен находиться минимум, возьмём за оценку решения его середину
    }
    return (left_border + right_border) / 2;
}
