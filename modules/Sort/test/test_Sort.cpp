// Copyright 2017 Kalinin Vladimir

#include <gtest/gtest.h>
#include <include/Sort.h>
#include <algorithm>

TEST(Sort, Can_Compare_Result) {
    // Arrange
    const int N = 6;
    const int Array[N] = { 5, 2, 1, 4, 3, 6 };
    Sort Array1(Array, N);
    Sort Array2(Array, N);

    // Act
    const bool expected_true = Array1 == Array2;

    // Assert
    EXPECT_TRUE(expected_true);
}

TEST(Sort, Can_Compare_Result_False) {
    // Arrange
    const int N = 10;
    const int M = 5;
    const int Arr1[N] = { 3457, 7, 5, 12, 56, 4, 1, 33, 27, 1040 };
    const int Arr2[M] = { 5, 2, 1, 4, 3 };
    Sort Array1(Arr1, N);
    Sort Array2(Arr2, M);

    // Act
    const bool expected_false = Array1 == Array2;

    // Assert
    EXPECT_FALSE(expected_false);
}

TEST(Sort, Can_Do_Paste_Sort) {
    // Arrange
    const int N = 7;
    const int Arr[N] = { 23, 14, 12, 63, 127, 8, 412 };
    Sort Array(Arr, N);

    // Act
    Array.PasteSort();

    // Assert
    const int expected_result[N] = { 8, 12, 14, 23, 63, 127, 412 };
    const Sort expected_sort(expected_result, N);
    EXPECT_EQ(expected_sort, Array);
}

TEST(Sort, Can_Do_Quick_Sort) {
    // Arrange
    const int N = 7;
    const int Arr[N] = { 111, 2321, 15, 43, 927, 432, 1 };
    Sort Array(Arr, N);

    // Act
    Array.QuickSort(0, N-1);

    // Assert
    const int expected_result[N] = { 1, 15, 43, 111, 432, 927, 2321 };
    const Sort expected_sort(expected_result, N);
    EXPECT_EQ(expected_sort, Array);
}

TEST(Sort, Can_Do_Paste_Sort_With_Duplicate_Elements) {
    // Arrange
    const int N = 7;
    const int Arr[N] = { 23, 14, 23, 63, 14, 8, 8 };
    Sort Array(Arr, N);

    // Act
    Array.PasteSort();

    // Assert
    const int expected_result[N] = { 8, 8, 14, 14, 23, 23, 63 };
    const Sort expected_sort(expected_result, N);
    EXPECT_EQ(expected_sort, Array);
}

TEST(Sort, Can_Do_Quick_Sort_With_Duplicate_Elements) {
    // Arrange
    const int N = 7;
    const int Arr[N] = { 111, 43, 15, 43, 111, 42, 1 };
    Sort Array(Arr, N);

    // Act
    Array.QuickSort(0, N-1);

    // Assert
    const int expected_result[N] = { 1, 15, 42, 43, 43, 111, 111 };
    const Sort expected_sort(expected_result, N);
    EXPECT_EQ(expected_sort, Array);
}

TEST(Sort, Can_Do_Quick_Sort_With_Negative_Elements) {
    // Arrange
    const int N = 7;
    const int Arr[N] = { -111, -2321, -15, -43, -927, -432, -1 };
    Sort Array(Arr, N);

    // Act
    Array.QuickSort(0, N-1);

    // Assert
    const int expected_result[N] = { -2321, -927, -432, -111, -43, -15, -1 };
    const Sort expected_sort(expected_result, N);
    EXPECT_EQ(expected_sort, Array);
}

TEST(Sort, Can_Do_Paste_Sort_With_Negative_Elements) {
    // Arrange
    const int N = 7;
    const int Arr[N] = { -23, -14, -3, -63, -4, -8, -18 };
    Sort Array(Arr, N);

    // Act
    Array.PasteSort();

    // Assert
    const int expected_result[N] = { -63, -23, -18, -14, -8, -4, -3 };
    const Sort expected_sort(expected_result, N);
    EXPECT_EQ(expected_sort, Array);
}

TEST(Sort, Can_Right_Recording_Elements) {
    // Arrange
    const int N = 7;
    const int Arr[N] = { 1, 2, 7, 4, 21, 18, 6 };
    Sort Array(Arr, N);

    // Act
    const int result_value = Array[6];

    // Assert
    const int expected_value = 6;
    EXPECT_EQ(result_value, expected_value);
}

