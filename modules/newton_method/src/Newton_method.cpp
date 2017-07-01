// Copyright 2017 Dmitry Dryakhlov

#define _USE_MATH_DEFINES

#include "../include/Newton_method.h"
#include <stdlib.h>
#include <ctime>
#include <cmath>

double NewtonMethod::NewtonMethodPolynom(unsigned int size,
                                                double *polynom_coef) {
    if (size == 0)
        throw "polynom is const";
    double x = 0, x1 = 1;
    double *polynom_derivative_coef = new double[size - 1];
    CalculateDerivativePolynom(size - 1, polynom_coef,
                                               polynom_derivative_coef);
    int iter = 0;
    while (fabs(x1 - x) >= 0.001 && iter < 1000) {
        iter++;
        x = x1;
        if (iter == 999)
        throw "no roots";
        double fx = PolynomValue(size, x, polynom_coef);
        double dfx = PolynomValue(size - 1, x, polynom_derivative_coef);
        x1 = x - (fx / dfx);
    }
    delete[]polynom_derivative_coef;
     return x;
}

double NewtonMethod::NewtonMethodFunction(double eps) {
    if (eps <= 0.0) {
        throw "eps <= 0";
    }
    double x = 0.0, x1 = 1.0;
    while (fabs(x1 - x) >= eps) {
        x = x1;
        double fx = FunctionValue(x);
        double fx1 = FirstDerivativeFunctionValue(x);
        x1 = x - (fx / fx1);
    }
    return x;
}

void NewtonMethod::GeneateRandomPolynom(unsigned int size,
                                                    double *polynom_coef) {
    for (unsigned int i = 0; i < size; i++) {
        polynom_coef[i] = static_cast<double>(i)*7.0;
    }
}

bool NewtonMethod::CheckRootPolynom(double x, double eps, unsigned int size,
                                                   const double *coef) {
    return fabs(PolynomValue(size, x, coef)) < eps;
}

bool NewtonMethod::CheckRootFunction(double x, double eps) {
    return fabs(FunctionValue(x)) < eps;
}

double NewtonMethod::PolynomValue(unsigned int size, double x,
                                                   const double * coef) {
    double sum = 0.0;
    for (unsigned int k = 0; k < size; k++) {
        sum += (coef[k] * pow(x, k));
    }
    return sum;
}

void NewtonMethod::CalculateDerivativePolynom(unsigned int size,
    const double * polynom_coef, double * polynom_derivative_coef) {
    for (int unsigned i = 0; i < size; i++) {
        polynom_derivative_coef[i] = (i + 1) * polynom_coef[i + 1];
    }
}

double NewtonMethod::FunctionValue(double x) {
    return 3.0*x + sin(x) - pow(M_E, x);
}

double NewtonMethod::FirstDerivativeFunctionValue(double x) {
    return 3.0 - cos(x) - pow(M_E, x);
}
