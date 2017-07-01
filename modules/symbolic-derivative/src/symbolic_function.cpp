// Copyright 2017 Kiparenko Ilya

#include "include/symbolic_function.h"
#include <cctype>
#include <iostream>
#include <stack>
#include <string>
#include <utility>

using std::string;
using std::cout;
using std::endl;
using std::stod;
using std::to_string;

using std::stack;

string SymbolicFunction::PrintTree(Node* root) {
  if (root != 0) {
    switch (root->type) {
      case NUMBER:
        return std::to_string(root->real_value);
        break;
      case SYMBOL:
        return symbols_[root->index];
        break;
      case FUNCTION:
        if (nargs.at(root->op_type) == 2)
          return "(" +
                  PrintTree(root->left) +
                  func_names.at(root->op_type) +
                  PrintTree(root->right) +
                 ")";
        else
          return func_names.at(root->op_type) +
                "(" + PrintTree(root->right) + ")";
        break;
    }
  } else {
    return "0";
  }
}

SymbolicFunction::SymbolicFunction(string s) {
  root_ = Parse(s);
  root_ = ToPostfixForm(root_);
  root_ = PostfixToAst(root_);
}

SymbolicFunction::~SymbolicFunction() {
  DelTree(root_);
}

SymbolicFunction::SymbolicFunction() {
  root_ = 0;
}

SymbolicFunction& SymbolicFunction::operator=(const SymbolicFunction& sym) {
  DelTree(root_);
  symbols_ = sym.symbols_;
  root_ = CopyTree(sym.root_);
  return (*this);
}

string SymbolicFunction::ToString() {
  return PrintTree(root_);
}

SymbolicFunction& SymbolicFunction::Derivative(string variable) {
  SymbolicFunction* sym = new SymbolicFunction;
  sym->symbols_ = symbols_;
  sym->root_ = Derivative(root_, variable);
  return *sym;
}

Node* SymbolicFunction::Parse(string s) {
  Node* out = CrEmptyNode();
  Node* out_t = out;

  char buf[20];
  int buf_pos = 0;
  int token_type = -1;
  int token_state = -1;
  unsigned int i = 0;
  string delimiters("+-*/^()");

  while (i < s.size() || (i == s.size() && token_state == 0)) {
    char ch = s[i];
    if (isspace(ch)) {
      i++;
    } else {
      if (token_state == -1) {
        if (isalpha(ch)) {
          token_type = 2;
        } else {
          if (isdigit(ch) || ch == '.') {
            token_type = 1;
          } else {
            size_t index = delimiters.find(ch);
            if (index != string::npos) {
              out_t->left = CrOpNode(functions.at(string(1, ch)));
              out_t = out_t->left;
              token_state = -1;
              i++;
              continue;
            } else {
              throw string("Unknown token");
            }
          }
        }
        buf[buf_pos++] = ch;
        token_state = 0;
        i++;
      } else {
        if (token_type == 1) {
          while (i < s.size() && isdigit(ch) || ch == '.') {
            buf[buf_pos++] = ch;
            i++;
            ch = s[i];
          }
          buf[buf_pos] = 0;
          out_t->left = CrNumberNode(stod(string(buf)));
          out_t = out_t->left;
          buf_pos = 0;
          token_state = -1;
        } else {
          while (i < s.size() && isalnum(ch)) {
            buf[buf_pos++] = ch;
            i++;
            ch = s[i];
          }
          buf[buf_pos] = 0;
          Node* new_node;
          string s_buf = string(buf);
          try {
            new_node = CrOpNode(functions.at(s_buf));
          } catch (std::out_of_range& e) {
            new_node = CrSymbolNode(symbols_.size());
            symbols_.push_back(s_buf);
          }
          out_t->left = new_node;
          out_t = out_t->left;
          buf_pos = 0;
          token_state = -1;
        }
      }
    }
  }

  out_t = out->left;
  delete out;
  return out_t;
}

