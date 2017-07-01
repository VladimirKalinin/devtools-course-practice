// Copyright 2017 Baranov Evgeny

#include <gtest/gtest.h>

#include <string>

#include "include/al_number.h"

TEST(Baranov_Evgeny_ALNumberTest, can_create_num) {
    // Arrange
    // Act
    // Assert
    ASSERT_NO_THROW(ALNumber number);
}

TEST(Baranov_Evgeny_ALNumberTest, can_create_num_as_str) {
    // Arrange
    std::string str = "123";
    // Act
    // Assert
    ASSERT_NO_THROW(ALNumber number(str));
}

TEST(Baranov_Evgeny_ALNumberTest, can_correct_get_value) {
    // Arrange
    ALNumber number1("12");
    std::string num;
    // Act
    num = number1.GetValue();
    // Assert
    EXPECT_EQ("12", num);
}

TEST(Baranov_Evgeny_ALNumberTest, corr_create_num_as_str) {
    // Arrange
    std::string str = "123";
    // Act
    ALNumber number(str);
    // Assert
    EXPECT_EQ("123", number.GetValue());
}

TEST(Baranov_Evgeny_ALNumberTest, corr_create_big_num_as_str) {
    // Arrange
    std::string str = "1234567891011121314151617181920212223242526";
    // Act
    ALNumber number(str);
    // Assert
    EXPECT_EQ("1234567891011121314151617181920212223242526", number.GetValue());
}

TEST(Baranov_Evgeny_ALNumberTest, cant_create_trash_num) {
    // Arrange
    std::string str = "12345s91011121314a1819202122d2526";
    // Act
    // Assert
    ASSERT_ANY_THROW(ALNumber number(str));
}

TEST(Baranov_Evgeny_ALNumberTest, can_create_copy_num) {
    // Arrange
    ALNumber number1("11124654846321654612");
    // Act
    // Assert
    ASSERT_NO_THROW(ALNumber number2(number1));
}

TEST(Baranov_Evgeny_ALNumberTest, copy_eq_source_num) {
    // Arrange
    ALNumber number1("11124654846321654612");
    // Act
    ALNumber number2(number1);
    // Assert
    EXPECT_EQ("11124654846321654612", number2.GetValue());
}

TEST(Baranov_Evgeny_ALNumberTest, correct_num_comparison1) {
    // Arrange
    ALNumber number1("123");
    ALNumber number2("123");
    // Act
    bool flag = number1 == number2;
    // Assert
    EXPECT_EQ(1, flag);
}

TEST(Baranov_Evgeny_ALNumberTest, correct_num_comparison2) {
    // Arrange
    ALNumber number1("123");
    ALNumber number2("213");
    bool flag;
    // Act
    flag = (number1 == number2);
    // Assert
    EXPECT_EQ(0, flag);
}

TEST(Baranov_Evgeny_ALNumberTest, correct_num_comparison3) {
    // Arrange
    ALNumber number1("123");
    ALNumber number2("123");
    bool flag;
    // Act
    flag = (number1 != number2);
    // Assert
    EXPECT_EQ(0, flag);
}

TEST(Baranov_Evgeny_ALNumberTest, correct_num_comparison4) {
    // Arrange
    ALNumber number1("123");
    ALNumber number2("213");
    // Act
    bool flag = number1 != number2;
    // Assert
    EXPECT_EQ(1, flag);
}

TEST(Baranov_Evgeny_ALNumberTest, correct_num_comparison5) {
    // Arrange
    ALNumber number1("123");
    ALNumber number2("1");
    // Act
    bool flag = number1 == number2;
    // Assert
    EXPECT_EQ(0, flag);
}

TEST(Baranov_Evgeny_ALNumberTest, correct_num_comparison6) {
    // Arrange
    ALNumber number1("123");
    ALNumber number2("1");
    // Act
    bool flag = number1 != number2;
    // Assert
    EXPECT_EQ(1, flag);
}

TEST(Baranov_Evgeny_ALNumberTest, correct_num_str_comparison1) {
    // Arrange
    ALNumber number1("123");
    std::string number2("123");
    // Act
    bool flag = number1 == number2;
    // Assert
    EXPECT_EQ(1, flag);
}

TEST(Baranov_Evgeny_ALNumberTest, correct_num_str_comparison2) {
    // Arrange
    ALNumber number1("123");
    std::string number2("213");
    bool flag;
    // Act
    flag = (number1 == number2);
    // Assert
    EXPECT_EQ(0, flag);
}

TEST(Baranov_Evgeny_ALNumberTest, correct_num_str_comparison3) {
    // Arrange
    ALNumber number1("123");
    std::string number2("123");
    bool flag;
    // Act
    flag = (number1 != number2);
    // Assert
    EXPECT_EQ(0, flag);
}

TEST(Baranov_Evgeny_ALNumberTest, correct_num_str_comparison4) {
    // Arrange
    ALNumber number1("123");
    std::string number2("213");
    // Act
    bool flag = number1 != number2;
    // Assert
    EXPECT_EQ(1, flag);
}

TEST(Baranov_Evgeny_ALNumberTest, can_correct_assign_num) {
    // Arrange
    ALNumber number1("123");
    ALNumber number2("1");
    // Act
    number1 = number2;
    // Assert
    EXPECT_EQ("1", number1.GetValue());
}

TEST(Baranov_Evgeny_ALNumberTest, can_assign_equal_nums) {
    // Arrange
    ALNumber number1("123");
    ALNumber number2("123");
    // Act
    number1 = number2;
    // Assert
    EXPECT_EQ("123", number1.GetValue());
}

TEST(Baranov_Evgeny_ALNumberTest, can_correct_assign_equal_str) {
    // Arrange
    ALNumber number1("465456456545645");
    // Act
    number1 = "465456456545645";
    // Assert
    EXPECT_EQ("465456456545645", number1.GetValue());
}

TEST(Baranov_Evgeny_ALNumberTest, cant_assign_corrupted_str) {
    // Arrange
    ALNumber number1;
    // Act
    // Assert
    ASSERT_ANY_THROW(number1 = "4654s56456as54564s5");
}

TEST(Baranov_Evgeny_ALNumberTest, can_correct_sum) {
    // Arrange
    ALNumber number1("1");
    ALNumber number2("1");
    ALNumber number3;
    // Act
    number3 = number1 + number2;
    // Assert
    EXPECT_EQ("2", number3.GetValue());
}

TEST(Baranov_Evgeny_ALNumberTest, can_correct_compos_nums) {
    // Arrange
    ALNumber number1("12");
    ALNumber number2("33");
    ALNumber number3;
    // Act
    number3 = number1 * number2;
    // Assert
    EXPECT_EQ("396", number3.GetValue());
}

TEST(Baranov_Evgeny_ALNumberTest, can_correct_compos_str) {
    // Arrange
    ALNumber number1("12");
    ALNumber number3;
    // Act
    number3 = number1 * "33";
    // Assert
    EXPECT_EQ("396", number3.GetValue());
}
