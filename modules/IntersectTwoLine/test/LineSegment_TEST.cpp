// Copyright 2017 Lobanov Andrey

#include "include/LineSegment.h"
#include <gtest/gtest.h>
#include <string>

using std::string;

TEST(LineSegment, Can_Create_LineSegment) {
  // Arrange and Assert
  ASSERT_NO_THROW(LineSegment2D line);
}

TEST(LineSegment, Can_Create_LineSegment_With_Initial_Values) {
  // Arrange and Assert
  ASSERT_NO_THROW(LineSegment2D line(2.0, 3.1, 4.2, 5.2));
}

TEST(LineSegment, Can_Not_Create_LineSegment_With_Same_Points) {
  // Arrange and Assert
  ASSERT_ANY_THROW(LineSegment2D line(9.1, 3.28, 9.1, 3.28));
}

TEST(LineSegment, Can_Create_LineSegment_With_Negative_Values) {
  // Arrange and Assert
  ASSERT_NO_THROW(LineSegment2D line(2.0, 3.1, -4.2, -7.21));
}

TEST(LineSegment, Can_Get_Coord_X1) {
  // Arrange
  LineSegment2D segment(5.6, -4.8, 11.1, 9.3);
  double X1;
  // Act
  X1 = segment.GetCoord(1);
  // Assert
  ASSERT_DOUBLE_EQ(5.6, X1);
}

TEST(LineSegment, Can_Get_Coord_Y1) {
  // Arrange
  LineSegment2D segment(5.6, -4.8, 11.1, 9.3);
  double Y1;
  // Act
  Y1 = segment.GetCoord(2);
  // Assert
  ASSERT_DOUBLE_EQ(-4.8, Y1);
}

TEST(LineSegment, Can_Get_Coord_X2) {
  // Arrange
  LineSegment2D segment(5.6, -4.8, 11.1, 9.3);
  double X2;
  // Act
  X2 = segment.GetCoord(3);
  // Assert
  ASSERT_DOUBLE_EQ(11.1, X2);
}

TEST(LineSegment, Can_Get_Coord_Y2) {
  // Arrange
  LineSegment2D segment(5.6, -4.8, 11.1, 9.3);
  double Y2;
  // Act
  Y2 = segment.GetCoord(4);
  // Assert
  ASSERT_DOUBLE_EQ(9.3, Y2);
}

TEST(LineSegment, Cant_Get_Coord_With_Incorrect_Initialization) {
  // Arrange
  LineSegment2D segment(1.0, -4.0, 5.2, 44.3);
  // Act and Assert
  ASSERT_ANY_THROW(segment.GetCoord(10));
}

TEST(LineSegment, Can_Set_X1) {
  // Arrange
  LineSegment2D segment(0, 0, 11.3, 37.98);
  double x;
  // Act
  segment.SetX1(3.3);
  x = segment.GetCoord(1);
  // Assert
  EXPECT_EQ(3.3, x);
}

TEST(LineSegment, Can_Set_Y1) {
  // Arrange
  LineSegment2D segment(10.5, 0, 8.8, 37.98);
  double y;
  // Act
  segment.SetY1(3.3);
  y = segment.GetCoord(2);
  // Assert
  EXPECT_EQ(3.3, y);
}

TEST(LineSegment, Can_Set_X2) {
  // Arrange
  LineSegment2D segment(11.7, 73.4, 0, 37.98);
  double x;
  // Act
  segment.SetX2(3.3);
  x = segment.GetCoord(3);
  // Assert
  EXPECT_EQ(3.3, x);
}

TEST(LineSegment, Can_Set_Y2) {
  // Arrange
  LineSegment2D segment(10.5, 3.7, 8.8, 0);
  double y;
  // Act
  segment.SetY2(3.3);
  y = segment.GetCoord(4);
  // Assert
  EXPECT_EQ(3.3, y);
}

