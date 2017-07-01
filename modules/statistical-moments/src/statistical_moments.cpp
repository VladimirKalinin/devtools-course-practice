// Copyright 2017 Olga Kiseleva

#include "include/statistical_moments.h"
#include <cmath>
#include <iostream>
#include <limits>
#include <stdexcept>
#include <vector>

bool StatisticalMoments::IsChanceValid(const std::vector<double>& values,
    const std::vector<double>& chances) {
    for (unsigned int i = 0; i < chances.size(); i++) {
        if ((chances[i] < 0) || (chances[i] > 1))
            return false;
    }
    return true;
}

bool StatisticalMoments::IsChancesDistributionRow(
    const std::vector<double>& values, const std::vector<double>& chances) {
    double tmp_sum = 0;
    for (unsigned int i = 0; i < chances.size(); i++) {
        tmp_sum += chances[i];
    }
    return std::fabs(tmp_sum-1)<std::numeric_limits<double>::epsilon();
}

void StatisticalMoments::CheckingInputData(const std::vector<double>& values,
    const std::vector<double>& chances) {
    if (values.empty() && chances.empty()) {
        throw std::runtime_error("Both vectors are empty");
    }
    if (values.empty()) {
        throw std::runtime_error("vector \"values\" is empty");
    }
    if (chances.empty()) {
        throw std::runtime_error("vector \"chances\" is empty");
    }
    if (chances.size() != values.size()) {
        throw std::runtime_error("values and chances must have equal size");
    }
    if (!IsChanceValid(values, chances)) {
        throw std::runtime_error("One of chances is out of range [0,1]");
    }
    if (!IsChancesDistributionRow(values, chances)) {
        throw std::runtime_error("sum of chances isn't equal 1");
    }
}

double StatisticalMoments::GetCustomMoment(const std::vector<double>& values,
    const std::vector<double>& chances, unsigned int order,
    unsigned int offset) {
    CheckingInputData(values, chances);
    double moment = 0;
    if (order == 0) {
        throw std::runtime_error("Order must be more than zero");
    }
    for (unsigned int i = 0; i < chances.size(); i++) {
        moment += pow(values[i] - offset, order)*chances[i];
    }
    return moment;
}
double StatisticalMoments::GetExpectancy(const std::vector<double>& values,
    const std::vector<double>& chances) {
    CheckingInputData(values, chances);
    double expectansy = 0;
    for (unsigned int i = 0; i < chances.size(); i++) {
        expectansy += values[i] * chances[i];
    }
    return expectansy;
}
double StatisticalMoments::GetDispersion(const std::vector<double>& values,
    const std::vector<double>& chances) {
    CheckingInputData(values, chances);
    double expectansy = StatisticalMoments::GetExpectancy(values, chances);
    double dispersion = 0;
    for (unsigned int i = 0; i < chances.size(); i++) {
        dispersion += pow(values[i] - expectansy, 2)*chances[i];
    }
    return dispersion;
}

