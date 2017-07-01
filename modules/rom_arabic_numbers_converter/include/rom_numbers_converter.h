// Copyright 2017 Ivan Kochin



#ifndef MODULES_ROM_ARABIC_NUMBERS_CONVERTER_INCLUDE_ROM_NUMBERS_CONVERTER_H_
#define MODULES_ROM_ARABIC_NUMBERS_CONVERTER_INCLUDE_ROM_NUMBERS_CONVERTER_H_

#include <string>
#include <iostream>

using std::string;

class RomNumConverter {
 public:
    static string ConvertArabicToRom(int temp);
    static int ConvertRomToArabic(const string& bufstr);
};
#endif  // MODULES_ROM_ARABIC_NUMBERS_CONVERTER_INCLUDE_ROM_NUMBERS_CONVERTER_H_
