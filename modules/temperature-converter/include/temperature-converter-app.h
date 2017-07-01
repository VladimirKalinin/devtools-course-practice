// Copyright 2017 Kulygina Julia

#ifndef MODULES_TEMPERATURE_CONVERTER_INCLUDE_TEMPERATURE_CONVERTER_APP_H_
#define MODULES_TEMPERATURE_CONVERTER_INCLUDE_TEMPERATURE_CONVERTER_APP_H_

#include <string>

class TemperatureConverterApp {
 public:
     TemperatureConverterApp();
     std::string operator()(int argc, const char** argv);
     ~TemperatureConverterApp();

 private:
     void help(const char* message = "");
     bool validateNumberOfArguments(int argc, const char** argv);
     std::string message_;
     typedef struct {
         char Scale1;
         double number;
         char Scale2;
     } Arguments;
};

#endif  // MODULES_TEMPERATURE_CONVERTER_INCLUDE_TEMPERATURE_CONVERTER_APP_H_
