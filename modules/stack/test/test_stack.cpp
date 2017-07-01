// Copyright 2017 Anna Mironova

#include <gtest/gtest.h>

#include "include/stack.h"

// TESTS FOR INT

TEST(StackTest, Can_Create_Stack_With_Positive_Length_INT) {
    // Arrange & Act & Assert
    EXPECT_NO_THROW(TStack<int> v(5));
}

TEST(StackTest, Cant_Create_Too_Large_Stack_INT) {
    // Arrange & Act & Assert
    EXPECT_ANY_THROW(TStack<int> v(MAX_STACK_SIZE + 1));
}

TEST(StackTest, Cant_Create_Stack_With_Negative_Length_INT) {
    // Arrange & Act & Assert
    EXPECT_ANY_THROW(TStack<int> v(-5));
}

TEST(StackTest, Can_Create_Copied_Stack_INT) {
    // Arrange
    TStack <int> v(10);

    // Act & Assert
    EXPECT_NO_THROW(TStack <int> v1(v));
}

TEST(StackTest, Can_Get_Stack_Size_INT) {
    // Arrange
    TStack <int> v(10);

    // Act & Assert
    EXPECT_EQ(10, v.GetStackSize());
}

TEST(StackTest, Can_Get_Stack_Top_INT) {
    // Arrange
    TStack <int> v(10);
    v.Push(2);
    v.Push(15);

    // Act & Assert
    EXPECT_EQ(1, v.GetStackTop());
}


TEST(StackTest, Can_Push_INT) {
    // Arrange
    TStack <int> v(2);

    // Act
    v.Push(5);

    // Assert
    EXPECT_EQ(5, v.StTop());
}

TEST(StackTest, Cant_Push_When_Stack_Is_Full_INT) {
    // Arrange
    TStack <int> v(2);
    v.Push(5);
    v.Push(7);

    // Act&Assert
    EXPECT_ANY_THROW(v.Push(9));
}

TEST(StackTest, Can_Pop_INT) {
    // Arrange
    TStack <int> v(2);
    v.Push(5);

    // Act&Assert
    EXPECT_EQ(5, v.Pop());
}

TEST(StackTest, Top_Decreases_When_Pop_INT) {
    // Arrange
    TStack <int> v(2);
    v.Push(5);

    // Act & Assert
    EXPECT_EQ(5, v.Pop());
    EXPECT_EQ(-1, v.GetStackTop());
}

TEST(StackTest, Can_Equate_To_Itself) {
    // Arrange
    TStack <int> v(2);
    v.Push(5);

    // Act
    v = v;

    // Assert
    EXPECT_EQ(5, v.Pop());
    EXPECT_TRUE(v.CheckEmpty());
}

TEST(StackTest, Can_stTop_INT) {
    // Arrange
    TStack <int> v(2);
    v.Push(5);

    // Act&Assert
    EXPECT_EQ(5, v.StTop());
}

TEST(StackTest, Top_Does_Not_Change_When_stTop_INT) {
    // Arrange
    TStack <int> v(2);
    v.Push(5);

    // Act & Assert
    EXPECT_EQ(5, v.StTop());
    EXPECT_EQ(0, v.GetStackTop());
}

TEST(StackTest, Cant_stTop_When_Stack_Is_Empty_INT) {
    // Arrange
    TStack <int> v(2);

    // Act & Assert
    EXPECT_ANY_THROW(v.StTop());
}

TEST(StackTest, Cant_Pop_When_Stack_Is_Empty_INT) {
    // Arrange
    TStack <int> v(2);

    // Act & Assert
    EXPECT_ANY_THROW(v.Pop());
}

TEST(StackTest, New_Stack_Is_Empty_INT) {
    // Arrange
    TStack<int> v(2);

    // Act & Assert
    EXPECT_TRUE(v.CheckEmpty());
}

TEST(StackTest, Can_Check_Full_Stack_INT) {
    // Arrange
    TStack<int> v(2);
    v.Push(5);
    v.Push(7);

    // Act & Assert
    EXPECT_TRUE(v.CheckFull());
}

TEST(StackTest, Can_Check_Stack_Not_Empty_INT) {
    // Arrange
    TStack<int> v(2);
    v.Push(5);

    // Act & Assert
    EXPECT_FALSE(v.CheckEmpty());
}

