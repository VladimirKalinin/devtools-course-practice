// Copyright 2017 Zorina Ekaterina

#ifndef MODULES_VECTOR3D_INCLUDE_VECTOR3D_H_
#define MODULES_VECTOR3D_INCLUDE_VECTOR3D_H_

#include <iostream>
#include <cmath>


// Vector in 3-dimensional space
class Vector3D {
 public:
    explicit Vector3D(double _x = 0.0, double _y = 0.0, double _z = 0.0);
    Vector3D(const Vector3D &v);                // copy constructor
    double GetX() const { return x_; }            // access
    double GetY() const { return y_; }
    double GetZ() const { return z_; }

    void SetX(double _x) { x_ = _x; }
    void SetY(double _y) { y_ = _y; }
    void SetZ(double _z) { z_ = _z; }

    bool operator==(const Vector3D &v) const;  // comparison
    bool operator!=(const Vector3D &v) const;  // comparison

    Vector3D& operator=(const Vector3D &v);     // assigment

    Vector3D  operator+(const Vector3D &v) const;     // addition
    Vector3D  operator-(const Vector3D &v) const;     // subtraction
    double Norm();                        // vector norm
    Vector3D Normalize();                // normalization vector
    double  operator*(const Vector3D &v) const;     // scalar product
    Vector3D  operator^(const Vector3D &v) const;   // vector product v1 ^ v2

 protected:
    double x_;
    double y_;
    double z_;
};


#endif     // MODULES_VECTOR3D_INCLUDE_VECTOR3D_H_
