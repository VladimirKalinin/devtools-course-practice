// Copyright 2017 Simonyan Vaginak

#ifndef MODULES_WEIGHT_CONVERTER_INCLUDE_WEIGHT_CONVERTER_APP_H_
#define MODULES_WEIGHT_CONVERTER_INCLUDE_WEIGHT_CONVERTER_APP_H_

#include <map>
#include <string>

class Application {
 public:
    Application();
    std::string operator()(int argc, const char** argv);

 private:
    void Help(const char* appname, const char* message = "");
    bool ValidateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double weight;
        char type_from;
        char type_to;
    } Arguments;
};

#endif  // MODULES_WEIGHT_CONVERTER_INCLUDE_WEIGHT_CONVERTER_APP_H_