// TESTS FOR DOUBLE

TEST(StackTest, Can_Create_Stack_With_Positive_Length_DOUBLE) {
    // Arrange & Act & Assert
    EXPECT_NO_THROW(TStack<double> v(5));
}

TEST(StackTest, Cant_Create_Too_Large_Stack_DOUBLE) {
    // Arrange & Act & Assert
    EXPECT_ANY_THROW(TStack<double> v(MAX_STACK_SIZE + 1));
}

TEST(StackTest, Cant_Create_Stack_With_Negative_Length_DOUBLE) {
    // Arrange & Act & Assert
    EXPECT_ANY_THROW(TStack<double> v(-5));
}

TEST(StackTest, Can_Create_Copied_Stack_DOUBLE) {
    // Arrange
    TStack <double> v(10);

    // Act & Assert
    EXPECT_NO_THROW(TStack <double> v1(v));
}

TEST(StackTest, Can_Get_Stack_Size_DOUBLE) {
    // Arrange
    TStack <double> v(10);

    // Act & Assert
    EXPECT_EQ(10, v.GetStackSize());
}

TEST(StackTest, Can_Get_Stack_Top_DOUBLE) {
    // Arrange
    TStack <double> v(10);
    v.Push(2.55);
    v.Push(15.1);

    // Act & Assert
    EXPECT_EQ(1, v.GetStackTop());
}

TEST(StackTest, Can_Check_Stack_Not_Full_DOUBLE) {
    // Arrange
    TStack <double> v(10);
    v.Push(2.55);
    v.Push(15.1);
    v.Push(10.1);
    v.Push(8.1);
    v.Push(14.1);

    // Act & Assert
    EXPECT_FALSE(v.CheckFull());
}

TEST(StackTest, Can_Push_DOUBLE) {
    // Arrange
    TStack <double> v(2);

    // Act
    v.Push(5.25);

    // Assert
    EXPECT_EQ(5.25, v.StTop());
}

TEST(StackTest, Cant_Push_When_Stack_Is_Full_DOUBLE) {
    // Arrange
    TStack <double> v(2);
    v.Push(5.7);
    v.Push(7.5);

    // Act&Assert
    EXPECT_ANY_THROW(v.Push(9.05));
}

TEST(StackTest, Can_Pop_DOUBLE) {
    // Arrange
    TStack <double> v(2);
    v.Push(5.1);

    // Act&Assert
    EXPECT_EQ(5.1, v.Pop());
}

TEST(StackTest, Top_Decreases_When_Pop_DOUBLE) {
    // Arrange
    TStack <double> v(2);
    v.Push(5.1);

    // Act & Assert
    EXPECT_EQ(5.1, v.Pop());
    EXPECT_EQ(-1, v.GetStackTop());
}

TEST(StackTest, Can_stTop_DOUBLE) {
    // Arrange
    TStack <double> v(2);
    v.Push(5.1);

    // Act&Assert
    EXPECT_EQ(5.1, v.StTop());
}

TEST(StackTest, Top_Does_Not_Change_When_stTop_DOUBLE) {
    // Arrange
    TStack <double> v(2);
    v.Push(5.1);

    // Act & Assert
    EXPECT_EQ(5.1, v.StTop());
    EXPECT_EQ(0, v.GetStackTop());
}

TEST(StackTest, Cant_stTop_When_Stack_Is_Empty_DOUBLE) {
    // Arrange
    TStack <double> v(2);

    // Act & Assert
    EXPECT_ANY_THROW(v.StTop());
}

TEST(StackTest, Cant_Pop_When_Stack_Is_Empty_DOUBLE) {
    // Arrange
    TStack <double> v(2);

    // Act & Assert
    EXPECT_ANY_THROW(v.Pop());
}

TEST(StackTest, New_Stack_Is_Empty_DOUBLE) {
    // Arrange
    TStack<double> v(2);

    // Act & Assert
    EXPECT_TRUE(v.CheckEmpty());
}

TEST(StackTest, Can_Check_Full_Stack_DOUBLE) {
    // Arrange
    TStack<double> v(2);
    v.Push(5.1);
    v.Push(7.15);

    // Act & Assert
    EXPECT_TRUE(v.CheckFull());
}

