// Copyright 2017 Baranov Evgeny

#ifndef MODULES_COLOR_SPACES_INCLUDE_COLORCONVERTER_H_
#define MODULES_COLOR_SPACES_INCLUDE_COLORCONVERTER_H_

#include <stdint.h>
#include <string>

typedef struct {
    uint16_t colorComponent1;
    uint16_t colorComponent2;
    uint16_t colorComponent3;

    uint8_t inType;
    uint8_t outType;
} Arguments;

class ColorConverter {
 public:
    ColorConverter();
    std::string operator()(int argc, const char** argv);

 private:
    void Help(const char* appname, const char* message = "");
    bool ValidateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    Arguments arg_;
};

#endif  // MODULES_COLOR_SPACES_INCLUDE_COLORCONVERTER_H_
