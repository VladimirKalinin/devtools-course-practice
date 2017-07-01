// Copyright 2017 Nazarov Aleksandr

#include <gtest/gtest.h>

#include "include/volume_calculator.h"

TEST(volume_test, can_get_right_cube_volume) {
    // Arrange
    double cube_rib = 25;
    double right_cube_volume = cube_rib * cube_rib * cube_rib;
    // Act & Assert
    EXPECT_EQ(Volume::Cube(cube_rib), right_cube_volume);
}

TEST(volume_test, cant_get_cube_volume_with_incorrect_rib) {
    // Arrange
    double cube_rib = -1;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Cube(cube_rib));
}

TEST(volume_test, can_get_right_cone_volume) {
    // Arrange
    double cone_radius = 10, cone_height = 10;
    double right_volume = (1 / 3)*M_PI*pow(cone_radius, 2)*cone_height;
    // Act & Assert
    EXPECT_EQ(Volume::Cone(cone_height, cone_radius), right_volume);
}

// Further, to tested incorrect entered value on all argument we give
// the notation to argument, c - is correct argument, i - incorrect argument

TEST(volume_test, cant_get_cone_volume_with_incorrect_variable_i_c) {
    // Arrange
    double incorrect_number = -2;
    double correct_number = 10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Cone(incorrect_number, correct_number));
}

TEST(volume_test, cant_get_cone_volume_with_incorrect_variable_c_i) {
    // Arrange
    double incorrect_number = -2;
    double correct_number = 10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Cone(correct_number, incorrect_number));
}

TEST(volume_test, cant_get_cone_volume_with_incorrect_variable_i_i) {
    // Arrange
    double incorrect_number = -2;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Cone(incorrect_number, incorrect_number));
}

TEST(volume_test, can_get_right_cylinder_volume) {
    // Arrange
    double cylinder_radius = 10, cylinder_height = 10;
    double right_volume = M_PI*pow(cylinder_radius, 2)*cylinder_height;
    // Act & Assert
    EXPECT_EQ(Volume::Cylinder(cylinder_height, cylinder_radius), right_volume);
}

TEST(volume_test, cant_get_cylinder_volume_with_incorrect_variable_i_c) {
    // Arrange
    double incorrect_number = -2;
    double correct_number = 10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Cylinder(incorrect_number, correct_number));
}

TEST(volume_test, cant_get_cylinder_volume_with_incorrect_variable_c_i) {
    // Arrange
    double incorrect_number = -2;
    double correct_number = 10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Cylinder(correct_number, incorrect_number));
}

TEST(volume_test, cant_get_cylinder_volume_with_incorrect_variable_i_i) {
    // Arrange
    double incorrect_number = -2;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Cylinder(incorrect_number, incorrect_number));
}

TEST(volume_test, can_get_right_dodecahedron_volume) {
    // Arrange
    double dodecahedron_rib = 10;
    double right_volume = (pow(dodecahedron_rib, 3)*(15 + 7 * sqrt(5))) / 4;
    // Act & Assert
    EXPECT_EQ(Volume::Dodecahedron(dodecahedron_rib), right_volume);
}

TEST(volume_test, cant_get_dodecahedron_volume_with_incorrect_rib) {
    // Arrange
    double dodecahedron_rib = -10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Dodecahedron(dodecahedron_rib));
}

TEST(volume_test, can_get_right_ellipsoid_volume) {
    // Arrange
    double a = 4, b = 4, c = 4;
    double right_volume = (4 / 3) * M_PI * a * b * c;
    // Act & Assert
    EXPECT_EQ(Volume::Ellipsoid(a, b, c), right_volume);
}

TEST(volume_test, cant_get_ellipsoid_volume_with_incorrect_ribs_i_c_c) {
    // Arrange
    double c_rib = 10;
    double inc_rib = -10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Ellipsoid(inc_rib, c_rib, c_rib));
}

TEST(volume_test, cant_get_ellipsoid_volume_with_incorrect_ribs_c_i_c) {
    // Arrange
    double c_rib = 10;
    double inc_rib = -10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Ellipsoid(c_rib, inc_rib, c_rib));
}

TEST(volume_test, cant_get_ellipsoid_volume_with_incorrect_ribs_c_c_i) {
    // Arrange
    double c_rib = 10;
    double inc_rib = -10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Ellipsoid(c_rib, c_rib, inc_rib));
}

