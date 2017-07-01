// Copyright 2017 Nesterov Alexander
#include <gtest/gtest.h>
#include "../include/hsb_hsv_space.h"
#include "../include/rgb_space.h"

TEST(HSBHSVSpaceTest, Can_Initiliaze_Variable_With_The_Default_Constructor) {
    // Arrange
    int sum = 0;
    // Act
    HSBHSVSpace space;
    sum += space.GetHue();
    sum += space.GetSaturation();
    sum += space.GetValueBrightnes();
    // Assert
    EXPECT_EQ(0, sum);
}

TEST(HSBHSVSpaceTest, Can_Hue_Not_Correct_Data_In_The_Constructor) {
    // Arrange
    int hue = 361;
    int saturation = 89;
    int value_brightnes = 98;
    // Act & Assert
    EXPECT_ANY_THROW({ HSBHSVSpace space(hue, saturation, value_brightnes); });
}

TEST(HSBHSVSpaceTest, Can_Saturation_Not_Correct_Data_In_The_Constructor) {
    // Arrange
    int hue = 270;
    int saturation = -256;
    int value_brightnes = 56;
    // Act & Assert
    EXPECT_ANY_THROW({ HSBHSVSpace space(hue, saturation, value_brightnes); });
}

TEST(HSBHSVSpaceTest, Can_Brightness_Not_Correct_Data_In_The_Constructor) {
    // Arrange
    int hue = 0;
    int saturation = 0;
    int value_brightnes = -1;
    // Act & Assert
    EXPECT_ANY_THROW({ HSBHSVSpace space(hue, saturation, value_brightnes); });
}

TEST(HSBHSVSpaceTest, Can_Enter_Data_Without_Throw_In_The_Constructor) {
    // Arrange
    int hue = 359;
    int saturation = 99;
    int value_brightnes = 56;
    // Act & Assert
    EXPECT_NO_THROW({ HSBHSVSpace space(hue, saturation, value_brightnes); });
}

TEST(HSBHSVSpaceTest, Can_Enter_Hue_Correct_Data_In_The_Constructor) {
    // Arrange
    int hue = 127;
    int saturation = 59;
    int value_brightnes = 56;
    // Act
    HSBHSVSpace space(hue, saturation, value_brightnes);
    // Assert
    EXPECT_EQ(hue, space.GetHue());
}

TEST(HSBHSVSpaceTest, Can_Enter_Saturation_Correct_Data_In_The_Constructor) {
    // Arrange
    int hue = 127;
    int saturation = 59;
    int value_brightnes = 56;
    // Act
    HSBHSVSpace space(hue, saturation, value_brightnes);
    // Assert
    EXPECT_EQ(saturation, space.GetSaturation());
}

TEST(HSBHSVSpaceTest, Can_Enter_Brightness_Correct_Data_In_The_Constructor) {
    // Arrange
    int hue = 127;
    int saturation = 40;
    int value_brightnes = 56;
    // Act
    HSBHSVSpace space(hue, saturation, value_brightnes);
    // Assert
    EXPECT_EQ(value_brightnes, space.GetValueBrightnes());
}

TEST(HSBHSVSpaceTest, Can_Use_The_Copying_Constructor) {
    // Arrange
    HSBHSVSpace space(203, 12, 59);
    // Act
    HSBHSVSpace copy_space(space);
    // Assert
    EXPECT_EQ(space, copy_space);
}

TEST(HSBHSVSpaceTest, Can_Use_Assignment_Operator) {
    // Arrange
    HSBHSVSpace space(102, 20, 69);
    // Act
    HSBHSVSpace assigment_space = space;
    // Assert
    EXPECT_EQ(space, assigment_space);
}

TEST(HSBHSVSpaceTest, Can_Set_Field_Hue) {
    // Arrange
    int hue = 127;
    // Act
    HSBHSVSpace space;
    space.SetHue(hue);
    // Assert
    EXPECT_EQ(hue, space.GetHue());
}

TEST(HSBHSVSpaceTest, Can_Set_Field_Saturation) {
    // Arrange
    int saturation = 25;
    // Act
    HSBHSVSpace space;
    space.SetSaturation(saturation);
    // Assert
    EXPECT_EQ(saturation, space.GetSaturation());
}

TEST(HSBHSVSpaceTest, Can_Set_Field_Brightnes) {
    // Arrange
    int value_brightnes = 69;
    // Act
    HSBHSVSpace space;
    space.SetValueBrightnes(value_brightnes);
    // Assert
    EXPECT_EQ(value_brightnes, space.GetValueBrightnes());
}

TEST(HSBHSVSpaceTest, Can_Set_Not_Correct_Data_In_Field_Hue) {
    // Arrange
int hue = 720;
    // Act
HSBHSVSpace space;
    // Assert
EXPECT_ANY_THROW({ space.SetHue(hue);});
}

TEST(HSBHSVSpaceTest, Can_Set_Not_Correct_Data_In_Field_Saturation) {
    // Arrange
    int saturation = -2;
    // Act
    HSBHSVSpace space;
    // Assert
    EXPECT_ANY_THROW({ space.SetSaturation(saturation); });
}

TEST(HSBHSVSpaceTest, Can_Set_Not_Correct_Data_In_Field_Brightnes) {
    // Arrange
    int value_brightnes = -258;
    // Act
    HSBHSVSpace space;
    // Assert
    EXPECT_ANY_THROW({ space.SetValueBrightnes(value_brightnes); });
}

TEST(HSBHSVSpaceTest, Can_Use_Equals_In_HSBHSVSpace) {
    // Arrange
    int hue = 127, saturation = 41, value_brightnes = 78;
    HSBHSVSpace left_space(hue, saturation, value_brightnes);
    HSBHSVSpace right_space(hue, saturation, value_brightnes);
    // Act & Assert
    EXPECT_TRUE(left_space == right_space);
}

TEST(HSBHSVSpaceTest, Can_Use_Equals_With_As) {
    // Arrange
    int hue = 127;
    int saturation = 41;
    int value_brightnes = 78;
    // Act
    HSBHSVSpace *space = new HSBHSVSpace(hue, saturation, value_brightnes);
    HSBHSVSpace *other_space = space;
    bool result = (space == other_space);
    delete space;
    // Assert
    EXPECT_TRUE(result);
}

TEST(HSBHSVSpaceTest, Can_Use_Not_Equals_In_HSBHSVSpace) {
    // Arrange
    int hue = 127;
    int saturation = 41;
    int value_brightnes = 78;
    // Act & Assert
    HSBHSVSpace left_space(hue, saturation, value_brightnes);
    hue++; saturation++; value_brightnes++;
    HSBHSVSpace right_space(hue, saturation, value_brightnes);
    EXPECT_TRUE(left_space != right_space);
}

TEST(HSBHSVSpaceTest, Can_Use_Swap_Method) {
    // Arrange
    HSBHSVSpace space1(1, 2, 3);
    HSBHSVSpace space2(3, 4, 5);
    // Act
    space1 = space2;
    // Assert
    EXPECT_EQ(space1, space2);
}

TEST(HSBHSVSpaceTest, Can_Use_Compare_As) {
    // Arrange
    HSBHSVSpace space(1, 2, 3);
    // Act & Assert
    EXPECT_TRUE(space == space);
}
