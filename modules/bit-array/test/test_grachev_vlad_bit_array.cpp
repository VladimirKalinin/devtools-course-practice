// Copyright 2017 Grachev Vlad

#include <gtest/gtest.h>

#include <string>
#include "include/bit_array.h"

TEST(BitArrayTest, Can_Create_Bit_Array_With_Positive_Size) {
    // Assert
    ASSERT_NO_THROW(BitArray bit_array(8));
}

TEST(BitArrayTest, Cant_Create_Bit_Array_With_Size_Zero) {
    // Assert
    ASSERT_ANY_THROW(BitArray bit_array(0));
}

TEST(BitArrayTest, Cant_Create_Bit_Array_With_Negative_Size) {
    // Assert
    ASSERT_ANY_THROW(BitArray bit_array(0));
}

TEST(BitArrayTest, Can_Get_Size) {
    // Arrange
    BitArray bit_array(8);
    unsigned int expected_array_size = 8;
    unsigned int real_array_size;

    // Act
    real_array_size = bit_array.GetSize();

    // Assert
    EXPECT_EQ(expected_array_size, real_array_size);
}

TEST(BitArrayTest, Bits_Sum_Of_New_Array_Is_Zero) {
    // Arrange
    BitArray bit_array(64);
    int sum = 0;

    // Act
    for (unsigned int i = 0; i < bit_array.GetSize(); i++)
        sum += bit_array.GetBit(i);

    // Assert
    EXPECT_EQ(0, sum);
}

TEST(BitArrayTest, Cant_Get_Bit_With_Negative_Index) {
    // Arrange
    BitArray bit_array(8);

    // Assert
    ASSERT_ANY_THROW(bit_array.GetBit(-1));
}

TEST(BitArrayTest, Cant_Get_Bit_With_Too_Large_Index) {
    // Arrange
    BitArray bit_array(8);

    // Assert
    ASSERT_ANY_THROW(bit_array.GetBit(8));
}

TEST(BitArrayTest, Can_Set_Bit) {
    // Arrange
    BitArray bit_array(8);

    // Act
    bit_array.SetBit(4);

    // Assert
    EXPECT_EQ(bit_array.GetBit(4), 1);
}

TEST(BitArrayTest, Cant_Set_Bit_With_Negative_Index) {
    // Arrange
    BitArray bit_array(8);

    // Assert
    ASSERT_ANY_THROW(bit_array.SetBit(-1));
}

TEST(BitArrayTest, Cant_Set_Bit_With_Too_Large_Index) {
    // Arrange
    BitArray bit_array(8);

    // Assert
    ASSERT_ANY_THROW(bit_array.SetBit(8));
}

TEST(BitArrayTest, Can_Clear_Bit) {
    // Arrange
    BitArray bit_array(8);
    int bit_value_aftrer_set, bit_value_after_clear;

    // Act
    bit_array.SetBit(5);
    bit_value_aftrer_set = bit_array.GetBit(5);
    bit_array.ClearBit(5);
    bit_value_after_clear = bit_array.GetBit(5);

    // Assert
    EXPECT_NE(bit_value_aftrer_set, bit_value_after_clear);
}

TEST(BitArrayTest, Can_Clear_Bit_With_Zero_Value) {
    // Arrange
    BitArray bit_array(8);

    // Assert
    ASSERT_NO_THROW(bit_array.ClearBit(5));
}

TEST(BitArrayTest, Cant_Clear_Bit_With_Negative_Index) {
    // Arrange
    BitArray bit_array(8);

    // Assert
    ASSERT_ANY_THROW(bit_array.ClearBit(-1));
}

TEST(BitArrayTest, Cant_Clear_Bit_With_Too_Large_Index) {
    // Arrange
    BitArray bit_array(8);

    // Assert
    ASSERT_ANY_THROW(bit_array.ClearBit(8));
}

TEST(BitArrayTest, Can_Assign_Bit_Arrays_With_Equal_Size) {
    // Arrange
    BitArray bit_array1(4), bit_array2(4);
    bool equality_of_bit_arrays;

    // Act
    for (unsigned int i = 0; i < bit_array1.GetSize(); i++)
        bit_array1.SetBit(i);
    bit_array2 = bit_array1;
    equality_of_bit_arrays = true;
    for (unsigned int i = 0; i < bit_array1.GetSize(); i++) {
        if (bit_array1.GetBit(i) != bit_array2.GetBit(i))
            equality_of_bit_arrays = false;
    }

    // Assert
    ASSERT_TRUE(equality_of_bit_arrays);
}

