// Copyright 2017 Bevzuk Semen

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/vector3D-app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class Vector3dAppTest : public ::testing::Test {
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
    Vector3DApp app_;
    string output_;
};

TEST_F(Vector3dAppTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a vector calculator application\\..*");
}

TEST_F(Vector3dAppTest, Is_Checking_Number_Of_Argumentsy) {
    vector<string> args = { "1", "2", "3", "4", "*"};

    Act(args);

    Assert("ERROR: Should be 7 or 4 arguments\\..*");
}

TEST_F(Vector3dAppTest, Can_Detect_Wrong_Number_Format_Unary) {
    vector<string> args = { "1", "string", "2" , "n" };

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(Vector3dAppTest, Can_Detect_Wrong_Operation_Format_Unary) {
    vector<string> args = { "1", "1", "1", "+" };

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(Vector3dAppTest, Can_Detect_Wrong_Number_Format_Binary) {
    vector<string> args = { "1", "2", "e", "4", "5", "6", "+" };

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(Vector3dAppTest, Can_Detect_Wrong_Operation_Format_Binaryy) {
    vector<string> args = { "1", "2", "3", "4", "5", "6", "n" };

    Act(args);

    Assert("Wrong operation format!");
}

TEST_F(Vector3dAppTest, Can_Add_Vector) {
    vector<string> args = { "1.1", "2.1", "3.1", "4.0", "5.0", "6.0", "+" };

    Act(args);

    Assert("Sum = <5.1; 7.1; 9.1>");
}

TEST_F(Vector3dAppTest, Can_Diff_Vector) {
    vector<string> args = { "1.0", "2.0", "3.0", "4.0", "5.0", "6.0", "-" };

    Act(args);

    Assert("Difference = <-3; -3; -3>");
}

TEST_F(Vector3dAppTest, Can_Mult_Scalar) {
    vector<string> args = { "1.0", "2.0", "3.0", "4.0", "5.0", "6.0", "*" };

    Act(args);

    Assert("Scalar multiplication = 32");
}

TEST_F(Vector3dAppTest, Can_Mult_Vector) {
    vector<string> args = { "1.0", "2.0", "3.0", "4.0", "5.0", "6.0", "^" };

    Act(args);

    Assert("Vector multiplication = <-3; 6; -3>");
}

TEST_F(Vector3dAppTest, Can_Norm_Vector) {
    vector<string> args = { "1.0", "1.0", "1.0", "n" };

    Act(args);

    Assert("Norm = 1.73205");
}

TEST_F(Vector3dAppTest, Can_Normalize_Vector) {
    vector<string> args = { "1.0", "1.0", "1.0", "N" };

    Act(args);

    Assert("Normalization vector = <0.57735; 0.57735; 0.57735>");
}
