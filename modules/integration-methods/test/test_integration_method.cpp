// Copyright 2017 Grechukhin Nikita

#include <gtest/gtest.h>

#include "include/integration_methods.h"
#include "include/function_parser.h"

TEST(INTEGRATION_METHOD, can_integrate_simple_function_by_rectangle_method) {
    IntegrationMethod im;
    double actual = im.RectangleMethod("x", 0, 1, 50);
    double expected = 0.5;
    EXPECT_NEAR(expected, actual, 1e-2);
}

TEST(INTEGRATION_METHOD, can_integrate_const_by_rectangle_method) {
    IntegrationMethod im;
    double actual = im.RectangleMethod("2", 0, 2, 50);
    double expected = 4;
    EXPECT_NEAR(expected, actual, 1e-2);
}

TEST(INTEGRATION_METHOD, can_integrate_function_by_rectangle_method) {
    IntegrationMethod im;
    double actual = im.RectangleMethod("x*x*x*x", 0, 1, 50);
    double expected = 0.2;

    EXPECT_NEAR(expected, actual, 1e-2);
}

TEST(INTEGRATION_METHOD, can_integrate_function_with_cos_by_rectangle_method) {
    IntegrationMethod im;
    double actual = im.RectangleMethod("x*x + 4*cos(x)", 0, 1, 50);
    double expected = 3.6992;

    EXPECT_NEAR(expected, actual, 1e-2);
}


TEST(INTEGRATION_METHOD, can_integrate_simple_function_by_trapezoid_method) {
    IntegrationMethod im;
    double actual = im.TrapezoidMethod("x", 0, 1, 50);
    double expected = 0.5;
    EXPECT_NEAR(expected, actual, 1e-2);
}

TEST(INTEGRATION_METHOD, can_integrate_const_by_trapezoid_method) {
    IntegrationMethod im;
    double actual = im.TrapezoidMethod("5", 1, 3, 50);
    double expected = 10;
    EXPECT_NEAR(expected, actual, 1e-2);
}

TEST(INTEGRATION_METHOD, can_integrate_function_by_trapezoid_method) {
    IntegrationMethod im;
    double actual = im.TrapezoidMethod("x*x*x", 1, 4, 150);
    double expected = (0.25)*(255);

    EXPECT_NEAR(expected, actual, 1e-2);
}

TEST(INTEGRATION_METHOD, can_integrate_function_with_sin_by_trapezoid_method) {
    IntegrationMethod im;
    double actual = im.TrapezoidMethod("x*sin(x)", 1, 4, 150);
    double expected = 1.5566;

    EXPECT_NEAR(expected, actual, 1e-2);
}

TEST(INTEGRATION_METHOD, can_integrate_simple_function_by_simpson_method) {
    IntegrationMethod im;
    double actual = im.SimpsonMethod("x", 0, 1, 1e-3);
    double expected = 0.5;
    EXPECT_NEAR(expected, actual, 1e-2);
}

TEST(INTEGRATION_METHOD, can_integrate_const_function_by_simpson_method) {
    IntegrationMethod im;
    double actual = im.SimpsonMethod("50", 2, 4, 1e-3);
    double expected = 100;
    EXPECT_NEAR(expected, actual, 1e-2);
}

TEST(INTEGRATION_METHOD, can_integrate_function_by_simpson_method) {
    IntegrationMethod im;
    double actual = im.SimpsonMethod("x+x*x+3*x*x*x", 2, 4, 1e-3);
    double expected = 204.67;

    EXPECT_NEAR(expected, actual, 1e-2);
}

TEST(INTEGRATION_METHOD, can_integrate_function_with_cos_by_simpson_method) {
    IntegrationMethod im;
    double actual =
        im.SimpsonMethod("x+x*x+3*x*x*x + x*cos(10*x)", 3, 5, 1e-3);
    double expected = 448.84;

    EXPECT_NEAR(expected, actual, 1e-2);
}

TEST(INTEGRATION_METHOD,
    can_integrate_func_with_raplaced_upper_and_lower_limits_by_simpson_method) {
    IntegrationMethod im;
    double actual =
        im.SimpsonMethod("x+x*x+3*x*x*x + x*cos(10*x)", 5, 3, 1e-3);
    double expected = -448.84;

    EXPECT_NEAR(expected, actual, 1e-2);
}

TEST(INTEGRATION_METHOD,
    can_integrate_function_with_negative_eps_by_simpson_method) {
    IntegrationMethod im;

    ASSERT_ANY_THROW(im.SimpsonMethod("x+x*x+3*x*x*x + x*cos(10*x)",
        5, 3, -1e-3));
}
