// Copyright 2017 Bakalin Andrey

#include "include/mortgage_calculator.h"
#include <stdexcept>
#include <cmath>

CalculatorResult MortgageCalculator::Calculate(double amount,
    int period, double year_interest) {
    if (amount <= 0) {
        throw std::invalid_argument("Amount was entered incorrectly");
    }
    if (period <= 0 || period > 600) {
        throw std::invalid_argument("Period was entered incorrectly");
    }
    if (year_interest <= 0 || year_interest > 30) {
        throw std::invalid_argument("Interest was entered incorrectly");
    }

    CalculatorResult result;
    double month_interest = year_interest / (100 * 12);

    if ((1 - pow(1 + month_interest, -period)) == 0) {
        throw std::invalid_argument("Interest can't be so low");
    } else {
        result.monthly_payment = amount * month_interest /
            (1 - pow(1 + month_interest, -period));
    }
    result.total_payout = result.monthly_payment * period;
    result.overpayment_amount = result.total_payout - amount;

    return result;
}
