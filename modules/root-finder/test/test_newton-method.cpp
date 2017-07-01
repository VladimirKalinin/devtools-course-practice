// Copyright 2017 Fedorov Igor

#include <gtest/gtest.h>

#include <vector>
#include "include/functions.h"
#include "include/newton-method.h"

class NewtonMethodTest : public ::testing::Test {
 protected:
    NewtonMethod nMet;
    Function* function;
    void SetUp() {
        std::vector<float> koefs;
        koefs.push_back(1);
        koefs.push_back(0);
        koefs.push_back(-1);
        function = new Polynomial2Degree(koefs);
    }
    void TearDown() {
        delete function;
    }
};

TEST_F(NewtonMethodTest, Can_Set_Conditions_One) {
    // Assert
    ASSERT_NO_THROW(nMet.SetAB(0.0, 1.0));
}

TEST_F(NewtonMethodTest, Can_set_conditions_two) {
    // Assert
    ASSERT_NO_THROW(nMet.SetAccuracy(0.01));
}

TEST_F(NewtonMethodTest, Throws_When_Function_Is_Not_Monotone1) {
    // Arrange
    nMet.SetAB(-1.0, 1.0);
    nMet.SetAccuracy(0.01);
    // Assert
    ASSERT_ANY_THROW(nMet.FindRoot(function));
}

TEST_F(NewtonMethodTest, Throws_When_Function_Is_Not_Monotone2) {
    // Arrange
    nMet.SetAB(-1.0, 3.0);
    nMet.SetAccuracy(0.01);
    // Assert
    ASSERT_ANY_THROW(nMet.FindRoot(function));
}

TEST_F(NewtonMethodTest, Throws_When_Function_Is_Not_Monotone3) {
    // Arrange
    nMet.SetAB(-3.0, 1.0);
    nMet.SetAccuracy(0.01);
    // Assert
    ASSERT_ANY_THROW(nMet.FindRoot(function));
}

TEST_F(NewtonMethodTest, Can_Recognize_Monotone_Function) {
    // Arrange
    nMet.SetAB(1.0, 0.0);
    nMet.SetAccuracy(0.01);
    // Assert
    ASSERT_NO_THROW(nMet.FindRoot(function));
}

TEST_F(NewtonMethodTest, Can_Find_Root) {
    // Arrange
    nMet.SetAB(0.0, 2.0);
    nMet.SetAccuracy(0.01);
    // Assert
    ASSERT_FLOAT_EQ(nMet.FindRoot(function), 1);
}

TEST_F(NewtonMethodTest, Can_Find_Root2) {
    // Arrange
    nMet.SetAB(-2.0, 0.0);
    nMet.SetAccuracy(0.01);
    // Assert
    ASSERT_FLOAT_EQ(nMet.FindRoot(function), -1);
}

TEST_F(NewtonMethodTest, Throws_When_No_Root_At_Segment) {
    // Arrange
    nMet.SetAB(9.0, 3.0);
    nMet.SetAccuracy(0.01);
    // Assert
    ASSERT_ANY_THROW(nMet.FindRoot(function));
}

TEST_F(NewtonMethodTest, Throws_When_Segment_Is_A_Point) {
    // Arrange
    nMet.SetAB(9.0, 9.0);
    nMet.SetAccuracy(0.01);
    // Assert
    ASSERT_ANY_THROW(nMet.FindRoot(function));
}
