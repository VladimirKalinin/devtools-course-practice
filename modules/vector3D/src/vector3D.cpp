// Copyright 2017 Zorina Ekaterina

#include "include/vector3D.h"

Vector3D::Vector3D(double _x, double _y, double _z) {
    x_ = _x;
    y_ = _y;
    z_ = _z;
}

Vector3D::Vector3D(const Vector3D &v) {
    x_ = v.x_;
    y_ = v.y_;
    z_ = v.z_;
}

bool Vector3D::operator==(const Vector3D &v) const {
    if (x_ == v.x_ && y_ == v.y_ && z_ == v.z_)
        return true;
    else
        return false;
}

bool Vector3D::operator!=(const Vector3D &v) const {
    return !(*this == v);
}

Vector3D& Vector3D::operator=(const Vector3D &v) {
    if (*this != v) {
        x_ = v.x_;
        y_ = v.y_;
        z_ = v.z_;
    }
    return *this;
}

Vector3D Vector3D::operator+(const Vector3D &v) const {
    Vector3D temp;
    temp.x_ = x_ + v.x_;
    temp.y_ = y_ + v.y_;
    temp.z_ = z_ + v.z_;

    return temp;
}

Vector3D Vector3D::operator-(const Vector3D &v) const {
    Vector3D temp;
    temp.x_ = x_ - v.x_;
    temp.y_ = y_ - v.y_;
    temp.z_ = z_ - v.z_;

    return temp;
}

double Vector3D::Norm() {
    return sqrt(x_*x_ + y_*y_ + z_*z_);
}

Vector3D Vector3D::Normalize() {
    double norm = Norm();
    if (norm != 0.0) {
        x_ = x_ / norm;
        y_ = y_ / norm;
        z_ = z_ / norm;
    }

    return *this;
}

double Vector3D::operator*(const Vector3D & v) const {
    return x_*v.x_ + y_*v.y_ + z_*v.z_;
}

Vector3D Vector3D::operator^(const Vector3D & v) const {
    Vector3D vt(*this), temp;
    if (vt.x_ != 0 || vt.y_ != 0 || vt.z_ != 0) {
        if (v.x_ != 0 || v.y_ != 0 || v.z_ != 0) {
            temp.x_ = vt.y_*v.z_ - vt.z_*v.y_;
            temp.y_ = vt.z_*v.x_ - vt.x_*v.z_;
            temp.z_ = vt.x_*v.y_ - vt.y_*v.x_;
        }
    }
    return temp;
}
