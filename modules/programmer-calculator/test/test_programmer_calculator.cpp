// Copyright 2017 Komarov Nikolay

#include <gtest/gtest.h>
#include <string>

#include "include/programmer_calculator.h"

TEST(Komarov_Nikolay_Programmer_Calculator_Test, Can_Convert_Dec_To_Bin) {
    std::string binResult = "";
    ProgrammerCalculator programmer_calculator;
    std::string bin = "1101010110111";
    int dec = 6839;

    binResult = programmer_calculator.ConvertDecToBin(dec);

    EXPECT_EQ(binResult, bin);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test, Can_Convert_Dec_To_Oct) {
    std::string octResult = "";
    ProgrammerCalculator programmer_calculator;
    std::string oct = "6761530211";
    int dec = 935768201;

    octResult = programmer_calculator.ConvertDecToOct(dec);

    EXPECT_EQ(octResult, oct);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test, Can_Convert_Dec_To_Hex) {
    std::string hexResult = "";
    ProgrammerCalculator programmer_calculator;
    std::string hex = "1661f37";
    int dec = 23469879;

    hexResult = programmer_calculator.ConvertDecToHex(dec);

    EXPECT_EQ(hexResult, hex);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test, Can_Convert_Bin_To_Oct) {
    std::string octResult = "";
    ProgrammerCalculator programmer_calculator;
    std::string bin = "1001111000";
    std::string oct = "1170";

    octResult = programmer_calculator.ConvertBinToOct(bin);

    EXPECT_EQ(octResult, oct);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test,
    All_Cases_In_Convert_Bin_To_Oct) {
    std::string octResult = "";
    ProgrammerCalculator programmer_calculator;
    std::string bin = "111110101100011010001000";
    std::string oct = "76543210";

    octResult = programmer_calculator.ConvertBinToOct(bin);

    EXPECT_EQ(octResult, oct);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test, Can_Convert_Bin_To_Dec) {
    int decResult = 0;
    ProgrammerCalculator programmer_calculator;
    std::string bin = "101011011001";
    int dec = 2777;

    decResult = programmer_calculator.ConvertBinToDec(bin);

    EXPECT_EQ(decResult, dec);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test, Can_Convert_Bin_To_Hex) {
    std::string hexResult = "";
    ProgrammerCalculator programmer_calculator;
    std::string bin = "1001011011100";
    std::string hex = "12dc";

    hexResult = programmer_calculator.ConvertBinToHex(bin);

    EXPECT_EQ(hexResult, hex);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test,
    All_Cases_In_Convert_Bin_To_Hex) {
    std::string hexResult = "";
    ProgrammerCalculator programmer_calculator;
    std::string bin =
        "1111111011011100101110101001100001110110010101000011001000010000";
    std::string hex = "fedcba9876543210";

    hexResult = programmer_calculator.ConvertBinToHex(bin);

    EXPECT_EQ(hexResult, hex);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test, Can_Convert_Oct_To_Bin) {
    std::string binResult = "";
    ProgrammerCalculator programmer_calculator;
    std::string oct = "125";
    std::string bin = "1010101";

    binResult = programmer_calculator.ConvertOctToBin(oct);

    EXPECT_EQ(binResult, bin);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test,
    All_Cases_In_Convert_Oct_To_Bin) {
    std::string binResult = "";
    ProgrammerCalculator programmer_calculator;
    std::string oct = "76543210";
    std::string bin = "111110101100011010001000";

    binResult = programmer_calculator.ConvertOctToBin(oct);

    EXPECT_EQ(binResult, bin);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test, Can_Convert_Oct_To_Dec) {
    int decResult = 0;
    ProgrammerCalculator programmer_calculator;
    std::string oct = "5174";
    int dec = 2684;

    decResult = programmer_calculator.ConvertOctToDec(oct);

    EXPECT_EQ(decResult, dec);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test, Can_Convert_Oct_To_Hex) {
    std::string hexResult = "";
    ProgrammerCalculator programmer_calculator;
    std::string oct = "13574367";
    std::string hex = "2ef8f7";

    hexResult = programmer_calculator.ConvertOctToHex(oct);

    EXPECT_EQ(hexResult, hex);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test, Can_Convert_Hex_To_Bin) {
    std::string binResult = "";
    ProgrammerCalculator programmer_calculator;
    std::string hex = "8eA2";
    std::string bin = "1000111010100010";

    binResult = programmer_calculator.ConvertHexToBin(hex);

    EXPECT_EQ(binResult, bin);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test,
    All_Cases_In_Convert_Hex_To_Bin_Small) {
    std::string binResult = "";
    ProgrammerCalculator programmer_calculator;
    std::string hex = "fedcba9876543210";
    std::string bin =
        "1111111011011100101110101001100001110110010101000011001000010000";

    binResult = programmer_calculator.ConvertHexToBin(hex);

    EXPECT_EQ(binResult, bin);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test,
    All_Cases_In_Convert_Hex_To_Bin_Caps) {
    std::string binResult = "";
    ProgrammerCalculator programmer_calculator;
    std::string hex = "FEDCBA9876543210";
    std::string bin =
        "1111111011011100101110101001100001110110010101000011001000010000";

    binResult = programmer_calculator.ConvertHexToBin(hex);

    EXPECT_EQ(binResult, bin);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test, Can_Convert_Hex_To_Oct) {
    std::string octResult = "";
    ProgrammerCalculator programmer_calculator;
    std::string hex = "78Dac";
    std::string oct = "1706654";

    octResult = programmer_calculator.ConvertHexToOct(hex);

    EXPECT_EQ(octResult, oct);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test, Can_Convert_Hex_To_Dec) {
    int decResult = 0;
    ProgrammerCalculator programmer_calculator;
    std::string hex = "fFae5";
    int dec = 1047269;

    decResult = programmer_calculator.ConvertHexToDec(hex);

    EXPECT_EQ(decResult, dec);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test,
    Wrong_Result_Of_Converting_Dec_To_Bin) {
    std::string binResult = "";
    ProgrammerCalculator programmer_calculator;
    std::string bin = "-1";
    int dec = -83904;

    binResult = programmer_calculator.ConvertDecToBin(dec);

    EXPECT_EQ(binResult, bin);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test,
    Wrong_Result_Of_Converting_Dec_To_Oct) {
    std::string octResult = "";
    ProgrammerCalculator programmer_calculator;
    std::string oct = "-1";
    int dec = -49;

    octResult = programmer_calculator.ConvertDecToOct(dec);

    EXPECT_EQ(octResult, oct);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test,
    Wrong_Result_Of_Converting_Dec_To_Hex) {
    std::string hexResult = "";
    ProgrammerCalculator programmer_calculator;
    std::string hex = "-1";
    int dec = -8657;

    hexResult = programmer_calculator.ConvertDecToHex(dec);

    EXPECT_EQ(hexResult, hex);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test,
    Wrong_Result_Of_Converting_Bin_To_Oct) {
    std::string octResult = "";
    ProgrammerCalculator programmer_calculator;
    std::string bin = "69838gjik";
    std::string oct = "-1";

    octResult = programmer_calculator.ConvertBinToOct(bin);

    EXPECT_EQ(octResult, oct);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test,
    Wrong_Result_Of_Converting_Bin_To_Dec) {
    int decResult = 0;
    ProgrammerCalculator programmer_calculator;
    std::string bin = "433572";
    int dec = -1;

    decResult = programmer_calculator.ConvertBinToDec(bin);

    EXPECT_EQ(decResult, dec);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test,
    Wrong_Result_Of_Converting_Bin_To_Hex) {
    std::string hexResult = "";
    ProgrammerCalculator programmer_calculator;
    std::string bin = "9jg348";
    std::string hex = "-1";

    hexResult = programmer_calculator.ConvertBinToHex(bin);

    EXPECT_EQ(hexResult, hex);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test,
    Wrong_Result_Of_Converting_Oct_To_Bin) {
    std::string binResult = "";
    ProgrammerCalculator programmer_calculator;
    std::string oct = "86205";
    std::string bin = "-1";

    binResult = programmer_calculator.ConvertOctToBin(oct);

    EXPECT_EQ(binResult, bin);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test,
    Wrong_Result_Of_Converting_Oct_To_Dec) {
    int decResult = 0;
    ProgrammerCalculator programmer_calculator;
    std::string oct = "jg930#&";
    int dec = -1;

    decResult = programmer_calculator.ConvertOctToDec(oct);

    EXPECT_EQ(decResult, dec);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test,
    Wrong_Result_Of_Converting_Oct_To_Hex) {
    std::string hexResult = "";
    ProgrammerCalculator programmer_calculator;
    std::string oct = "289360";
    std::string hex = "-1";

    hexResult = programmer_calculator.ConvertOctToHex(oct);

    EXPECT_EQ(hexResult, hex);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test,
    Wrong_Result_Of_Converting_Hex_To_Bin) {
    std::string binResult = "";
    ProgrammerCalculator programmer_calculator;
    std::string hex = "49a7feg";
    std::string bin = "-1";

    binResult = programmer_calculator.ConvertHexToBin(hex);

    EXPECT_EQ(binResult, bin);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test,
    Wrong_Result_Of_Converting_Hex_To_Oct) {
    std::string octResult = "";
    ProgrammerCalculator programmer_calculator;
    std::string hex = "ig5095uj";
    std::string oct = "-1";

    octResult = programmer_calculator.ConvertHexToOct(hex);

    EXPECT_EQ(octResult, oct);
}

TEST(Komarov_Nikolay_Programmer_Calculator_Test,
    Wrong_Result_Of_Converting_Hex_To_Dec) {
    int decResult = 0;
    ProgrammerCalculator programmer_calculator;
    std::string hex = "8592^";
    int dec = -1;

    decResult = programmer_calculator.ConvertHexToDec(hex);

    EXPECT_EQ(decResult, dec);
}
