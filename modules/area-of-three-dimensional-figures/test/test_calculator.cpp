// Copyright 2017 Kulygina Julia

#define _USE_MATH_DEFINES
#include <gtest/gtest.h>
#include "include/calculator.h"

TEST(AreaOfThreeDimensionalFiguresTest, Can_Create_Calc) {
    // Arrange & Act & Assert
    EXPECT_NO_THROW(Calculator z);
}

TEST(AreaOfThreeDimensionalFiguresTest, No_assert_Calc_Cone) {
    // Arrange
    double r = 2.0;
    double l = 1.0;
    Calculator z;

    // Act & Assert
    EXPECT_NO_THROW(z.Calculate_Cone(r, l));
}

TEST(AreaOfThreeDimensionalFiguresTest, Can_assert_Calc_Cone) {
    // Arrange
    double r = -2.0;
    double l = 1.0;
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calculate_Cone(r, l));
}

TEST(AreaOfThreeDimensionalFiguresTest, Can_assert_Calc_Cone_2) {
    // Arrange
    double r = 2.0;
    double l = -1.0;
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calculate_Cone(r, l));
}

TEST(AreaOfThreeDimensionalFiguresTest, Can_assert_Calc_Cone_3) {
    // Arrange
    double r = 2.0;
    double l = 0;
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calculate_Cone(r, l));
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_Cone) {
    // Arrang
    Calculator z;

    // Act
    double s = z.Calculate_Cone(1.0, 1.0);
    double s1 = M_PI;

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_Cone_2) {
    // Arrang
    Calculator z;

    // Act
    double s = z.Calculate_Cone(1.5, 1.5);
    double s1 = M_PI * 1.5 * 1.5;

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, No_Assert_Calc_Conoid) {
    // Arrange
    double r1 = 2.0;
    double r2 = 1.0;
    double l = 1.0;
    Calculator z;

    // Act & Assert
    EXPECT_NO_THROW(z.Calculate_Conoid(r1, r2, l));
}

TEST(AreaOfThreeDimensionalFiguresTest, Assert_Calc_Conoid) {
    // Arrange
    double r1 = -2.0;
    double r2 = 1.0;
    double l = 1.0;
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calculate_Conoid(r1, r2, l));
}

TEST(AreaOfThreeDimensionalFiguresTest, Assert_Calc_Conoid_2) {
    // Arrange
    double r1 = 2.0;
    double r2 = -1.0;
    double l = 1.0;
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calculate_Conoid(r1, r2, l));
}

TEST(AreaOfThreeDimensionalFiguresTest, Can_Assert_Calc_Conoid_3) {
    // Arrange
    double r1 = 2.0;
    double r2 = 1.0;
    double l = 0;
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calculate_Conoid(r1, r2, l));
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_Conoid) {
    // Arrang
    Calculator z;

    // Act
    double s = z.Calculate_Conoid(1.0, 1.0, 1.0);
    double s1 = 2 * M_PI;

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_Conoid_2) {
    // Arrang
    Calculator z;

    // Act
    double s = z.Calculate_Conoid(1.5, 1.5, 1.5);
    double s1 = M_PI * 3 * 1.5;

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, No_Assert_Calc_Cube) {
    // Arrange
    double h = 10.0;
    Calculator z;

    // Act & Assert
    EXPECT_NO_THROW(z.Calculate_Cube(h));
}

TEST(AreaOfThreeDimensionalFiguresTest, Assert_Calc_Cube) {
    // Arrange
    double h = -2.0;
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calculate_Cube(h));
}

TEST(AreaOfThreeDimensionalFiguresTest, Assert_Calc_Cube_2) {
    // Arrange
    double h = 0;
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calculate_Cube(h));
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_Cube) {
    // Arrang
    Calculator z;

    // Act
    double s = z.Calculate_Cube(1.0);
    double s1 = 6.0;

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_Cube_2) {
    // Arrang
    Calculator z;

    // Act
    double s = z.Calculate_Cube(1.5);
    double s1 = 6 * 1.5 * 1.5;

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, No_Assert_Calc_Cylinder) {
    // Arrange
    double r = 3.0;
    double h = 10.0;
    Calculator z;

    // Act & Assert
    EXPECT_NO_THROW(z.Calculate_Cylinder(r, h));
}

