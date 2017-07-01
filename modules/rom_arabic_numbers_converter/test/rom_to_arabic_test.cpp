// Copyright 2017 Kochin Ivan

#include <gtest/gtest.h>
#include <string>
#include "include/rom_numbers_converter.h"

using std::string;


// ROM TO ARABIC

TEST(RomNumConverter, convetr_rom_to_arabic_I_1) {
    // Arrange
    int temp;
    string bufstr = "I";
    RomNumConverter Convert;
    // Act
    temp = Convert.ConvertRomToArabic(bufstr);
    // Assert
    EXPECT_EQ(temp, 1);
}

TEST(RomNumConverter, convetr_rom_to_arabic_V_5) {
    // Arrange
    int temp;
    string bufstr = "V";
    RomNumConverter Convert;
    // Act
    temp = Convert.ConvertRomToArabic(bufstr);
    // Assert
    EXPECT_EQ(temp, 5);
}

TEST(RomNumConverter, convetr_rom_to_arabic_IV_4) {
    // Arrange
    int temp;
    string bufstr = "IV";
    RomNumConverter Convert;
    // Act
    temp = Convert.ConvertRomToArabic(bufstr);
    // Assert
    EXPECT_EQ(temp, 4);
}

TEST(RomNumConverter, convetr_rom_to_arabic_X_10) {
    // Arrange
    int temp;
    string bufstr = "X";
    RomNumConverter Convert;
    // Act
    temp = Convert.ConvertRomToArabic(bufstr);
    // Assert
    EXPECT_EQ(temp, 10);
}

TEST(RomNumConverter, convetr_rom_to_arabic_IX_9) {
    // Arrange
    int temp;
    string bufstr = "IX";
    RomNumConverter Convert;
    // Act
    temp = Convert.ConvertRomToArabic(bufstr);
    // Assert
    EXPECT_EQ(temp, 9);
}

TEST(RomNumConverter, convetr_rom_to_arabic_L_50) {
    // Arrange
    int temp;
    string bufstr = "L";
    RomNumConverter Convert;
    // Act
    temp = Convert.ConvertRomToArabic(bufstr);
    // Assert
    EXPECT_EQ(temp, 50);
}

TEST(RomNumConverter, convetr_rom_to_arabic_XL_40) {
    // Arrange
    int temp;
    string bufstr = "XL";
    RomNumConverter Convert;
    // Act
    temp = Convert.ConvertRomToArabic(bufstr);
    // Assert
    EXPECT_EQ(temp, 40);
}

TEST(RomNumConverter, convetr_rom_to_arabic_XC_90) {
    // Arrange
    int temp;
    string bufstr = "XC";
    RomNumConverter Convert;
    // Act
    temp = Convert.ConvertRomToArabic(bufstr);
    // Assert
    EXPECT_EQ(temp, 90);
}

TEST(RomNumConverter, convetr_rom_to_arabic_C_100) {
    // Arrange
    int temp;
    string bufstr = "C";
    RomNumConverter Convert;
    // Act
    temp = Convert.ConvertRomToArabic(bufstr);
    // Assert
    EXPECT_EQ(temp, 100);
}

TEST(RomNumConverter, convetr_rom_to_arabic_D_500) {
    // Arrange
    int temp;
    string bufstr = "D";
    RomNumConverter Convert;
    // Act
    temp = Convert.ConvertRomToArabic(bufstr);
    // Assert
    EXPECT_EQ(temp, 500);
}

TEST(RomNumConverter, convetr_rom_to_arabic_CD_400) {
    // Arrange
    int temp;
    string bufstr = "CD";
    RomNumConverter Convert;
    // Act
    temp = Convert.ConvertRomToArabic(bufstr);
    // Assert
    EXPECT_EQ(temp, 400);
}

TEST(RomNumConverter, convetr_rom_to_arabic_CM_900) {
    // Arrange
    int temp;
    string bufstr = "CM";
    RomNumConverter Convert;
    // Act
    temp = Convert.ConvertRomToArabic(bufstr);
    // Assert
    EXPECT_EQ(temp, 900);
}

TEST(RomNumConverter, convetr_rom_to_arabic_M_1000) {
    // Arrange
    int temp;
    string bufstr = "M";
    RomNumConverter Convert;
    // Act
    temp = Convert.ConvertRomToArabic(bufstr);
    // Assert
    EXPECT_EQ(temp, 1000);
}

TEST(RomNumConverter, convetr_rom_to_arabic_MMMCMXCIX_3999_maximum) {
    // Arrange
    int temp;
    string bufstr = "MMMCMXCIX";
    RomNumConverter Convert;
    // Act
    temp = Convert.ConvertRomToArabic(bufstr);
    // Assert
    EXPECT_EQ(temp, 3999);
}

TEST(RomNumConverter, convetr_rom_to_arabic_CDXLIV_444) {
    // Arrange
    int temp;
    string bufstr = "CDXLIV";
    RomNumConverter Convert;
    // Act
    temp = Convert.ConvertRomToArabic(bufstr);
    // Assert
    EXPECT_EQ(temp, 444);
}

TEST(RomNumConverter, convetr_rom_to_arabic__2345) {
    // Arrange
    int temp;
    string bufstr = "MMCCCXLV";
    RomNumConverter Convert;
    // Act
    temp = Convert.ConvertRomToArabic(bufstr);
    // Assert
    EXPECT_EQ(temp, 2345);
}


// EXEPTION
TEST(RomNumConverter, wrong_litera_in_roman_number) {
    // Arrange
    RomNumConverter Convert;
    // Assert
    ASSERT_ANY_THROW(Convert.ConvertRomToArabic("AB"));
}
