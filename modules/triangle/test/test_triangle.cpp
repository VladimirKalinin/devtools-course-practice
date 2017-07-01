// Copyright 2017 Karev Boris

#include <gtest/gtest.h>

#include <string>

#include "include/triangle.h"

TEST(TriangleTest, Can_Create_Via_Constructor) {
    double point1_coordx = 10.11;
    double point1_coordy = 10.11;
    double point2_coordx = 12.14;
    double point2_coordy = 12.14;
    double point3_coordx = 0;
    double point3_coordy = 5.31;

    Triangle t(point1_coordx, point1_coordy,
        point2_coordx, point2_coordy,
        point3_coordx, point3_coordy);

    EXPECT_EQ(point1_coordx, t.GetCoordXPoint(1));
    EXPECT_EQ(point1_coordy, t.GetCoordYPoint(1));
    EXPECT_EQ(point2_coordx, t.GetCoordXPoint(2));
    EXPECT_EQ(point2_coordy, t.GetCoordYPoint(2));
    EXPECT_EQ(point3_coordx, t.GetCoordXPoint(3));
    EXPECT_EQ(point3_coordy, t.GetCoordYPoint(3));
}

TEST(TriangleTest, Constructor_Throw_Exception) {
    double point1_coordx = 10.11;
    double point1_coordy = 10.11;
    double point2_coordx = 12.14;
    double point2_coordy = 12.14;
    double point3_coordx = 10.11;
    double point3_coordy = 10.11;

    EXPECT_THROW(Triangle t(point1_coordx, point1_coordy, point2_coordx,
        point2_coordy, point3_coordx, point3_coordy), std::string);
}

TEST(TriangleTest, Can_Create_Via_Copy_Constructor) {
    double point1_coordx = 10.11;
    double point1_coordy = 10.11;
    double point2_coordx = 12.14;
    double point2_coordy = 12.14;
    double point3_coordx = 0;
    double point3_coordy = 5.31;

    Triangle t(point1_coordx, point1_coordy, point2_coordx, point2_coordy,
        point3_coordx, point3_coordy);
    Triangle copy_t(t);

    EXPECT_EQ(copy_t, t);
}

TEST(TriangleTest, Can_Create_Via_Default_Constructor) {
    Triangle t1;
    Triangle t2(0, 0, 0, 1, 1, 0);

    EXPECT_EQ(t1, t2);
}

TEST(TriangleTest, Can_Calculate_Square) {
    Triangle t;

    double sq = t.CalculateSquare();

    EXPECT_NEAR(0.5, sq, 0.001);
}

TEST(TriangleTest, Can_Calculate_Perimeter) {
    Triangle t(0, 0, 0, 3, 4, 0);

    double pr = t.CalculatePerimeter();

    EXPECT_EQ(12, pr);
}

TEST(TriangleTest, Can_Calculate_MedianX) {
    Triangle t(0, 0, 0, 3, 3, 0);

    double x = t.GetCoordXMedian();

    EXPECT_EQ(1, x);
}

TEST(TriangleTest, Can_Calculate_MedianY) {
    Triangle t(0, 0, 0, 3, 3, 0);

    double y = t.GetCoordYMedian();

    EXPECT_EQ(1, y);
}

TEST(TriangleTest, Equal_Triangle_Are_Equal) {
    Triangle t1(0, 0, 0, 3, 4, 0);
    Triangle t2(0, 0, 0, 3, 4, 0);

    EXPECT_EQ(t1, t2);
}

TEST(TriangleTest, Different_Trieangle_Not_Equal) {
    Triangle t1(0, 0, 0, 3, 4, 0);
    Triangle t2(0, 0, 0, 3.1, 4, 0);

    EXPECT_TRUE(t1 != t2);
}

TEST(TriangleTest, Can_Set_CoordX_Point1) {
    Triangle t;
    double point_coordx = 10.11;

    t.SetCoordXPoint(point_coordx, 1);

    EXPECT_EQ(point_coordx, t.GetCoordXPoint(1));
}

TEST(TriangleTest, Can_Set_CoordX_Point2) {
    Triangle t;
    double point_coordx = 10.11;

    t.SetCoordXPoint(point_coordx, 2);

    EXPECT_EQ(point_coordx, t.GetCoordXPoint(2));
}

TEST(TriangleTest, Can_Set_CoordX_Point3) {
    Triangle t;
    double point_coordx = 10.11;

    t.SetCoordXPoint(point_coordx, 3);

    EXPECT_EQ(point_coordx, t.GetCoordXPoint(3));
}

TEST(TriangleTest, Set_CoordX_Throw_Exception_Uncorrect_Number) {
    Triangle t;
    double point_coordx = 10.11;

    EXPECT_THROW(t.SetCoordXPoint(point_coordx, 0), std::string);
}

TEST(TriangleTest, Set_CoordX_Throw_Exception_Uncorrect_Coord) {
    Triangle t(0, 0, 0, 1, 1, 0);
    double point_coordx = 1;

    EXPECT_THROW(t.SetCoordXPoint(point_coordx, 1), std::string);
}