TEST(volume_test, cant_get_ellipsoid_volume_with_incorrect_ribs_i_i_c) {
    // Arrange
    double c_rib = 10;
    double inc_rib = -10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Ellipsoid(inc_rib, inc_rib, c_rib));
}

TEST(volume_test, cant_get_ellipsoid_volume_with_incorrect_ribs_c_i_i) {
    // Arrange
    double c_rib = 10;
    double inc_rib = -10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Ellipsoid(c_rib, inc_rib, inc_rib));
}

TEST(volume_test, cant_get_ellipsoid_volume_with_incorrect_ribs_i_c_i) {
    // Arrange
    double c_rib = 10;
    double inc_rib = -10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Ellipsoid(inc_rib, c_rib, inc_rib));
}

TEST(volume_test, cant_get_ellipsoid_volume_with_incorrect_ribs_i_i_i) {
    // Arrange
    double inc_rib = -10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Ellipsoid(inc_rib, inc_rib, inc_rib));
}

TEST(volume_test, can_get_right_frustum_volume) {
    // Arrange
    double radius_of_first_base = 10;
    double radius_of_second_base = 5;
    double height = 15;
    double right_volume = (1 / 3)*M_PI*height*(pow(radius_of_first_base, 2)
        + radius_of_first_base*radius_of_second_base
        + pow(radius_of_second_base, 2));
    // Act & Assert
    EXPECT_EQ(Volume::Frustum(radius_of_first_base,
        radius_of_second_base,
        height),
        right_volume);
}

TEST(volume_test, cant_get_frustum_volume_with_incorrect_r_and_h_i_c_c) {
    // Arrange
    double c_num = 10;
    double in_num = -10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Frustum(in_num, c_num, c_num));
}

TEST(volume_test, cant_get_frustum_volume_with_incorrect_r_and_h_c_i_c) {
    // Arrange
    double c_num = 10;
    double in_num = -10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Frustum(c_num, in_num, c_num));
}

TEST(volume_test, cant_get_frustum_volume_with_incorrect_r_and_h_c_c_i) {
    // Arrange
    double c_num = 10;
    double in_num = -10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Frustum(c_num, c_num, in_num));
}

TEST(volume_test, cant_get_frustum_volume_with_incorrect_r_and_h_i_i_c) {
    // Arrange
    double c_num = 10;
    double in_num = -10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Frustum(in_num, in_num, c_num));
}

TEST(volume_test, cant_get_frustum_volume_with_incorrect_r_and_h_c_i_i) {
    // Arrange
    double c_num = 10;
    double in_num = -10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Frustum(c_num, in_num, in_num));
}

TEST(volume_test, cant_get_frustum_volume_with_incorrect_r_and_h_i_c_i) {
    // Arrange
    double c_num = 10;
    double in_num = -10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Frustum(in_num, c_num, in_num));
}

TEST(volume_test, cant_get_frustum_volume_with_incorrect_r_and_h_i_i_i) {
    // Arrange
    double in_num = -10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Frustum(in_num, in_num, in_num));
}

TEST(volume_test, can_get_right_paraboloid_volume) {
    // Arrange
    double radius = 10, height = 5;
    double right_value = (1 / 2)*M_PI*pow(radius, 2)*height;
    // Act & Assert
    EXPECT_EQ(Volume::Paraboloid(height, radius), right_value);
}

TEST(volume_test, cant_get_paraboloid_volume_with_incorrect_r_and_h_i_c) {
    // Arrange
    double correct_number = 10;
    double incorrect_number = -10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Paraboloid(incorrect_number, correct_number));
}

TEST(volume_test, cant_get_paraboloid_volume_with_incorrect_r_and_h_c_i) {
    // Arrange
    double correct_number = 10;
    double incorrect_number = -10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Paraboloid(correct_number, incorrect_number));
}

TEST(volume_test, cant_get_paraboloid_volume_with_incorrect_r_and_h_i_i) {
    // Arrange
    double incorrect_number = -10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Paraboloid(incorrect_number, incorrect_number));
}

TEST(volume_test, can_get_right_parallelepiped_volume_with_ribs_and_h) {
    // Arrange
    double a_base_rib = 5, b_base_rib = 10, height = 20;
    double base_area = a_base_rib * b_base_rib;
    double right_volume = base_area * height;
    // Act & Assert
    EXPECT_EQ(Volume::Parallelepiped(a_base_rib, b_base_rib, height),
        right_volume);
}

