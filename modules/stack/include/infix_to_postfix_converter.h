// Copyright 2017 Gvozdeva Viktoria

#ifndef MODULES_STACK_INCLUDE_INFIX_TO_POSTFIX_CONVERTER_H_
#define MODULES_STACK_INCLUDE_INFIX_TO_POSTFIX_CONVERTER_H_

#include <string>
#include <map>

class InfixToPostfixConverter {
 public:
    InfixToPostfixConverter();
    std::string operator()(int argc, const char** argv);

 private:
    bool isOperation(char c);
    bool isValidCharacter(char c);
    bool validateInputExpression(const std::string& inputExpression);
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    std::map<char, int> opPriority_;
};

#endif  // MODULES_STACK_INCLUDE_INFIX_TO_POSTFIX_CONVERTER_H_
