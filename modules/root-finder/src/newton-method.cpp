// Copyright 2017 Fedorov Igor

#include "include/newton-method.h"

#include <algorithm>
#include <iostream>
#include <cmath>
#include <string>

void NewtonMethod::SetAB(float a, float b) {
    A_ = a;
    B_ = b;
}

void NewtonMethod::SetAccuracy(float acc) {
    Acc_ = acc;
}

bool NewtonMethod::IsMonotone(const Function* const function) {
    if (A_ > B_) {
        std::swap(A_, B_);
    }
    if (function->f(A_) > function->f(B_)) {
        float i = A_;
        float temp_i = i;
        while (temp_i < B_) {
            if (function->f(i) < function->f(temp_i))
                return false;
            i = temp_i;
            temp_i += Acc_;
            }
    } else if (function->f(A_) < function->f(B_)) {
        float i = A_;
        float temp_i = i;
        while (temp_i < B_) {
            if (function->f(i) > function->f(temp_i))
                return false;
            i = temp_i;
            temp_i += Acc_;
        }
    }
    if (A_ == B_) {
        return false;
    }
    if (function->f(A_) == function->f(B_)) {
        return false;
    }
    return true;
}

float NewtonMethod::FindRoot(const Function* const function) {
    if (IsMonotone(function)) {
        float xn = function->f(A_) * function->d2f(A_) > 0 ? A_ : B_;
        float x1 = xn - function->f(xn) / function->df(xn);
        float x0 = xn;
        float xsum = std::abs(x0 - x1);
        while (xsum > Acc_) {
            if (x1 < A_ || x1 > B_)
                throw std::string("There are no roots on the segment");
            x0 = x1;
            x1 = x1 - function->f(x1) / function->df(x1);
            xsum = std::abs(x0 - x1);
        }
        return x1;
    } else {
        throw std::string("Function is not monotone or it is a point");
    }
}
