// Copyright 2017 Pletnev Nikita

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/line_plane_intersec_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class ApplicationTest : public ::testing::Test {
 protected:
    void Act(vector<string> args_) {
        vector<const char*> options;

        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    Application app_;
    string output_;
};

TEST_F(ApplicationTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is an application of calculating the intersection.*");
}

TEST_F(ApplicationTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = { "1", "2" };

    Act(args);

    Assert("ERROR: Should be 10 or 15 arguments\\..*");
}

TEST_F(ApplicationTest, Can_Detect_Wrong_Number_Format_Case1) {
    vector<string> args = {"1", "qe", "2", "4", "5", "5", "2", "7", "1", "0"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(ApplicationTest, Can_Detect_Wrong_Number_Format_Case2) {
    vector<string> args = {
        "1", "qe", "2", "4", "5", "5",
        "2", "7", "1", "0", "6", "-4", "2", "9", "1"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(ApplicationTest, Can_Calculate_Intersection_Case1) {
    vector<string> args = {
        "-3", "0", "-2", "-1", "-3", "3", "1", "-2", "-1", "3" };

    Act(args);

    Assert("coordinates of intersection point:\n x: -2\n y: 3\n z: -5");
}

TEST_F(ApplicationTest, Can_Calculate_Intersection_Case2) {
    vector<string> args = {
        "-3", "0", "-2", "-4", "-3", "1",
        "-3", "0", "0", "0", "0", "3", "0", "1", "1"};

    Act(args);

    Assert("coordinates of intersection point:\n x: -2\n y: 3\n z: -5");
}

TEST_F(ApplicationTest, Line_And_Plane_Are_Parallel) {
    vector<string> args = {
        "1", "-2", "2", "2", "3", "-4", "1", "6", "5", "4" };

    Act(args);

    Assert("Line and plane are parallel or line lies in plane.*");
}

TEST_F(ApplicationTest, Line_Lies_In_Plane) {
    vector<string> args = {
        "0", "5", "-1", "3", "-2", "4", "2", "-3", "-3", "12" };

    Act(args);

    Assert("Line and plane are parallel or line lies in plane.*");
}

TEST_F(ApplicationTest, Incorrect_Input_When_Set_Line_With_2_Points) {
    vector<string> args = {
        "0", "0", "0", "0", "0", "0",
        "-3", "0", "0", "0", "0", "3", "0", "1", "1" };

    Act(args);

    Assert("Incorrect input");
}


TEST_F(ApplicationTest, Incorrect_Input_When_Set_Plane_With_3_Points) {
    vector<string> args = {
        "-3", "0", "-2", "-4", "-3", "1",
        "0", "0", "0", "0", "0", "0", "0", "1", "1" };

    Act(args);

    Assert("Incorrect input");
}



