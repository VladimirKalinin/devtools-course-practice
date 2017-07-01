// Copyright 2017 Alexander Gaivanuk

#include "include/statistical_calculator.h"
#include <iostream>

int main(int argc, char **argv) {
    StatisticalCalculator app;
    std::cout << app(argc, argv) << std::endl;
    return 0;
}
