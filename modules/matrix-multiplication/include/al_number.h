// Copyright 2017 Baranov Evgeny

#ifndef MODULES_MATRIX_MULTIPLICATION_INCLUDE_AL_NUMBER_H_
#define MODULES_MATRIX_MULTIPLICATION_INCLUDE_AL_NUMBER_H_

#include <string>
#include <iostream>

class ALNumber {
 public:
    ALNumber();

    explicit ALNumber(const std::string& _str);

    bool operator == (const ALNumber& _number) const;

    bool operator == (const std::string& _str) const;

    bool operator != (const ALNumber& _number) const;

    bool operator != (const std::string& _str) const;

    ALNumber& operator = (const std::string& _str);

    ALNumber operator + (const ALNumber& _number) const;

    ALNumber operator + (const std::string& _number) const;

    ALNumber operator * (const ALNumber& _number) const;

    ALNumber operator * (const std::string& _number) const;

    std::string GetValue() const;

 private:
    std::string number_representation_;
    unsigned int size_;
    ALNumber Sum(const ALNumber& _firstnum,
        const ALNumber& _secondnum) const;
    ALNumber Compos(const ALNumber& _firstnum,
        const ALNumber& _secondnum) const;
};
#endif  // MODULES_MATRIX_MULTIPLICATION_INCLUDE_AL_NUMBER_H_