TEST(volume_test, can_get_right_parallelepiped_volume_with_base_area_and_h) {
    // Arrange
    double a_base_rib = 5, b_base_rib = 10, height = 20;
    double base_area = a_base_rib * b_base_rib;
    double right_volume = base_area * height;
    // Act & Assert
    EXPECT_EQ(Volume::Parallelepiped(base_area, height), right_volume);
}

TEST(volume_test, cant_get_parallelepiped_volume_with_inc_variables_i_c_c) {
    // Arrange
    double in_num = -10;
    double c_num = 10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Parallelepiped(in_num, c_num, c_num));
}

TEST(volume_test, cant_get_parallelepiped_volume_with_inc_variables_c_i_c) {
    // Arrange
    double in_num = -10;
    double c_num = 10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Parallelepiped(c_num, in_num, c_num));
}

TEST(volume_test, cant_get_parallelepiped_volume_with_inc_variables_c_c_i) {
    // Arrange
    double in_num = -10;
    double c_num = 10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Parallelepiped(c_num, c_num, in_num));
}

TEST(volume_test, cant_get_parallelepiped_volume_with_inc_variables_i_i_c) {
    // Arrange
    double in_num = -10;
    double c_num = 10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Parallelepiped(in_num, in_num, c_num));
}

TEST(volume_test, cant_get_parallelepiped_volume_with_inc_variables_c_i_i) {
    // Arrange
    double in_num = -10;
    double c_num = 10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Parallelepiped(c_num, in_num, in_num));
}

TEST(volume_test, cant_get_parallelepiped_volume_with_inc_variables_i_c_i) {
    // Arrange
    double in_num = -10;
    double c_num = 10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Parallelepiped(in_num, c_num, in_num));
}

TEST(volume_test, cant_get_parallelepiped_volume_with_inc_variables_i_i_i) {
    // Arrange
    double in_num = -10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Parallelepiped(in_num, in_num, in_num));
}

TEST(volume_test, cant_get_parallelepiped_volume_with_inc_variables_i_c) {
    // Arrange
    double in_num = -10;
    double c_num = 10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Parallelepiped(in_num, c_num));
}

TEST(volume_test, cant_get_parallelepiped_volume_with_inc_variables_c_i) {
    // Arrange
    double in_num = -10;
    double c_num = 10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Parallelepiped(c_num, in_num));
}

TEST(volume_test, cant_get_parallelepiped_volume_with_inc_variables_i_i) {
    // Arrange
    double in_num = -10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Parallelepiped(in_num, in_num));
}

TEST(volume_test, can_get_right_parallelepiped_volume_with_ribs_and_angle) {
    // Arrange
    double a = 5, b = 10, c = 15;
    double argument_of_sin = M_PI/4;
    double right_volume = a*b*c*sin(argument_of_sin);
    // Act & Assert
    EXPECT_EQ(Volume::Parallelepiped(a, b, c, argument_of_sin), right_volume);
}

TEST(volume_test, cant_get_right_parallelepiped_volume_with_inc_var_i_c_c_c) {
    // Arrange
    double in_rib = -10;
    double c_rib = 10, c_sin = M_PI / 4;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Parallelepiped(in_rib, c_rib, c_rib, c_sin));
}

TEST(volume_test, cant_get_right_parallelepiped_volume_with_inc_var_c_i_c_c) {
    // Arrange
    double in_rib = -10;
    double c_rib = 10, c_sin = M_PI / 4;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Parallelepiped(c_rib, in_rib, c_rib, c_sin));
}

TEST(volume_test, cant_get_right_parallelepiped_volume_with_inc_var_c_c_i_c) {
    // Arrange
    double in_rib = -10;
    double c_rib = 10, c_sin = M_PI / 4;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Parallelepiped(c_rib, c_rib, in_rib, c_sin));
}

TEST(volume_test, cant_get_right_parallelepiped_volume_with_inc_var_c_c_c_i) {
    // Arrange
    double in_sin = -M_PI / 4;
    double c_rib = 10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Parallelepiped(c_rib, c_rib, c_rib, in_sin));
}

TEST(volume_test, cant_get_right_parallelepiped_volume_with_inc_var_i_i_c_c) {
    // Arrange
    double in_rib = -10;
    double c_rib = 10, c_sin = M_PI / 4;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Parallelepiped(in_rib, in_rib, c_rib, c_sin));
}

