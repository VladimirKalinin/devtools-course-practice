// Copyright 2017 Kulygina Julia, Zhorin Sergey

#define _USE_MATH_DEFINES
#include "include/calculator.h"
#include <cmath>
#include <string>

Calculator::Calculator() {
    S_ = 0;
}

bool Calculator::Is_Positive_Parameter(double a) {
    if (a <= 0)
        return false;
    else
        return true;
}

bool Calculator::Check_Positives(double massive_parameters[], int size) {
    for (int i = 0; i < size; i++) {
        if (!(Is_Positive_Parameter(massive_parameters[i]))) {
            throw std::string("Parameters are negative");
            return false;
        }
    }

    return true;
}

bool Calculator::Check_For_Heron(double a, double b, double c) {
    if ((a + b >= c) && (b + c >= a) && (a + c >= b))
        return true;
    else
        return false;
}

double Calculator::Calc_Heron(double a, double b, double c) {
    double heronabc;
    if (Check_For_Heron(a, b, c)) {
        double p = (a + b + c) / 2;
        heronabc = sqrt(p* (p - a)*(p - b)*(p - c));
    } else {
        throw std::string("Triangle is not calc");
    }
    return heronabc;
}

double Calculator::Calculate_Sphere(double r) {
    if (Is_Positive_Parameter(r))
        S_ = 4 * M_PI * r * r;
    else
        throw std::string("r <== 0");
    return S_;
}

double Calculator::Calculate_Cone(double r, double l) {
    double *parameters_rl = new double[2];
    parameters_rl[0] = r;
    parameters_rl[1] = l;
    if (Check_Positives(parameters_rl, 2))
        S_ = M_PI * r * l;

    return S_;
}

double Calculator::Calculate_Conoid(double r1, double r2, double l) {
    double *parameters_rlr = new double[3];
    parameters_rlr[0] = r1;
    parameters_rlr[1] = r2;
    parameters_rlr[2] = l;
    if (Check_Positives(parameters_rlr, 3))
        S_ = M_PI * (r1 + r2) * l;

    return S_;
}

double Calculator::Calculate_Cube(double h) {
    if (Is_Positive_Parameter(h))
        S_ = 6 * h * h;
    else
        throw std::string("h <= 0");
    return S_;
}

double Calculator::Calculate_Cylinder(double r, double h) {
    double *parameters_rh = new double[2];
    parameters_rh[0] = r;
    parameters_rh[1] = h;
    if (Check_Positives(parameters_rh, 2))
        S_ = 2 * M_PI * r * h;

    return S_;
}

double Calculator::Calculate_Parallelepiped(double a, double b, double c) {
    double *parameters_abc = new double[3];
    parameters_abc[0] = a;
    parameters_abc[1] = b;
    parameters_abc[2] = c;
    if (Check_Positives(parameters_abc, 3))
        S_ = 2 * (a * b + b * c + a * c);

    return S_;
}

double Calculator::Calculate_Prism(double a, double b, double c, double h) {
    double *parameters_abch = new double[4];
    parameters_abch[0] = a;
    parameters_abch[1] = b;
    parameters_abch[2] = c;
    parameters_abch[3] = h;

    if (Check_Positives(parameters_abch, 4)) {
        double heron_abc = Calc_Heron(a, b, c);
        S_ = 2 * heron_abc + a*h + b*h + a*h;
    }

    return S_;
}

double Calculator::Calculate_Pyramid(double a, double b, double l) {
    double *parameters_abl = new double[3];
    parameters_abl[0] = a;
    parameters_abl[1] = b;
    parameters_abl[2] = l;

    if (Check_Positives(parameters_abl, 3)) {
        double heron_al = Calc_Heron(a, l, l);
        double heron_bl = Calc_Heron(b, l, l);
        S_ = a*b + 2 * heron_al + 2 * heron_bl;
    }

    return S_;
}

double Calculator::Calc_Tetra(double a, double b, double c, double l) {
    double *parameters_abcl = new double[4];
    parameters_abcl[0] = a;
    parameters_abcl[1] = b;
    parameters_abcl[2] = c;
    parameters_abcl[3] = l;

    if (Check_Positives(parameters_abcl, 4)) {
        double heron_al = Calc_Heron(a, l, l);
        double heron_bl = Calc_Heron(b, l, l);
        double heron_abc = Calc_Heron(a, b, c);
        double heron_cl = Calc_Heron(c, l, l);

        S_ = heron_abc + heron_al + heron_bl + heron_cl;
    }

    return S_;
}
