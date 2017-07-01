// Copyright 2017 Nesterov Alexander

#include "../include/lab_space.h"

#include <stdint.h>
#include <string>
#include <algorithm>

void LABSpace::Swap(LABSpace &lab_space) {
    std::swap(lightness_, lab_space.lightness_);
    std::swap(a_, lab_space.a_);
    std::swap(b_, lab_space.b_);
}

LABSpace::LABSpace() {
    lightness_ = 0;
    a_ = 0;
    b_ = 0;
}

LABSpace::LABSpace(const int lightness,
                   const int a,
                   const int b) {
    if ((lightness < 0) || (lightness > 100)) {
        throw std::string("The index of lightness isn't in the range 0-100");
    } else if ((a < 0) || (a > 128)) {
        throw std::string("The index of a color isn't in the range 0-128");
    } else if ((b < 0) || (b > 128)) {
        throw std::string("The index of b color isn't in the range 0-128");
    } else {
        lightness_ = static_cast<uint8_t>(lightness);
        a_ = static_cast<uint8_t>(a);
        b_ = static_cast<uint8_t>(b);
    }
}

LABSpace::LABSpace(const LABSpace &lab_space) {
    lightness_ = lab_space.lightness_;
    a_ = lab_space.a_;
    b_ = lab_space.b_;
}

LABSpace& LABSpace::operator=(const LABSpace &lab_space) {
    if (this != &lab_space) {
        LABSpace(lab_space).Swap(*this);
    }
    return *this;
}

uint8_t LABSpace::GetLightness() const {
    return lightness_;
}

uint8_t LABSpace::GetA() const {
    return a_;
}

uint8_t LABSpace::GetB() const {
    return b_;
}

void LABSpace::SetLightness(const int lightness) {
    if ((lightness < 0) || (lightness > 100)) {
        throw std::string("The index of lightness isn't in the range 0-100");
    } else {
        lightness_ = static_cast<uint8_t>(lightness);
    }
}

void LABSpace::SetA(const int a) {
    if ((a < 0) || (a > 128)) {
        throw std::string("The index of a color isn't in the range 0-128");
    }  else {
        a_ = static_cast<uint8_t>(a);
    }
}

void LABSpace::SetB(const int b) {
    if ((b < 0) || (b > 128)) {
        throw std::string("The index of b color isn't in the range 0-128");
    } else {
        b_ = static_cast<uint8_t>(b);
    }
}

bool operator==(const LABSpace &lab_space_left,
                const LABSpace &lab_space_right) {
    if (&lab_space_left == &lab_space_right) {
        return true;
    } else {
        return ((lab_space_left.lightness_ == lab_space_right.lightness_) &&
            (lab_space_left.a_ == lab_space_right.a_) &&
            (lab_space_left.b_ == lab_space_right.b_));
    }
}

bool operator!=(const LABSpace &lab_space_left,
                const LABSpace &lab_space_right) {
    return !(lab_space_left == lab_space_right);
}
