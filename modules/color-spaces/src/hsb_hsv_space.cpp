// Copyright 2017 Nesterov Alexander

#include "../include/hsb_hsv_space.h"

#include <stdint.h>
#include <string>
#include <algorithm>

void HSBHSVSpace::Swap(HSBHSVSpace &hsb_hsv_space) {
    std::swap(hue_, hsb_hsv_space.hue_);
    std::swap(saturation_, hsb_hsv_space.saturation_);
    std::swap(value_brightnes_, hsb_hsv_space.value_brightnes_);
}

HSBHSVSpace::HSBHSVSpace() {
    hue_ = 0;
    saturation_ = 0;
    value_brightnes_ = 0;
}

HSBHSVSpace::HSBHSVSpace(const int hue,
                   const int saturation,
                   const int value_brightnes) {
    if ((hue < 0) || (hue > 360)) {
        throw std::string("The index of hue not in the range 0-360");
    } else if ((saturation < 0) || (saturation > 100)) {
        throw std::string("The index of saturation not in the range 0-100");
    } else if ((value_brightnes < 0) || (value_brightnes > 100)) {
        throw std::string("The index of brightnes not in the range 0-100");
    } else {
        hue_ = static_cast<uint16_t>(hue);
        saturation_ = static_cast<uint16_t>(saturation);
        value_brightnes_ = static_cast<uint16_t>(value_brightnes);
    }
}

HSBHSVSpace::HSBHSVSpace(const HSBHSVSpace &hsb_hsv_space) {
    hue_ = hsb_hsv_space.hue_;
    saturation_ = hsb_hsv_space.saturation_;
    value_brightnes_ = hsb_hsv_space.value_brightnes_;
}

HSBHSVSpace& HSBHSVSpace::operator=(const HSBHSVSpace &hsb_hsv_space) {
    if (this != &hsb_hsv_space) {
        HSBHSVSpace(hsb_hsv_space).Swap(*this);
    }
    return *this;
}

uint16_t HSBHSVSpace::GetHue() const {
    return hue_;
}

uint16_t HSBHSVSpace::GetSaturation() const {
    return saturation_;
}

uint16_t HSBHSVSpace::GetValueBrightnes() const {
    return value_brightnes_;
}

void HSBHSVSpace::SetHue(const int hue) {
    if ((hue < 0) || (hue > 360)) {
        throw std::string("The index of hue isn't in the range 0-360");
    } else {
        hue_ = static_cast<uint16_t>(hue);
    }
}

void HSBHSVSpace::SetSaturation(const int saturation) {
    if ((saturation < 0) || (saturation > 100)) {
        throw std::string("The index of saturation isn't in the range 0-100");
    }  else {
        saturation_ = static_cast<uint16_t>(saturation);
    }
}

void HSBHSVSpace::SetValueBrightnes(const int value_brightnes) {
    if ((value_brightnes < 0) || (value_brightnes > 100)) {
        throw std::string("The index of brightnes isn't in the range 0-100");
    } else {
        value_brightnes_ = static_cast<uint16_t>(value_brightnes);
    }
}

bool operator==(const HSBHSVSpace &hsb_hsv_space_left,
                const HSBHSVSpace &hsb_hsv_space_right) {
    if (&hsb_hsv_space_left == &hsb_hsv_space_right) {
        return true;
    } else {
        return ((hsb_hsv_space_left.hue_ == hsb_hsv_space_right.hue_) &&
            (hsb_hsv_space_left.saturation_ == hsb_hsv_space_right.saturation_)
            && (hsb_hsv_space_left.value_brightnes_ ==
                hsb_hsv_space_right.value_brightnes_));
    }
}

bool operator!=(const HSBHSVSpace &hsb_hsv_space_left,
                const HSBHSVSpace &hsb_hsv_space_right) {
    return !(hsb_hsv_space_left == hsb_hsv_space_right);
}
