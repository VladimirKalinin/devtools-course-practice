// Copyright 2017 Nesterov Alexander

#include "../include/rgb_space.h"
#include <math.h>
#include <string>
#include <algorithm>

void RGBSpace::Swap(RGBSpace &rgb_space) {
    std::swap(red_, rgb_space.red_);
    std::swap(green_, rgb_space.green_);
    std::swap(blue_, rgb_space.blue_);
}

HSBHSVSpace RGBSpace::ToHSBHSVSpace() const {
    double red_quote = static_cast<double>(red_) / 255;
    double green_quote = static_cast<double>(green_) / 255;
    double blue_quote = static_cast<double>(blue_) / 255;

    double min = std::min(red_quote, std::min(green_quote, blue_quote));
    double max = std::max(red_quote, std::max(green_quote, blue_quote));

    uint16_t hue = 0, saturation, value_brightnes;
    if (max == min) {
        hue = 0;
    } else if ((max == red_quote) && (green_quote >= blue_quote)) {
        hue = static_cast<uint16_t>(round(
            60 * ((green_quote - blue_quote)/(max - min))));
    } else if ((max == red_quote) && (green_quote < blue_quote)) {
        hue = static_cast<uint16_t>(round(
            60 * ((green_quote - blue_quote)/(max - min)) + 360));
    } else if (max == green_quote) {
        hue = static_cast<uint16_t>(round(
            60 * ((blue_quote - red_quote)/(max - min)) + 120));
    } else if (max == blue_quote) {
        hue = static_cast<uint16_t>(round(
            60 * ((red_quote - green_quote)/(max - min)) + 240));
    }

    saturation = (uint16_t) round((max == 0) ? 0 : (1 - min/max)*100);

    value_brightnes = (uint16_t) round(max * 100);

    HSBHSVSpace hsbhsv_space(hue, saturation, value_brightnes);

    return hsbhsv_space;
}

XYZSpace RGBSpace::ToXYZSpace() const {
    double red_quote = static_cast<double >(red_) / 255;
    double green_quote = static_cast<double >(green_) / 255;
    double blue_quote = static_cast<double >(blue_) / 255;

    if (red_quote > 0.04045) {
        red_quote = pow((red_quote + 0.055) / 1.055, 2.4);
    } else {
        red_quote /= 12.92;
    }

    if (green_quote > 0.04045) {
        green_quote = pow((green_quote + 0.055) / 1.055, 2.4);
    } else {
        green_quote /= 12.92;
    }

    if (blue_quote > 0.04045) {
        blue_quote = pow((blue_quote + 0.055) / 1.055, 2.4);
    } else {
        blue_quote /= 12.92;
    }

    red_quote *= 100;
    green_quote *= 100;
    blue_quote *= 100;

    uint8_t x = static_cast<uint8_t>(round(
        red_quote *0.4124564 + green_quote*0.3575761 + blue_quote*0.1804375));
    uint8_t y = static_cast<uint8_t>(round(
        red_quote *0.2126729 + green_quote*0.7151522 + blue_quote*0.0721750));
    uint8_t z = static_cast<uint8_t>(round(
        red_quote *0.0193339 + green_quote*0.1191920 + blue_quote*0.9503041));

    XYZSpace xyz_space(x, y, z);
    return xyz_space;
}

RGBSpace::RGBSpace() {
    red_ = 0;
    green_ = 0;
    blue_ = 0;
}

RGBSpace::RGBSpace(const int red,
                   const int green,
                   const int blue) {
    if ((red < 0) || (red > 255)) {
        throw std::string("The index of red color isn't in the range 0-255");
    } else if ((green < 0) || (green > 255)) {
        throw std::string("The index of green color isn't in the range 0-255");
    } else if ((blue < 0) || (blue > 255)) {
        throw std::string("The index of blue color isn't in the range 0-255");
    } else {
        red_ = static_cast<uint8_t>(red);
        green_ = static_cast<uint8_t>(green);
        blue_ = static_cast<uint8_t>(blue);
    }
}

RGBSpace::RGBSpace(const RGBSpace &rgb_space) {
    red_ = rgb_space.red_;
    green_ = rgb_space.green_;
    blue_ = rgb_space.blue_;
}

