// Copyright 2017 Grechukhin Nikita

#include <gtest/gtest.h>

#include <string>
#include <cmath>

#include "include/function_parser.h"

TEST(EXPRESSION, can_create_number_expression) {
    std::string token = "1";

    Expression expression(token);

    EXPECT_EQ(token, expression.token);
}

TEST(EXPRESSION, can_create_unary_expression) {
    std::string token = "sin";
    std::string args = "90";

    Expression args_exp(args);
    Expression expression(token, args_exp);

    EXPECT_EQ(token, expression.token);
    EXPECT_EQ(args, expression.args.at(0).token);
}

TEST(EXPRESSION, can_create_binary_expression) {
    std::string token = "+";
    std::string arg1 = "90";
    std::string arg2 = "180";

    Expression arg_exp1(arg1);
    Expression arg_exp2(arg2);
    Expression expression(token, arg_exp1, arg_exp2);

    EXPECT_EQ(token, expression.token);
    EXPECT_EQ(arg1, expression.args.at(0).token);
    EXPECT_EQ(arg2, expression.args.at(1).token);
}

TEST(PARSER, can_calculate) {
    std::string func = "45+15*sin(2*45) + cos(45)";

    Parser parser;
    double actual = parser.Parse(func.c_str()).eval();
    double expected = 45 + 15*sin(2*45) + cos(45);

    EXPECT_NEAR(expected, actual, 1e-2);
}

TEST(PARSER, throw_exception_when_input_empty) {
    std::string func = "";

    Parser parser;
    ASSERT_ANY_THROW(parser.Parse(func.c_str()).eval());
}

TEST(PARSER, throw_exception_when_input_invalid) {
    std::string func = "10*(115+3";

    Parser parser;
    ASSERT_ANY_THROW(parser.Parse(func.c_str()).eval());
}

TEST(PARSER, throw_exception_when_unknow_binary_operator) {
    std::string func = "2*(3q3)";

    Parser parser;

    ASSERT_ANY_THROW(parser.Parse(func.c_str()).eval());
}

TEST(PARSER, throw_exception_when_unknow_unary_operator) {
    std::string func = "qwe(2)";

    Parser parser;
    ASSERT_ANY_THROW(parser.Parse(func.c_str()).eval());
}

TEST(PARSER, can_calculate_with_first_cos) {
    const char *func = "cos(180)";

    Parser parser;

    double expected = cos(180);
    EXPECT_NEAR(expected, parser.Parse(func).eval(), 1e-2);
}
