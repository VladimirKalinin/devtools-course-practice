// Copyright 2017 Bakalin Andrey

#ifndef MODULES_MORTGAGE_CALCULATOR_INCLUDE_MORTGAGE_CALCULATOR_H_
#define MODULES_MORTGAGE_CALCULATOR_INCLUDE_MORTGAGE_CALCULATOR_H_

struct CalculatorResult {
    double monthly_payment;
    double overpayment_amount;
    double total_payout;
};

class MortgageCalculator {
 public:
     static CalculatorResult Calculate(double amount,
         int period, double year_interest);
};

#endif  // MODULES_MORTGAGE_CALCULATOR_INCLUDE_MORTGAGE_CALCULATOR_H_