TEST(BitArrayTest, Assing_Operator_Changes_Bit_Array_Size) {
    // Arrange
    BitArray bit_array1(16), bit_array2(4);
    unsigned int expected_array_size = 16, realArraylSize;

    // Act
    bit_array2 = bit_array1;
    realArraylSize = bit_array2.GetSize();

    // Assert
    EXPECT_EQ(realArraylSize, expected_array_size);
}

TEST(BitArrayTest, Can_Assign_Bit_Arrays_With_Different_Size) {
    // Arrange
    BitArray bit_array1(16), bit_array2(4);
    bool equality_of_bit_arrays;

    // Act
    for (unsigned int i = 0; i < bit_array1.GetSize(); i++)
        bit_array1.SetBit(i);
    bit_array2 = bit_array1;
    equality_of_bit_arrays = true;
    for (unsigned int i = 0; i < bit_array1.GetSize(); i++) {
        if (bit_array1.GetBit(i) != bit_array2.GetBit(i))
            equality_of_bit_arrays = false;
    }

    // Assert
    ASSERT_TRUE(equality_of_bit_arrays);
}

TEST(BitArrayTest, Assigned_Bit_Array_Has_Its_Own_Memory) {
    // Arrange
    BitArray bit_array1(5), bit_array2(8);
    bool equality_of_bit_arrays;

    // Act
    bit_array1.SetBit(2);
    bit_array1.SetBit(4);

    bit_array2 = bit_array1;
    bit_array1.ClearBit(4);
    bit_array1.SetBit(0);

    for (unsigned int i = 0; i < bit_array1.GetSize(); i++) {
        if (bit_array1.GetBit(i) != bit_array2.GetBit(i))
            equality_of_bit_arrays = false;
    }

    // Assert
    ASSERT_FALSE(equality_of_bit_arrays);
}

TEST(BitArrayTest, Equal_Bit_Arrays_Are_Equal) {
    // Arrange
    BitArray bit_array1(8), bit_array2(8);

    // Act
    for (unsigned int i = 0; i < bit_array1.GetSize(); i++) {
        if (i % 2 == 0) {
            bit_array1.SetBit(i);
            bit_array2.SetBit(i);
        }
    }

    // Assert
    ASSERT_TRUE(bit_array1 == bit_array2);
}

TEST(BitArrayTest, Bit_Arrays_Witn_Different_Size_Are_Not_Equal) {
    // Arrange
    BitArray bit_array1(8), bit_array2(16);
    bool equality_of_bit_arrays;

    // Act
    equality_of_bit_arrays = !(bit_array1 == bit_array2)
                           && (bit_array1 != bit_array2);

    // Assert
    ASSERT_TRUE(equality_of_bit_arrays);
}

TEST(BitArrayTest, Not_Equal_Bit_Arrays_Are_Not_Equal) {
    // Arrange
    BitArray bit_array1(8), bit_array2(8);
    bool equality_of_bit_arrays;

    // Act
    for (unsigned int i = 0; i < bit_array1.GetSize(); i++) {
        if (i % 2 == 0)
            bit_array1.SetBit(i);
        else
            bit_array2.SetBit(i);
    }
    equality_of_bit_arrays = !(bit_array1 == bit_array2)
                           && (bit_array1 != bit_array2);

    // Assert
    ASSERT_TRUE(equality_of_bit_arrays);
}

TEST(BitArrayTest, Can_Copy_Bit_Array) {
    // Arrange
    BitArray bit_array1(8);

    // Assert
    ASSERT_NO_THROW(BitArray bit_array2(bit_array1));
}

TEST(BitArrayTest, Copied_Bit_Array_Is_Equal_Original) {
    // Arrange
    BitArray bit_array1(8);

    // Act
    for (unsigned int i = 0; i < bit_array1.GetSize(); i++) {
        if (i % 2 == 0)
            bit_array1.SetBit(i);
    }
    BitArray bit_array2(bit_array1);

    // Assert
    EXPECT_EQ(bit_array1, bit_array2);
}

TEST(BitArrayTest, Copied_Bit_Array_Has_Its_Own_Memory) {
    // Arrange
    BitArray bit_array1(5);

    // Act
    bit_array1.SetBit(2);
    bit_array1.SetBit(4);

    BitArray bit_array2(bit_array1);
    bit_array1.ClearBit(4);
    bit_array1.SetBit(0);

    // Assert
    EXPECT_NE(bit_array1, bit_array2);
}

