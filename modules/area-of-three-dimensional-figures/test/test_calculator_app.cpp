// Copyright 2017 Zhorin Sergey

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/calculator_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class CalculatorAppTest : public ::testing::Test {
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
    CalculatorApp app_;
    string output_;
};

TEST_F(CalculatorAppTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is an area calculator application.*");
}

TEST_F(CalculatorAppTest, Is_Checking_Number_Of_Arguments_With_Spheres) {
    vector<string> args = {"Sphere", "1", "2"};

    Act(args);

    Assert("ERROR: wrong number of arguments!.*");
}

TEST_F(CalculatorAppTest, Is_Checking_Number_Of_Arguments_With_Pyramid) {
    vector<string> args = {"Pyramid", "1", "2"};

    Act(args);

    Assert("ERROR: wrong number of arguments!.*");
}

TEST_F(CalculatorAppTest, Is_Checking_Number_Of_Arguments_With_Cone) {
    vector<string> args = {"Cone", "1"};

    Act(args);

    Assert("ERROR: wrong number of arguments!.*");
}

TEST_F(CalculatorAppTest, Is_Checking_Number_Of_Arguments_With_Cube) {
    vector<string> args = {"Cube", "1", "1"};

    Act(args);

    Assert("ERROR: wrong number of arguments!.*");
}

TEST_F(CalculatorAppTest, Is_Checking_Number_Of_Arguments_With_Cylinder) {
    vector<string> args = {"Cylinder", "1"};

    Act(args);

    Assert("ERROR: wrong number of arguments!.*");
}

TEST_F(CalculatorAppTest, Is_Checking_Number_Of_Arguments_With_Parallelepiped) {
    vector<string> args = {"Parallelepiped", "1"};

    Act(args);

    Assert("ERROR: wrong number of arguments!.*");
}

TEST_F(CalculatorAppTest, Is_Checking_Number_Of_Arguments_With_Prism) {
    vector<string> args = {"Prism", "1"};

    Act(args);

    Assert("ERROR: wrong number of arguments!.*");
}

TEST_F(CalculatorAppTest, Is_Checking_Number_Of_Arguments_With_Conoid) {
    vector<string> args = {"Conoid", "1"};

    Act(args);

    Assert("ERROR: wrong number of arguments!.*");
}

TEST_F(CalculatorAppTest, Is_Checking_Number_Of_Arguments_With_Tetra) {
    vector<string> args = {"Tetra", "1"};

    Act(args);

    Assert("ERROR: wrong number of arguments!.*");
}

