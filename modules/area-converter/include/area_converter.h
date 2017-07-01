// Copyright 2017 Kuchkov Ivan

#ifndef MODULES_AREA_CONVERTER_INCLUDE_AREA_CONVERTER_H_
#define MODULES_AREA_CONVERTER_INCLUDE_AREA_CONVERTER_H_

#include <cmath>

class AreaConverter {
 public:
    static constexpr double kCentimeter = 0.01;
    static constexpr double kDecimeter = 0.1;
    static constexpr double kMeter = 1.0;
    static constexpr double kYard = 0.9144;
    static constexpr double kInch = 0.0254;
    static constexpr double kAcr = 63.614907234075253345955341654644;
    static constexpr double kHectare = 100;

    AreaConverter(double from, double to);
    double operator()(double x);

 private:
    double ratio_;
};

#endif  // MODULES_AREA_CONVERTER_INCLUDE_AREA_CONVERTER_H_