Node* SymbolicFunction::ToPostfixForm(Node* root) {
  Node* out = CrEmptyNode();
  Node* out_t = out;
  stack<Node*> st;
  Node* t = root;
  while (t != 0) {
    if (t->type == FUNCTION) {
      switch (t->op_type) {
        case L_BRACE:
          st.push(t);
          break;
        case R_BRACE: {
          Node* top = st.top();
          st.pop();
          while (!st.empty() && top->op_type != L_BRACE) {
            out_t->left = top;
            out_t = out_t->left;

            top = st.top();
            st.pop();
          }
          if (top->op_type != L_BRACE)
            throw string("wrong braces");
          break;
        }
        default: {
          int prec = precendence.at(t->op_type);
          while (!st.empty() && precendence.at(st.top()->op_type) >= prec) {
            out_t->left = st.top();
            st.pop();
            out_t = out_t->left;
          }
          st.push(t);
          break;
        }
      }
    } else {  // Symbol or Number
      out_t->left = t;
      out_t = out_t->left;
    }

    t = t->left;
  }

  while (!st.empty()) {
    out_t->left = st.top();
    st.pop();
    out_t = out_t->left;
  }
  out_t->left = 0;
  out_t = out->left;
  delete out;
  return out_t;
}

Node* MyPop(stack<Node*>* st) {
  if (st->empty()) {
    throw std::out_of_range("stack underlow");
  } else {
    Node* t = st->top(); st->pop();
    return t;
  }
}

Node* SymbolicFunction::PostfixToAst(Node* root) {
  stack<Node*> st;
  Node* out;
  Node* t = root;
  while (t != 0) {
    if (t->type == FUNCTION) {
      Node* new_token = t;
      t = t->left;
      new_token->right = MyPop(&st);
      if (nargs.at(new_token->op_type) > 1)
        new_token->left = MyPop(&st);
      else
        new_token->left = 0;
      st.push(new_token);

    } else {
      Node* new_token = t;
      t = t->left;
      new_token->left = 0;
      st.push(new_token);
    }
  }
  out = MyPop(&st);
  if (!st.empty())
    throw string("syntax error");
  return out;
}

void SymbolicFunction::DelTree(Node* root) {
  if (root != 0) {
    stack<Node*> st;
    st.push(root);
    while (!st.empty()) {
      root = st.top(); st.pop();
      if (root->left != 0)
        st.push(root->left);
      if (root->right != 0)
        st.push(root->right);
      delete root;
    }
  }
}

Node* SymbolicFunction::CopyTree(Node* root) {
  if (root != 0) {
    Node* out = new Node();
    *out = *root;
    out->left  = CopyTree(root->left);
    out->right = CopyTree(root->right);
    return out;
  } else {
    return 0;
  }
}


