// Copyright 2017 Dmitrichev Nikita

#ifndef MODULES_CONVERTER_CURRENCY_INCLUDE_CONVERTERCURRENCY_H_
#define MODULES_CONVERTER_CURRENCY_INCLUDE_CONVERTERCURRENCY_H_

#include <vector>

// Names were taken from "svali.ru/currency/index.htm"
enum CurrencyName { BYN, CNY, CZK, EUR, GBP, KZT, RUR, USD, UAH, JPY, KRW};

class ConverterCurrency {
 public:
    static double Convert(double money_size, CurrencyName old_currency,
        CurrencyName new_currency);
    static void SetExchangeRateToRUR(CurrencyName target_currency,
        double exchange_rate_to_rur);
 private:
     static std::vector<double> convert_coefficients_;
};

#endif  // MODULES_CONVERTER_CURRENCY_INCLUDE_CONVERTERCURRENCY_H_