TEST(TriangleTest, Can_Set_CoordY_Point1) {
    Triangle t;
    double point_coordy = 10.11;

    t.SetCoordYPoint(point_coordy, 1);

    EXPECT_EQ(point_coordy, t.GetCoordYPoint(1));
}

TEST(TriangleTest, Can_Set_CoordY_Point2) {
    Triangle t;
    double point_coordy = 10.11;

    t.SetCoordYPoint(point_coordy, 2);

    EXPECT_EQ(point_coordy, t.GetCoordYPoint(2));
}

TEST(TriangleTest, Can_Set_CoordY_Point3) {
    Triangle t;
    double point_coordy = 10.11;

    t.SetCoordYPoint(point_coordy, 3);

    EXPECT_EQ(point_coordy, t.GetCoordYPoint(3));
}

TEST(TriangleTest, Set_CoordY_Throw_Exception_Uncorrect_Number) {
    Triangle t;
    double point_coordy = 10.11;

    EXPECT_THROW(t.SetCoordYPoint(point_coordy, 0), std::string);
}

TEST(TriangleTest, Set_CoordY_Throw_Exception_Uncorrect_Coord) {
    Triangle t(0, 0, 0, 1, 1, 0);
    double point_coordy = 1;

    EXPECT_THROW(t.SetCoordYPoint(point_coordy, 1), std::string);
}

TEST(TriangleTest, Can_Get_CoordX) {
    Triangle t(0, 0, 1, 3, 4, 0);

    t.GetCoordXPoint(1);

    EXPECT_EQ(0, t.GetCoordXPoint(1));
}

TEST(TriangleTest, Get_CoordX_Throw_Exception) {
    Triangle t;

    EXPECT_THROW(t.GetCoordXPoint(0), std::string);
}

TEST(TriangleTest, Can_Get_CoordY) {
    Triangle t(0, 0, 1, 3, 4, 5);

    t.GetCoordYPoint(1);

    EXPECT_EQ(0, t.GetCoordYPoint(1));
}

TEST(TriangleTest, Get_CoordY_Throw_Exception) {
    Triangle t;

    EXPECT_THROW(t.GetCoordYPoint(0), std::string);
}

TEST(TriangleTest, Can_Calculate_Side1) {
    Triangle t(0, 0, 0, 3, 4, 0);

    double side = t.CalculateSide(1);

    EXPECT_EQ(5, side);
}

TEST(TriangleTest, Can_Calculate_Side2) {
    Triangle t(0, 0, 0, 3, 4, 0);

    double side = t.CalculateSide(2);

    EXPECT_EQ(4, side);
}

TEST(TriangleTest, Can_Calculate_Side3) {
    Triangle t(0, 0, 0, 3, 4, 0);

    double side = t.CalculateSide(3);

    EXPECT_EQ(3, side);
}

TEST(TriangleTest, Calculate_Side_Throw_Exception) {
    Triangle t;

    EXPECT_THROW(t.CalculateSide(0), std::string);
}

TEST(TriangleTest, Can_Calculate_Corner1) {
    Triangle t(0, 0, 0, 3, 4, 0);

    double corner = t.CalculateCorner(1);

    EXPECT_NEAR(1.57, corner, 0.001);
}

TEST(TriangleTest, Can_Calculate_Corner2) {
    Triangle t(4, 0, 0, 0, 0, 3);

    double corner = t.CalculateCorner(2);

    EXPECT_NEAR(1.57, corner, 0.001);
}

TEST(TriangleTest, Can_Calculate_Corner3) {
    Triangle t(0, 3, 4, 0, 0, 0);

    double corner = t.CalculateCorner(3);

    EXPECT_NEAR(1.57, corner, 0.001);
}

TEST(TriangleTest, Calculate_Corner_Throw_Exception) {
    Triangle t;

    EXPECT_THROW(t.CalculateCorner(0), std::string);
}

TEST(TriangleTest, Can_Calculate_CircumscribedCircleX) {
    Triangle t(0, 0, 0, 3, 4, 0);

    double x = t.GetCoordXCircumscribedCircle();

    EXPECT_EQ(2, x);
}

TEST(TriangleTest, Can_Calculate_CircumscribedCircleY) {
    Triangle t(0, 0, 0, 3, 4, 0);

    double y = t.GetCoordYCircumscribedCircle();

    EXPECT_EQ(1.5, y);
}

TEST(TriangleTest, Can_Calculate_InscribedCircleX) {
    Triangle t(0, 0, 0, 3, 4, 0);

    double x = t.GetCoordXInscribedCircle();

    EXPECT_EQ(1, x);
}

TEST(TriangleTest, Can_Calculate_InscribedCircleY) {
    Triangle t(0, 0, 0, 3, 4, 0);

    double y = t.GetCoordYInscribedCircle();

    EXPECT_EQ(1, y);
}
