// Copyright 2017 Baranov Evgeny

#include <gtest/gtest.h>

#include <utility>

#include "include/al_number.h"
#include "include/matrix.h"

TEST(Baranov_Evgeny_MatrixMultiplicationTest, can_create_matrix) {
    // Arrange
    // Act
    // Assert
    ASSERT_NO_THROW(ALMatrix matrix);
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, can_create_matrix1) {
    // Arrange
    // Act
    // Assert
    ASSERT_NO_THROW(ALMatrix matrix(4));
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, can_create_matrix2) {
    // Arrange
    // Act
    // Assert
    ASSERT_NO_THROW(ALMatrix matrix(3, 4));
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, can_create_matrix3) {
    // Arrange
    // Act
    // Assert
    ASSERT_NO_THROW(ALMatrix matrix(0));
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, can_create_matrix4) {
    // Arrange
    // Act
    // Assert
    ASSERT_NO_THROW(ALMatrix matrix(0, 0));
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, can_correct_get_row) {
    // Arrange
    ALMatrix matrix(3, 4);
    // Act
    // Assert
    EXPECT_EQ(3, matrix.GetRows());
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, can_correct_get_columns) {
    // Arrange
    ALMatrix matrix(3, 4);
    // Act
    // Assert
    EXPECT_EQ(4, matrix.GetColumns());
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, can_create_matrix_correct) {
    // Arrange
    ALMatrix matrix(3, 4);
    std::pair<int, int> rows_columns;
    std::pair<int, int> result;
    // Act
    rows_columns.first = matrix.GetRows();
    result.first = 3;
    rows_columns.second = matrix.GetColumns();
    result.second = 4;
    // Assert
    EXPECT_EQ(result, rows_columns);
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, can_correct_set_matrix) {
    // Arrange
    ALMatrix matrix(3, 4);
    ALNumber expected("11");
    // Act
    matrix[1][2] = "11";
    // Assert
    EXPECT_EQ(expected, matrix[1][2]);
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, can_correct_assign_matrixes) {
    // Arrange
    ALMatrix matrix1(3, 4);
    ALMatrix matrix2;
    ALNumber expected("2");
    // Act
    matrix1[1][2] = "2";
    matrix2 = matrix1;
    // Assert
    EXPECT_EQ(expected, matrix2[1][2]);
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, correct_assign_not_0_matrix) {
    // Arrange
    ALMatrix matrix1(3, 4);
    ALMatrix matrix2(1);
    ALNumber expected("2");
    // Act
    matrix1[1][2] = "2";
    matrix2 = matrix1;
    // Assert
    EXPECT_EQ(expected, matrix2[1][2]);
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, can_correct_sum_matrixes) {
    // Arrange
    ALMatrix matrix1(3, 4);
    ALMatrix matrix2(3, 4);
    ALMatrix sum_matrixes;
    ALMatrix result(3, 4);
    bool flag(true);
    // Act
    for (unsigned int i = 0; i < 3; ++i) {
        for (unsigned int j = 0; j < 4; ++j) {
            matrix1[i][j] = "990";
            matrix2[i][j] = "120";
            result[i][j] = "1110";
        }
    }
    sum_matrixes = matrix1 + matrix2;
    for (unsigned int i = 0; i < 3; ++i) {
        for (unsigned int j = 0; j < 4; ++j) {
            if (sum_matrixes[i][j] != result[i][j]) {
                flag = false;
                break;
            }
        }
    }
    // Assert
    EXPECT_EQ(1, flag);
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, can_correct_compos_matrixes) {
    // Arrange
    ALMatrix matrix1(2, 3);
    ALMatrix matrix2(3, 5);
    ALMatrix compos_matrixes;
    ALMatrix result(2, 5);
    bool flag(true);
    // Act
    for (unsigned int i = 0; i < matrix1.GetRows(); ++i) {
        for (unsigned int j = 0; j < matrix1.GetColumns(); ++j) {
            matrix1[i][j] = "23";
        }
    }
    for (unsigned int i = 0; i < matrix2.GetRows(); ++i) {
        for (unsigned int j = 0; j < matrix2.GetColumns(); ++j) {
            matrix2[i][j] = "23";
        }
    }
    for (unsigned int i = 0; i < result.GetRows(); ++i) {
        for (unsigned int j = 0; j < result.GetColumns(); ++j) {
            result[i][j] = "1587";
        }
    }
    compos_matrixes = matrix1 * matrix2;
    for (unsigned int i = 0; i < compos_matrixes.GetRows(); ++i) {
        for (unsigned int j = 0; j < compos_matrixes.GetColumns(); ++j) {
            if (compos_matrixes[i][j] != result[i][j]) {
                flag = false;
                break;
            }
        }
    }
    // Assert
    EXPECT_EQ(1, flag);
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, can_create_copy_matrix) {
    // Arrange
    ALMatrix matrix1(3, 4);
    bool flag(true);
    // Act
    for (unsigned int i = 0; i < matrix1.GetRows(); ++i) {
        for (unsigned int j = 0; j < matrix1.GetColumns(); ++j) {
            matrix1[i][j] = "23";
        }
    }
    ALMatrix matrix2(matrix1);
    for (unsigned int i = 0; i < matrix2.GetRows(); ++i) {
        for (unsigned int j = 0; j < matrix2.GetColumns(); ++j) {
            if (matrix2[i][j] != matrix1[i][j]) {
                flag = false;
                break;
            }
        }
    }
    // Assert
    EXPECT_EQ(1, flag);
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, cant_sum_wrong_matrixes) {
    // Arrange
    ALMatrix matrix1(3, 4);
    ALMatrix matrix2(3, 3);
    // Act
    for (unsigned int i = 0; i < matrix1.GetRows(); ++i) {
        for (unsigned int j = 0; j < matrix1.GetColumns(); ++j) {
            matrix1[i][j] = "23";
        }
    }
    for (unsigned int i = 0; i < matrix2.GetRows(); ++i) {
        for (unsigned int j = 0; j < matrix2.GetColumns(); ++j) {
            matrix2[i][j] = "23";
        }
    }
    // Assert
    ASSERT_ANY_THROW(matrix1+matrix2);
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, cant_compos_wrong_matrixes) {
    // Arrange
    ALMatrix matrix1(3, 4);
    ALMatrix matrix2(2, 3);
    // Act
    // Assert
    ASSERT_ANY_THROW(matrix1 * matrix2);
}

TEST(Baranov_Evgeny_MatrixMultiplicationTest, cant_use_wrong_indexation) {
    // Arrange
    ALMatrix matrix1(3);
    // Act
    // Assert
    ASSERT_ANY_THROW(matrix1[4]);
}
