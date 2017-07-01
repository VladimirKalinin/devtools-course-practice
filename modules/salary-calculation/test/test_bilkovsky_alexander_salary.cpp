// Copyright 2017 Bilkovsky Alexander

#include <gtest/gtest.h>
#include "include/salary_caculationl.h"

TEST(Bilkovsky_Alexander_SalaryTest, throw_when_incorrect_input) {
    //  Arrange & Assert
    EXPECT_ANY_THROW(Salary worker(-1, 200, 200, 9));
}
TEST(Bilkovsky_Alexander_SalaryTest, throw_when_set_negative1) {
    //  Arrage
    Salary worker;
    //  Act & Assert
    EXPECT_ANY_THROW(worker.SetAdminRest(-1));
}
TEST(Bilkovsky_Alexander_SalaryTest, throw_when_set_negative2) {
    //  Arrage
    Salary worker;
    //  Act & Assert
    EXPECT_ANY_THROW(worker.SetNeededHours(-1));
}
TEST(Bilkovsky_Alexander_SalaryTest, throw_when_set_negative3) {
    //  Arrage
    Salary worker;
    //  Act & Assert
    EXPECT_ANY_THROW(worker.SetOvertimeBonus(-1));
}
TEST(Bilkovsky_Alexander_SalaryTest, throw_when_set_negative4) {
    //  Arrage
    Salary worker;
    //  Act & Assert
    EXPECT_ANY_THROW(worker.SetSalaryPerHour(-1));
}
TEST(Bilkovsky_Alexander_SalaryTest, throw_when_set_negative5) {
    //  Arrage
    Salary worker;
    //  Act & Assert
    EXPECT_ANY_THROW(worker.SetWorkDay(-1));
}
TEST(Bilkovsky_Alexander_SalaryTest, throw_when_set_negative6) {
    //  Arrage
    Salary worker;
    //  Act & Assert
    EXPECT_ANY_THROW(worker.SetWorkHours(-1));
}
TEST(Bilkovsky_Alexander_SalaryTest, throw_when_set_negative7) {
    //  Arrage
    Salary worker;
    //  Act & Assert
    EXPECT_ANY_THROW(worker.SetPenalty(-1));
}
TEST(Bilkovsky_Alexander_SalaryTest, can_set1) {
    //  Arrage
    Salary worker;
    //  Act
    worker.SetAdminRest(10);
    //  Assert
    EXPECT_EQ(10, worker.GetAdminRest());
}
TEST(Bilkovsky_Alexander_SalaryTest, can_set2) {
    //  Arrage
    Salary worker;
    //  Act
    worker.SetNeededHours(10);
    //  Assert
    EXPECT_EQ(10, worker.GetNeededHours());
}
TEST(Bilkovsky_Alexander_SalaryTest, can_set3) {
    //  Arrage
    Salary worker;
    //  Act
    worker.SetOvertimeBonus(10);
    //  Assert
    EXPECT_EQ(10, worker.GetOvertimeBonus());
}
TEST(Bilkovsky_Alexander_SalaryTest, can_set4) {
    //  Arrage
    Salary worker;
    //  Act
    worker.SetPenalty(10);
    //  Assert
    EXPECT_EQ(10, worker.GetPenalty());
}
TEST(Bilkovsky_Alexander_SalaryTest, can_set5) {
    //  Arrage
    Salary worker;
    //  Act
    worker.SetSalaryPerHour(10);
    //  Assert
    EXPECT_EQ(10, worker.GetSalaryPerHour());
}
TEST(Bilkovsky_Alexander_SalaryTest, can_set6) {
    //  Arrage
    Salary worker;
    //  Act
    worker.SetWorkDay(10);
    //  Assert
    EXPECT_EQ(10, worker.GetWorkDay());
}
TEST(Bilkovsky_Alexander_SalaryTest, can_set7) {
    //  Arrage
    Salary worker;
    //  Act
    worker.SetWorkHours(10);
    //  Assert
    EXPECT_EQ(10, worker.GetWorkHours());
}
TEST(Bilkovsky_Alexander_SalaryTest, can_calculate_salary1) {
    //  Arrage
    Salary worker;
    //  Act
    worker.CalculateSalary();
    //  Assert
    EXPECT_EQ(4000, worker.GetSalary());
}
TEST(Bilkovsky_Alexander_SalaryTest, can_calculate_salary2) {
    //  Arrage
    Salary worker(10, 100 , 90);
    //  Act
    worker.SetPenalty(10);
    worker.CalculateSalary();
    //  Assert
    EXPECT_EQ(800, worker.GetSalary());
}
TEST(Bilkovsky_Alexander_SalaryTest, can_calculate_salary3) {
    //  Arrage
    Salary worker(10, 100, 110);
    //  Act
    worker.SetOvertimeBonus(10);
    worker.CalculateSalary();
    //  Assert
    EXPECT_EQ(1100, worker.GetSalary());
}
TEST(Bilkovsky_Alexander_SalaryTest, can_calculate_salary4) {
    //  Arrage
    Salary worker(10, 100, 90);
    //  Act
    worker.SetAdminRest(4);
    worker.SetPenalty(10);
    worker.CalculateSalary();
    //  Assert
    EXPECT_EQ(900, worker.GetSalary());
}
TEST(Bilkovsky_Alexander_SalaryTest, can_calculate_salary5) {
    //  Arrage
    Salary worker(10, 100, 60);
    //  Act
    worker.SetAdminRest(4);
    worker.SetPenalty(10);
    worker.CalculateSalary();
    //  Assert
    EXPECT_EQ(560, worker.GetSalary());
}
