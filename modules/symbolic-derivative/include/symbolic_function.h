// Copyright 2017 Kiparenko Ilya

#ifndef MODULES_SYMBOLIC_DERIVATIVE_INCLUDE_SYMBOLIC_FUNCTION_H_
#define MODULES_SYMBOLIC_DERIVATIVE_INCLUDE_SYMBOLIC_FUNCTION_H_

#include <string>
#include <vector>
#include <unordered_map>

#include "include/types_and_consts.h"

using std::vector;
using std::string;

class SymbolicFunction {
 public:
  explicit SymbolicFunction(string s);
  string ToString();
  SymbolicFunction();
  SymbolicFunction& Derivative(string variable);
  SymbolicFunction& operator=(const SymbolicFunction& sym);
  ~SymbolicFunction();

 private:
  Node* root_;
  vector<string> symbols_;

  Node*  Parse(string s);
  Node*  ToPostfixForm(Node* root);
  Node*  PostfixToAst(Node* root);
  Node*  Derivative(Node* root, string);
  void   DelTree(Node* root);
  Node*  CopyTree(Node* root);
  string PrintTree(Node* root);
};

#endif  // MODULES_SYMBOLIC_DERIVATIVE_INCLUDE_SYMBOLIC_FUNCTION_H_
