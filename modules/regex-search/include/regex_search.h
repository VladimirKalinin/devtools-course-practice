// Copyright 2017 Kazakov Andrew

#ifndef MODULES_REGEX_SEARCH_INCLUDE_REGEX_SEARCH_H_
#define MODULES_REGEX_SEARCH_INCLUDE_REGEX_SEARCH_H_

#include <string>
#include <vector>

// Basic regular expressions search.
// - Supported quantifiers: *, ?, +, {n} (1<=n<=9)
// (only after some text somewhere before)
// - Parentheses and quanitifiers within another parenthesis are not allowed,
// however there can be nothing within parentheses
// - \n, \r support, but \<char> equals just <char>
// - There can be empty regular expressions
// - Search is implemented according to DFA principle
class RegexSearch {
 public:
  static const int kMaxStringLength = 5000;
  static const int kMaxRegexLength = 150;
  static const int errorNotFound = -1;
  static const int errorTooLongRegex = -2;
  static const int errorRegExpIncorrect = -3;
  static const int errorTooLongString = -4;
  static const int errorStringIsEmpty = -5;

  explicit RegexSearch(const std::string = "");
  RegexSearch(const RegexSearch&);
  ~RegexSearch(void) {}

  void SetRegex(const std::string&);
  std::string GetRegex(void) const;

  // On success, returns vector(pos1,match_length1,pos2,match_length2,...)
  // No matches, returns vector(RegexSearch::errorNotFound,<some random number>)
  std::vector<int> Find(const std::string&);

 private:
  // Token type. TOK_Q_CUSTOM is {n} quantifier
  enum TokenType {
    TOK_WORD,
    TOK_Q_ASTERISK,
    TOK_Q_QUESTION,
    TOK_Q_PLUS,
    TOK_Q_CUSTOM,
    TOK_PAR_OPEN,
    TOK_PAR_CLOSE,
    _ABSENT
  };

  struct Lexeme {
    std::string str;
    int min, max;
  };

  static const int kMaxTokenSize = 3;
  static const int kInfinityRepeats = -1;

  std::vector<Lexeme> regex_;
  std::string regex_str_;

  std::vector<int> FindFirst(const std::string&, const size_t pos = 0);

  static void MakeStringLonger(std::string* out_str, const std::string& str);
  static void Parse(const std::string&, std::vector<Lexeme>&);
};

#endif  // MODULES_REGEX_SEARCH_INCLUDE_REGEX_SEARCH_H_
