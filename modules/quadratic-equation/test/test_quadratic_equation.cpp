// Copyright 2017 Pletnev Nikita

#include <gtest/gtest.h>
#include <string>
#include <vector>
#include "include/quadratic_equation.h"


TEST(Pletnev_Nikita_QuadraticEquationTest, Can_Create_Quadratic_Equation) {
    QuadraticEquation e;

    EXPECT_EQ(1, e.GetCoefA());
    EXPECT_EQ(0, e.GetCoefB());
    EXPECT_EQ(0, e.GetCoefC());
}

TEST(Pletnev_Nikita_QuadraticEquationTest, Create_Equat_With_Coefficients) {
    QuadraticEquation e(2.1, 0.0, 4.8);

    EXPECT_DOUBLE_EQ(2.1, e.GetCoefA());
    EXPECT_DOUBLE_EQ(0.0, e.GetCoefB());
    EXPECT_DOUBLE_EQ(4.8, e.GetCoefC());
}

TEST(Pletnev_Nikita_QuadraticEquationTest, Cant_Create_Coef_A_As_0) {
    EXPECT_THROW(QuadraticEquation e(0.0, 0.0, 4.8), std::string);
}

TEST(Pletnev_Nikita_QuadraticEquationTest, Cant_Set_Coef_A_As_0) {
    QuadraticEquation e(2.1, 0.0, 4.8);

    EXPECT_THROW(e.SetCoefA(0), std::string);
}

TEST(Pletnev_Nikita_QuadraticEquationTest, Can_Set_Coefficients) {
    QuadraticEquation e(2.1, 0.0, 4.8);

    e.SetCoefficients(3, 7, 1);

    EXPECT_DOUBLE_EQ(3, e.GetCoefA());
    EXPECT_DOUBLE_EQ(7, e.GetCoefB());
    EXPECT_DOUBLE_EQ(1, e.GetCoefC());
}

TEST(Pletnev_Nikita_QuadraticEquationTest, Can_Get_Coefficients) {
    QuadraticEquation e(2.1, 0.0, 4.8);

    std::vector<double> coefs(e.GetCoefficients());

    EXPECT_DOUBLE_EQ(coefs[0], e.GetCoefA());
    EXPECT_DOUBLE_EQ(coefs[1], e.GetCoefB());
    EXPECT_DOUBLE_EQ(coefs[2], e.GetCoefC());
}

TEST(Pletnev_Nikita_QuadraticEquationTest, Number_Of_Real_Solutions_Is_1) {
    QuadraticEquation e(2.1, 0, 0);

    EXPECT_EQ(1, e.NumOfRealSolutions());
}

TEST(Pletnev_Nikita_QuadraticEquationTest, Number_Of_Real_Solutions_Is_0) {
    QuadraticEquation e(20.5, 1, 3);

    EXPECT_EQ(0, e.NumOfRealSolutions());
}

TEST(Pletnev_Nikita_QuadraticEquationTest, Number_Of_Real_Solutions_Is_2) {
    QuadraticEquation e(2, 10.53, 3);

    EXPECT_EQ(2, e.NumOfRealSolutions());
}

TEST(Pletnev_Nikita_QuadraticEquationTest, Can_Get_1_Real_Solution) {
    QuadraticEquation e(1, 4, 4);

    EXPECT_DOUBLE_EQ(-2, e.GetRealX2());
    EXPECT_DOUBLE_EQ(e.GetRealX1(), e.GetRealX2());
}

TEST(Pletnev_Nikita_QuadraticEquationTest, Can_Get_2_Real_Solutions) {
    QuadraticEquation e(1, 0.7, -2.94);

    EXPECT_DOUBLE_EQ(1.4, e.GetRealX1());
    EXPECT_DOUBLE_EQ(-2.1, e.GetRealX2());
}

TEST(Pletnev_Nikita_QuadraticEquationTest, Can_Get_Complex_Solutions) {
    QuadraticEquation e(1, 2, 5);

    ComplexNumber x1 = e.GetComplexX1();
    ComplexNumber x2 = e.GetComplexX2();

    EXPECT_DOUBLE_EQ(-1, x1.getRe());
    EXPECT_DOUBLE_EQ(2, x1.getIm());
    EXPECT_DOUBLE_EQ(-1, x2.getRe());
    EXPECT_DOUBLE_EQ(-2, x2.getIm());
}

TEST(Pletnev_Nikita_QuadraticEquationTest, 2_Real_Solutions_As_Complex_Num) {
    QuadraticEquation e(1, 0.7, -2.94);

    ComplexNumber x1 = e.GetComplexX1();
    ComplexNumber x2 = e.GetComplexX2();

    EXPECT_DOUBLE_EQ(1.4, x1.getRe());
    EXPECT_DOUBLE_EQ(0, x1.getIm());
    EXPECT_DOUBLE_EQ(-2.1, x2.getRe());
    EXPECT_DOUBLE_EQ(0, x2.getIm());
}

TEST(Pletnev_Nikita_QuadraticEquationTest, Get_Real_Part_Of_Compl_Solutions) {
    QuadraticEquation e(1, 2, 5);

    EXPECT_DOUBLE_EQ(-1, e.GetRealX1());
    EXPECT_DOUBLE_EQ(-1, e.GetRealX2());
}