TEST(volume_test, cant_get_right_parallelepiped_volume_with_inc_var_i_c_i_c) {
    // Arrange
    double in_rib = -10;
    double c_rib = 10, c_sin = M_PI / 4;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Parallelepiped(in_rib, c_rib, in_rib, c_sin));
}

TEST(volume_test, cant_get_right_parallelepiped_volume_with_inc_var_i_c_c_i) {
    // Arrange
    double in_rib = -10, in_sin = -M_PI / 4;
    double c_rib = 10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Parallelepiped(in_rib, c_rib, c_rib, in_sin));
}

TEST(volume_test, cant_get_right_parallelepiped_volume_with_inc_var_c_i_i_c) {
    // Arrange
    double in_rib = -10;
    double c_rib = 10, c_sin = M_PI / 4;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Parallelepiped(c_rib, in_rib, in_rib, c_sin));
}

TEST(volume_test, cant_get_right_parallelepiped_volume_with_inc_var_c_i_c_i) {
    // Arrange
    double in_rib = -10, in_sin = -M_PI / 4;
    double c_rib = 10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Parallelepiped(c_rib, in_rib, c_rib, in_sin));
}

TEST(volume_test, cant_get_right_parallelepiped_volume_with_inc_var_c_c_i_i) {
    // Arrange
    double in_rib = -10, in_sin = -M_PI / 4;
    double c_rib = 10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Parallelepiped(c_rib, c_rib, in_rib, in_sin));
}

TEST(volume_test, cant_get_right_parallelepiped_volume_with_inc_var_i_i_i_c) {
    // Arrange
    double in_rib = -10;
    double c_sin = M_PI / 4;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Parallelepiped(in_rib, in_rib, in_rib, c_sin));
}

TEST(volume_test, cant_get_right_parallelepiped_volume_with_inc_var_i_i_c_i) {
    // Arrange
    double in_rib = -10, in_sin = -M_PI / 4;
    double c_rib = 10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Parallelepiped(in_rib, in_rib, c_rib, in_sin));
}

TEST(volume_test, cant_get_right_parallelepiped_volume_with_inc_var_i_c_i_i) {
    // Arrange
    double in_rib = -10, in_sin = -M_PI / 4;
    double c_rib = 10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Parallelepiped(in_rib, c_rib, in_rib, in_sin));
}

TEST(volume_test, cant_get_right_parallelepiped_volume_with_inc_var_c_i_i_i) {
    // Arrange
    double in_rib = -10, in_sin = -M_PI / 4;
    double c_rib = 10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Parallelepiped(c_rib, in_rib, in_rib, in_sin));
}

TEST(volume_test, cant_get_right_parallelepiped_volume_with_inc_var_i_i_i_i) {
    // Arrange
    double in_rib = -10, in_sin = -M_PI / 4;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Parallelepiped(in_rib, in_rib, in_rib, in_sin));
}

TEST(volume_test, can_get_right_pyramid_volume_with_ribs) {
    // Arrange
    double a_rib_of_triangle = 5;
    double height_of_triangle = 10;
    double height_of_pyramid = 20;
    double base_area = (0.5)*a_rib_of_triangle*height_of_triangle;
    double right_volume = (1 / 3)*base_area*height_of_pyramid;
    // Act & Assert
    EXPECT_EQ(Volume::Pyramid(a_rib_of_triangle,
                              height_of_triangle,
                              height_of_pyramid), right_volume);
}

TEST(volume_test, can_get_right_pyramid_volume_with_base_area) {
    // Arrange
    double a_rib_of_triangle = 5;
    double height_of_triangle = 10;
    double height_of_pyramid = 20;
    double base_area = (0.5)*a_rib_of_triangle*height_of_triangle;
    double right_volume = (1 / 3)*base_area*height_of_pyramid;
    // Act & Assert
    EXPECT_EQ(Volume::Pyramid(base_area, height_of_pyramid), right_volume);
}

TEST(volume_test, cant_get_pyramid_volume_with_incorrect_volume_i_c_c) {
    // Arrange
    double in_num = -10;
    double c_num = 10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Pyramid(in_num, c_num, c_num));
}

TEST(volume_test, cant_get_pyramid_volume_with_incorrect_volume_c_i_c) {
    // Arrange
    double in_num = -10;
    double c_num = 10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Pyramid(c_num, in_num, c_num));
}

