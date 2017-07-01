// Copyright 2017 Olga Kiseleva

#ifndef MODULES_STATISTICAL_MOMENTS_INCLUDE_STATISTICAL_MOMENTS_H_
#define MODULES_STATISTICAL_MOMENTS_INCLUDE_STATISTICAL_MOMENTS_H_

#include <vector>
#include <string>

class StatisticalMoments {
 public:
    static double GetCustomMoment(const std::vector<double>& values,
        const std::vector<double>& chances, unsigned int order,
        unsigned int offset);
    static double GetExpectancy(const std::vector<double>& values,
        const std::vector<double>& chances);
    static double GetDispersion(const std::vector<double>& values,
        const std::vector<double>& chances);
 private:
    static void CheckingInputData(const std::vector<double>& values,
        const std::vector<double>& chances);
    static bool IsChanceValid(const std::vector<double>& values,
        const std::vector<double>& chances);
    static bool IsChancesDistributionRow(const std::vector<double>& values,
        const std::vector<double>& chances);
};
#endif  // MODULES_STATISTICAL_MOMENTS_INCLUDE_STATISTICAL_MOMENTS_H_
