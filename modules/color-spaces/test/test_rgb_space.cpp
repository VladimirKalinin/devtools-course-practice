// Copyright 2017 Nesterov Alexander
#include <gtest/gtest.h>
#include "../include/rgb_space.h"
TEST(RGBSpaceTest, Can_Initiliaze_Variable_With_The_Default_Constructor) {
    // Arrange
    int sum = 0;
    // Act
    RGBSpace space;
    sum += space.GetRed();
    sum += space.GetGreen();
    sum += space.GetBlue();
    // Assert
    EXPECT_EQ(0, sum);
}

TEST(RGBSpaceTest, Can_Enter_Red_Not_Correct_Data_In_The_Constructor) {
    // Arrange
    int red = 256;
    int green = 128;
    int blue = 128;
    // Act & Assert
    EXPECT_ANY_THROW({ RGBSpace space(red, green, blue);});
}

TEST(RGBSpaceTest, Can_Enter_Green_Not_Correct_Data_In_The_Constructor) {
    // Arrange
    int red = 128;
    int green = -256;
    int blue = 128;
    // Act & Assert
    EXPECT_ANY_THROW({ RGBSpace space(red, green, blue);});
}

TEST(RGBSpaceTest, Can_Enter_Blue_Not_Correct_Data_In_The_Constructor) {
    // Arrange
    int red = 0;
    int green = 0;
    int blue = -1;
    // Act & Assert
    EXPECT_ANY_THROW({ RGBSpace space(red, green, blue);});
}

TEST(RGBSpaceTest, Can_Enter_Data_Without_Throw_In_The_Constructor) {
    // Arrange
    int red = 127;
    int green = 236;
    int blue = 56;
    // Act & Assert
    EXPECT_NO_THROW({ RGBSpace space(red, green, blue);});
}

TEST(RGBSpaceTest, Can_Enter_Red_Correct_Data_In_The_Constructor) {
    // Arrange
    int red = 127;
    int green = 236;
    int blue = 56;
    // Act
    RGBSpace space(red, green, blue);
    // Assert
    EXPECT_EQ(red, space.GetRed());
}

TEST(RGBSpaceTest, Can_Enter_Green_Correct_Data_In_The_Constructor) {
    // Arrange
    int red = 127;
    int green = 236;
    int blue = 56;
    // Act
    RGBSpace space(red, green, blue);
    // Assert
    EXPECT_EQ(green, space.GetGreen());
}

TEST(RGBSpaceTest, Can_Enter_Blue_Correct_Data_In_The_Constructor) {
    // Arrange
    int red = 127;
    int green = 236;
    int blue = 56;
    // Act
    RGBSpace space(red, green, blue);
    // Assert
    EXPECT_EQ(blue, space.GetBlue());
}

TEST(RGBSpaceTest, Can_Use_The_Copying_Constructor) {
    // Arrange
    RGBSpace space(203, 102, 59);
    // Act
    RGBSpace copy_space(space);
    // Assert
    EXPECT_EQ(space, copy_space);
}

TEST(RGBSpaceTest, Can_Use_Assignment_Operator) {
    // Arrange
    RGBSpace space(102, 205, 69);
    // Act
    RGBSpace assigment_space = space;
    // Assert
    EXPECT_EQ(space, assigment_space);
}

TEST(RGBSpaceTest, Can_Set_Field_Red) {
    // Arrange
    int red = 127;
    // Act
    RGBSpace space;
    space.SetRed(red);
    // Assert
    EXPECT_EQ(red, space.GetRed());
}

TEST(RGBSpaceTest, Can_Set_Field_Green) {
    // Arrange
    int green = 253;
    // Act
    RGBSpace space;
    space.SetGreen(green);
    // Assert
    EXPECT_EQ(green, space.GetGreen());
}

TEST(RGBSpaceTest, Can_Set_Field_Blue) {
    // Arrange
    int blue = 127;
    // Act
    RGBSpace space;
    space.SetBlue(blue);
    // Assert
    EXPECT_EQ(blue, space.GetBlue());
}

TEST(RGBSpaceTest, Can_Set_Not_Correct_Data_In_Field_Red) {
    // Arrange
    int red = 257;
    // Act
    RGBSpace space;
    // Assert
    EXPECT_ANY_THROW({ space.SetRed(red);});
}

TEST(RGBSpaceTest, Can_Set_Not_Correct_Data_In_Field_Green) {
    // Arrange
    int green = -2;
    // Act
    RGBSpace space;
    // Assert
    EXPECT_ANY_THROW({ space.SetGreen(green);});
}

TEST(RGBSpaceTest, Can_Set_Not_Correct_Data_In_Field_Blue) {
    // Arrange
    int blue = -258;
    // Act
    RGBSpace space;
    // Assert
    EXPECT_ANY_THROW({ space.SetBlue(blue);});
}

TEST(RGBSpaceTest, Can_Use_Equals_In_RGBSpace) {
    // Arrange
    int red = 127, green = 236, blue = 56;
    RGBSpace left_space(red, green, blue);
    RGBSpace right_space(red, green, blue);
    // Act & Assert
    EXPECT_TRUE(left_space == right_space);
}

TEST(RGBSpaceTest, Can_Use_Equals_With_As) {
    // Arrange
    int red = 127;
    int green = 236;
    int blue = 56;
    // Act
    RGBSpace *space = new RGBSpace(red, green, blue);
    RGBSpace *other_space = space;
    bool result = (space == other_space);
    delete space;
    // Assert
    EXPECT_TRUE(result);
}

TEST(RGBSpaceTest, Can_Use_Not_Equals_In_RGBSpace) {
    // Arrange
    int red = 127;
    int green = 236;
    int blue = 56;
    // Act & Assert
    RGBSpace left_space(red, green, blue);
    red++; green++; blue++;
    RGBSpace right_space(red, green, blue);
    EXPECT_TRUE(left_space != right_space);
}

TEST(RGBSpaceTest, Can_Use_Swap_Method) {
    // Arrange
    RGBSpace space1(1, 2, 3);
    RGBSpace space2(3, 4, 5);
    // Act
    space1 = space2;
    // Assert
    EXPECT_EQ(space1, space2);
}

TEST(RGBSpaceTest, Can_Use_Compare_As) {
    // Arrange
    RGBSpace space(1, 2, 3);
    // Act & Assert
    EXPECT_TRUE(space == space);
}
