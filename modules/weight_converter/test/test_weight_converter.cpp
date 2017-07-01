// Copyright 2017 Buldakov Vladislav

#include <gtest/gtest.h>

#include "include/weight_converter.h"

const double EPS = 0.001;

TEST(WeightConverterTest, Can_Create_With_Default_Constructor) {
    // Arrange
    // Act
    // Assert
    ASSERT_NO_THROW(WeightConverter wc);
}

TEST(WeightConverterTest, Can_Create_With_Data) {
    // Arrange
    // Act
    // Assert
    ASSERT_NO_THROW(WeightConverter wc(1.0, G));
}

TEST(WeightConverterTest, Can_Get_Weight) {
    // Arrange
    double weight_g = 1.0;
    double weight_kg = 0.001;
    WeightConverter wc(weight_g, G);
    // Act
    // Assert
    ASSERT_NEAR(weight_kg, wc.GetWeight(), EPS);
}

TEST(WeightConverterTest, Can_Set_Weight) {
    // Arrange
    double weight_g = 1.0;
    double weight_kg = 0.001;
    WeightConverter wc;
    // Act
    wc.SetWeight(weight_g, G);
    // Assert
    ASSERT_NEAR(weight_kg, wc.GetWeight(), EPS);
}

TEST(WeightConverterTest, Can_Convert_Inner_Value) {
    // Arrange
    double weight_g = 1.0;
    double weight_kg = 0.001;
    WeightConverter wc(weight_kg, KG);
    // Act
    double converted_weight = wc.Convert(G);
    // Assert
    ASSERT_NEAR(weight_g, converted_weight, EPS);
}

TEST(WeightConverterTest, Can_Convert_Outer_Value) {
    // Arrange
    WeightConverter wc;
    double actual_weight = 0.625;
    // Act
    double converted_weight = wc.Convert(10, OZ, LB);
    // Assert
    ASSERT_NEAR(actual_weight, converted_weight, EPS);
}

TEST(WeightConverterTest, Can_Convert_MG_to_DR) {
    // Arrange
    WeightConverter wc;
    double weight_dr = 36.86598;
    // Act
    double weight_dr_conv = wc.Convert(65321, MG, DR);
    // Assert
    ASSERT_NEAR(weight_dr, weight_dr_conv, EPS);
}

TEST(WeightConverterTest, Can_Convert_LB_to_CR) {
    // Arrange
    WeightConverter wc;
    double weight_cr = 453.592;
    // Act
    double weight_cr_conv = wc.Convert(0.2, LB, CR);
    // Assert
    ASSERT_NEAR(weight_cr, weight_cr_conv, EPS);
}

TEST(WeightConverterTest, Can_Convert_DR_to_GR) {
    // Arrange
    WeightConverter wc;
    double weight_gr = 3.4179;
    // Act
    double weight_gr_conv = wc.Convert(0.125, DR, GR);
    // Assert
    ASSERT_NEAR(weight_gr, weight_gr_conv, EPS);
}
