// Copyright 2017 Kiseleva Olga

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/quadratic_eq_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class  QuadraticEquationAppTest : public ::testing::Test {
 protected:
    void Act(vector<string> args) {
        vector<const char*> options;

        options.push_back("appname");
        for (size_t i = 0; i < args.size(); ++i) {
            options.push_back(args[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(std::string expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    QuadrEquationCalc app_;
    string output_;
};

TEST_F(QuadraticEquationAppTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a quadratic equation application\\..*");
}

TEST_F(QuadraticEquationAppTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = { "1", "2"};

    Act(args);

    Assert("ERROR: Should be 3 arguments\\..*");
}

TEST_F(QuadraticEquationAppTest, Is_Checking_Coefficient) {
    vector<string> args = { "0", "1", "2"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(QuadraticEquationAppTest, Is_Checking_Coefficient_Format) {
    vector<string> args = { "most", "2", "3"};

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(QuadraticEquationAppTest, Is_Checking_Num_With_Correct_Coefficient) {
    vector<string> args = { "1", "4", "4"};

    Act(args);

    Assert("x = -2");
}
