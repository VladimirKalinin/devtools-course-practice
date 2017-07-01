// Copyright 2017 Komarov Nikolay

#include <math.h>
#include <string>
#include <vector>

#include "include/programmer_calculator.h"

std::vector<std::string> ProgrammerCalculator::triades_ =
    { "000", "001", "010", "011", "100", "101", "110", "111" };

std::vector<std::string> ProgrammerCalculator::tetrads_ =
    { "0000", "0001", "0010", "0011", "0100", "0101", "0110", "0111",
      "1000", "1001", "1010", "1011", "1100", "1101", "1110", "1111"};

std::vector<std::string> ProgrammerCalculator::chars_set_ =
{ "0", "1", "2", "3", "4", "5", "6", "7", "8", "9",
    "a", "b", "c", "d", "e", "f" };

ProgrammerCalculator::ProgrammerCalculator() {}

std::string ProgrammerCalculator::ConvertDecToBin(int dec) {
    if (dec < 0) {
        return "-1";
    }
    std::string result = "";
    int quotient = dec;

    while (quotient >= 2) {
        int remainder = quotient % 2;
        quotient = quotient / 2;
        result = std::to_string(remainder) + result;
    }

    result = std::to_string(quotient) + result;

    return result;
}

std::string ProgrammerCalculator::ConvertDecToOct(int dec) {
    if (dec < 0) {
        return "-1";
    }
    return ConvertBinToOct(ConvertDecToBin(dec));
}

std::string ProgrammerCalculator::ConvertDecToHex(int dec) {
    if (dec < 0) {
        return "-1";
    }
    return ConvertBinToHex(ConvertDecToBin(dec));
}

std::string ProgrammerCalculator::ConvertBinToOct(const std::string &bin) {
    if (bin.find_first_not_of("01") != std::string::npos) {
        return "-1";
    }
    std::string bin_copy = bin;
    std::string result = "";
    int lenght_of_bin = bin_copy.length();
    int additionalLeftZeroesCount = 3 - lenght_of_bin % 3;

    if (additionalLeftZeroesCount != 3) {
        for (int i = 0; i < additionalLeftZeroesCount; i++) {
            bin_copy = "0" + bin_copy;
        }
    }

    int triadsCount = bin_copy.length() / 3;

    for (int i = 0; i < triadsCount; i++) {
        std::string triad = bin_copy.substr(3 * (triadsCount - 1 - i), 3);

        result = std::to_string((triad[0] - '0') * 4 +
            (triad[1] - '0') * 2 +
            (triad[2] - '0')) + result;
    }

    return result;
}

int ProgrammerCalculator::ConvertBinToDec(const std::string &bin) {
    if (bin.find_first_not_of("01") != std::string::npos) {
        return -1;
    }
    int result = 0;
    int length_of_bin = bin.length();

    for (int i = 0; i < length_of_bin; i++) {
        if (bin[i] == '1') {
            result += pow(2, length_of_bin - 1 - i);
        }
    }

    return result;
}

std::string ProgrammerCalculator::ConvertBinToHex(const std::string &bin) {
    if (bin.find_first_not_of("01") != std::string::npos) {
        return "-1";
    }
    std::string bin_copy = bin;
    std::string result = "";
    int length_of_bin = bin_copy.length();
    int additional_left_zeroes_count = 4 - length_of_bin % 4;

    if (additional_left_zeroes_count != 4) {
        for (int i = 0; i < additional_left_zeroes_count; i++) {
            bin_copy = "0" + bin_copy;
        }
    }

    int tetrads_count = bin_copy.length() / 4;

    for (int i = 0; i < tetrads_count; i++) {
        std::string tetrad = bin_copy.substr(4 * (tetrads_count - 1 - i), 4);
        result = chars_set_[(tetrad[0] - '0') * 8 + (tetrad[1] - '0') * 4 +
            (tetrad[2] - '0') * 2 + (tetrad[3] - '0')] + result;
    }

    return result;
}

std::string ProgrammerCalculator::ConvertOctToBin(const std::string &oct) {
    if (oct.find_first_not_of("01234567") != std::string::npos) {
        return "-1";
    }
    std::string result = "";
    int length_of_oct = oct.length();

    for (int i = 0; i < length_of_oct; i++) {
        result += triades_[oct[i] - '0'];
    }

    return CutUnnecessaryZeroes(result);
}

int ProgrammerCalculator::ConvertOctToDec(const std::string &oct) {
    if (oct.find_first_not_of("01234567") != std::string::npos) {
        return -1;
    }
    return ConvertBinToDec(ConvertOctToBin(oct));
}

std::string ProgrammerCalculator::ConvertOctToHex(const std::string &oct) {
    if (oct.find_first_not_of("01234567") != std::string::npos) {
        return "-1";
    }
    return ConvertBinToHex(ConvertOctToBin(oct));
}

std::string ProgrammerCalculator::ConvertHexToBin(const std::string &hex) {
    if (hex.find_first_not_of("0123456789abcdefABCDEF") != std::string::npos) {
        return "-1";
    }
    std::string result = "";
    int length_of_hex = hex.length();

    for (int i = 0; i < length_of_hex; i++) {
        if (hex[i] >= '0' && hex[i] <= '9') {
            result += tetrads_[hex[i] - '0'];
        } else if (hex[i] >= 'a' && hex[i] <= 'f') {
            result += tetrads_[10 + hex[i] - 'a'];
        } else if (hex[i] >= 'A' && hex[i] <= 'F') {
            result += tetrads_[10 + hex[i] - 'A'];
        }
    }

    return CutUnnecessaryZeroes(result);
}

std::string ProgrammerCalculator::ConvertHexToOct(const std::string &hex) {
    if (hex.find_first_not_of("0123456789abcdefABCDEF") != std::string::npos) {
        return "-1";
    }
    return ConvertBinToOct(ConvertHexToBin(hex));
}

int ProgrammerCalculator::ConvertHexToDec(const std::string &hex) {
    if (hex.find_first_not_of("0123456789abcdefABCDEF") != std::string::npos) {
        return -1;
    }
    return ConvertBinToDec(ConvertHexToBin(hex));
}


std::string ProgrammerCalculator::CutUnnecessaryZeroes(const std::string &bin) {
    std::string bin_copy = bin;
    int length_of_bin = bin_copy.length();
    int position_of_the_first_one = bin_copy.find("1");

    if (position_of_the_first_one < length_of_bin) {
        bin_copy = bin_copy.substr(position_of_the_first_one, length_of_bin);
    }

    return bin_copy;
}
