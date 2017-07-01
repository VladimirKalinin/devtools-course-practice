// Copyright 2017 Nesterov Alexander

#ifndef MODULES_COLOR_SPACES_INCLUDE_HSB_HSV_SPACE_H_
#define MODULES_COLOR_SPACES_INCLUDE_HSB_HSV_SPACE_H_

#include <stdint.h>
#include <algorithm>

class HSBHSVSpace {
 public:
    HSBHSVSpace();
    HSBHSVSpace(const int hue, const int saturation,
                const int value_brightnes);
    HSBHSVSpace(const HSBHSVSpace &hsb_hsv_space);

    HSBHSVSpace& operator=(const HSBHSVSpace &hsb_hsv_space);

    uint16_t GetHue() const;
    uint16_t GetSaturation() const;
    uint16_t GetValueBrightnes() const;
    void SetHue(const int hue);
    void SetSaturation(const int saturation);
    void SetValueBrightnes(const int value_brightnes);

    friend bool operator==(const HSBHSVSpace &hsb_hsv_space_left,
                           const HSBHSVSpace &hsb_hsv_space_right);
    friend bool operator!=(const HSBHSVSpace &hsb_hsv_space_left,
                           const HSBHSVSpace &hsb_hsv_space_right);

 private:
    uint16_t hue_;
    uint16_t saturation_;
    uint16_t value_brightnes_;
    void Swap(HSBHSVSpace &hsb_hsv_space);
};

#endif  // MODULES_COLOR_SPACES_INCLUDE_HSB_HSV_SPACE_H_
