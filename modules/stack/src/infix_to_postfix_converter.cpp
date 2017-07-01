// Copyright 2017 Gvozdeva Viktoria

#include "include/infix_to_postfix_converter.h"

#include <string>
#include <cctype>

#include "include/stack.h"

using std::string;

InfixToPostfixConverter::InfixToPostfixConverter() : message_("") {
    opPriority_['+'] = 1;
    opPriority_['-'] = 1;
    opPriority_['*'] = 2;
    opPriority_['/'] = 2;
}

void InfixToPostfixConverter::help(const char* appname, const char* message) {
    message_ =
            string(message) +
            "This is an application for infix to postfix conversion.\n\n" +
            "You can enter an algebraic expression consisting of:\n" +
            "   1) integers,\n" +
            "   2) The following algebraic operations:\n" +
            "      1) Addition - '+',\n" +
            "      2) Subtraction - '-',\n" +
            "      3) Multiplication - '*',\n" +
            "      4) Division - '/'.\n" +
            "Do not use white spaces.\n\n"
            "Example:\n"
            "  $ " + appname + " (4-3)*5\n";
}

bool InfixToPostfixConverter::validateNumberOfArguments(int argc,
                                                        const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc != 2) {
        help(argv[0], "ERROR: Should be 1 argument.\n\n");
        return false;
    }
    return true;
}

bool InfixToPostfixConverter::isOperation(char c) {
    return opPriority_.find(c) != opPriority_.end();
}

bool InfixToPostfixConverter::isValidCharacter(char c) {
    return isOperation(c) || isdigit(c) || c == '(' || c == ')';
}
string InfixToPostfixConverter::operator()(int argc, const char** argv) {
    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }

    string inputExpr(argv[1]);
    string outputExpr;

    if (inputExpr.empty()) {
        return string("Input is empty!");
    }

    if (inputExpr.size() > MAX_STACK_SIZE) {
        return string("Input expression is too long!");
    }

    for (string::size_type i = 0; i < inputExpr.size(); i++) {
        if (!isValidCharacter(inputExpr[i])) {
            return string(inputExpr[i]+string(" is not valid character!"));
        }
    }

    if (isOperation(inputExpr[0])) {
        return string("First character can't be an operation!");
    }

    if (isOperation(inputExpr[inputExpr.size()-1])) {
        return string("Last character can't be an operation!");
    }

    for (string::size_type i = 0; i < inputExpr.size()-1; ++i) {
        if (isOperation(inputExpr[i]) &&
                !isdigit(inputExpr[i+1]) && inputExpr[i+1] != '(') {
            return string("Operation should be followed by number or '('!");
        }
        if (inputExpr[i] == ')' &&
                !isOperation(inputExpr[i+1]) && inputExpr[i+1] != ')') {
            return string("')' should be followed by an operation or ')'!");
        }
        if (inputExpr[i] == '(' &&
                !isdigit(inputExpr[i+1]) && inputExpr[i+1] != '(') {
            return string("'(' should be followed by an integer or '('!");
        }
        if (isdigit(inputExpr[i]) &&
            inputExpr[i+1] == '(') {
            return string("Number can't be followed by '('!");
        }
    }

    TStack<char> opStack(inputExpr.size());
    string::size_type i = 0;
    while ( i < inputExpr.size() ) {
        if (isdigit(inputExpr[i])) {
            string integer;
            while (i < inputExpr.size() && isdigit(inputExpr[i])) {
                integer += inputExpr[i];
                i++;
            }
            if (integer.size() > 1 && integer[0] == '0') {
                return string(integer+" is wrong integer value!");
            } else {
                outputExpr += integer + " ";
            }
        } else if (inputExpr[i] == '(') {
            opStack.Push(inputExpr[i]);
            i++;
        } else if (inputExpr[i] == ')') {
            while (!opStack.CheckEmpty() && opStack.StTop() != '(') {
                outputExpr += opStack.Pop();
                outputExpr += " ";
            }
            if (opStack.CheckEmpty()) {
                return string("Wrong input expression!");
            } else {
                opStack.Pop();
            }
            i++;
        } else if (isOperation(inputExpr[i])) {
            while (!opStack.CheckEmpty() &&
                   isOperation(opStack.StTop()) &&
                   opPriority_[opStack.StTop()] >= opPriority_[inputExpr[i]]) {
                outputExpr += opStack.Pop();
                outputExpr += " ";
            }
            opStack.Push(inputExpr[i]);
            i++;
        }
    }
    while (!opStack.CheckEmpty()) {
        if (!isOperation(opStack.StTop())) {
            return string("Wrong input expression!");
        } else {
            outputExpr += opStack. Pop();
            outputExpr += " ";
        }
    }


    return outputExpr;
}