TEST(AreaOfThreeDimensionalFiguresTest, Assert_Calc_Cylinder) {
    // Arrange
    double r = -1.0;
    double h = 2.0;
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calculate_Cylinder(r, h));
}

TEST(AreaOfThreeDimensionalFiguresTest, Assert_Calc_Cylinder_2) {
    // Arrange
    double r = 1.0;
    double h = 0;
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calculate_Cylinder(r, h));
}

TEST(AreaOfThreeDimensionalFiguresTest, Assert_Calc_Cylinder_3) {
    // Arrange
    double r = 1.0;
    double h = -2.0;
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calculate_Cylinder(r, h));
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_Cylinder) {
    // Arrang
    Calculator z;

    // Act
    double s = z.Calculate_Cylinder(1.0, 1.0);
    double s1 = 2 * M_PI;

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_Cylinder_2) {
    // Arrang
    Calculator z;

    // Act
    double s = z.Calculate_Cylinder(1.5, 1.5);
    double s1 = 2 * M_PI * 1.5 * 1.5;

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, No_Assert_Calc_Parallelepiped) {
    // Arrange
    double a = 3.0;
    double b = 10.0;
    double c = 1.0;
    Calculator z;

    // Act & Assert
    EXPECT_NO_THROW(z.Calculate_Parallelepiped(a, b, c));
}

TEST(AreaOfThreeDimensionalFiguresTest, Assert_Calc_Parallelepiped) {
    // Arrange
    double a = -3.0;
    double b = 10.0;
    double c = 1.0;
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calculate_Parallelepiped(a, b, c));
}

TEST(AreaOfThreeDimensionalFiguresTest, Assert_Calc_Parallelepiped_2) {
    // Arrange
    double a = 3.0;
    double b = -10.0;
    double c = 1.0;
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calculate_Parallelepiped(a, b, c));
}

TEST(AreaOfThreeDimensionalFiguresTest, Assert_Calc_Parallelepiped_3) {
    // Arrange
    double a = 3.0;
    double b = 10.0;
    double c = -1.0;
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calculate_Parallelepiped(a, b, c));
}

TEST(AreaOfThreeDimensionalFiguresTest, Assert_Calc_Parallelepiped_4) {
    // Arrange
    double a = 3.0;
    double b = 10.0;
    double c = 0;
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calculate_Parallelepiped(a, b, c));
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_Parallelepiped) {
    // Arrang
    Calculator z;

    // Act
    double s = z.Calculate_Parallelepiped(1.0, 1.0, 1.0);
    double s1 = 6.0;

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_Parallelepiped_2) {
    // Arrang
    Calculator z;

    // Act
    double s = z.Calculate_Parallelepiped(1.5, 1.5, 1.5);
    double s1 = 3 * 2 * 1.5 * 1.5;

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, No_Assert_Calc_Prism) {
    // Arrange
    double a = 3.0;
    double b = 2.0;
    double c = 1.0;
    double h = 5.0;
    Calculator z;

    // Act & Assert
    EXPECT_NO_THROW(z.Calculate_Prism(a, b, c, h));
}

TEST(AreaOfThreeDimensionalFiguresTest, Assert_Calc_Prism) {
    // Arrange
    double a = -3.0;
    double b = 10.0;
    double c = 1.0;
    double h = 5.0;
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calculate_Prism(a, b, c, h));
}

TEST(AreaOfThreeDimensionalFiguresTest, Assert_Calc_Prism_2) {
    // Arrange
    double a = 3.0;
    double b = -10.0;
    double c = 1.0;
    double h = 5.0;
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calculate_Prism(a, b, c, h));
}

