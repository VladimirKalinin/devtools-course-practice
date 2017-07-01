// Copyright 2017 Grechukhin Nikita

#include "include/function_parser.h"
#include <cctype>
#include <cstring>
#include <string>
#include <cmath>
#include <stdexcept>
#include <cstdlib>
#include <iomanip>

int get_priority(const std::string& token) {
    if (token == "+" || token == "-") return 1;
    if (token == "*" || token == "/" || token == "mod") return 2;
    if (token == "**") return 3;
    return 0;
}

Expression::Expression(const std::string &token) : token(token) {}

Expression::Expression(const std::string &token,
    const Expression &a) : token(token) {
    args.push_back(a);
}

Expression::Expression(const std::string &token,
    const Expression &a, const Expression &b) :
    token(token) {
    args.push_back(a);
    args.push_back(b);
}

std::string Parser::ParseToken() {
    if (input_ != nullptr) {
        while (std::isspace(*input_))
            ++input_;

        if (std::isdigit(*input_)) {
            std::string number;
            while (std::isdigit(*input_) || *input_ == '.')
                number.push_back(*input_++);
            return number;
        }

        static const std::string tokens[] =
        { "+", "-", "**", "*", "/", "mod", "abs", "sin", "cos", "(", ")" };


        for (auto &token : tokens) {
            if (std::strncmp(input_, token.c_str(), token.size()) == 0) {
                input_ += token.size();
                return token;
            }
        }
    } else {
        throw std::runtime_error("Input fucntion is null");
    }

    return "";
}

Expression Parser::ParseSimpleExpression() {
    auto token = ParseToken();

    if (token.empty())
        throw std::runtime_error("Invalid input");

    if (std::isdigit(token[0]))
        return Expression(token);

    if (token == "(") {
        auto result = Parse2();
        if (ParseToken() != ")") throw std::runtime_error("Expected ')' ");
        return result;
    }

    auto arg = ParseSimpleExpression();
    return Expression(token, arg);
}

Expression Parser::ParseBinaryExpression(int min_priority) {
    auto left_expr = ParseSimpleExpression();

    for (;;) {
        auto op = ParseToken();
        auto priority = get_priority(op);
        if (priority <= min_priority) {
            input_ -= op.size();
            return left_expr;
        }

        auto right_expr = ParseBinaryExpression(priority);
        left_expr = Expression(op, left_expr, right_expr);
    }
}

Expression Parser::Parse2() {
    return ParseBinaryExpression(0);
}

Expression Parser::Parse(const char *input) {
    input_ = input;
    return Parse2();
}

double Expression::eval() {
    switch (args.size()) {
    case 2: {
                auto a = args[0].eval();
                auto b = args[1].eval();
                if (token == "+") return a + b;
                if (token == "-") return a - b;
                if (token == "*") return a * b;
                if (token == "/") return a / b;
                if (token == "**") return pow(a, b);
                if (token == "mod")
                    return static_cast<int>(a) % static_cast<int>(b);
                throw std::runtime_error("Unknown binary operator");
    }

    case 1: {
                auto a = args[0].eval();
                if (token == "+") return +a;
                if (token == "-") return -a;
                if (token == "abs") return fabs(a);
                if (token == "sin") return sin(a);
                if (token == "cos") return cos(a);
                throw std::runtime_error("Unknown unary operator");
    }

    case 0:
        return strtod(token.c_str(), nullptr);
    }

    throw std::runtime_error("Unknown expression type");
}
