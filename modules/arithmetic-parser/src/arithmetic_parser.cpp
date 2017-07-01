// Copyright 2017 Alexander Gaivanuk

#include "include/arithmetic_parser.h"

#include <math.h>
#include <cassert>
#include <cstring>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>
#include <iterator>

/*
    ArithmeticParser is a recursive descent parser that
    uses the folowing formal grammar:

    EXPRESSION        -> PLUSMINUS
    PLUSMINUS         -> MULDIV{[+ | -]MULDIV}
    MULDIV            -> POW{[* | /]POW}
    POW               -> VALUE | VALUE^VALUE
    VALUE             -> x | NUM x | NUM(EXPRESSION) | -VALUE | FUNCTION(EXPRESSION) | (EXPRESSION)
    FUNCTION          -> cos | sin | tg | ctg | arcsin | arccos | arctg | ln | lg | abs
    NUM               -> I | R
    I                 -> 0|1|2...|9|0I|1I|...|9I
    R                 -> I.I
*/

using std::string;
using std::vector;
using std::stack;

vector<char> ArithmeticParser::delims_ = {
    '^', '+', '-', '*', '/', '(', ')'
};

vector<string> ArithmeticParser::funcnames_ = {
    "cos",
    "sin",
    "tg",
    "ctg",
    "arcsin",
    "arccos",
    "arctg",
    "ln",
    "lg",
    "abs"
};

ArithmeticParser::Function ArithmeticParser::functions_[] = {
    cos,
    sin,
    tan,
    [](double x) -> double { return 1.0 / tan(x); },
    asin,
    acos,
    atan,
    log,
    log10,
    fabs
};

bool ArithmeticParser::Parse(const string &expression) {
    buffer_ = vector<char>();
    rpn_ = vector<Token>();
    buffer_.reserve(80);
    rpn_.reserve(50);

    is_good = true;
    string_ptr_ = expression.c_str();

    try {
        NextToken();
        NonterminalPlusMinus();
        ExpectToken(T_END);
    }
    catch (Token) {
        rpn_.clear();
        is_good = false;
    }
    catch (const char *) {
        rpn_.clear();
        is_good = false;
    }

    return is_good;
}

bool ArithmeticParser::Evaluate(double x, double *result) const {
    assert(result);
    if (!is_good) return false;

    stack<double> nums;
    size_t rpn_size = rpn_.size();
    if (rpn_size == 0) return false;

    for (size_t i = 0; i < rpn_size; i++) {
        const Token &token = rpn_[i];
        TokenType token_type = token.type;

        if (token_type == T_NUMBER) {
            nums.push(token.real_value);
        } else if (token_type == T_X) {
            nums.push(x);
        } else {
            double left_operand, right_operand;

            right_operand = nums.top(); nums.pop();
            if (token_type != T_NEGATE && token_type != T_FUNC) {
                left_operand = nums.top(); nums.pop();
            }

            if (token_type == T_PLUS)
                nums.push(left_operand + right_operand);
            else if (token_type == T_MINUS)
                nums.push(left_operand - right_operand);
            else if (token_type == T_MUL)
                nums.push(left_operand * right_operand);
            else if (token_type == T_DIV)
                nums.push(left_operand / right_operand);
            else if (token_type == T_POW)
                nums.push(pow(left_operand, right_operand));
            else if (token_type == T_NEGATE)
                nums.push(-right_operand);
            else if (token_type == T_FUNC)
                nums.push(functions_[token.int_value](right_operand));
        }
    }

    *result = nums.top();
    return true;
}

