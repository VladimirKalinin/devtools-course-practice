// Copyright 2017 Fedorov Igor

#ifndef MODULES_ROOT_FINDER_INCLUDE_NEWTON_METHOD_H_
#define MODULES_ROOT_FINDER_INCLUDE_NEWTON_METHOD_H_

#include <string>
#include "include/functions.h"

class NewtonMethod {
 public:
    void SetAB(float a, float b);
    void SetAccuracy(float acc);
    float FindRoot(const Function* const function);
 private:
    float A_;
    float B_;
    float Acc_;
    bool IsMonotone(const Function* const function);
};

#endif  // MODULES_ROOT_FINDER_INCLUDE_NEWTON_METHOD_H_