TEST(LineSegment, Can_Get_Coeff_A) {
  // Arrange
  LineSegment2D segment(5.6, -4.8, 11.1, 9.3);
  double A;
  // Act
  A = segment.GetCoeff(1);
  // Assert
  ASSERT_DOUBLE_EQ(-14.1, A);
}

TEST(LineSegment, Can_Get_Coeff_B) {
  // Arrange
  LineSegment2D segment(5.6, -4.8, 11.1, 9.3);
  double B;
  // Act
  B = segment.GetCoeff(2);
  // Assert
  ASSERT_DOUBLE_EQ(5.5, B);
}

TEST(LineSegment, Can_Get_Coeff_C) {
  // Arrange
  LineSegment2D segment(5.6, -4.8, 11.1, 9.3);
  double C;
  // Act
  C = segment.GetCoeff(3);
  // Assert
  ASSERT_DOUBLE_EQ(105.36, C);
}

TEST(LineSegment, Can_Not_Get_Coeff_With_Incorrect_Initialization) {
  // Arrange
  LineSegment2D segment(5.6, -4.8, 11.1, 9.3);
  // Act and Assert
  ASSERT_ANY_THROW(segment.GetCoeff(10));
}

TEST(LineSegment, Check_Segments_For_Coincide) {
  // Arrange
  string str, str1 = "The segments are on the same line";
  LineSegment2D segment(-4, -2, -2, 0);
  LineSegment2D segment1(-1, 1, 2, 4);
  // Act
  str = segment.CheckIntersection(segment1);
  // Assert
  ASSERT_EQ(str, str1);
}

TEST(LineSegment, Check_Segments_For_Parallel) {
  // Arrange
  string str, str1 = "Segments are parallel";
  LineSegment2D segment(5, 4, 7, 4);
  LineSegment2D segment1(4, 3, 8, 3);
  // Act
  str = segment.CheckIntersection(segment1);
  // Assert
  ASSERT_EQ(str, str1);
}

TEST(LineSegment, Check_Segments_For_Intersection) {
  // Arrange
  string str, str1 = "Segments do not intersect";
  LineSegment2D segment(-3.1, -5.3, -7.8, -3);
  LineSegment2D segment1(2.8, 5.871, 1.3, 2.4);
  // Act
  str = segment.CheckIntersection(segment1);
  // Assert
  ASSERT_EQ(str, str1);
}

TEST(LineSegment, Calculation_Of_Points_Of_Intersection) {
  // Arrange
  string str, str1 = "Intersection point: (3;2)";
  LineSegment2D segment(1, 2, 6, 2);
  LineSegment2D segment1(3, 0, 3, 4);
  // Act
  str = segment.CheckIntersection(segment1);
  // Assert
  ASSERT_EQ(str, str1);
}

TEST(LineSegment, Check_Belonging_Points) {
  // Arrange
  bool belong;
  LineSegment2D segment(1, 2, 6, 2);
  LineSegment2D segment1(3, 0, 3, 4);
  // Act
  belong = segment.BelongingToSegment(segment1);
  // Assert
  ASSERT_EQ(belong, true);
}

TEST(LineSegment, Points_Belong_To_Segment) {
  // Arrange
  bool belong;
  LineSegment2D segment(3.8, 1.11, 7.3, -2.23);
  LineSegment2D segment1(4.31, 0, 16.17, -14.3);
  // Act
  belong = segment.BelongingToSegment(segment1);
  // Assert
  ASSERT_EQ(belong, true);
}

TEST(LineSegment, Points_Not_Belong_To_Segment) {
  // Arrange
  bool belong;
  LineSegment2D segment(11.73, 41.3, -14.2, 31.7);
  LineSegment2D segment1(34.1, 11.3, 81.3, -1.48);
  // Act
  belong = segment.BelongingToSegment(segment1);
  // Assert
  ASSERT_EQ(belong, false);
}
