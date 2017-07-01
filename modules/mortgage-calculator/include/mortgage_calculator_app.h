// Copyright 2017 Grechukhin Nikita

#ifndef MODULES_MORTGAGE_CALCULATOR_INCLUDE_MORTGAGE_CALCULATOR_APP_H_
#define MODULES_MORTGAGE_CALCULATOR_INCLUDE_MORTGAGE_CALCULATOR_APP_H_

#include <string>

class Application {
 public:
    Application();
    std::string operator()(int argc, const char** argv);

 private:
    void Help(const char *appName, const char *message = "");
    bool ValidateNumberOfArguments(int argc, const char **argv);

    std::string message_;
};
#endif  // MODULES_MORTGAGE_CALCULATOR_INCLUDE_MORTGAGE_CALCULATOR_APP_H_
