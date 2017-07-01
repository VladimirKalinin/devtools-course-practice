// Copyright 2017 Kochin Ivan

#include <gtest/gtest.h>
#include <string>
#include "include/rom_numbers_converter.h"

using std::string;


// ARABIC TO ROM


TEST(RomNumConverter, convetr_arabic_to_rom_I_1) {
    // Arrange
    int temp = 1;
    string bufstr;
    RomNumConverter Convert;
    // Act
    bufstr = Convert.ConvertArabicToRom(temp);
    // Assert
    EXPECT_EQ(bufstr, "I");
}

TEST(RomNumConverter, convetr_arabic_to_rom_V_5) {
    // Arrange
    int temp = 5;
    string bufstr;
    RomNumConverter Convert;
    // Act
    bufstr = Convert.ConvertArabicToRom(temp);
    // Assert
    EXPECT_EQ(bufstr, "V");
}

TEST(RomNumConverter, convetr_arabic_to_rom_IV_4) {
    // Arrange
    int temp = 4;
    string bufstr;
    RomNumConverter Convert;
    // Act
    bufstr = Convert.ConvertArabicToRom(temp);
    // Assert
    EXPECT_EQ(bufstr, "IV");
}

TEST(RomNumConverter, convetr_arabic_to_rom_X_10) {
    // Arrange
    int temp = 10;
    string bufstr;
    RomNumConverter Convert;
    // Act
    bufstr = Convert.ConvertArabicToRom(temp);
    // Assert
    EXPECT_EQ(bufstr, "X");
}

TEST(RomNumConverter, convetr_arabic_to_rom_IX_9) {
    // Arrange
    int temp = 9;
    string bufstr;
    RomNumConverter Convert;
    // Act
    bufstr = Convert.ConvertArabicToRom(temp);
    // Assert
    EXPECT_EQ(bufstr, "IX");
}

TEST(RomNumConverter, convetr_arabic_to_rom_L_50) {
    // Arrange
    int temp = 50;
    string bufstr;
    RomNumConverter Convert;
    // Act
    bufstr = Convert.ConvertArabicToRom(temp);
    // Assert
    EXPECT_EQ(bufstr, "L");
}

TEST(RomNumConverter, convetr_arabic_to_rom_XL_40) {
    // Arrange
    int temp = 40;
    string bufstr;
    RomNumConverter Convert;
    // Act
    bufstr = Convert.ConvertArabicToRom(temp);
    // Assert
    EXPECT_EQ(bufstr, "XL");
}

TEST(RomNumConverter, convetr_arabic_to_rom_XC_90) {
    // Arrange
    int temp = 90;
    string bufstr;
    RomNumConverter Convert;
    // Act
    bufstr = Convert.ConvertArabicToRom(temp);
    // Assert
    EXPECT_EQ(bufstr, "XC");
}

TEST(RomNumConverter, convetr_arabic_to_rom_C_100) {
    // Arrange
    int temp = 100;
    string bufstr;
    RomNumConverter Convert;
    // Act
    bufstr = Convert.ConvertArabicToRom(temp);
    // Assert
    EXPECT_EQ(bufstr, "C");
}

TEST(RomNumConverter, convetr_arabic_to_rom_D_500) {
    // Arrange
    int temp = 500;
    string bufstr;
    RomNumConverter Convert;
    // Act
    bufstr = Convert.ConvertArabicToRom(temp);
    // Assert
    EXPECT_EQ(bufstr, "D");
}

TEST(RomNumConverter, convetr_arabic_to_rom_CD_400) {
    // Arrange
    int temp = 400;
    string bufstr;
    RomNumConverter Convert;
    // Act
    bufstr = Convert.ConvertArabicToRom(temp);
    // Assert
    EXPECT_EQ(bufstr, "CD");
}

TEST(RomNumConverter, convetr_arabic_to_rom_CM_900) {
    // Arrange
    int temp = 900;
    string bufstr;
    RomNumConverter Convert;
    // Act
    bufstr = Convert.ConvertArabicToRom(temp);
    // Assert
    EXPECT_EQ(bufstr, "CM");
}

TEST(RomNumConverter, convetr_arabic_to_rom_M_1000) {
    // Arrange
    int temp = 1000;
    string bufstr;
    RomNumConverter Convert;
    // Act
    bufstr = Convert.ConvertArabicToRom(temp);
    // Assert
    EXPECT_EQ(bufstr, "M");
}

TEST(RomNumConverter, convetr_arabic_to_rom_MMMCMXCIX_3999_maximum) {
    // Arrange
    int temp = 3999;
    string bufstr;
    RomNumConverter Convert;
    // Act
    bufstr = Convert.ConvertArabicToRom(temp);
    // Assert
    EXPECT_EQ(bufstr, "MMMCMXCIX");
}

TEST(RomNumConverter, convetr_arabic_to_rom_CDXLIV_444) {
    // Arrange
    int temp = 444;
    string bufstr;
    RomNumConverter Convert;
    // Act
    bufstr = Convert.ConvertArabicToRom(temp);
    // Assert
    EXPECT_EQ(bufstr, "CDXLIV");
}

TEST(RomNumConverter, convetr_arabic_to_rom_MMCCCXLV_2345) {
    // Arrange
    int temp = 2345;
    string bufstr;
    RomNumConverter Convert;
    // Act
    bufstr = Convert.ConvertArabicToRom(temp);
    // Assert
    EXPECT_EQ(bufstr, "MMCCCXLV");
}
