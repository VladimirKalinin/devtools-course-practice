// Copyright 2017 Nesterov Alexander
#include <gtest/gtest.h>
#include "../include/hsb_hsv_space.h"
#include "../include/rgb_space.h"
#include "../include/lab_space.h"
#include "../include/xyz_space.h"

TEST(IntegrationSpaceTest, Can_Convert_HSBHSV_To_RGB_H_Interval_0_60) {
    // Arrange
    HSBHSVSpace space(30, 57, 73);
    // Act
    RGBSpace convert_space(space);
    // Assert
    RGBSpace correct_space(186, 133, 80);
    EXPECT_EQ(correct_space, convert_space);
}

TEST(IntegrationSpaceTest, Can_Convert_HSBHSV_To_RGB_H_Interval_60_120) {
    // Arrange
    HSBHSVSpace space(90, 57, 73);
    // Act
    RGBSpace convert_space(space);
    // Assert
    RGBSpace correct_space(133, 186, 80);
    EXPECT_EQ(correct_space, convert_space);
}

TEST(IntegrationSpaceTest, Can_Convert_HSBHSV_To_RGB_H_Interval_120_180) {
    // Arrange
    HSBHSVSpace space(150, 57, 73);
    // Act
    RGBSpace convert_space(space);
    // Assert
    RGBSpace correct_space(80, 186, 133);
    EXPECT_EQ(correct_space, convert_space);
}

TEST(IntegrationSpaceTest, Can_Convert_HSBHSV_To_RGB_H_Interval_180_240) {
    // Arrange
    HSBHSVSpace space(210, 57, 73);
    // Act
    RGBSpace convert_space(space);
    // Assert
    RGBSpace correct_space(80, 133, 186);
    EXPECT_EQ(correct_space, convert_space);
}

TEST(IntegrationSpaceTest, Can_Convert_HSBHSV_To_RGB_H_Interval_240_300) {
    // Arrange
    HSBHSVSpace space(270, 57, 73);
    // Act
    RGBSpace convert_space(space);
    // Assert
    RGBSpace correct_space(133, 80, 186);
    EXPECT_EQ(correct_space, convert_space);
}

TEST(IntegrationSpaceTest, Can_Convert_HSBHSV_To_RGB_H_Interval_300_360) {
    // Arrange
    HSBHSVSpace space(330, 57, 73);
    // Act
    RGBSpace convert_space(space);
    // Assert
    RGBSpace correct_space(186, 80, 133);
    EXPECT_EQ(correct_space, convert_space);
}

TEST(IntegrationSpaceTest, Can_Convert_RGB_To_HSBHSV_Max_Eq_Min) {
    // Arrange
    RGBSpace space(10, 10, 10);
    // Act
    HSBHSVSpace convert_space(space);
    // Assert
    HSBHSVSpace correct_space(0, 0, 4);
    EXPECT_EQ(correct_space, convert_space);
}

TEST(IntegrationSpaceTest, Can_Convert_RGB_To_HSBHSV_Max_Eq_Red_And_G_more_B) {
    // Arrange
    RGBSpace space(150, 45, 37);
    // Act
    HSBHSVSpace convert_space(space);
    // Assert
    HSBHSVSpace correct_space(4, 75, 59);
    EXPECT_EQ(correct_space, convert_space);
}

TEST(IntegrationSpaceTest, Can_Convert_RGB_To_HSBHSV_Max_Eq_Red_And_B_more_G) {
    // Arrange
    RGBSpace space(150, 37, 45);
    // Act
    HSBHSVSpace convert_space(space);
    // Assert
    HSBHSVSpace correct_space(356, 75, 59);
    EXPECT_EQ(correct_space, convert_space);
}

TEST(IntegrationSpaceTest, Can_Convert_RGB_To_HSBHSV_Max_Eq_Green) {
    // Arrange
    RGBSpace space(37, 150, 45);
    // Act
    HSBHSVSpace convert_space(space);
    // Assert
    HSBHSVSpace correct_space(124, 75, 59);
    EXPECT_EQ(correct_space, convert_space);
}

TEST(IntegrationSpaceTest, Can_Convert_RGB_To_HSBHSV_Max_Eq_Blue) {
    // Arrange
    RGBSpace space(37, 45, 150);
    // Act
    HSBHSVSpace convert_space(space);
    // Assert
    HSBHSVSpace correct_space(236, 75, 59);
    EXPECT_EQ(correct_space, convert_space);
}

