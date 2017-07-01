// Copyright 2017 Mitrokhin Nikita

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/DichotomyApp.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class DichotomyAppTest : public ::testing::Test {
 protected:
    // virtual void SetUp() {}

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
    DichotomyApp app_;
    string output_;
};

TEST_F(DichotomyAppTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a method of dichotomy application\\..*");
}

TEST_F(DichotomyAppTest, Is_Checking_Number_Of_Argumentsy) {
    vector<string> args = {"1", "2", "3"};

    Act(args);

    Assert("Error: Should be 4 arguments\\..*");
}

TEST_F(DichotomyAppTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"1", "asd", "2", "1"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(DichotomyAppTest, Can_Detect_Wrong_Number_Format_Func) {
    vector<string> args = {"1", "2", "0.01", "1.1"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(DichotomyAppTest, Findmin_L_Border_Func_1_Is_Correct) {
    vector<string> args = {"0", "1", "0.01", "1"};

    Act(args);

    Assert("Min = 0.00390625");
}

TEST_F(DichotomyAppTest, Findmin_R_Border_Func_1_Is_Correct) {
    vector<string> args = {"-1", "0", "0.01", "1"};

    Act(args);

    Assert("Min = -0.00390625");
}

TEST_F(DichotomyAppTest, Findmin_L_Border_Func_2_Is_Correct) {
    vector<string> args = {"0", "1", "0.01", "2"};

    Act(args);

    Assert("Min = 0.75");
}

TEST_F(DichotomyAppTest, Findmin_R_Border_Func_2_Is_Correct) {
    vector<string> args = {"-1", "0", "0.01", "2"};

    Act(args);

    Assert("Min = -0.00390625");
}
