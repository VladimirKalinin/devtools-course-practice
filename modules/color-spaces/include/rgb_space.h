// Copyright 2017 Nesterov Alexander
#ifndef MODULES_COLOR_SPACES_INCLUDE_RGB_SPACE_H_
#define MODULES_COLOR_SPACES_INCLUDE_RGB_SPACE_H_
#include <stdint.h>
#include <algorithm>
#include "../include/hsb_hsv_space.h"
#include "../include/xyz_space.h"


class RGBSpace {
 public:
    RGBSpace();
    RGBSpace(const int red, const int green, const int blue);
    RGBSpace(const RGBSpace &rgb_space);
    explicit RGBSpace(const HSBHSVSpace &hsbhsv_space);
    explicit RGBSpace(const XYZSpace &xyz_space);

    RGBSpace& operator=(const RGBSpace &rgb_space);

    uint8_t GetRed() const;
    uint8_t GetGreen() const;
    uint8_t GetBlue() const;
    void SetRed(const int red_);
    void SetGreen(const int green_);
    void SetBlue(const int blue_);

    friend bool operator==(const RGBSpace &rgb_space_left,
                           const RGBSpace &rgb_space_right);
    friend bool operator!=(const RGBSpace &rgb_space_left,
                           const RGBSpace &rgb_space_right);

    operator HSBHSVSpace() const { return ToHSBHSVSpace(); }
    operator XYZSpace() const { return ToXYZSpace(); }

 private:
    uint8_t red_;
    uint8_t green_;
    uint8_t blue_;
    void Swap(RGBSpace &rgb_space);
    HSBHSVSpace ToHSBHSVSpace() const;
    XYZSpace ToXYZSpace() const;
};

#endif  // MODULES_COLOR_SPACES_INCLUDE_RGB_SPACE_H_
