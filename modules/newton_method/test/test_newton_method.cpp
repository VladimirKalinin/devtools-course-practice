// Copyright 2017 Dmitry Dryakhlov

#include <gtest/gtest.h>

#include "include/Newton_method.h"

const double eps = 0.01;
const unsigned int polynom_size = 10;

TEST(test_newton_method, can_generate_random_polynom) {
    // Arrange
    NewtonMethod nm;
    double *polynom_coef = new double[polynom_size];
    // Act & Assert
    ASSERT_NO_THROW(nm.GeneateRandomPolynom(polynom_size, polynom_coef));
    delete[]polynom_coef;
}

TEST(test_newton_method, random_polynom_whith_zero_size) {
    // Arrange
    unsigned int zero_size = 0;
    double *polynom_coef = new double[zero_size];
    NewtonMethod nm;
    // Act & Assert
    ASSERT_NO_THROW(nm.GeneateRandomPolynom(zero_size, polynom_coef););
    delete[]polynom_coef;
}


TEST(test_newton_method, work_with_const_function) {
    // Arrange
    NewtonMethod nm;
    // Act & Assert
    ASSERT_NO_THROW(nm.NewtonMethodFunction(eps));
}

TEST(test_newton_method, work_with_const_function_negative_eps) {
    // Arrange
    NewtonMethod nm;
    // Act & Assert
    ASSERT_ANY_THROW(nm.NewtonMethodFunction(-0.01));
}

TEST(test_newton_method, work_with_random_polynom) {
    // Arrange
    NewtonMethod nm;
    double *polynom_coef = new double[polynom_size];
    nm.GeneateRandomPolynom(polynom_size, polynom_coef);
    // Act & Assert
    ASSERT_NO_THROW(nm.NewtonMethodPolynom(polynom_size, polynom_coef));
    delete[]polynom_coef;
}

TEST(test_newton_method, work_with_random_polynom_zero_size) {
    // Arrange
    NewtonMethod nm;
    unsigned int zero_size = 0;
    double *polynom_coef = new double[polynom_size];
    nm.GeneateRandomPolynom(zero_size, polynom_coef);
    // Act & Assert
    ASSERT_ANY_THROW(nm.NewtonMethodPolynom(zero_size, polynom_coef));
    delete[]polynom_coef;
}

TEST(test_newton_method, polynom_whith_no_root) {
    // Arrange
    unsigned int size = 3;
    double *polynom_coef = new double[size];
    polynom_coef[0] = 1.0;
    polynom_coef[1] = 1.0;
    polynom_coef[2] = 1.0;
    NewtonMethod nm;
    // Act & Assert
    ASSERT_ANY_THROW(nm.NewtonMethodPolynom(size, polynom_coef));
    delete[]polynom_coef;
}

TEST(test_newton_method, check_result_function) {
    // Arrange
    NewtonMethod nm;
    // Act & Assert
    ASSERT_TRUE(nm.CheckRootFunction(nm.NewtonMethodFunction(eps), eps));
}

TEST(test_newton_method, check_result_polynom) {
    // Arrange
    double *polynom_coef = new double[polynom_size];
    NewtonMethod nm;
    nm.GeneateRandomPolynom(polynom_size, polynom_coef);
    double root = nm.NewtonMethodPolynom(polynom_size, polynom_coef);
    // Act & Assert
    ASSERT_TRUE(nm.CheckRootPolynom(root, eps, polynom_size,
                                                               polynom_coef));
    delete[]polynom_coef;
}
