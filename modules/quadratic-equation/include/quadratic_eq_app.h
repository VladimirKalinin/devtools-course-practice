// Copyright 2017 Kiseleva Olga

#ifndef MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQ_APP_H_
#define MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQ_APP_H_

#include <string>
#include <vector>

class QuadrEquationCalc {
 public:
     QuadrEquationCalc();
    std::string operator()(int argc, const char** argv);

 private:
    void Help(const char* appname, const char* message = "");
    bool ValidateNumberOfArguments(int argc, const char** argv);
    std::string message_;
};
#endif  // MODULES_QUADRATIC_EQUATION_INCLUDE_QUADRATIC_EQ_APP_H_
