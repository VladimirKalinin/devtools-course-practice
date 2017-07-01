// Copyright 2017 Gvozdeva Viktoriia

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/infix_to_postfix_converter.h"
#include "include/stack.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class  InfixToPostfixConverterTest : public ::testing::Test {
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
    InfixToPostfixConverter app_;
    string output_;
};

TEST_F(InfixToPostfixConverterTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is an application for infix to postfix conversion\\..*");
}

TEST_F(InfixToPostfixConverterTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"1", "2"};

    Act(args);

    Assert("ERROR: Should be 1 argument\\..*");
}

TEST_F(InfixToPostfixConverterTest, Can_Detect_Empty_Input) {
    vector<string> args = {""};

    Act(args);

    Assert("Input is empty.*");
}

TEST_F(InfixToPostfixConverterTest, Can_Detect_Wrong_Character) {
    vector<string> args = {"1+x"};

    Act(args);

    Assert("is not valid character.*");
}

TEST_F(InfixToPostfixConverterTest, Can_Detect_Too_Long_Input) {
    vector<string> args = {string(MAX_STACK_SIZE+1, '1')};

    Act(args);

    Assert("Input expression is too long.*");
}

TEST_F(InfixToPostfixConverterTest, Can_Detect_Operation_In_First_Position) {
    vector<string> args = {"+1+1"};

    Act(args);

    Assert("First character can't be an operation.*");
}

TEST_F(InfixToPostfixConverterTest, Can_Detect_Operation_At_Last_Position) {
    vector<string> args = {"1+1+"};

    Act(args);

    Assert("Last character can't be an operation.*");
}


TEST_F(InfixToPostfixConverterTest, Can_Detect_Operation_After_Operation) {
    vector<string> args = {"1++1"};

    Act(args);

    Assert("Operation should be followed by number or.*");
}

TEST_F(InfixToPostfixConverterTest, Can_Detect_Close_Bracket_After_Operation) {
    vector<string> args = {"1+)"};

    Act(args);

    Assert("Operation should be followed by number or.*");
}

TEST_F(InfixToPostfixConverterTest, Can_Detect_Number_After_Close_Bracket) {
    vector<string> args = {"(1+1)1"};

    Act(args);

    Assert("'\\)' should be followed by an operation.*");
}

TEST_F(InfixToPostfixConverterTest,
       Can_Detect_Open_Bracket_After_Close_Bracket) {
    vector<string> args = {"(1+1)(1+1)"};

    Act(args);

    Assert("'\\)' should be followed by an operation.*");
}

TEST_F(InfixToPostfixConverterTest, Can_Detect_Operation_After_Open_Bracket) {
    vector<string> args = {"(+1+1)"};

    Act(args);

    Assert("'\\(' should be followed by an integer.*");
}

TEST_F(InfixToPostfixConverterTest,
       Can_Detect_Close_Bracket_After_Open_Bracket) {
    vector<string> args = {"1+()"};

    Act(args);

    Assert("'\\(' should be followed by an integer.*");
}

TEST_F(InfixToPostfixConverterTest, Can_Detect_Wrong_Integer) {
    vector<string> args = {"1+01"};

    Act(args);

    Assert("is wrong integer value.*");
}

TEST_F(InfixToPostfixConverterTest, Can_Work_Without_Brackets) {
    vector<string> args = {"1+1"};

    Act(args);

    Assert("1 1 \\+");
}

TEST_F(InfixToPostfixConverterTest, Can_Work_With_Brackets) {
    vector<string> args = {"(1+1)"};

    Act(args);

    Assert("1 1 \\+");
}

TEST_F(InfixToPostfixConverterTest, Can_Detect_Open_Bracket_Without_Close) {
    vector<string> args = {"(1+1"};

    Act(args);

    Assert("Wrong input expression*");
}

TEST_F(InfixToPostfixConverterTest, Can_Detect_Close_Bracket_Without_Open) {
    vector<string> args = {"1+1)"};

    Act(args);

    Assert("Wrong input expression*");
}

TEST_F(InfixToPostfixConverterTest, Can_Detect_Open_Bracket_Before_Operation) {
    vector<string> args = {"(+1+2)"};

    Act(args);

    Assert("'\\(' should be followed by an integer or '\\('.*");
}

TEST_F(InfixToPostfixConverterTest, Can_Detect_Close_Bracket_After_Open) {
    vector<string> args = {"1+()"};

    Act(args);

    Assert("'\\(' should be followed by an integer or '\\('.*");
}

TEST_F(InfixToPostfixConverterTest, Can_Detect_Open_Bracket_After_Number) {
    vector<string> args = {"1+1(1+1)"};

    Act(args);

    Assert("Number can't be followed by '\\('.*");
}

TEST_F(InfixToPostfixConverterTest, Can_Work_With_Operation_Between_Brackets) {
    vector<string> args = {"(1+1)+(1+1)"};

    Act(args);

    Assert("1 1 \\+ 1 1 \\+ \\+");
}


TEST_F(InfixToPostfixConverterTest, Can_Work_With_Nested_Brackets) {
    vector<string> args = {"(1+(1+1)+1)"};

    Act(args);

    Assert("1 1 1 \\+ \\+ 1 \\+");
}

TEST_F(InfixToPostfixConverterTest,
       Can_Work_With_Open_Bracket_After_Open_Braket) {
    vector<string> args = {"((1+1)+1)"};

    Act(args);

    Assert("1 1 \\+ 1 \\+");
}

TEST_F(InfixToPostfixConverterTest,
       Can_Work_With_Close_Bracket_After_Close_Braket) {
    vector<string> args = {"(1+(1+1))"};

    Act(args);

    Assert("1 1 1 \\+ \\+");
}

TEST_F(InfixToPostfixConverterTest, Can_Detect_Open_Bracket_After_Close) {
    vector<string> args = {"(1+1)(1+1)"};

    Act(args);

    Assert("'\\)' should be followed by an operation or '\\)'!");
}

TEST_F(InfixToPostfixConverterTest,
       Can_Work_With_Operation_With_Same_Priority) {
    vector<string> args = {"1+1-1"};

    Act(args);

    Assert("1 1 \\+ 1 -.*");
}

TEST_F(InfixToPostfixConverterTest,
       Can_Work_With_Operation_With_Diff_Piorities) {
    vector<string> args = {"1+2*2"};

    Act(args);

    Assert("1 2 2 \\* \\+");
}

TEST_F(InfixToPostfixConverterTest, Can_Work_With_Zero_Integer) {
    vector<string> args = {"1+0"};

    Act(args);

    Assert("1 0 \\+");
}

TEST_F(InfixToPostfixConverterTest,
       Can_Work_With_Complex_Expr_Without_Brackets) {
    vector<string> args = {"8+2*5-1/7+3*2-4"};

    Act(args);

    Assert("8 2 5 \\* \\+ 1 7 / - 3 2 \\* \\+ 4 -");
}

TEST_F(InfixToPostfixConverterTest, Can_Work_With_Complex_Expr_With_Brackets) {
    vector<string> args = {"(8+2*5)/(1+3*2-4)"};

    Act(args);

    Assert("8 2 5 \\* \\+ 1 3 2 \\* \\+ 4 - / ");
}
