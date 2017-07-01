// Copyright 2017 Grechukhin Nikita

#ifndef MODULES_INTEGRATION_METHODS_INCLUDE_INTEGRATION_METHODS_H_
#define MODULES_INTEGRATION_METHODS_INCLUDE_INTEGRATION_METHODS_H_

#include <string>

class IntegrationMethod {
 public:
    double RectangleMethod(const std::string &integrand, double low_limit,
        double upper_limit, unsigned quantity_of_steps);
    double TrapezoidMethod(const std::string &integrand, double low_limit,
        double upper_limit, unsigned quantity_of_steps);
    double SimpsonMethod(const std::string &integrand, double low_limit,
        double upper_limit, double eps);
 private:
     std::string ChangeVariableToValue(const std::string &integrand,
        double value);
     double CalculateFunction(const std::string &integrand);
};

#endif  // MODULES_INTEGRATION_METHODS_INCLUDE_INTEGRATION_METHODS_H_
