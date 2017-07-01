// Copyright 2017 Alexander Gaivanuk

#ifndef MODULES_STATISTICAL_MOMENTS_INCLUDE_STATISTICAL_CALCULATOR_H_
#define MODULES_STATISTICAL_MOMENTS_INCLUDE_STATISTICAL_CALCULATOR_H_

#include <string>
#include <vector>

class StatisticalCalculator {
 public:
    StatisticalCalculator() { }
    std::string operator()(int argc, const char *const *argv) const;
 private:
     static const char *help_message_;
     static unsigned ParseInt(const char *s);
     static bool TryParseDouble(const char *s, double *value);
     static int ParseList(int argc, const char *const *argv,
         int cur_arg, std::vector<double> *list);
};

#endif  // MODULES_STATISTICAL_MOMENTS_INCLUDE_STATISTICAL_CALCULATOR_H_
