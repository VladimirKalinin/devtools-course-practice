// Copyright 2017 Grechukhin Nikita

#ifndef MODULES_INTEGRATION_METHODS_INCLUDE_FUNCTION_PARSER_H_
#define MODULES_INTEGRATION_METHODS_INCLUDE_FUNCTION_PARSER_H_

#include <vector>
#include <string>

struct Expression {
    explicit Expression(const std::string &token);
    Expression(const std::string &token, const Expression &a);
    Expression(const std::string &token, const Expression &a,
        const Expression &b);

    std::string token;
    std::vector<Expression> args;
    double eval();
};

class Parser {
 public:
     Expression Parse(const char *input);

 private:
     Expression Parse2();
     std::string ParseToken();
     Expression ParseSimpleExpression();
     Expression ParseBinaryExpression(int min_priority);

     const char* input_;
};

#endif  // MODULES_INTEGRATION_METHODS_INCLUDE_FUNCTION_PARSER_H_