TEST(IntegrationSpaceTest, Can_Convert_RGB_To_HSBHSV_Max_Eq_Zero) {
    // Arrange
    RGBSpace space(0, 0, 0);
    // Act
    HSBHSVSpace convert_space(space);
    // Assert
    HSBHSVSpace correct_space(0, 0, 0);
    EXPECT_EQ(correct_space, convert_space);
}

TEST(IntegrationSpaceTest, Can_Convert_RGB_To_XYZ) {
    // Arrange
    RGBSpace space(88, 80, 55);
    // Act
    XYZSpace convert_space(space);
    // Assert
    XYZSpace correct_space(8, 8, 5);
    EXPECT_EQ(correct_space, convert_space);
}

TEST(IntegrationSpaceTest, Can_Convert_RGB_To_XYZ_Where_Var_Small) {
    // Arrange
    RGBSpace space(9, 9, 9);
    // Act
    XYZSpace convert_space(space);
    // Assert
    XYZSpace correct_space(0, 0, 0);
    EXPECT_EQ(correct_space, convert_space);
}

TEST(IntegrationSpaceTest, Can_Convert_RGB_To_XYZ_Where_Var_Big) {
    // Arrange
    RGBSpace space(254, 254, 254);
    // Act
    XYZSpace convert_space(space);
    // Assert
    XYZSpace correct_space(94, 99, 108);
    EXPECT_EQ(correct_space, convert_space);
}

TEST(IntegrationSpaceTest, Can_Convert_XYZ_To_RGB) {
    // Arrange
    XYZSpace space(8, 8, 5);
    // Act
    RGBSpace convert_space(space);
    // Assert
    RGBSpace correct_space(94, 77, 57);
    EXPECT_EQ(correct_space, convert_space);
}

TEST(IntegrationSpaceTest, Can_Convert_XYZ_To_RGB_Where_Var_Small) {
    // Arrange
    XYZSpace space(0, 0, 0);
    // Act
    RGBSpace convert_space(space);
    // Assert
    RGBSpace correct_space(0, 0, 0);
    EXPECT_EQ(correct_space, convert_space);
}

TEST(IntegrationSpaceTest, Can_Convert_XYZ_To_RGB_Where_Var_Big) {
    // Arrange
    XYZSpace space(94, 99, 108);
    // Act
    RGBSpace convert_space(space);
    // Assert
    RGBSpace correct_space(253, 254, 254);
    EXPECT_EQ(correct_space, convert_space);
}
TEST(IntegrationSpaceTest, Can_Convert_XYZ_To_LAB_Where_Var_Small) {
    // Arrange
    XYZSpace space(0, 0, 0);
    // Act
    LABSpace convert_space(space);
    // Assert
    LABSpace correct_space(0, 0, 0);
    EXPECT_EQ(correct_space, convert_space);
}

TEST(IntegrationSpaceTest, Can_Convert_Lab_To_XYZ_Where_Var_Small) {
    // Arrange
    LABSpace space(0, 0, 0);
    // Act
    XYZSpace convert_space(space);
    // Assert
    XYZSpace correct_space(0, 0, 0);
    EXPECT_EQ(correct_space, convert_space);
}

TEST(IntegrationSpaceTest, Can_Convert_XYZ_To_LAB_Where_Var_Big) {
    // Arrange
    XYZSpace space(35, 34, 12);
    // Act
    LABSpace convert_space(space);
    // Assert
    LABSpace correct_space(65, 9, 44);
    EXPECT_EQ(correct_space, convert_space);
}

TEST(IntegrationSpaceTest, Can_Convert_Lab_To_XYZ_Where_Var_Big) {
    // Arrange
    LABSpace space(6, 4, 2);
    // Act
    XYZSpace convert_space(space);
    // Assert
    XYZSpace correct_space(0, 0, 0);
    EXPECT_EQ(correct_space, convert_space);
}

TEST(IntegrationSpaceTest, Can_Convert_Lab_To_XYZ_Where_Var_Very_Big) {
    // Arrange
    LABSpace space(56, 6, 6);
    // Act
    XYZSpace convert_space(space);
    // Assert
    XYZSpace correct_space(1, 23, 22);
    EXPECT_EQ(correct_space, convert_space);
}
