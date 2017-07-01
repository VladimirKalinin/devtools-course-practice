// Copyright 2017 Ivan Kuchkov

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/arithmetic_calculator.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

typedef vector<const char*> AppArgs;

class ArithmeticCalculatorTest : public ::testing::Test {
 protected:
    ArithmeticCalculatorTest() : retcode_(0) {}

    void Act(AppArgs args) {
        args.insert(args.begin(), "appname");
        testing::internal::CaptureStdout();
        testing::internal::CaptureStderr();
        retcode_ = ArithmeticCalculator(static_cast<int>(args.size()),
                                        args.data());
        out_ = testing::internal::GetCapturedStdout();
        err_ = testing::internal::GetCapturedStderr();
    }

    void Assert(int ret, const std::string &out, const std::string &err) {
        EXPECT_EQ(ret, retcode_);
        EXPECT_TRUE(RE::PartialMatch(out_, RE(out)));
        EXPECT_TRUE(RE::PartialMatch(err_, RE(err)));
    }

 private:
    int retcode_;
    string out_;
    string err_;
};

TEST_F(ArithmeticCalculatorTest, Do_Print_Help_Without_Arguments) {
    AppArgs args = {};

    Act(args);

    Assert(RESULT_BAD_ARGUMENTS,
           "",
           "appname: a simple arithmetic calculator application\\..*");
}

TEST_F(ArithmeticCalculatorTest, Do_Print_Error_Wrong_Number_of_Arguments) {
    AppArgs args = {"1", "2", "3"};

    Act(args);

    Assert(RESULT_BAD_ARGUMENTS,
           "",
           "appname: error: wrong number of arguments.*");
}

TEST_F(ArithmeticCalculatorTest, Do_Print_Error_Cannot_Parse_Formal_Parameter) {
    AppArgs args = {"1+1", "not a number"};

    Act(args);

    Assert(RESULT_ERROR_PARSING,
           "",
           "appname: error: cannot parse formal parameter.*");
}

TEST_F(ArithmeticCalculatorTest, Do_Print_Error_Cannot_Parse_Expression) {
    AppArgs args = {"invalid expression"};

    Act(args);

    Assert(RESULT_ERROR_PARSING,
           "",
           "appname: error: cannot parse expression\n");
}

TEST_F(ArithmeticCalculatorTest, Do_Print_Result_of_Simple_Expression) {
    AppArgs args = {"2 * 2"};

    Act(args);

    Assert(RESULT_SUCESS,
           "4",
           "");
}

TEST_F(ArithmeticCalculatorTest, Do_Print_Result_of_Expression_With_Parameter) {
    AppArgs args = {"104 + x", "42"};

    Act(args);

    Assert(RESULT_SUCESS,
           "146",
           "");
}