TEST(AreaOfThreeDimensionalFiguresTest, Assert_Calc_Prism_3) {
    // Arrange
    double a = 3.0;
    double b = 10.0;
    double c = -1.0;
    double h = 5.0;
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calculate_Prism(a, b, c, h));
}

TEST(AreaOfThreeDimensionalFiguresTest, Assert_Calc_Prism_4) {
    // Arrange
    double a = 3.0;
    double b = 10.0;
    double c = 1.0;
    double h = -5.0;
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calculate_Prism(a, b, c, h));
}

TEST(AreaOfThreeDimensionalFiguresTest, Assert_Calc_Prism_5) {
    // Arrange
    double a = 3.0;
    double b = 10.0;
    double c = 1.0;
    double h = 0;
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calculate_Prism(a, b, c, h));
}

TEST(AreaOfThreeDimensionalFiguresTest, Assert_heron_Calc_Prism) {
    // Arrange
    double a = 3.0;
    double b = 10.0;
    double c = 1.0;
    double h = 1.0;
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calculate_Prism(a, b, c, h));
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_Prism) {
    // Arrang
    Calculator z;

    // Act
    double s = z.Calculate_Prism(1.0, 1.0, 1.0, 1.0);
    double s1 = 3 + sqrt(3) / 2;

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_Prism_2) {
    // Arrang
    Calculator z;

    // Act
    double s = z.Calculate_Prism(2.0, 2.0, 2.0, 1.5);
    double s1 = 2 * 1.5 * 3 + 2 * sqrt(3);

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_Prism_3) {
    // Arrang
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calculate_Prism(6.0, 2.0, 2.0, 1.5));
}

TEST(AreaOfThreeDimensionalFiguresTest, No_Assert_Calc_Pyramid) {
    // Arrange
    double a = 3.0;
    double b = 10.0;
    double l = 5.0;
    Calculator z;

    // Act & Assert
    EXPECT_NO_THROW(z.Calculate_Pyramid(a, b, l));
}

TEST(AreaOfThreeDimensionalFiguresTest, Assert_heron_Calc_Pyramid) {
    // Arrange
    double a = 3.0;
    double b = 10.0;
    double l = 1.0;
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calculate_Pyramid(a, b, l));
}


TEST(AreaOfThreeDimensionalFiguresTest, Assert_Calc_Pyramid) {
    // Arrange
    double a = -3.0;
    double b = 10.0;
    double l = 5.0;
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calculate_Pyramid(a, b, l));
}

TEST(AreaOfThreeDimensionalFiguresTest, Assert_Calc_Pyramid_2) {
    // Arrange
    double a = 3.0;
    double b = -10.0;
    double l = 5.0;
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calculate_Pyramid(a, b, l));
}

TEST(AreaOfThreeDimensionalFiguresTest, Assert_Calc_Pyramid_3) {
    // Arrange
    double a = 3.0;
    double b = 10.0;
    double l = -1.0;
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calculate_Pyramid(a, b, l));
}

TEST(AreaOfThreeDimensionalFiguresTest, Assert_Calc_Pyramid_4) {
    // Arrange
    double a = 3.0;
    double b = 10.0;
    double l = 0;
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calculate_Pyramid(a, b, l));
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_Pyramid) {
    // Arrang
    Calculator z;

    // Act
    double s = z.Calculate_Pyramid(1.0, 1.0, 1.0);
    double s1 = 1.0 + sqrt(3);

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_Pyramid_2) {
    // Arrang
    Calculator z;

    // Act
    double s = z.Calculate_Pyramid(2.0, 2.0, 1.5);
    double s1 = 4 + 2 * sqrt(5);

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_Pyramid_3) {
    // Arrang
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calculate_Pyramid(6.0, 2.0, 2.0));
}

