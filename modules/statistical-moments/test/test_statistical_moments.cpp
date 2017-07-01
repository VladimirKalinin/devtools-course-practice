// Copyright 2017 Olga Kiseleva

#include <gtest/gtest.h>
#include <vector>
#include "include/statistical_moments.h"

TEST(Kiseleva_Olga_StatisticalMomentsTest,
    Do_Throw_When_Two_Vectors_Are_Empty) {
    // Arrange
    std::vector<double> values;
    std::vector<double> changes;
    // Act+Assert
    EXPECT_ANY_THROW(StatisticalMoments::GetExpectancy(values, changes));
}
TEST(Kiseleva_Olga_StatisticalMomentsTest, Do_Throw_When_Values_Is_Empty) {
    // Arrange
    std::vector<double> values;
    std::vector<double> changes = { 0.25, 0.3 };
    // Act+Assert
    EXPECT_ANY_THROW(StatisticalMoments::GetExpectancy(values, changes));
}
TEST(Kiseleva_Olga_StatisticalMomentsTest, Do_Throw_When_Changes_Is_Empty) {
    // Arrange
    std::vector<double> values = { 0, 1, 2 };
    std::vector<double> changes;
    // Act+Assert
    EXPECT_ANY_THROW(StatisticalMoments::GetExpectancy(values, changes));
}
TEST(Kiseleva_Olga_StatisticalMomentsTest, Do_Throw_When_One_Change_Not_Valid) {
    // Arrange
    std::vector<double> values = { 0, 1, 2 };
    std::vector<double> changes = { 0.25, 5, 0.35 };
    // Act+Assert
    EXPECT_ANY_THROW(StatisticalMoments::GetExpectancy(values, changes));
}
TEST(Kiseleva_Olga_StatisticalMomentsTest,
    Do_Throw_When_One_Change_Is_Negative) {
    // Arrange
    std::vector<double> values = { 0, 1, 2 };
    std::vector<double> changes = { 0.25, -3.5, 0.35 };
    // Act+Assert
    EXPECT_ANY_THROW(StatisticalMoments::GetExpectancy(values, changes));
}
TEST(Kiseleva_Olga_StatisticalMomentsTest, Do_Throw_When_Sizes_Not_equals) {
    // Arrange
    std::vector<double> values = { 0, 1, 2, 3 };
    std::vector<double> changes = { 0.25, 0.1, 0.35 };
    // Act+Assert
    EXPECT_ANY_THROW(StatisticalMoments::GetExpectancy(values, changes));
}
TEST(Kiseleva_Olga_StatisticalMomentsTest,
    Do_Throw_When_Sum_Change_Not_Equals_1) {
    // Arrange
    std::vector<double> values = { 0, 1, 2 };
    std::vector<double> changes = { 0.25, 0.1, 0.35 };
    // Act+Assert
    EXPECT_ANY_THROW(StatisticalMoments::GetExpectancy(values, changes));
}
TEST(Kiseleva_Olga_StatisticalMomentsTest,
    Can_Count_Expectancy) {
    // Arrange
    std::vector<double> values = { 1, 2, 3, 4 };
    std::vector<double> changes = { 0.6, 0.24, 0.096, 0.064 };
    // Act
    double test_moment = StatisticalMoments::GetExpectancy(values, changes);
    // Assert
    EXPECT_DOUBLE_EQ(1.624, test_moment);
}
TEST(Kiseleva_Olga_StatisticalMomentsTest,
    Can_Count_Dispersion) {
    // Arrange
    std::vector<double> values = { 1, 2, 3, 4 };
    std::vector<double> changes = { 0.6, 0.24, 0.096, 0.064 };
    // Act
    double test_moment = StatisticalMoments::GetDispersion(values, changes);
    // Assert
    EXPECT_DOUBLE_EQ(0.810624, test_moment);
}
TEST(Kiseleva_Olga_StatisticalMomentsTest,
    Do_Throw_When_Custom_Moment_With_Zero_Order) {
    // Arrange
    std::vector<double> values = { 1, 2, 3, 4 };
    std::vector<double> changes = { 0.6, 0.24, 0.096, 0.064 };
    // Assert
    EXPECT_ANY_THROW(StatisticalMoments::GetCustomMoment(
        values, changes, 0, 0));
}
TEST(Kiseleva_Olga_StatisticalMomentsTest,
    Can_Count_Custom_Moment) {
    // Arrange
    std::vector<double> values = { 1, 2, 3, 4 };
    std::vector<double> changes = { 0.6, 0.24, 0.096, 0.064 };
    // Act
    double test_moment = StatisticalMoments::GetCustomMoment(
        values, changes, 1, 0);
    // Assert
    EXPECT_DOUBLE_EQ(1.624, test_moment);
}



