// Copyright 2017 Dmitrichev Nikita

#include <vector>
#include <string>
#include "include/ConverterCurrency.h"

std::vector<double> ConverterCurrency::convert_coefficients_ = {
    30.84,  // BYN to RUR
    8.413,  // CNY to RUR
    2.368,  // CZK to RUR
    63.26,  // EUR to RUR
    75.41,  // GBP to RUR
    0.1824,  // KZT to RUR
    1.0,  // RUR to RUR
    58.08,  // USD to RUR
    2.194,  // UAH to RUR
    0.521197,  // JPY to RUR
    0.05118,  // KRW to RUR
};

void ConverterCurrency::SetExchangeRateToRUR(CurrencyName target_currency,
    double exchange_rate_to_rur) {
    if (exchange_rate_to_rur > 0) {
        if (target_currency != RUR)
            convert_coefficients_[target_currency] = exchange_rate_to_rur;
    } else {
        throw std::string("Convert coefficient has to be more than 0");
    }
}

double ConverterCurrency::Convert(double money_size,
                          CurrencyName old_currency,
                          CurrencyName new_currency) {
    if (money_size >= 0) {
        double result_money_size;

        if (money_size == 0) {
            result_money_size = 0;
        } else if (old_currency == new_currency) {
            result_money_size = money_size;
        } else {
            result_money_size = money_size * convert_coefficients_[old_currency]
                / convert_coefficients_[new_currency];
        }

        return result_money_size;
    } else {
        throw std::string("Money size can't be negative");
    }
}
