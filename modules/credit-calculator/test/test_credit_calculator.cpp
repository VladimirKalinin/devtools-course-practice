// Copyright 2017 Simonyan Vaginak

#include <gtest/gtest.h>

#include "include/credit_calculator.h"

TEST(Simonyan_Vaginak_CreditCalculator, Get_Monthly_Payment) {
    // Arrange
    int amount = 300000;
    int period = 12;
    double inter = 22;
    double result;
    double moth_pay = 28078.3;
    double month_error = 0.01;

    // Act
    result = CreditCalculator::MonthlyPayment(amount, period, inter);

    // Assert
    EXPECT_NEAR(moth_pay, result, period*month_error);
}

TEST(Simonyan_Vaginak_CreditCalculator,
    Get_Monthly_Payment_With_Incorrect_Param) {
    // Arrange
    int amount = -300000;
    int period = 12;
    double inter = 150;

    // Act+Assert
    ASSERT_ANY_THROW(CreditCalculator::MonthlyPayment(amount, period, inter));
}

TEST(Simonyan_Vaginak_CreditCalculator,
    Get_Monthly_Payment_With_Low_Inter) {
    // Arrange
    int amount = 300000;
    int period = 12;
    double inter = 1e-15;

    // Act+Assert
    ASSERT_ANY_THROW(CreditCalculator::MonthlyPayment(amount, period, inter));
}

TEST(Simonyan_Vaginak_CreditCalculator, Get_Total_Payout) {
    // Arrange
    int amount = 300000;
    int period = 12;
    double inter = 22;
    double result;
    double payout = 336939.7;
    double month_error = 0.01;

    // Act
    result = CreditCalculator::TotalPayout(amount, period, inter);

    // Assert
    EXPECT_NEAR(payout, result, period*month_error);
}

TEST(Simonyan_Vaginak_CreditCalculator,
    Get_Total_Payout_With_Incorrect_Parameters) {
    // Arrange
    int amount = 300000;
    int period = -12;
    double inter = 22;

    // Act+Assert
    ASSERT_ANY_THROW(CreditCalculator::TotalPayout(amount, period, inter));
}

TEST(Simonyan_Vaginak_CreditCalculator, Get_Overpayment_Amount) {
    // Arrange
    int amount = 300000;
    int period = 12;
    double inter = 22;
    double result;
    double overpay = 36939.7;
    double month_error = 0.01;

    // Act
    result = CreditCalculator::OverpaymentAmount(amount, period, inter);

    // Assert
    EXPECT_NEAR(overpay, result, period*month_error);
}

TEST(Simonyan_Vaginak_CreditCalculator,
    Get_Overpayment_Amount_With_Incorrect_Parameters) {
    // Arrange
    int amount = 300000;
    int period = -12;
    double inter = 22;

    // Act+Assert
    ASSERT_ANY_THROW(CreditCalculator::OverpaymentAmount(amount,
        period, inter));
}

TEST(Simonyan_Vaginak_CreditCalculator, Check_Balance) {
    // Arrange
    int amount = 300000;
    int period = 12;
    int month_pas = 5;
    double inter = 22;
    double result;
    double balance = 196548.1;
    double month_error = 0.01;

    // Act
    result = CreditCalculator::CheckBalance(amount, period, inter, month_pas);

    // Assert
    EXPECT_NEAR(balance, result, period*month_error);
}

TEST(Simonyan_Vaginak_CreditCalculator,
    Check_Balance_With_Incorrect_Parameters) {
    // Arrange
    int amount = 300000;
    int period = 12;
    int month_pas = 15;
    double inter = 22;

    // Act+Assert
    ASSERT_ANY_THROW(CreditCalculator::CheckBalance(amount, period,
        inter, month_pas));
}

TEST(Simonyan_Vaginak_CreditCalculator,
    Check_Balance_With_Incorrect_Interest) {
    // Arrange
    int amount = 300000;
    int period = 12;
    int month_pas = 5;
    double inter = -110;

    // Act+Assert
    ASSERT_ANY_THROW(CreditCalculator::CheckBalance(amount, period,
        inter, month_pas));
}
