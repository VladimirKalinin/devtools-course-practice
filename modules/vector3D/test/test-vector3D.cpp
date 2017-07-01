// Copyright 2017 Zorina Ekaterina

#include <gtest/gtest.h>
#include "include/vector3D.h"

TEST(Vector3D, can_create_vector) {
    ASSERT_NO_THROW(Vector3D v(0.1, 0.2, 0.3));
}

TEST(Vector3D, can_create_copied_vector) {
    Vector3D v(1.9, 2.8, 3.2);

    ASSERT_NO_THROW(Vector3D v1(v));
}

TEST(Vector3D, copied_vector_is_equal_to_source_one) {
    Vector3D v(1.2, 3.4, 5.6);

    Vector3D vt(v);

    EXPECT_EQ(v, vt);
}

TEST(Vector3D, copied_vector_has_its_own_memory) {
    Vector3D v(1.2, 3.4, 5.6);

    Vector3D vt(v);
    Vector3D *p, *pt;
    p = &v;
    pt = &vt;

    EXPECT_NE(p, pt);
}

TEST(Vector3D, can_get_x) {
    double x = 21.54;
    Vector3D v(x, 0.0, 0.0);

    EXPECT_EQ(x, v.GetX());
}

TEST(Vector3D, can_get_y) {
    double y = -34.979;
    Vector3D v(0.0, y, 0.0);

    EXPECT_EQ(y, v.GetY());
}

TEST(Vector3D, can_get_z) {
    double z = 65.4633;
    Vector3D v(0.0, 0.0, z);

    EXPECT_EQ(z, v.GetZ());
}

TEST(Vector3D, can_set_x) {
    double x = 21.54;
    Vector3D v, vt(x, 0.0, 0.0);

    v.SetX(x);

    EXPECT_EQ(v, vt);
}

TEST(Vector3D, can_set_y) {
    double y = -34.979;
    Vector3D v, vt(0.0, y, 0.0);

    v.SetY(y);

    EXPECT_EQ(v, vt);
}

TEST(Vector3D, can_set_z) {
    double z = 65.4633;
    Vector3D v, vt(0.0, 0.0, z);

    v.SetZ(z);

    EXPECT_EQ(v, vt);
}

TEST(Vector3D, can_assign_vector_to_itself) {
    Vector3D v(2.55, 6.25, 0.99), vt(2.55, 6.25, 0.99);

    v = v;

    EXPECT_EQ(vt, v);
}

TEST(Vector3D, can_assign_vectors) {
    Vector3D v(3.4, 6.2, 0.0), vt(2.55, 6.25, 0.99);

    v = vt;

    EXPECT_EQ(vt, v);
}

TEST(Vector3D, compare_equal_vectors_returns_true) {
    Vector3D v1(3.345, 5.0970, 0.0), v2(3.345, 5.097, 0.0);

    EXPECT_TRUE((v1 == v2) && !(v1 != v2));
}

TEST(Vector3D, compare_vector_with_itself_returns_true) {
    Vector3D v1(45.2, 5.3, 0.8);

    EXPECT_TRUE(v1 == v1);
}

TEST(Vector3D, compare_not_equal_vectors_returns_false) {
    Vector3D v1(3.345, 5.097001, 0.0), v2(3.345, 5.097, 0.0);

    EXPECT_TRUE(!(v1 == v2) && (v1 != v2));
}

TEST(Vector3D, can_add_vectors) {
    Vector3D v1(1.0, 3.2, 4.7), v2(-3.6, 5.23, -4.7), vt(-2.6, 8.43, 0.0);

    EXPECT_EQ(vt, (v1 + v2));
}

TEST(Vector3D, can_subtract_vectors) {
    Vector3D v1(1.0, 0.0, 4.7), v2(-3.6, 1.1, 4.7), vt(4.6, -1.1, 0.0);

    EXPECT_EQ(vt, (v1 - v2));
}

TEST(Vector3D, can_get_vectors_norm) {
    double norm = 13.0;
    Vector3D v(3.0, 4.0, 12.0);

    EXPECT_EQ(norm, v.Norm());
}

TEST(Vector3D, can_normalize_vector) {
    Vector3D v(2.0, 4.0, -4.0);

    v.Normalize();

    EXPECT_DOUBLE_EQ(1.0, v.Norm());
}

TEST(Vector3D, can_scalar_multiply_vectors) {
    double scal = 0.0;
    Vector3D v1(4.0, -2.0, 1.0), v2(1.0, 3.0, 2.0);

    EXPECT_DOUBLE_EQ(scal, v1 * v2);
}

TEST(Vector3D, can_vector_multiply_vectors) {
    Vector3D v1(2.5, 3.0, 1.0), v2(2.0, 0.2, 4.0);
    Vector3D vt(11.8, -8.0, -5.5);
    Vector3D vmult = v1 ^ v2;

    EXPECT_EQ(vt, vmult);
}

TEST(Vector3D, vector_multiply_of_collinear_vectors_is_zero_vector) {
    Vector3D v1(4.0, 2.0, -4.0), v2(-2.0, -1.0, 2.0);
    Vector3D vt(0.0, 0.0, 0.0);
    Vector3D vmult = v1 ^ v2;

    EXPECT_EQ(vt, vmult);
}