RGBSpace::RGBSpace(const HSBHSVSpace &hsbhsv_space) {
    uint16_t hue = hsbhsv_space.GetHue();
    uint16_t saturation = hsbhsv_space.GetSaturation();
    uint16_t value_brightnes = hsbhsv_space.GetValueBrightnes();

    uint8_t index = static_cast<uint8_t>(
        floor(static_cast<double>(hue)/60)) % 6;

    double v_min = ((100.0 - static_cast<double>(saturation))*
        value_brightnes) / 100;

    double a = ((static_cast<double>(value_brightnes) - v_min))*
        (static_cast<double>(hue % 60)/60);

    double v_inc = v_min + a;
    double v_dec = static_cast<double>(value_brightnes) - a;

    double red_quote = 0, green_quote = 0, blue_quote = 0;

    switch (index) {
        case 0:
            red_quote = static_cast<double>(value_brightnes);
            green_quote = v_inc;
            blue_quote = v_min;
            break;
        case 1:
            red_quote = v_dec;
            green_quote = static_cast<double>(value_brightnes);
            blue_quote = v_min;
            break;
        case 2:
            red_quote = v_min;
            green_quote = static_cast<double>(value_brightnes);
            blue_quote = v_inc;
            break;
        case 3:
            red_quote = v_min;
            green_quote = v_dec;
            blue_quote = static_cast<double>(value_brightnes);
            break;
        case 4:
            red_quote = v_inc;
            green_quote = v_min;
            blue_quote = static_cast<double>(value_brightnes);
            break;
        case 5:
            red_quote = static_cast<double>(value_brightnes);
            green_quote = v_min;
            blue_quote = v_dec;
            break;
    }

    red_ = static_cast<uint8_t >(round(red_quote * 255 / 100));
    green_ = static_cast<uint8_t >(round(green_quote * 255 / 100));
    blue_ = static_cast<uint8_t >(round(blue_quote * 255 / 100));
}

RGBSpace::RGBSpace(const XYZSpace &xyz_space) {
    double x_quote = static_cast<double>(xyz_space.GetX())/100;
    double y_quote = static_cast<double>(xyz_space.GetY())/100;
    double z_quote = static_cast<double>(xyz_space.GetZ())/100;

    double red_quote =
        x_quote * 3.2404542  + y_quote*(-1.5371385) + z_quote*(-0.4985314);
    double green_quote =
        x_quote*(-0.9692660) + y_quote * 1.8760108  + z_quote * 0.0415560;
    double blue_quote =
        x_quote * 0.0556434  + y_quote*(-0.2040259) + z_quote * 1.0572252;

    if (red_quote > 0.0031308) {
        red_quote = 1.055 * (pow(red_quote, 1/2.4)) - 0.055;
    } else {
        red_quote = 12.92 * red_quote;
    }

    if (green_quote > 0.0031308) {
        green_quote = 1.055 * (pow(green_quote, 1/2.4)) - 0.055;
    } else {
        green_quote = 12.92 * green_quote;
    }

    if (blue_quote > 0.0031308) {
        blue_quote = 1.055 * (pow(blue_quote, 1/2.4)) - 0.055;
    } else {
        blue_quote = 12.92 * red_quote;
    }

    red_ = static_cast<uint8_t>(round(red_quote*255));
    green_ = static_cast<uint8_t>(round(green_quote*255));
    blue_ = static_cast<uint8_t>(round(blue_quote*255));
}

RGBSpace& RGBSpace::operator=(const RGBSpace &rgb_space) {
    if (this != &rgb_space) {
        RGBSpace(rgb_space).Swap(*this);
    }
    return *this;
}

uint8_t RGBSpace::GetRed() const {
    return red_;
}

uint8_t RGBSpace::GetGreen() const {
    return green_;
}

uint8_t RGBSpace::GetBlue() const {
    return blue_;
}

void RGBSpace::SetRed(const int red) {
    if ((red < 0) || (red > 255)) {
        throw std::string("The index of red color isn't in the range 0-255");
    } else {
        red_ = static_cast<uint8_t>(red);
    }
}

void RGBSpace::SetGreen(const int green) {
    if ((green < 0) || (green > 255)) {
        throw std::string("The index of green color isn't in the range 0-255");
    }  else {
        green_ = static_cast<uint8_t>(green);
    }
}

void RGBSpace::SetBlue(const int blue) {
    if ((blue < 0) || (blue > 255)) {
        throw std::string("The index of blue color isn't in the range 0-255");
    } else {
        blue_ = static_cast<uint8_t>(blue);
    }
}

bool operator==(const RGBSpace &rgb_space_left,
                const RGBSpace &rgb_space_right) {
    if (&rgb_space_left == &rgb_space_right) {
        return true;
    } else {
        return ((rgb_space_left.red_ == rgb_space_right.red_) &&
            (rgb_space_left.green_ == rgb_space_right.green_) &&
            (rgb_space_left.blue_ == rgb_space_right.blue_));
    }
}

bool operator!=(const RGBSpace &rgb_space_left,
                const RGBSpace &rgb_space_right) {
    return !(rgb_space_left == rgb_space_right);
}