TEST_F(CalculatorAppTest, Can_Detect_Wrong_Number_Format_With_Sphere) {
    vector<string> args = {"Sphere", "pi"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(CalculatorAppTest, Can_Detect_Wrong_Figure_Format) {
    vector<string> args = {"asd", "1"};

    Act(args);

    Assert("Wrong figure format!");
}

TEST_F(CalculatorAppTest, Can_Detect_Wrong_Number_Format_With_Pyramid) {
    vector<string> args = {"Pyramid", "pi", "1", "1"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(CalculatorAppTest, Can_Detect_Wrong_Number_Format_With_Cone) {
    vector<string> args = {"Cone", "pi", "1"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(CalculatorAppTest, Can_Detect_Wrong_Number_Format_With_Cube) {
    vector<string> args = {"Cube", "pi"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(CalculatorAppTest, Can_Detect_Wrong_Number_Format_With_Cylinder) {
    vector<string> args = {"Cylinder", "pi", "1"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(CalculatorAppTest, Can_Detect_Wrong_Number_Format_With_Parallelepiped) {
    vector<string> args = {"Parallelepiped", "pi", "1", "1"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(CalculatorAppTest, Can_Detect_Wrong_Number_Format_With_Prism) {
    vector<string> args = {"Prism", "pi", "1", "1", "1"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(CalculatorAppTest, Can_Detect_Wrong_Number_Format_With_Conoid) {
    vector<string> args = {"Conoid", "pi", "1", "1"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(CalculatorAppTest, Can_Detect_Wrong_Number_Format_With_Tetra) {
    vector<string> args = {"Tetra", "pi", "1", "1", "1"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(CalculatorAppTest, Can_Calc_Sphere) {
    vector<string> args = {"Sphere", "1"};

    Act(args);

    Assert("S = 12.5664");
}

TEST_F(CalculatorAppTest, Can_Calc_Pyramid) {
    vector<string> args = {"Pyramid", "1" , "1", "1"};

    Act(args);

    Assert("S = 2.73205");
}

TEST_F(CalculatorAppTest, Can_Calc_Cone) {
    vector<string> args = {"Cone", "1", "1"};

    Act(args);

    Assert("S = 3.14159");
}

TEST_F(CalculatorAppTest, Can_Calc_Cube) {
    vector<string> args = {"Cube", "1"};

    Act(args);

    Assert("S = 6");
}

TEST_F(CalculatorAppTest, Can_Calc_Cylinder) {
    vector<string> args = {"Cylinder", "1", "1" };

    Act(args);

    Assert("S = 6.28319");
}

TEST_F(CalculatorAppTest, Can_Calc_Parallelepiped) {
    vector<string> args = {"Parallelepiped", "1", "1", "1"};

    Act(args);

    Assert("S = 6");
}

TEST_F(CalculatorAppTest, Can_Calc_Prism) {
    vector<string> args = {"Prism", "1", "1", "1", "1"};

    Act(args);

    Assert("S = 3.86603");
}

TEST_F(CalculatorAppTest, Can_Calc_Conoid) {
    vector<string> args = {"Conoid", "1", "1", "1"};

    Act(args);

    Assert("S = 6.28319");
}

TEST_F(CalculatorAppTest, Can_Calc_Tetra) {
    vector<string> args = {"Tetra", "1", "1", "1", "1"};

    Act(args);

    Assert("S = 1.73205");
}
TEST_F(CalculatorAppTest, Can_Detect_Negative_Argument_With_Sphere) {
    vector<string> args = {"Sphere", "-1"};

    Act(args);

    Assert("r <== 0");
}

TEST_F(CalculatorAppTest, Can_Detect_Negative_Argument_With_Pyramid) {
    vector<string> args = { "Pyramid", "-1", "1", "1" };

    Act(args);

    Assert("Parameters are negative");
}

TEST_F(CalculatorAppTest, Can_Detect_Negative_Argument_With_Cone) {
    vector<string> args = { "Cone", "-1", "1" };

    Act(args);

    Assert("Parameters are negative");
}

TEST_F(CalculatorAppTest, Can_Detect_Negative_Argument_With_Cube) {
    vector<string> args = { "Cube", "-1" };

    Act(args);

    Assert("h <= 0");
}

TEST_F(CalculatorAppTest, Can_Detect_Negative_Argument_With_Cylinder) {
    vector<string> args = { "Cylinder", "-1", "1" };

    Act(args);

    Assert("Parameters are negative");
}

TEST_F(CalculatorAppTest, Can_Detect_Negative_Argument_With_Parallelepiped) {
    vector<string> args = { "Parallelepiped", "-1", "1", "1" };

    Act(args);

    Assert("Parameters are negative");
}

TEST_F(CalculatorAppTest, Can_Detect_Negative_Argument_With_Prism) {
    vector<string> args = { "Prism", "-1", "1", "1", "1" };

    Act(args);

    Assert("Parameters are negative");
}

TEST_F(CalculatorAppTest, Can_Detect_Negative_Argument_With_Conoid) {
    vector<string> args = { "Conoid", "-1", "1", "1" };

    Act(args);

    Assert("Parameters are negative");
}

TEST_F(CalculatorAppTest, Can_Detect_Negative_Argument_With_Tetra) {
    vector<string> args = { "Tetra", "-1", "1", "1", "1" };

    Act(args);

    Assert("Parameters are negative");
}
