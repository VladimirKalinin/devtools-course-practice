// Copyright 2017 Simonyan Vaginak

#include <math.h>
#include <stdexcept>

#include "include/credit_calculator.h"

bool CreditCalculator::CheckData(int amount, int period,
    double interest, unsigned int month_pas) {
    CheckData(amount, period, interest);
    if (month_pas > (unsigned)period) {
        throw std::runtime_error("Entered month_pas is incorrect");
    }
    return true;
}

bool CreditCalculator::CheckData(int amount, int period,
    double interest) {
    if (amount <= 0 || amount > 10000000) {
        throw std::runtime_error("Entered amount is incorrect");
    }
    if (period <= 0 || period > 240) {
        throw std::runtime_error("Entered period is incorrect");
    }
    if (interest <= 0 || interest > 500) {
        throw std::runtime_error("Entered interest is incorrect");
    }
    return true;
}

double CreditCalculator::MonthlyPayment(int amount, int period,
    double interest) {
    CheckData(amount, period, interest);
    double month_inter = interest / 100 / 12;
    double denominator = (1 - pow(1 + month_inter, -period));
    if (denominator == 0.0) {
        throw std::runtime_error("You have entered an interest rate too low");
    }
    return (amount*(month_inter / denominator));
}

double CreditCalculator::TotalPayout(int amount, int period,
    double interest) {
    CheckData(amount, period, interest);
    return MonthlyPayment(amount, period, interest)*period;
}

double CreditCalculator::OverpaymentAmount(int amount, int period,
    double interest) {
    CheckData(amount, period, interest);
    return TotalPayout(amount, period, interest) - amount;
}

double CreditCalculator::CheckBalance(int amount, int period,
    double interest, int month_pas) {
    CheckData(amount, period, interest, month_pas);
    double paid_out = MonthlyPayment(amount, period, interest)*month_pas;
    return TotalPayout(amount, period, interest) - paid_out;
}