ArithmeticParser::Token ArithmeticParser::GetToken() {
    TokenState state = TS_INITIAL;
    int number = 0;  // currently parsed number

    while (true) {
        char ch = *string_ptr_;  // current char
        switch (state) {
        case TS_INITIAL:
            if (isspace(ch)) {
                string_ptr_++;
            } else if (tolower(ch) == 'x') {
                string_ptr_++;
                return Token(T_X);
            } else if (isdigit(ch)) {
                number = ch - '0';
                string_ptr_++;
                state = TS_NUMBER;
            } else if (isalpha(ch)) {
                state = TS_FUNCNAME;
            } else if (ch == 0) {
                return Token(T_END);
            } else {
                state = TS_DELIM;
            }
            break;
        case TS_NUMBER:
            while (isdigit(ch)) {
                number = number * 10 + ch - '0';
                ch = *++string_ptr_;
            }

            if (ch == '.') {
                ch = *++string_ptr_;
                if (!isdigit(ch)) throw string_ptr_;

                buffer_.clear();
                buffer_.push_back('0');
                buffer_.push_back('.');
                do {
                    buffer_.push_back(ch);
                    ch = *++string_ptr_;
                } while (isdigit(ch));

                buffer_.push_back('\0');

                double value = number + atof(buffer_.data());
                return Token(T_NUMBER, value);
            } else {
                return Token(T_NUMBER, static_cast<double>(number));
            }
            break;
        case TS_FUNCNAME: {
            buffer_.clear();
            while (isalpha(ch)) {
                buffer_.push_back(ch);
                ch = *++string_ptr_;
            }
            buffer_.push_back('\0');
            const char *str = buffer_.data();

            auto it = std::find(funcnames_.begin(), funcnames_.end(), str);
            if (it != funcnames_.end()) {
                int index =
                    static_cast<int>(std::distance(funcnames_.begin(), it));
                return Token(T_FUNC, index);
            }

            throw str;
        }
        case TS_DELIM:
            auto it = std::find(delims_.begin(), delims_.end(), ch);
            if (it != delims_.end()) {
                int index =
                    static_cast<int>(std::distance(delims_.begin(), it));
                string_ptr_++;
                return Token((TokenType)index);
            }
            throw string_ptr_;
        }
    }
}

void ArithmeticParser::NonterminalPlusMinus() {
    NonterminalMulDiv();
    while (token_.type == T_PLUS || token_.type == T_MINUS) {
        TokenType token_type = token_.type;
        NextToken();
        NonterminalMulDiv();
        rpn_.push_back(Token(token_type));
    }
}

void ArithmeticParser::NonterminalMulDiv() {
    NonterminalPow();
    while (token_.type == T_MUL || token_.type == T_DIV) {
        TokenType token_type = token_.type;
        NextToken();
        NonterminalPow();
        rpn_.push_back(Token(token_type));
    }
}

void ArithmeticParser::NonterminalPow() {
    NonterminalValue();
    if (token_.type == T_POW) {
        NextToken();
        NonterminalValue();
        rpn_.push_back(Token(T_POW));
    }
}

void ArithmeticParser::NonterminalValue() {
    if (token_.type == T_FUNC) {
        int functionIndex = token_.int_value;
        NextToken();
        ExpectToken(T_LPAREN);
        NextToken();
        NonterminalPlusMinus();
        ExpectToken(T_RPAREN);
        NextToken();
        rpn_.push_back(Token(T_FUNC, functionIndex));
    } else if (token_.type == T_X) {
        rpn_.push_back(Token(T_X));
        NextToken();
    } else if (token_.type == T_NUMBER) {
        rpn_.push_back(Token(token_));
        NextToken();
        if (token_.type == T_X) {
            rpn_.push_back(Token(T_X));
            rpn_.push_back(Token(T_MUL));
            NextToken();
        } else if (token_.type == T_LPAREN) {
            NextToken();
            NonterminalPlusMinus();
            ExpectToken(T_RPAREN);
            NextToken();
            rpn_.push_back(Token(T_MUL));
        }
    } else if (token_.type == T_LPAREN) {
        NextToken();
        NonterminalPlusMinus();
        ExpectToken(T_RPAREN);
        NextToken();
    } else if (token_.type == T_MINUS) {
        NextToken();
        NonterminalValue();
        rpn_.push_back(Token(T_NEGATE));
    } else {
        throw token_;
    }
}
