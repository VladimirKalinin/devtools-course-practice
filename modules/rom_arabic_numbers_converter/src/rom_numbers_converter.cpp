// Copyright 2017 Ivan Kochin
// I 1
// V 5
// X 10
// L 50
// C 100
// D 500
// M 1000
#include "include/rom_numbers_converter.h"
#include <string>



string RomNumConverter::ConvertArabicToRom(int temp) {
    int buf = temp;
    string result = "";
    // thousands
    while (buf >= 1000) {
        result += 'M';
        buf -= 1000;
    }
    // houndreds
    if (buf / 100 == 9) {
        result +="CM";
        buf -= 900;
    }
    if (buf / 100 == 4) {
        result += "CD";
        buf -= 400;
    }
    if (buf / 100 == 5) {
        result += 'D';
        buf -= 500;
    }
    while (buf >= 100) {
        result += 'C';
        buf -= 100;
    }
    //  decade
    if (buf / 10 == 9) {
        result += "XC";
        buf -= 90;
    }
    if (buf / 10 == 4) {
        result += "XL";
        buf -= 40;
    }
    if (buf / 10 == 5) {
        result += 'L';
        buf -= 50;
    }
    while (buf >= 10) {
        result += 'X';
        buf -= 10;
    }
    //  units
    if (buf == 9) {
        result += "IX";
        buf -= 9;
    }
    if (buf == 4) {
        result += "IV";
        buf -= 4;
    }
    if (buf == 5) {
        result += 'V';
        buf -= 5;
    }
    while (buf > 0) {
        result += 'I';
        buf -= 1;
    }
    return result;
}

int  RomNumConverter::ConvertRomToArabic(const string& bufstr) {
    int result = 0;
    for (unsigned int i = 0 ; i < bufstr.length() ; i++) {
    switch (bufstr[i]) {
        case 'I':  // 1
            result += 1;
            break;
        case 'V':  // 5
            result += 5;
            break;
        case 'X':  // 10
            result += 10;
            break;
        case 'L':  // 50
            result += 50;
            break;
        case 'C':  // 100
            result += 100;
            break;
        case 'D':  // 500
            result += 500;
            break;
        case 'M':  // 1000
            result += 1000;
            break;
        default:
            throw std::string("Incorrect number");
    }
    }

    for (unsigned int i = 0; i < bufstr.length()-1; i++) {
        if (bufstr[i] == 'I' && bufstr[i + 1] == 'V') { result -= 2; }
        if (bufstr[i] == 'I' && bufstr[i + 1] == 'X') { result -= 2; }
        if (bufstr[i] == 'X' && bufstr[i + 1] == 'L') { result -= 20; }
        if (bufstr[i] == 'X' && bufstr[i + 1] == 'C') { result -= 20; }
        if (bufstr[i] == 'C' && bufstr[i + 1] == 'D') { result -= 200; }
        if (bufstr[i] == 'C' && bufstr[i + 1] == 'M') { result -= 200; }
    }
    return result;
}
