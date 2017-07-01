// Copyright 2017 Simonyan Vaginak

#ifndef MODULES_CREDIT_CALCULATOR_INCLUDE_CREDIT_CALCULATOR_H_
#define MODULES_CREDIT_CALCULATOR_INCLUDE_CREDIT_CALCULATOR_H_

class CreditCalculator {
 public:
  static double OverpaymentAmount(int amount, int period, double interest);
  static double MonthlyPayment(int amount, int period, double interest);
  static double TotalPayout(int amount, int period, double interest);
  static double CheckBalance(int amount, int period,
      double interest, int month_pas);

 private:
  static bool CheckData(int amount, int period, double interest);
  static bool CheckData(int amount, int period,
      double interest, unsigned int month_pas);
};

#endif  // MODULES_CREDIT_CALCULATOR_INCLUDE_CREDIT_CALCULATOR_H_
