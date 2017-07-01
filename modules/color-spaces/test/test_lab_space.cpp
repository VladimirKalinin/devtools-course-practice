// Copyright 2017 Nesterov Alexander
#include <gtest/gtest.h>
#include "../include/lab_space.h"

TEST(LABSpaceTest, Can_Initiliaze_Variable_With_The_Default_Constructor) {
    // Arrange
    int sum = 0;
    // Act
    LABSpace space;
    sum += space.GetLightness();
    sum += space.GetA();
    sum += space.GetB();
    // Assert
    EXPECT_EQ(0, sum);
}

TEST(LABSpaceTest, Can_Enter_Lightness_Not_Correct_Data_In_The_Constructor) {
    // Arrange
    int lightness = 256;
    int a = 128;
    int b = 128;
    // Act & Assert
    EXPECT_ANY_THROW({ LABSpace space(lightness, a, b);});
}

TEST(LABSpaceTest, Can_Enter_A_Not_Correct_Data_In_The_Constructor) {
    // Arrange
    int lightness = 100;
    int a = -256;
    int b = 128;
    // Act & Assert
    EXPECT_ANY_THROW({ LABSpace space(lightness, a, b); });
}

TEST(LABSpaceTest, Can_Enter_B_Not_Correct_Data_In_The_Constructor) {
    // Arrange
    int lightness = 0;
    int a = 0;
    int b = -1;
    // Act & Assert
    EXPECT_ANY_THROW({ LABSpace space(lightness, a, b); });
}

TEST(LABSpaceTest, Can_Enter_Data_Without_Throw_In_The_Constructor) {
    // Arrange
    int lightness = 90;
    int a = 100;
    int b = 100;
    // Act & Assert
    EXPECT_NO_THROW({ LABSpace space(lightness, a, b); });
}

TEST(LABSpaceTest, Can_Enter_Lightness_Correct_Data_In_The_Constructor) {
    // Arrange
    int lightness = 88;
    int a = 99;
    int b = 111;
    // Act
    LABSpace space(lightness, a, b);
    // Assert
    EXPECT_EQ(lightness, space.GetLightness());
}

TEST(LABSpaceTest, Can_Enter_A_Correct_Data_In_The_Constructor) {
    // Arrange
    int lightness = 99;
    int a = 127;
    int b = 127;
    // Act
    LABSpace space(lightness, a, b);
    // Assert
    EXPECT_EQ(a, space.GetA());
}

TEST(LABSpaceTest, Can_Enter_B_Correct_Data_In_The_Constructor) {
    // Arrange
    int lightness = 99;
    int a = 127;
    int b = 127;
    // Act
    LABSpace space(lightness, a, b);
    // Assert
    EXPECT_EQ(b, space.GetB());
}

TEST(LABSpaceTest, Can_Use_The_Copying_Constructor) {
    // Arrange
    LABSpace space(55, 66, 77);
    // Act
    LABSpace copy_space(space);
    // Assert
    EXPECT_EQ(space, copy_space);
}

TEST(LABSpaceTest, Can_Use_Assignment_Operator) {
    // Arrange
    LABSpace space(77, 66, 55);
    // Act
    LABSpace assigment_space = space;
    // Assert
    EXPECT_EQ(space, assigment_space);
}

TEST(LABSpaceTest, Can_Set_Field_Lightness) {
    // Arrange
    int lightness = 89;
    // Act
    LABSpace space;
    space.SetLightness(lightness);
    // Assert
    EXPECT_EQ(lightness, space.GetLightness());
}

TEST(LABSpaceTest, Can_Set_Field_A) {
    // Arrange
    int a = 14;
    // Act
    LABSpace space;
    space.SetA(a);
    // Assert
    EXPECT_EQ(a, space.GetA());
}

TEST(LABSpaceTest, Can_Set_Field_B) {
    // Arrange
    int b = 75;
    // Act
    LABSpace space;
    space.SetB(b);
    // Assert
    EXPECT_EQ(b, space.GetB());
}

TEST(LABSpaceTest, Can_Set_Not_Correct_Data_In_Field_Lightness) {
    // Arrange
    int lightness = 257;
    // Act
    LABSpace space;
    // Assert
    EXPECT_ANY_THROW({ space.SetLightness(lightness); });
}

TEST(LABSpaceTest, Can_Set_Not_Correct_Data_In_Field_A) {
    // Arrange
    int a = -2;
    // Act
    LABSpace space;
    // Assert
    EXPECT_ANY_THROW({ space.SetA(a); });
}

TEST(LABSpaceTest, Can_Set_Not_Correct_Data_In_Field_B) {
    // Arrange
    int b = -258;
    // Act
    LABSpace space;
    // Assert
    EXPECT_ANY_THROW({ space.SetB(b); });
}

TEST(LABSpaceTest, Can_Use_Equals_In_LABSpace) {
    // Arrange
    int lightness = 88, a = 100, b = 105;
    LABSpace left_space(lightness, a, b);
    LABSpace right_space(lightness, a, b);
    // Act & Assert
    EXPECT_TRUE(left_space == right_space);
}

TEST(LABSpaceTest, Can_Use_Equals_With_As) {
    // Arrange
    int lightness = 88;
    int a = 100;
    int b = 105;
    // Act
    LABSpace *space = new LABSpace(lightness, a, b);
    LABSpace *other_space = space;
    bool result = (space == other_space);
    delete space;
    // Assert
    EXPECT_TRUE(result);
}

TEST(LABSpaceTest, Can_Use_Not_Equals_In_LABSpace) {
    // Arrange
    int lightness = 88;
    int a = 100;
    int b = 105;
    // Act & Assert
    LABSpace left_space(lightness, a, b);
    lightness++; a++; b++;
    LABSpace right_space(lightness, a, b);
    EXPECT_TRUE(left_space != right_space);
}

TEST(LABSpaceTest, Can_Use_Swap_Method) {
    // Arrange
    LABSpace space1(1, 2, 3);
    LABSpace space2(3, 4, 5);
    // Act
    space1 = space2;
    // Assert
    EXPECT_EQ(space1, space2);
}

TEST(LABSpaceTest, Can_Use_Compare_As) {
    // Arrange
    LABSpace space(1, 2, 3);
    // Act & Assert
    EXPECT_TRUE(space == space);
}
