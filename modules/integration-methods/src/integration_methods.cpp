// Copyright 2017 Grechukhin Nikita

#include "include/integration_methods.h"
#include <string>
#include <cmath>
#include <stdexcept>
#include "include/function_parser.h"

std::string IntegrationMethod::ChangeVariableToValue(
    const std::string &integrand,
    double value) {
    auto result = integrand;
    auto string_format_value = std::to_string(value);
    int size = integrand.size();
    for (int i = 0; i < size; i++) {
        if (result.at(i) == 'x' || result.at(i) == 'X') {
            result.replace(i, 1, string_format_value);
            size = result.size();
        }
    }
    return result;
}

double IntegrationMethod::CalculateFunction(const std::string &integrand) {
    Parser parser;
    return parser.Parse(integrand.c_str()).eval();
}

double IntegrationMethod::RectangleMethod(const std::string &integrand,
    double low_limit,
    double upper_limit, unsigned quantity_of_steps) {
    std::string func_in_low_limit = ChangeVariableToValue(integrand,
        low_limit);
    std::string func_in_upper_limit =
        ChangeVariableToValue(integrand, upper_limit);

    double s = CalculateFunction(func_in_low_limit) +
        CalculateFunction(func_in_upper_limit);
    s /=2;

    double h = (upper_limit - low_limit) / quantity_of_steps;
    for (unsigned i=1; i < quantity_of_steps; i++) {
        double x = low_limit + i*h;
        std::string func = ChangeVariableToValue(integrand, x);
        s += CalculateFunction(func);
    }

    return s*h;
}

double IntegrationMethod::TrapezoidMethod(const std::string &integrand,
    double low_limit,
    double upper_limit, unsigned quantity_of_steps) {
        double result = 0;
        if (quantity_of_steps > 1) {
            double y, dy;
            dy = (upper_limit - low_limit)/quantity_of_steps;
            std::string func_in_low_limit =
                ChangeVariableToValue(integrand, low_limit);
            std::string func_in_upper_limit =
                ChangeVariableToValue(integrand, upper_limit);
            y = CalculateFunction(func_in_low_limit) +
                CalculateFunction(func_in_upper_limit);

            for (unsigned i=1; i < quantity_of_steps; i++) {
                double x = low_limit + dy*i;
                std::string func = ChangeVariableToValue(integrand, x);
                y += 2 * CalculateFunction(func);
            }
            result = (upper_limit - low_limit) / (2*quantity_of_steps)*y;
        }
        return result;
}

double IntegrationMethod::SimpsonMethod(const std::string &integrand,
    double low_limit,
    double upper_limit, double eps) {
        if (eps < 0)
            throw std::runtime_error("Epsilon has negative value");
        double integral = eps + 1;
        double integral1 = 0;
     for (int n=2; (n <= 4) || (fabs(integral1-integral) > eps); n*=2) {
            double h, sum2 = 0, sum4 = 0, sum = 0;
            h = (upper_limit - low_limit)/(2*n);
            for (int i=1; i <= 2*n-1; i+=2) {
                double x1 = low_limit + h*i;
                double x2 = low_limit + h*(i+1);
                std::string func1 = ChangeVariableToValue(integrand, x1);
                std::string func2 = ChangeVariableToValue(integrand, x2);

                sum4 += CalculateFunction(func1);
                sum2 += CalculateFunction(func2);
            }
            std::string func_with_lower_limit =
                ChangeVariableToValue(integrand, low_limit);
            std::string func_with_upper_limit =
                ChangeVariableToValue(integrand, upper_limit);
            sum = CalculateFunction(func_with_lower_limit) + 4 * sum4
                + 2 * sum2 -
                CalculateFunction(func_with_upper_limit);
            integral = integral1;
            integral1 = (h/3)*sum;
        }
    return integral1;
}
