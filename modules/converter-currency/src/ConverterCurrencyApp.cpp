// Copyright 2017 Karev Boris

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

#include "include/ConverterCurrencyApp.h"
#include "include/ConverterCurrency.h"

ConverterCurrencyApp::ConverterCurrencyApp() : message_("") {}

void ConverterCurrencyApp::Help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a converter currency application.\n\n" +
        "Please provide arguments in the following format:\n\n" +

        "  $ " + appname + " <money size> <old currency> " +
        "<new currency> <exchange rate to the RUR of the old currency> " +
        "<exchange rate to the RUR of the new currency>\n\n" +

        "Where 1, 4 and 5 arguments is double-precision nonnegative number," +
        " 2 and 3 arguments is one of type of currency: " +
        "BYN, CNY, CZK, EUR, GBP, KZT, RUR, USD, UAH, JPY, KRW. " +
        "Names were taken from svali.ru / currency / index.htm" +
        "4 and 5 arguments are exchange rates for RUR, " +
        "they use, because the course changes with time " +
        "If selected meaning '0'- zero, for 4 or 5 argument " +
        "will use default meaning of convert coefficient\n";
}

bool ConverterCurrencyApp::ValidateNumberOfArguments
(int argc, const char** argv) {
    if (argc == 1) {
        Help(argv[0]);
        return false;
    } else if (argc != 6) {
        Help(argv[0], "ERROR: Should be 5 arguments.\n\n");
        return false;
    }
    return true;
}

double ParseDouble(const char* arg) {
    char* end;
    double value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }
    return value;
}

CurrencyName ParseCurrency(const char* arg) {
    CurrencyName currency;
    if (strcmp(arg, "BYN") == 0) {
        currency = BYN;
    } else if (strcmp(arg, "CNY") == 0) {
        currency = CNY;
    } else if (strcmp(arg, "CZK") == 0) {
        currency = CZK;
    } else if (strcmp(arg, "EUR") == 0) {
        currency = EUR;
    } else if (strcmp(arg, "GBP") == 0) {
        currency = GBP;
    } else if (strcmp(arg, "KZT") == 0) {
        currency = KZT;
    } else if (strcmp(arg, "RUR") == 0) {
        currency = RUR;
    } else if (strcmp(arg, "USD") == 0) {
        currency = USD;
    } else if (strcmp(arg, "UAH") == 0) {
        currency = UAH;
    } else if (strcmp(arg, "JPY") == 0) {
        currency = JPY;
    } else if (strcmp(arg, "KRW") == 0) {
        currency = KRW;
    } else {
        throw std::string("Wrong currency format!");
    }
    return currency;
}

std::string ConverterCurrencyApp::operator()(int argc, const char** argv) {
    Arguments args;
    if (!ValidateNumberOfArguments(argc, argv)) {
        return message_;
    }

    try {
        args.old_currency = ParseCurrency(argv[2]);
        args.new_currency = ParseCurrency(argv[3]);
        args.money_size = ParseDouble(argv[1]);
        args.first_convert_coeff = ParseDouble(argv[4]);
        args.second_convert_coeff = ParseDouble(argv[5]);
    }
    catch(std::string& str) {
        return str;
    }

    std::ostringstream stream;

    if (args.first_convert_coeff != 0) {
        try {
            ConverterCurrency::SetExchangeRateToRUR(args.old_currency,
                args.first_convert_coeff);
        } catch (std::string& str) {
            return str;
        }
    }

    if (args.second_convert_coeff != 0) {
        try {
            ConverterCurrency::SetExchangeRateToRUR(args.new_currency,
                args.second_convert_coeff);
        } catch (std::string& str) {
            return str;
        }
    }

    try {
        double result;
        result = ConverterCurrency::Convert(args.money_size,
            args.old_currency, args.new_currency);
        stream << "Result of convertation = " << result;
    } catch (std::string& str) {
        return str;
    }

    message_ = stream.str();

    return message_;
}