TEST(volume_test, cant_get_pyramid_volume_with_incorrect_volume_c_c_i) {
    // Arrange
    double in_num = -10;
    double c_num = 10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Pyramid(c_num, c_num, in_num));
}

TEST(volume_test, cant_get_pyramid_volume_with_incorrect_volume_i_i_c) {
    // Arrange
    double in_num = -10;
    double c_num = 10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Pyramid(in_num, in_num, c_num));
}

TEST(volume_test, cant_get_pyramid_volume_with_incorrect_volume_i_c_i) {
    // Arrange
    double in_num = -10;
    double c_num = 10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Pyramid(in_num, c_num, in_num));
}

TEST(volume_test, cant_get_pyramid_volume_with_incorrect_volume_c_i_i) {
    // Arrange
    double in_num = -10;
    double c_num = 10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Pyramid(c_num, in_num, in_num));
}

TEST(volume_test, cant_get_pyramid_volume_with_incorrect_volume_i_i_i) {
    // Arrange
    double in_num = -10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Pyramid(in_num, in_num, in_num));
}

TEST(volume_test, cant_get_pyramid_volume_with_incorrect_volume_i_c) {
    // Arrange
    double in_num = -10;
    double c_num = 10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Pyramid(in_num, c_num));
}

TEST(volume_test, cant_get_pyramid_volume_with_incorrect_volume_c_i) {
    // Arrange
    double in_num = -10;
    double c_num = 10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Pyramid(c_num, in_num));
}

TEST(volume_test, cant_get_pyramid_volume_with_incorrect_volume_i_i) {
    // Arrange
    double in_num = -10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Pyramid(in_num, in_num));
}

TEST(volume_test, can_get_right_rectangular_parallelepiped_volume) {
    // Arrange
    double a = 4, b = 6, c = 10;
    double right_volume = a * b * c;
    // Act & Assert
    EXPECT_EQ(Volume::RectangularParallelepiped(a, b, c), right_volume);
}

TEST(volume_test, cant_get_right_r_parallelepiped_volume_with_inc_ribs_i_c_c) {
    // Arrange
    double c_rib = 10;
    double in_rib = -10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::RectangularParallelepiped(in_rib, c_rib, c_rib));
}

TEST(volume_test, cant_get_right_r_parallelepiped_volume_with_inc_ribs_c_i_c) {
    // Arrange
    double c_rib = 10;
    double in_rib = -10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::RectangularParallelepiped(c_rib, in_rib, c_rib));
}

TEST(volume_test, cant_get_right_r_parallelepiped_volume_with_inc_ribs_c_c_i) {
    // Arrange
    double c_rib = 10;
    double in_rib = -10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::RectangularParallelepiped(c_rib, c_rib, in_rib));
}

TEST(volume_test, cant_get_right_r_parallelepiped_volume_with_inc_ribs_i_i_c) {
    // Arrange
    double c_rib = 10;
    double in_rib = -10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::RectangularParallelepiped(in_rib, in_rib, c_rib));
}

TEST(volume_test, cant_get_right_r_parallelepiped_volume_with_inc_ribs_c_i_i) {
    // Arrange
    double c_rib = 10;
    double in_rib = -10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::RectangularParallelepiped(c_rib, in_rib, in_rib));
}

TEST(volume_test, cant_get_right_r_parallelepiped_volume_with_inc_ribs_i_c_i) {
    // Arrange
    double c_rib = 10;
    double in_rib = -10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::RectangularParallelepiped(in_rib, c_rib, in_rib));
}

TEST(volume_test, cant_get_right_r_parallelepiped_volume_with_inc_ribs_i_i_i) {
    // Arrange
    double in_rib = -10;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::RectangularParallelepiped(in_rib, in_rib, in_rib));
}

TEST(volume_test, can_get_right_sphere_volume) {
    // Arrange
    double radius = 10;
    // Act
    double right_volume = (4 / 3)*M_PI*pow(radius, 3);
    // Act & Assert
    EXPECT_EQ(Volume::Sphere(radius), right_volume);
}

TEST(volume_test, cant_get_sphere_volume_with_incorrect_radius) {
    // Arrange
    double radius = -100;
    // Act & Assert
    ASSERT_ANY_THROW(Volume::Sphere(radius));
}
