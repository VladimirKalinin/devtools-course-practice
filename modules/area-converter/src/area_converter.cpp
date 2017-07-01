// Copyright 2017 Kuchkov Ivan

#include <stdexcept>
#include <string>
#include "include/area_converter.h"

namespace {
    static double Square(double x) {
        return x*x;
    }
}

AreaConverter::AreaConverter(double from, double to) {
    if (to <= 0)
        throw std::invalid_argument("to <= 0");
    if (from <= 0)
        throw std::invalid_argument("from <= 0");
    ratio_ = Square(from / to);
}

double AreaConverter::operator()(double x) {
    if (x < 0) {
        throw std::string("It is impossible to work with negative area");
    }

    return x * ratio_;
}
