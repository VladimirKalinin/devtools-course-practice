// Copyright 2017 Mitrokhin Nikita

#ifndef MODULES_DICHOTOMY_METHOD_INCLUDE_DICHOTOMYAPP_H_
#define MODULES_DICHOTOMY_METHOD_INCLUDE_DICHOTOMYAPP_H_

#include <string>


class DichotomyApp {
 public:
    DichotomyApp();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberofArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double left_border_;
        double right_border_;
        double eps_;
        int func_;
    } Arguments;
};

#endif  // MODULES_DICHOTOMY_METHOD_INCLUDE_DICHOTOMYAPP_H_
