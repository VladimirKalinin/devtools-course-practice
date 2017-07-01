// Copyright 2017 Nazarov Aleksandr

#ifndef MODULES_VOLUME_CALCULATOR_INCLUDE_VOLUME_CALCULATOR_H_
#define MODULES_VOLUME_CALCULATOR_INCLUDE_VOLUME_CALCULATOR_H_
#define _USE_MATH_DEFINES

#include <math.h>

// Class "Volume" can calculate volume of 3d figure.
// Class "Volume" have only static methods because
// to calculate volume of figure we don't need create object of class
class Volume {
 public:
    // a is side length of cube
    static double Cube(double a);
    // a is rib length of dodecahedron
    static double Dodecahedron(double a);
    // h is height of cylinder, r is radius
    static double Cylinder(double h, double r);
    // S is base area, h is height
    static double Parallelepiped(double S, double h);
    // a,b is rib of base area, h is height
    static double Parallelepiped(double a, double b, double h);
    // a,b,c is non parallel rib, x is argument of sine of slope angle
    static double Parallelepiped(double a, double b, double c, double x);
    // S is base area of pyramid, h is height
    static double Pyramid(double S, double h);
    // a is rid of base triangle of pyramid, base_h is height of base triangle,
    // pyramid_h is height of pyramid
    static double Pyramid(double a, double base_h, double pyramid_h);
    // h is height of cone, r is radius of cone
    static double Cone(double h, double r);
    // r is radius of sphere
    static double Sphere(double r);
    // a, b, c is radius of perpendicular axis of ellipsoid
    static double Ellipsoid(double a, double b, double c);
    // r is rarius of paraboloid, h is height of paraboloid
    static double Paraboloid(double h, double r);
    // a,b,c is perpendicular rib of rectangular parallelepiped
    static double RectangularParallelepiped(double a, double b, double c);
    // r_base_1, r_base_2 is radius of bases of frustum, h is height of frustum
    static double Frustum(double r_base_1, double r_base_2, double h);
};
#endif  // MODULES_VOLUME_CALCULATOR_INCLUDE_VOLUME_CALCULATOR_H_
