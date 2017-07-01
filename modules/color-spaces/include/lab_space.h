// Copyright 2017 Nesterov Alexander

#ifndef MODULES_COLOR_SPACES_INCLUDE_LAB_SPACE_H_
#define MODULES_COLOR_SPACES_INCLUDE_LAB_SPACE_H_
#include <stdint.h>
#include <algorithm>

class LABSpace {
 public:
    LABSpace();
    LABSpace(const int lightness, const int a, const int b);
    LABSpace(const LABSpace &lab_space);

    LABSpace& operator=(const LABSpace &lab_space);

    uint8_t GetLightness() const;
    uint8_t GetA() const;
    uint8_t GetB() const;
    void SetLightness(const int lightness);
    void SetA(const int a);
    void SetB(const int b);

    friend bool operator==(const LABSpace &lab_space_left,
                           const LABSpace &lab_space_right);
    friend bool operator!=(const LABSpace &lab_space_left,
                           const LABSpace &lab_space_right);

 private:
    uint8_t lightness_;
    uint8_t a_;
    uint8_t b_;
    void Swap(LABSpace &lab_space);
};

#endif  // MODULES_COLOR_SPACES_INCLUDE_LAB_SPACE_H_
