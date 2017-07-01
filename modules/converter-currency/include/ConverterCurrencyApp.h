// Copyright 2017 Karev Boris

#ifndef MODULES_CONVERTER_CURRENCY_INCLUDE_CONVERTERCURRENCYAPP_H_
#define MODULES_CONVERTER_CURRENCY_INCLUDE_CONVERTERCURRENCYAPP_H_

#include <string>
#include "include/ConverterCurrency.h"

class ConverterCurrencyApp {
 public:
    ConverterCurrencyApp();
    std::string operator()(int argc, const char** argv);

 private:
    void Help(const char* appname, const char* message = "");
    bool ValidateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        double money_size;
        CurrencyName old_currency;
        CurrencyName new_currency;
        double first_convert_coeff;
        double second_convert_coeff;
    } Arguments;
};

#endif  // MODULES_CONVERTER_CURRENCY_INCLUDE_CONVERTERCURRENCYAPP_H_