TEST(BitArrayTest, AND_Operator_Applied_To_Bit_Arrays_Of_Equal_Size) {
    // Arrange
    BitArray bit_array1(4), bit_array2(4), expected_bit_array(4);

    // Act
    bit_array1.SetBit(2);
    bit_array1.SetBit(3);

    bit_array2.SetBit(1);
    bit_array2.SetBit(3);

    expected_bit_array.SetBit(3);

    // Assert
    EXPECT_EQ(expected_bit_array, bit_array1 & bit_array2);
}

TEST(BitArrayTest, AND_Operator_Applied_To_Bit_Arrays_Of_Non_Equal_Size) {
    // Arrange
    BitArray bit_array1(4), bit_array2(5), expected_bit_array(5);

    // Act
    bit_array1.SetBit(2);
    bit_array1.SetBit(3);

    bit_array2.SetBit(1);
    bit_array2.SetBit(3);

    expected_bit_array.SetBit(3);

    // Assert
    EXPECT_EQ(expected_bit_array, bit_array1 & bit_array2);
}

TEST(BitArrayTest, OR_Operator_Applied_To_Bit_Arrays_Of_Equal_Size) {
    // Arrange
    BitArray bit_array1(4), bit_array2(4), expected_bit_array(4);

    // Act
    bit_array1.SetBit(2);
    bit_array1.SetBit(3);

    bit_array2.SetBit(1);
    bit_array2.SetBit(3);

    expected_bit_array.SetBit(1);
    expected_bit_array.SetBit(2);
    expected_bit_array.SetBit(3);

    // Assert
    EXPECT_EQ(expected_bit_array, bit_array1 | bit_array2);
}

TEST(BitArrayTest, OR_Operator_Applied_To_Bit_Arrays_Of_Non_Equal_Size) {
    // Arrange
    BitArray bit_array1(4), bit_array2(5), expected_bit_array(5);

    // Act
    bit_array1.SetBit(2);
    bit_array1.SetBit(3);

    bit_array2.SetBit(1);
    bit_array2.SetBit(3);

    expected_bit_array.SetBit(1);
    expected_bit_array.SetBit(2);
    expected_bit_array.SetBit(3);

    // Assert
    EXPECT_EQ(expected_bit_array, bit_array1 | bit_array2);
}

TEST(BitArrayTest, XOR_Operator_Applied_To_Bit_Arrays_Of_Equal_Size) {
    // Arrange
    BitArray bit_array1(4), bit_array2(4), expected_bit_array(4);

    // Act
    bit_array1.SetBit(2);
    bit_array1.SetBit(3);

    bit_array2.SetBit(1);
    bit_array2.SetBit(3);

    expected_bit_array.SetBit(1);
    expected_bit_array.SetBit(2);

    // Assert
    EXPECT_EQ(expected_bit_array, bit_array1 ^ bit_array2);
}

TEST(BitArrayTest, XOR_Operator_Applied_To_Bit_Arrays_Of_Non_Equal_Size) {
    // Arrange
    BitArray bit_array1(4), bit_array2(5), expected_bit_array(5);

    // Act
    bit_array1.SetBit(2);
    bit_array1.SetBit(3);

    bit_array2.SetBit(1);
    bit_array2.SetBit(3);

    expected_bit_array.SetBit(1);
    expected_bit_array.SetBit(2);

    // Assert
    EXPECT_EQ(expected_bit_array, bit_array1 ^ bit_array2);
}

TEST(BitArrayTest, Can_Invert_Bit_Array) {
    // Arrange
    BitArray bf(2), negativeBitArray(2), expected_bit_array(2);

    // Act
    bf.SetBit(1);
    negativeBitArray = ~bf;

    expected_bit_array.SetBit(0);

    // Assert
    EXPECT_EQ(expected_bit_array, negativeBitArray);
}

TEST(BitArrayTest, Can_Invert_Large_BitArray) {
    // Arrange
    BitArray bit_array(128), negativeBitArray(128), expected_bit_array(128);

    // Act
    for (unsigned int i = 0; i < bit_array.GetSize(); i++) {
        if (i % 2 == 0)
            bit_array.SetBit(i);
        else
            expected_bit_array.SetBit(i);
    }
    negativeBitArray = ~bit_array;

    // Assert
    EXPECT_EQ(expected_bit_array, negativeBitArray);
}

TEST(BitArrayTest, Can_Transform_Bit_Array_Into_Strign) {
    // Arrange
    BitArray bit_array(8);
    std::string result_string, expected_strign = "00011010";

    // Act
    bit_array.SetBit(1);
    bit_array.SetBit(3);
    bit_array.SetBit(4);
    result_string = bit_array.ToString();

    // Assert
    EXPECT_EQ(expected_strign, result_string);
}