TEST(Sort, Can_Do_Choice_Sort) {
    // Arrange
    const int N = 7;
    const int Arr[N] = { 7, 11, 3, 228, 1, 1001, 4400 };
    Sort Array(Arr, N);

    // Act
    Array.ChoiceSort();

    // Assert
    const int expected_result[N] = { 1, 3, 7, 11, 228, 1001, 4400 };
    const Sort expected_sort(expected_result, N);
    EXPECT_EQ(expected_sort, Array);
}

TEST(Sort, Can_Do_Choice_Sort_With_Duplicate_Elements) {
    // Arrange
    const int N = 7;
    const int Arr[N] = { 7, 11, 3, 11, 1, 1, 4400 };
    Sort Array(Arr, N);

    // Act
    Array.ChoiceSort();

    // Assert
    const int expected_result[N] = { 1, 1, 3, 7, 11, 11, 4400 };
    const Sort expected_sort(expected_result, N);
    EXPECT_EQ(expected_sort, Array);
}

TEST(Sort, Can_Do_Choice_Sort_With_Negative_Elements) {
    // Arrange
    const int N = 7;
    const int Arr[N] = { -7, -11, -3, -228, -1, -1001, -4400 };
    Sort Array(Arr, N);

    // Act
    Array.ChoiceSort();

    // Assert
    const int expected_result[N] = { -4400, -1001, -228, -11, -7, -3, -1 };
    const Sort expected_sort(expected_result, N);
    EXPECT_EQ(expected_sort, Array);
}

TEST(Sort, Can_Result_False) {
  // Arrange
    const int N = 5;
    const int Arr1[N] = { 3, 7, 5, 12, 56 };
    const int Arr2[N] = { 5, 2, 1, 4, 7 };
    Sort Array1(Arr1, N);
    Sort Array2(Arr2, N);

    // Act
    const bool expected_false = Array1 == Array2;

    // Assert
    EXPECT_FALSE(expected_false);
}

TEST(Sort, Can_Do_Merge_Sort) {
    // Arrange
    const int N = 7;
    const int Arr[N] = { 7, 13, 2, 64, 11, 923, 4 };
    Sort Array(Arr, N);

    // Act
    Array.MergeSort(0, N-1);

    // Assert
    const int expected_result[N] = { 2, 4, 7, 11, 13, 64, 923 };
    const Sort expected_sort(expected_result, N);
    EXPECT_EQ(expected_sort, Array);
}

TEST(Sort, Can_Do_Merge_Sort_With_Duplicate_Elements) {
    // Arrange
    const int N = 7;
    const int Arr[N] = { 7, 13, 2, 7, 14, 2, 13 };
    Sort Array(Arr, N);

    // Act
    Array.MergeSort(0, N-1);

    // Assert
    const int expected_result[N] = { 2, 2, 7, 7, 13, 13, 14 };
    const Sort expected_sort(expected_result, N);
    EXPECT_EQ(expected_sort, Array);
}

TEST(Sort, Can_Do_Merge_Sort_With_Negative_Elements) {
    // Arrange
    const int N = 7;
    const int Arr[N] = { -7, -13, -2, -64, -11, -923, -4 };
    Sort Array(Arr, N);

    // Act
    Array.MergeSort(0, N-1);

    // Assert
    const int expected_result[N] = { -923, -64, -13, -11, -7, -4, -2 };
    const Sort expected_sort(expected_result, N);
    EXPECT_EQ(expected_sort, Array);
}

TEST(SortTest, bugreport_gaivanuk_mitrokhin_check_assign_operator) {
    const int N = 3;
    const int arr[N] = {3, 1, 2};
    const int expected_result[N] = {1, 2, 3};

    Sort sort(arr, N);
    Sort expected_sort(expected_result, N);

    {
        Sort sort2(arr, N);
        sort2 = sort;
    }

    sort.PasteSort();
    EXPECT_EQ(expected_sort, sort);
}

TEST(Sort, Can_Assign) {
    // Arrange
    const int N = 5;
    const int Arr1[N] = { 3, 7, 5, 12, 56 };
    const int Arr2[N] = { 5, 2, 1, 4, 7 };
    Sort expected_sort(Arr1, N);
    Sort sort(Arr2, N);

    // Act
    sort = expected_sort;

    // Assert
    EXPECT_EQ(expected_sort, sort);
}

TEST(Sort, Can_Assign_Yourself) {
    // Arrange
    const int N = 5;
    const int Arr1[N] = { 3, 7, 5, 12, 56 };
    Sort expected_sort(Arr1, N);
    Sort sort(Arr1, N);

    // Act
    sort = sort;

    // Assert
    EXPECT_EQ(expected_sort, sort);
}
