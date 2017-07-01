// Copyright 2017 Yashkov Vladislav + Kiparenko Ilya

#include <gtest/gtest.h>

#include "include/interpolation_search.h"

TEST(InterpolationSearch, Correct_Check_Validity_When_Array_Unsorted) {
  // Arrange
  const int len = 3;
  int* unSortedArr = new int[len] {3, 2, 1};

  // Assert
  EXPECT_FALSE(InterpolationSearch::isArrayValid(unSortedArr, len));
}

TEST(InterpolationSearch, Correct_Check_Validity_When_Array_Sorted) {
  // Arrange
  const int len = 3;
  int* sortedArr = new int[len] {1, 2, 3};

  // Assert
  EXPECT_TRUE(InterpolationSearch::isArrayValid(sortedArr, len));
}

TEST(InterpolationSearch, Check_Validity_Throws_With_Null_Array) {
  // Arrange
  const int length = 3;

  // Assert
  ASSERT_ANY_THROW(InterpolationSearch::isArrayValid(NULL, length));
}

TEST(InterpolationSearch, Check_Validity_Throws_With_Negative_Array_Length) {
  // Arrange
  const int length = 3;
  int* sortedArray = new int[length] {1, 2, 3};

  // Assert
  ASSERT_ANY_THROW(InterpolationSearch::isArrayValid(sortedArray, -1));
}

TEST(InterpolationSearch, Check_Validity_Throws_With_Zero_Array_Length) {
  // Arrange
  const int len = 0;
  int* sortedArray = new int[len];

  // Assert
  ASSERT_ANY_THROW(InterpolationSearch::isArrayValid(sortedArray, len));
}

TEST(InterpolationSearch, Search_Return_Missing) {
  // Arrange
  const int length = 3;
  int* sortedArray = new int[length] {1, 2, 3};

  // Assert
  EXPECT_EQ(-1, InterpolationSearch::Search(4, sortedArray, length));
}

TEST(InterpolationSearch, Search_Return_Low) {
  // Arrange
  const int length = 3;
  int* sortedArray = new int[length] {1, 2, 3};

  // Assert
  EXPECT_EQ(0, InterpolationSearch::Search(1, sortedArray, length));
}

TEST(InterpolationSearch, Search_Return_Mid) {
  // Arrange
  const int length = 3;
  int* sortedArray = new int[length] {1, 2, 3};

  // Assert
  EXPECT_EQ(1, InterpolationSearch::Search(2, sortedArray, length));
}

TEST(InterpolationSearch, Search_Return_High) {
  // Arrange
  const int length = 3;
  int* sortedArray = new int[length] {1, 2, 3};

  // Assert
  EXPECT_EQ(2, InterpolationSearch::Search(3, sortedArray, length));
}

TEST(InterpolationSearch, Search_Return_Mid_From_Low) {
  // Arrange
  const int length = 4;
  int* sortedArray = new int[length] {5, 6, 7, 20};

  // Assert
  EXPECT_EQ(2, InterpolationSearch::Search(7, sortedArray, length));
}

TEST(InterpolationSearch, Search_Return_Mid_From_High) {
  // Arrange
  const int length = 4;
  int * sortedArray = new int[length] {5, 17, 19, 20};

  // Assert
  EXPECT_EQ(1, InterpolationSearch::Search(17, sortedArray, length));
}