// TESTS FOR CHAR

TEST(StackTest, Can_Create_Stack_With_Positive_Length_CHAR) {
    // Arrange & Act & Assert
    EXPECT_NO_THROW(TStack<char> v(5));
}

TEST(StackTest, Cant_Create_Too_Large_Stack_CHAR) {
    // Arrange & Act & Assert
    EXPECT_ANY_THROW(TStack<char> v(MAX_STACK_SIZE + 1));
}

TEST(StackTest, Cant_Create_Stack_With_Negative_Length_CHAR) {
    // Arrange & Act & Assert
    EXPECT_ANY_THROW(TStack<char> v(-5));
}

TEST(StackTest, Can_Create_Copied_Stack_CHAR) {
    // Arrange
    TStack <char> v(10);

    // Act & Assert
    EXPECT_NO_THROW(TStack <char> v1(v));
}

TEST(StackTest, Can_Get_Stack_Size_CHAR) {
    // Arrange
    TStack <char> v(10);

    // Act & Assert
    EXPECT_EQ(10, v.GetStackSize());
}

TEST(StackTest, Can_Get_Stack_Top_CHAR) {
    // Arrange
    TStack <char> v(10);
    v.Push('s');
    v.Push('a');

    // Act & Assert
    EXPECT_EQ(1, v.GetStackTop());
}


TEST(StackTest, Can_Push_CHAR) {
    // Arrange
    TStack <char> v(2);

    // Act
    v.Push('a');

    // Assert
    EXPECT_EQ('a', v.StTop());
}

TEST(StackTest, Cant_Push_When_Stack_Is_Full_CHAR) {
    // Arrange
    TStack <char> v(2);
    v.Push('a');
    v.Push('b');

    // Act&Assert
    EXPECT_ANY_THROW(v.Push('c'));
}

TEST(StackTest, Can_Pop_CHAR) {
    // Arrange
    TStack <char> v(2);
    v.Push('d');

    // Act&Assert
    EXPECT_EQ('d', v.Pop());
}

TEST(StackTest, Top_Decreases_When_Pop_CHAR) {
    // Arrange
    TStack <char> v(2);
    v.Push('d');

    // Act&Assert
    EXPECT_EQ('d', v.Pop());
    EXPECT_EQ(-1, v.GetStackTop());
}

TEST(StackTest, Can_stTop_CHAR) {
    // Arrange
    TStack <char> v(2);
    v.Push('d');

    // Act&Assert
    EXPECT_EQ('d', v.StTop());
}

TEST(StackTest, Top_Does_Not_Change_When_stTop_CHAR) {
    // Arrange
    TStack <char> v(2);
    v.Push('d');

    // Act&Assert
    EXPECT_EQ('d', v.StTop());
    EXPECT_EQ(0, v.GetStackTop());
}

TEST(StackTest, Cant_stTop_When_Stack_Is_Empty_CHAR) {
    // Arrange
    TStack <char> v(2);

    // Act & Assert
    EXPECT_ANY_THROW(v.StTop());
}

TEST(StackTest, Cant_Pop_When_Stack_Is_Empty_CHAR) {
    // Arrange
    TStack <char> v(2);

    // Act & Assert
    EXPECT_ANY_THROW(v.Pop());
}

TEST(StackTest, New_Stack_Is_Empty_CHAR) {
    // Arrange
    TStack<char> v(2);

    // Act & Assert
    EXPECT_TRUE(v.CheckEmpty());
}

TEST(StackTest, Can_Check_Full_Stack_CHAR) {
    // Arrange
    TStack<char> v(2);
    v.Push('m');
    v.Push('n');

    // Act & Assert
    EXPECT_TRUE(v.CheckFull());
}
TEST(StackTest, bugreport_gaivanuk_mironova_check_assign_operator) {
    TStack<int> st(1);
    st.Push(1);

    {
        TStack<int> st2(1);
        st2 = st;
    }

    ASSERT_NO_FATAL_FAILURE(st.StTop());
    ASSERT_NO_THROW(st.StTop());
    EXPECT_EQ(1, st.StTop());
}
