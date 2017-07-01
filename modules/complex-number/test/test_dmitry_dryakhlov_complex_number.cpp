// Copyright 2017 Dmitry Dryakhlov

#include <gtest/gtest.h>

#include "include/complex_number.h"

TEST(Dmitry_Dryakhlov_ComplexNumberTest, Can_Get_Real) {
    // Arrange
    double re = 2.0, im = 4.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_DOUBLE_EQ(re, z.getRe());
}

TEST(Dmitry_Dryakhlov_ComplexNumberTest, Can_Get_Im) {
    // Arrange
    double re = 2.0, im = 4.0;

    // Act
    ComplexNumber z(re, im);

    // Assert
    EXPECT_DOUBLE_EQ(im, z.getIm());
}

TEST(Dmitry_Dryakhlov_ComplexNumberTest, Can_Set_Re) {
    // Arrange
    double re = 2.0, im = 4.0;
    double re_set = 3.0;
    ComplexNumber z(re, im);

    // Act
    z.setRe(re_set);

    // Assert
    EXPECT_DOUBLE_EQ(re_set, z.getRe());
}

TEST(Dmitry_Dryakhlov_ComplexNumberTest, Can_Set_Im) {
    // Arrange
    double re = 2.0, im = 4.0;
    double im_set = 3.0;
    ComplexNumber z(re, im);

    // Act
    z.setIm(im_set);

    // Assert
    EXPECT_DOUBLE_EQ(im_set, z.getIm());
}

TEST(Dmitry_Dryakhlov_ComplexNumberTest, Can_Add_Complex) {
    // Arrange
    double re_1 = 2.0, im_1 = 4.0;
    double re_2 = 3.0, im_2 = 6.0;
    ComplexNumber z_1(re_1, im_1);
    ComplexNumber z_2(re_2, im_2);
    ComplexNumber z_result(5.0, 10.0);

    // Act
    ComplexNumber z_sum = z_1 + z_2;

    // Assert
    EXPECT_DOUBLE_EQ(z_result.getRe(), z_sum.getRe());
    EXPECT_DOUBLE_EQ(z_result.getIm(), z_sum.getIm());
}

TEST(Dmitry_Dryakhlov_ComplexNumberTest, Can_Sub_Complex) {
    // Arrange
    double re_1 = 2.0, im_1 = 4.0;
    double re_2 = 3.0, im_2 = 6.0;
    ComplexNumber z_1(re_1, im_1);
    ComplexNumber z_2(re_2, im_2);
    ComplexNumber z_result(-1.0, -2.0);

     // Act
    ComplexNumber z_sub = z_1 - z_2;

    // Assert
    EXPECT_DOUBLE_EQ(z_result.getRe(), z_sub.getRe());
    EXPECT_DOUBLE_EQ(z_result.getIm(), z_sub.getIm());
}
