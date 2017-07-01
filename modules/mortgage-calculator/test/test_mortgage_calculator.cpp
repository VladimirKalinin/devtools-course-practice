// Copyright 2017 Bakalin Andrey

#include <gtest/gtest.h>

#include "include/mortgage_calculator.h"

TEST(Bakalin_Andrey_MortgageCalculator, Throws_If_Amount_Less_Than_Zero) {
    // Arrange
    double amount = -1000.0;
    int period = 240;
    double year_interest = 10;

    // Act & Assert
    ASSERT_ANY_THROW(MortgageCalculator::Calculate(amount,
        period, year_interest));
}

TEST(Bakalin_Andrey_MortgageCalculator, Throws_If_Amount_Is_Equal_To_Zero) {
    // Arrange
    double amount = 0;
    int period = 240;
    double year_interest = 10;

    // Act & Assert
    ASSERT_ANY_THROW(MortgageCalculator::Calculate(amount,
        period, year_interest));
}

TEST(Bakalin_Andrey_MortgageCalculator,
    Throws_If_Period_Less_Than_Zero) {
    // Arrange
    double amount = 1000000.0;
    int period = -240;
    double year_interest = 10;

    // Act & Assert
    ASSERT_ANY_THROW(MortgageCalculator::Calculate(amount,
        period, year_interest));
}

TEST(Bakalin_Andrey_MortgageCalculator,
    Throws_If_Period_Is_Equal_To_Zero) {
    // Arrange
    double amount = 1000000.0;
    int period = 0;
    double year_interest = 10;

    // Act & Assert
    ASSERT_ANY_THROW(MortgageCalculator::Calculate(amount,
        period, year_interest));
}

TEST(Bakalin_Andrey_MortgageCalculator,
    Throws_If_Period_More_Than_Six_Hundred) {
    // Arrange
    double amount = 1000000.0;
    int period = 601;
    double year_interest = 10;

    // Act & Assert
    ASSERT_ANY_THROW(MortgageCalculator::Calculate(amount,
        period, year_interest));
}

TEST(Bakalin_Andrey_MortgageCalculator, Throws_If_Interest_Less_Than_Zero) {
    // Arrange
    double amount = 1000000.0;
    int period = 240;
    double year_interest = -10;

    // Act & Assert
    ASSERT_ANY_THROW(MortgageCalculator::Calculate(amount,
        period, year_interest));
}

TEST(Bakalin_Andrey_MortgageCalculator, Throws_If_Interest_Is_Equal_To_Zero) {
    // Arrange
    double amount = 1000000.0;
    int period = 240;
    double year_interest = 0;

    // Act & Assert
    ASSERT_ANY_THROW(MortgageCalculator::Calculate(amount,
        period, year_interest));
}

TEST(Bakalin_Andrey_MortgageCalculator,
    Throws_If_Interest_More_Than_Thirty) {
    // Arrange
    double amount = 1000000.0;
    int period = 240;
    double year_interest = 35;

    // Act & Assert
    ASSERT_ANY_THROW(MortgageCalculator::Calculate(amount,
        period, year_interest));
}

TEST(Bakalin_Andrey_MortgageCalculator, Throws_If_Interest_Is_Very_Low) {
    // Arrange
    double amount = 1000000.0;
    int period = 240;
    double year_interest = 1e-20;

    // Act & Assert
    ASSERT_ANY_THROW(MortgageCalculator::Calculate(amount,
        period, year_interest));
}

TEST(Bakalin_Andrey_MortgageCalculator, Can_Get_Monthly_Payment) {
    // Arrange
    double amount = 3000000.0;
    int period = 240;
    double year_interest = 12;
    double right_mothly_payment = 33032.58;
    double error = 0.02;

    // Act
    CalculatorResult result = MortgageCalculator::Calculate(amount,
        period, year_interest);

    // Assert
    EXPECT_NEAR(right_mothly_payment, result.monthly_payment, error);
}

TEST(Bakalin_Andrey_MortgageCalculator, Can_Get_Total_Payout) {
    // Arrange
    double amount = 2500000.0;
    int period = 300;
    double year_interest = 11;
    double right_total_payout = 7350848.07;
    double error = 0.02;

    // Act
    CalculatorResult result = MortgageCalculator::Calculate(amount,
        period, year_interest);

    // Assert
    EXPECT_NEAR(right_total_payout, result.total_payout, error);
}

TEST(Bakalin_Andrey_MortgageCalculator, Can_Get_Overpayment_Amount) {
    // Arrange
    double amount = 4300000.0;
    int period = 120;
    double year_interest = 15;
    double right_overpayment_amount = 4024883.78;
    double error = 0.02;

    // Act
    CalculatorResult result = MortgageCalculator::Calculate(amount,
        period, year_interest);

    // Assert
    EXPECT_NEAR(right_overpayment_amount, result.overpayment_amount,
        error);
}
