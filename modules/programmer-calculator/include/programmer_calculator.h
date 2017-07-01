// Copyright 2017 Komarov Nikolay

#ifndef MODULES_PROGRAMMER_CALCULATOR_INCLUDE_PROGRAMMER_CALCULATOR_H_
#define MODULES_PROGRAMMER_CALCULATOR_INCLUDE_PROGRAMMER_CALCULATOR_H_

#include <string>
#include <vector>

class ProgrammerCalculator {
 public:
    ProgrammerCalculator();

    std::string ConvertDecToBin(int dec);
    std::string ConvertDecToOct(int dec);
    std::string ConvertDecToHex(int dec);

    std::string ConvertBinToOct(const std::string &bin);
    int ConvertBinToDec(const std::string &bin);
    std::string ConvertBinToHex(const std::string &bin);

    std::string ConvertOctToBin(const std::string &oct);
    int ConvertOctToDec(const std::string &oct);
    std::string ConvertOctToHex(const std::string &oct);

    std::string ConvertHexToBin(const std::string &hex);
    std::string ConvertHexToOct(const std::string &hex);
    int ConvertHexToDec(const std::string &hex);

 private:
    static std::vector<std::string> triades_;
    static std::vector<std::string> tetrads_;
    static std::vector<std::string> chars_set_;
    std::string CutUnnecessaryZeroes(const std::string &bin);
};

#endif  // MODULES_PROGRAMMER_CALCULATOR_INCLUDE_PROGRAMMER_CALCULATOR_H_
