// Copyright 2017 Komarov Nikolay

#ifndef MODULES_INTEGRATION_METHODS_INCLUDE_INTEGRATION_METHODS_APP_H_
#define MODULES_INTEGRATION_METHODS_INCLUDE_INTEGRATION_METHODS_APP_H_

#include <string>

class Application {
 public:
    Application();
    std::string operator()(int argc, const char** argv);

 private:
    void Help(const char* appname, const char* message = "");
    bool ValidateNumberOfArguments(int argc, const char** argv);
    bool ValidateOperationName(const char *arg);
    double ParseDouble(const char* arg);
    int ParseInteger(const char* arg);
    std::string message_;
    typedef struct {
        std::string integrand;
        double low_limit;
        double upper_limit;
        const char* method_name;
        int quantity_of_steps;
        double epsilon;
    } Arguments;
};

#endif  // MODULES_INTEGRATION_METHODS_INCLUDE_INTEGRATION_METHODS_APP_H_
