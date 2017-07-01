// Copyright 2017 Pletnev Nikita

#ifndef MODULES_LINE_PLANE_INTERSEC_INCLUDE_LINE_PLANE_INTERSEC_APP_H_
#define MODULES_LINE_PLANE_INTERSEC_INCLUDE_LINE_PLANE_INTERSEC_APP_H_

#include <string>

class Application {
 public:
    Application();
    std::string operator()(int argc, const char** argv);

 private:
    void Help(const char* appname, const char* message = "");
    bool ValidateNumberOfArguments(int argc, const char** argv);
    std::string message_;
};

#endif  // MODULES_LINE_PLANE_INTERSEC_INCLUDE_LINE_PLANE_INTERSEC_APP_H_