TEST(AreaOfThreeDimensionalFiguresTest, No_Assert_Calc_Sphere) {
    // Arrange
    double r = 3.0;
    Calculator z;

    // Act & Assert
    EXPECT_NO_THROW(z.Calculate_Sphere(r));
}

TEST(AreaOfThreeDimensionalFiguresTest, Assert_Calc_Sphere) {
    // Arrange
    double r = -3.0;
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calculate_Sphere(r));
}

TEST(AreaOfThreeDimensionalFiguresTest, Assert_Calc_Sphere_2) {
    // Arrange
    double r = 0;
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calculate_Sphere(r));
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_Sphere) {
    // Arrang
    Calculator z;

    // Act
    double s = z.Calculate_Sphere(1.0);
    double s1 = 4 * M_PI;

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_Sphere_2) {
    // Arrang
    Calculator z;

    // Act
    double s = z.Calculate_Sphere(1.5);
    double s1 = 4 * M_PI * 1.5 * 1.5;

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, No_Assert_Calc_Tetra) {
    // Arrange
    double a = 3.0;
    double b = 2.0;
    double c = 1.0;
    double l = 5.0;
    Calculator z;

    // Act & Assert
    EXPECT_NO_THROW(z.Calc_Tetra(a, b, c, l));
}

TEST(AreaOfThreeDimensionalFiguresTest, Assert_heron_Calc_Tetra) {
    // Arrange
    double a = 3.0;
    double b = 20.0;
    double c = 1.0;
    double l = 5.0;
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calc_Tetra(a, b, c, l));
}

TEST(AreaOfThreeDimensionalFiguresTest, Assert_Calc_Tetra) {
    // Arrange
    double a = -3.0;
    double b = 2.0;
    double c = 1.0;
    double l = 5.0;
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calc_Tetra(a, b, c, l));
}

TEST(AreaOfThreeDimensionalFiguresTest, Assert_Calc_Tetra_2) {
    // Arrange
    double a = 3.0;
    double b = -2.0;
    double c = 1.0;
    double l = 5.0;
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calc_Tetra(a, b, c, l));
}

TEST(AreaOfThreeDimensionalFiguresTest, Assert_Calc_Tetra_3) {
    // Arrange
    double a = 3.0;
    double b = 2.0;
    double c = -1.0;
    double l = 5.0;
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calc_Tetra(a, b, c, l));
}

TEST(AreaOfThreeDimensionalFiguresTest, Assert_Calc_Tetra_4) {
    // Arrange
    double a = 3.0;
    double b = 2.0;
    double c = 1.0;
    double l = -5.0;
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calc_Tetra(a, b, c, l));
}

TEST(AreaOfThreeDimensionalFiguresTest, Assert_Calc_Tetra_5) {
    // Arrange
    double a = 3.0;
    double b = 10.0;
    double c = 1.0;
    double l = 0;
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calc_Tetra(a, b, c, l));
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_Tetrahedron) {
    // Arrang
    Calculator z;

    // Act
    double s = z.Calc_Tetra(1.0, 1.0, 1.0, 1.0);
    double s1 = sqrt(3);

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_Tetrahedron_2) {
    // Arrang
    Calculator z;

    // Act
    double s = z.Calc_Tetra(2.0, 3.0, 4.0, 5.0);
    double heron_abc = sqrt(4.5* 2.5* 1.5 *0.5);
    double heron_al = sqrt(6 * 4);
    double heron_bl = sqrt(6.5 * 3.5 * 1.5 * 1.5);
    double heron_cl = sqrt(7 * 3 * 4);

    double s1 = heron_abc + heron_al + heron_bl + heron_cl;

    // Assert
    EXPECT_EQ(s1, s);
}

TEST(AreaOfThreeDimensionalFiguresTest, Calc_Tetra_3) {
    // Arrang
    Calculator z;

    // Act & Assert
    EXPECT_ANY_THROW(z.Calc_Tetra(6.0, 2.0, 2.0, 1.5));
}
