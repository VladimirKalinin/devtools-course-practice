// Copyright 2017 Nesterov Alexander

#include "../include/xyz_space.h"
#include <math.h>
#include <stdint.h>
#include <string>
#include <algorithm>


void XYZSpace::Swap(XYZSpace &xyz_space) {
    std::swap(x_, xyz_space.x_);
    std::swap(y_, xyz_space.y_);
    std::swap(z_, xyz_space.z_);
}

LABSpace XYZSpace::ToLABSpace() const {
    double x_quote = static_cast<double>(x_) / 95.05;
    double y_quote = static_cast<double>(y_) / 100;
    double z_quote = static_cast<double>(z_) / 108.9;

    if (x_quote > 0.008856) {
        x_quote = pow(x_quote, 1.0/3);
    } else {
        x_quote = (7.787 * x_quote) + (16.0/116);
    }

    if (y_quote > 0.008856) {
        y_quote = pow(y_quote, 1.0/3);
    } else {
        y_quote = (7.787 * y_quote) + (16.0/116);
    }

    if (z_quote > 0.008856) {
        z_quote = pow(z_quote, 1.0/3);
    } else {
        z_quote = (7.787 * z_quote) + (16.0/116);
    }

    uint8_t lightness = static_cast<uint8_t>(round((116.0*y_quote)-16.0));
    uint8_t a = static_cast<uint8_t>(round(500.0 * (x_quote - y_quote)));
    uint8_t b = static_cast<uint8_t>(round(200.0 * (y_quote - z_quote)));

    LABSpace lab_space(lightness, a, b);
    return lab_space;
}

XYZSpace::XYZSpace() {
    x_ = 0;
    y_ = 0;
    z_ = 0;
}

XYZSpace::XYZSpace(const int x,
                   const int y,
                   const int z) {
    if ((x < 0) || (x > 95)) {
        throw std::string("The index of x isn't in the range 0-95");
    } else if ((y < 0) || (y > 100)) {
        throw std::string("The index of y isn't in the range 0-100");
    } else if ((z < 0) || (z > 108)) {
        throw std::string("The index of z isn't in the range 0-108");
    } else {
        x_ = static_cast<uint8_t>(x);
        y_ = static_cast<uint8_t> (y);
        z_ = static_cast<uint8_t> (z);
    }
}

XYZSpace::XYZSpace(const XYZSpace &xyz_space) {
    x_ = xyz_space.x_;
    y_ = xyz_space.y_;
    z_ = xyz_space.z_;
}

XYZSpace::XYZSpace(const LABSpace &lab_space) {
    double y_quote =
        (((static_cast<double>(lab_space.GetLightness())) + 16.0) / 116.0);
    double x_quote =
        (static_cast<double>(lab_space.GetA()) / 500 + y_quote);
    double z_quote =
        (y_quote - static_cast<double>(lab_space.GetB()) / 200);

    if (pow(y_quote, 3.0) > 0.008856) {
        y_quote = pow(y_quote, 3.0);
    } else {
        y_quote = (y_quote - 16.0/116) / 7.787;
    }

    if (pow(x_quote, 3.0) > 0.008856) {
        x_quote = pow(y_quote, 3.0);
    } else {
        x_quote = (x_quote - 16.0/116) / 7.787;
    }

    if (pow(z_quote, 3.0) > 0.008856) {
        z_quote = pow(z_quote, 3.0);
    } else {
        z_quote = (z_quote - 16.0/116) / 7.787;
    }

    x_ = static_cast<uint8_t>((x_quote * 95.05));
    y_ = static_cast<uint8_t>((y_quote * 100));
    z_ = static_cast<uint8_t>((z_quote * 108.9));
}

XYZSpace& XYZSpace::operator=(const XYZSpace &xyz_space) {
    if (this != &xyz_space) {
        XYZSpace(xyz_space).Swap(*this);
    }
    return *this;
}

uint8_t XYZSpace::GetX() const {
    return x_;
}

uint8_t XYZSpace::GetY() const {
    return y_;
}

uint8_t XYZSpace::GetZ() const {
    return z_;
}

void XYZSpace::SetX(const int x) {
    if ((x < 0) || (x > 95)) {
        throw std::string("The index of x isn't in the range 0-95");
    } else {
        x_ = static_cast<uint8_t>(x);
    }
}

void XYZSpace::SetY(const int y) {
    if ((y < 0) || (y > 100)) {
        throw std::string("The index of y isn't in the range 0-100");
    }  else {
        y_ = static_cast<uint8_t>(y);
    }
}

void XYZSpace::SetZ(const int z) {
    if ((z < 0) || (z > 108)) {
        throw std::string("The index of z isn't in the range 0-108");
    } else {
        z_ = static_cast<uint8_t>(z);
    }
}

bool operator==(const XYZSpace &xyz_space_left,
                const XYZSpace &xyz_space_right) {
    if (&xyz_space_left == &xyz_space_right) {
        return true;
    } else {
        return ((xyz_space_left.x_ == xyz_space_right.x_) &&
            (xyz_space_left.y_ == xyz_space_right.y_) &&
            (xyz_space_left.z_ == xyz_space_right.z_));
    }
}

bool operator!=(const XYZSpace &xyz_space_left,
                const XYZSpace &xyz_space_right) {
    return !(xyz_space_left == xyz_space_right);
}
