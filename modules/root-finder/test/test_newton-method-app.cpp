// Copyright 2017 Maxim Doronin

#include <gtest/gtest.h>
#include <vector>
#include <string>
#include "include/functions.h"
#include "include/newton-method-app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class NewtonMethodApplicationTest : public ::testing::Test {
 protected:
     void Act(std::vector<std::string> args_) {
        std::vector<const char*> options;

        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); i++) {
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
    NewtonMethodApplication app_;
    std::string output_;
};

TEST_F(NewtonMethodApplicationTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a Newton Method application");
}

TEST_F(NewtonMethodApplicationTest, Is_Checking_Accuracy) {
    vector<string> args = { "EXPONENT" };

    Act(args);

    Assert("ERROR: No accuracy!");
}

TEST_F(NewtonMethodApplicationTest, Is_Checking_Bounds) {
    vector<string> args = { "EXPONENT", "0.01", "0" };

    Act(args);

    Assert("ERROR: No bounds!");
}

TEST_F(NewtonMethodApplicationTest, Is_Checking_Any_Coefficients) {
    vector<string> args = { "EXPONENT", "0.01", "0", "1" };

    Act(args);

    Assert("ERROR: No coefficients");
}

TEST_F(NewtonMethodApplicationTest, Is_Checking_Coefficients) {
    vector<string> args = { "EXPONENT", "0.01", "0", "1", "1" };

    Act(args);

    Assert("Mismatch in the number of arguments");
}

TEST_F(NewtonMethodApplicationTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"EXPONENT", "0.01", "pi", "phi"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(NewtonMethodApplicationTest, Can_Detect_Wrong_Function_Format) {
    vector<string> args = {"EXP", "0.01", "0", "1", "2", "3", "4"};

    Act(args);

    Assert("Function doesn't exist");
}

TEST_F(NewtonMethodApplicationTest, Can_Detect_Zero_As_First_Coeff) {
    vector<string> args = {"EXPONENT", "0.01", "0", "1", "0", "3", "4"};

    Act(args);

    Assert("First coefficient can't be zero");
}

TEST_F(NewtonMethodApplicationTest, Can_Detect_No_Monotone_Function) {
    vector<string> args = { "POLINOMIAL_2_DEGREE" };
    string added[] = { "0.01", "-4", "4", "2", "1", "-6" };
    args.insert(args.end(), added, added + 6);
    Act(args);

    Assert("Function is not monotone or it is a point");
}

TEST_F(NewtonMethodApplicationTest, Can_Detect_If_Segment_Is_Point) {
    vector<string> args = { "POLINOMIAL_2_DEGREE" };
    string added[] = { "0.01", "4", "4", "2", "1", "-6" };
    args.insert(args.end(), added, added + 6);
    Act(args);

    Assert("Function is not monotone or it is a point");
}

TEST_F(NewtonMethodApplicationTest, Can_Detect_If_Function_Hasnt_Roots) {
    vector<string> args = { "POLINOMIAL_2_DEGREE" };
    string added[] = { "0.01", "3", "4", "2", "1", "-6" };
    args.insert(args.end(), added, added + 6);
    Act(args);

    Assert("There are no roots on the segment");
}

TEST_F(NewtonMethodApplicationTest, Can_Find_Root_On_Polinomial_2_Degree) {
    vector<string> args = { "POLINOMIAL_2_DEGREE" };
    string added[] = { "0.01", "0", "2", "2", "1", "-6" };
    args.insert(args.end(), added, added + 6);
    Act(args);

    Assert("Root: 1.5");
}

TEST_F(NewtonMethodApplicationTest, Can_Find_Root_On_Polinomial_3_Degree) {
    vector<string> args = { "POLINOMIAL_3_DEGREE" };
    string added[] = { "0.01", "3", "6", "1", "-1", "-16", "16" };
    args.insert(args.end(), added, added + 7);
    Act(args);

    Assert("Root: 4");
}

TEST_F(NewtonMethodApplicationTest, Can_Find_Root_On_Polinomial_4_Degree) {
    vector<string> args = { "POLINOMIAL_4_DEGREE", "0.01" };
    string added[] = { "2.5", "3.5", "1", "1", "-9", "-9", "0" };
    args.insert(args.end(), added, added + 7);
    Act(args);

    Assert("Root: 3");
}

TEST_F(NewtonMethodApplicationTest, Can_Find_Root_On_Exponent) {
    vector<string> args = { "EXPONENT", "0.01", "-1", "1", "1", "2", "-1" };

    Act(args);

    Assert("Root: 0");
}

TEST_F(NewtonMethodApplicationTest, Low_Accuracy_Affect_On_Result) {
    vector<string> args = { "EXPONENT", "0.01", "0", "0.5", "1", "2.5", "-2" };

    Act(args);

    Assert("Root: 0.277272");
}

TEST_F(NewtonMethodApplicationTest, Hi_Accuracy_Affect_On_Result) {
    vector<string> args = { "EXPONENT" };
    string added[] = { "0.0001", "0", "0.5", "1", "2.5", "-2" };
    args.insert(args.end(), added, added + 6);
    Act(args);

    Assert("Root: 0.277259");
}