Node* SymbolicFunction::Derivative(Node* root, string variable) {
  switch (root->type) {
    case NUMBER:
      return 0;
      break;
    case SYMBOL:
      if (symbols_[root->index] == variable)
        return CrNumberNode(1.0);
      else
        return 0;
      break;
    case FUNCTION: {
      Node* r_der = Derivative(root->right, variable);
      Node* l_der = (root->left == 0) ? 0 : Derivative(root->left, variable);
      int flag = (l_der != 0)*2 + (r_der != 0);
      switch (root->op_type) {
        case SUB:
        case ADD: {  // a +- b
          switch (flag) {
            case 0:  // a' = b' = 0
              return 0;
              break;
            case 1:  // a' = 0
              if (root->op_type == SUB)
                return CrOpNode(MUL,
                         CrNumberNode(-1.0),
                         r_der);                // -b'
              else
                return r_der;
              break;
            case 2:  // b' = 0
              return l_der;
              break;
            case 3:  // a' != 0 && b' != 0
              return CrOpNode(root->op_type, l_der, r_der);
              break;
          }
        }
        case DIV:
        case POW:
        case MUL: {
          if (flag > 0) {
            Node* temp_l = CopyTree(root->left);
            Node* temp_r = CopyTree(root->right);
            switch (root->op_type) {
              case DIV:  // a/b
                switch (flag) {
                  case 3:  // a' != 0 && b' != 0
                    return
                      CrOpNode(DIV,
                        CrOpNode(POW,
                          temp_r,
                          CrNumberNode(2.0))  // b^2
                        ,  // ),
                        CrOpNode(SUB,
                          CrOpNode(MUL, l_der, CopyTree(temp_r)),
                          CrOpNode(MUL, temp_l, r_der)));    // a'*b - a*b'
                        // )
                      // );
                    break;
                  case 2:  // b' = 0
                    DelTree(temp_l);
                    return CrOpNode(DIV,
                             l_der,
                             temp_r);  // a'/b
                           // );
                    break;
                  case 1:  // a' = 0
                    return
                      CrOpNode(DIV,
                        CrOpNode(POW,
                          temp_r,
                          CrNumberNode(2.0))     // b^2
                        ,  // )
                        CrOpNode(MUL,
                          CrNumberNode(-1.0),
                          CrOpNode(MUL, temp_l, r_der)));    // - a*b'
                        // )
                      // );
                    break;
                }
              case MUL:  // a*b
                switch (flag) {
                  case 3:  // a' != 0 && b' != 0
                    return
                      CrOpNode(ADD,
                        CrOpNode(MUL, l_der, temp_r),  // a'* b
                        CrOpNode(MUL, temp_l, r_der));  // a * b'
                      // );
                  case 2:  // b' = 0
                    DelTree(temp_l);
                    return
                      CrOpNode(MUL, l_der, temp_r);   // a'* b
                  case 1:  // a' = 0
                    DelTree(temp_r);
                    return
                      CrOpNode(MUL, temp_l, r_der);    // a * b'
                }
              case POW:  // a^b = exp(b*log(a))
                switch (flag) {
                  case 3:  // a' != 0 && b' != 0
                    return
                      CrOpNode(MUL,
                        CopyTree(root),
                        CrOpNode(ADD,
                          CrOpNode(MUL,
                            r_der,
                            CrOpNode(LOG, 0, CopyTree(temp_l)))  // b' * log(a)
                          ,  // ),
                          CrOpNode(MUL,
                            temp_r,
                            CrOpNode(DIV, l_der, temp_l))));  // b * a'/a
                          // )
                        // )
                      // );  // a^b * (b' * log(a) + b * a' / a)
                  case 2:  // b' = 0
                    return
                      CrOpNode(MUL,
                        temp_r,
                        CrOpNode(MUL,
                          CrOpNode(POW,
                            temp_l,
                            CrOpNode(SUB,
                              CopyTree(temp_r),
                              CrNumberNode(1.0)))    // b - 1
                            //)
                          ,  // ),
                          l_der));
                        // )
                      // );  // b * a^(b-1) * a'
                  case 1:  // a' = 0
                    DelTree(temp_r);
                    return
                      CrOpNode(MUL,
                        CopyTree(root),
                        CrOpNode(MUL,
                          r_der,
                          CrOpNode(LOG, 0, temp_l)));  // b' * log(a)
                        // )
                      // );  // a^b * b' * log(a)
                }
            }
          } else {
            return 0;
          }
        }
        case COS:
        case SIN:
        case LOG:  // f(a)
          if (flag) {
            Node* temp_r = CopyTree(root->right);
            Node* new_root = CrOpNode(MUL, 0, r_der);  // ??? * a'
            switch (root->op_type) {
              case COS:  // cos(a)
                new_root->left =
                  CrOpNode(MUL,
                    CrNumberNode(-1.0),
                    CrOpNode(SIN, 0, temp_r));  // -sin(a)
                  // );
                break;
              case SIN:  // sin(a)
                new_root->left =
                  CrOpNode(COS, 0, temp_r);  // cos(a)
                break;
              case LOG:  // log(a)
                new_root->left =
                  CrOpNode(DIV,
                    CrNumberNode(1.0),
                    temp_r);                 // 1/a
                  // );
                break;
            }
            // f'(a) * a';
            return new_root;
          } else {
            return 0;
          }
        }
    }
  }
}
