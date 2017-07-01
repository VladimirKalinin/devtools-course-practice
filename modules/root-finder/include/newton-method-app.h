// Copyright 2017 Maxim Doronin

#ifndef MODULES_ROOT_FINDER_INCLUDE_NEWTON_METHOD_APP_H_
#define MODULES_ROOT_FINDER_INCLUDE_NEWTON_METHOD_APP_H_

#include <string>
#include <vector>

class NewtonMethodApplication {
 public:
    NewtonMethodApplication();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const std::string message = "");
    bool isThereArguments(int argc, const char** argv);
    float getAccuracy(int argc, const char** argv);
    std::vector<float> getBounds(int argc, const char** argv);
    std::vector<float> getKoefs(int argc, const char** argv);
    float parseFloat(const char* arg);
    std::string message_;
};

#endif  // MODULES_ROOT_FINDER_INCLUDE_NEWTON_METHOD_APP_H_
