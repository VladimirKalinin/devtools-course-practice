// Copyright 2017 Maxim Doronin

#ifndef MODULES_ROOT_FINDER_INCLUDE_FUNCTION_FACTORY_H_
#define MODULES_ROOT_FINDER_INCLUDE_FUNCTION_FACTORY_H_

#include <string>
#include <map>
#include <vector>
#include "include/functions.h"

std::map<std::string, int> FunctionId {
    std::make_pair("POLINOMIAL_2_DEGREE", 0),
    std::make_pair("POLINOMIAL_3_DEGREE", 1),
    std::make_pair("POLINOMIAL_4_DEGREE", 2),
    std::make_pair("EXPONENT", 3)
};

class FunctionFactory {
 public:
     static Function* CreateFunction(std::string functionName,
         std::vector<float> koefs) {
             Function *function;
             switch (FunctionId[functionName]) {
                 case 0: function = new Polynomial2Degree(koefs); break;
                 case 1: function = new Polynomial3Degree(koefs); break;
                 case 2: function = new Polynomial4Degree(koefs); break;
                 case 3: function = new Exponent(koefs); break;
             }
             return function;
         }
};

#endif  // MODULES_ROOT_FINDER_INCLUDE_FUNCTION_FACTORY_H_
