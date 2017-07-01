// Copyright 2017 Kazakov Andrew

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/regex_search.h"

const int RegexSearch::kMaxRegexLength;
const int RegexSearch::kMaxStringLength;
const int RegexSearch::errorNotFound;

//
// Constructor
//

// Since the constructor calls SetRegex method, it makes no sense to test
// the constructor instead of SetRegex.
TEST(RegexSearchTest, can_use_default_constructor) {
  // Assert
  ASSERT_NO_THROW(RegexSearch r);
}

TEST(RegexSearchTest, can_set_regex_through_constructor) {
  // Arrange
  std::string s;

  // Act
  s = "some?regex";

  // Assert
  ASSERT_NO_THROW(RegexSearch r(s));
}

//
// Set regexp
//

TEST(RegexSearchTest, cant_set_too_long_regex) {
  // Arrange
  RegexSearch r;
  std::string s;

  // Act
  for (int i = 0; i <= RegexSearch::kMaxRegexLength; ++i)
    s += "a";

  // Assert
  ASSERT_ANY_THROW(r.SetRegex(s));
}

TEST(RegexSearchTest, can_use_empty_regex) {
  // Arrange
  RegexSearch r;
  std::string s;

  // Act
  s = "";

  // Assert
  ASSERT_NO_THROW(r.SetRegex(s));
}

TEST(RegexSearchTest, can_use_regex_consists_only_of_parentheses) {
  // Arrange
  RegexSearch r;
  std::string s;

  // Act
  s = "()";

  // Assert
  ASSERT_NO_THROW(r.SetRegex(s));
}

TEST(RegexSearchTest, can_use_regex_consists_of_a_single_char) {
  // Arrange
  RegexSearch r;
  std::string s;

  // Act
  s = "b";

  // Assert
  ASSERT_NO_THROW(r.SetRegex(s));
}

TEST(RegexSearchTest, can_use_regex_consists_of_several_chars) {
  // Arrange
  RegexSearch r;
  std::string s;

  // Act
  s = "test";

  // Assert
  ASSERT_NO_THROW(r.SetRegex(s));
}

TEST(RegexSearchTest, can_use_parentheses) {
  // Arrange
  RegexSearch r;
  std::string s;

  // Act
  s = "t(es)(t)t";

  // Assert
  ASSERT_NO_THROW(r.SetRegex(s));
}

TEST(RegexSearchTest, can_use_regex_with_some_symbols_with_slash) {
  // Arrange
  RegexSearch r;
  std::string s;

  // Act
  s = "t\\e\\s\\t\\r\\n";

  // Assert
  ASSERT_NO_THROW(r.SetRegex(s));
}

TEST(RegexSearchTest, can_use_question_mark_quantifier) {
  // Arrange
  RegexSearch r;
  std::string s;

  // Act
  s = "tes?st";

  // Assert
  ASSERT_NO_THROW(r.SetRegex(s));
}

TEST(RegexSearchTest, can_use_asterisk_quantifier) {
  // Arrange
  RegexSearch r;
  std::string s;

  // Act
  s = "abc*";

  // Assert
  ASSERT_NO_THROW(r.SetRegex(s));
}

TEST(RegexSearchTest, can_use_plus_quantifier) {
  // Arrange
  RegexSearch r;
  std::string s;

  // Act
  s = "abc+";

  // Assert
  ASSERT_NO_THROW(r.SetRegex(s));
}

TEST(RegexSearchTest, can_use_custom_quantifier) {
  // Arrange
  RegexSearch r;
  std::string s;

  // Act
  s = "ab{3}c";

  // Assert
  ASSERT_NO_THROW(r.SetRegex(s));
}

TEST(RegexSearchTest, can_use_asterisk_and_qustion_mark_quantifiers_together) {
  // Arrange
  RegexSearch r;
  std::string s;

  // Act
  s = "a?bc*";

  // Assert
  ASSERT_NO_THROW(r.SetRegex(s));
}

TEST(RegexSearchTest, can_use_question_mark_quantifier_after_parentheses) {
  // Arrange
  RegexSearch r;
  std::string s;

  // Act
  s = "te(s)?st";

  // Assert
  ASSERT_NO_THROW(r.SetRegex(s));
}

TEST(RegexSearchTest, can_use_asterisk_quantifier_after_parentheses) {
  // Arrange
  RegexSearch r;
  std::string s;

  // Act
  s = "(abc)*";

  // Assert
  ASSERT_NO_THROW(r.SetRegex(s));
}

TEST(RegexSearchTest, can_use_plus_quantifier_after_parentheses) {
  // Arrange
  RegexSearch r;
  std::string s;

  // Act
  s = "(abc)+";

  // Assert
  ASSERT_NO_THROW(r.SetRegex(s));
}

TEST(RegexSearchTest, can_use_custom_quantifier_after_parentheses) {
  // Arrange
  RegexSearch r;
  std::string s;

  // Act
  s = "(abc){2}";

  // Assert
  ASSERT_NO_THROW(r.SetRegex(s));
}

TEST(RegexSearchTest, can_mix_quantifiers_and_parentheses) {
  // Arrange
  RegexSearch r;
  std::string s;

  // Act
  s = "(aa)a?(bc)*";

  // Assert
  ASSERT_NO_THROW(r.SetRegex(s));
}

//
// Get regexp
//

TEST(RegexSearchTest, can_get_empty_regex) {
  // Arrange
  RegexSearch r;
  std::string s;

  // Act
  s = "";

  // Assert
  ASSERT_NO_THROW(r.GetRegex());
}

TEST(RegexSearchTest, get_regex_works_properly) {
  // Arrange
  RegexSearch r;
  std::string s;

  // Act
  s = "(aa)a?(bc)*";
  r.SetRegex(s);

  // Assert
  EXPECT_EQ(r.GetRegex(), s);
}

//
// Set: what is forbidden
//

TEST(RegexSearchTest, cannot_use_question_mark_within_parentheses) {
  // Arrange
  RegexSearch r;
  std::string s;

  // Act
  s = "a(b?)c*";

  // Assert
  ASSERT_ANY_THROW(r.SetRegex(s));
}

TEST(RegexSearchTest, cannot_use_asterisk_within_parentheses) {
  // Arrange
  RegexSearch r;
  std::string s;

  // Act
  s = "a(bc*)";

  // Assert
  ASSERT_ANY_THROW(r.SetRegex(s));
}

TEST(RegexSearchTest, cannot_use_plus_within_parentheses) {
  // Arrange
  RegexSearch r;
  std::string s;

  // Act
  s = "a(bc+)";

  // Assert
  ASSERT_ANY_THROW(r.SetRegex(s));
}

TEST(RegexSearchTest, cannot_use_custom_quanitfier_within_parentheses) {
  // Arrange
  RegexSearch r;
  std::string s;

  // Act
  s = "a(bc{5})";

  // Assert
  ASSERT_ANY_THROW(r.SetRegex(s));
}

TEST(RegexSearchTest, cannot_use_parentheses_within_parentheses) {
  // Arrange
  RegexSearch r;
  std::string s;

  // Act
  s = "a(b(c))d";

  // Assert
  ASSERT_ANY_THROW(r.SetRegex(s));
}

TEST(RegexSearchTest, cannot_let_parenthesis_be_open) {
  // Arrange
  RegexSearch r;
  std::string s;

  // Act
  s = "a(bc";

  // Assert
  ASSERT_ANY_THROW(r.SetRegex(s));
}

TEST(RegexSearchTest, cannot_use_only_close_parenthesis) {
  // Arrange
  RegexSearch r;
  std::string s;

  // Act
  s = "abc)";

  // Assert
  ASSERT_ANY_THROW(r.SetRegex(s));
}

TEST(RegexSearchTest, cannot_let_brace_be_open) {
  // Arrange
  RegexSearch r;
  std::string s;

  // Act
  s = "abc{2";

  // Assert
  ASSERT_ANY_THROW(r.SetRegex(s));
}

TEST(RegexSearchTest, cannot_let_custom_quanitifier_be_zero) {
  // Arrange
  RegexSearch r;
  std::string s;

  // Act
  s = "abc{0}";

  // Assert
  ASSERT_ANY_THROW(r.SetRegex(s));
}

TEST(RegexSearchTest, cannot_let_custom_quanitifier_be_more_than_nine) {
  // Arrange
  RegexSearch r;
  std::string s;

  // Act
  s = "abc{10}";

  // Assert
  ASSERT_ANY_THROW(r.SetRegex(s));
}

TEST(RegexSearchTest, custom_quanitifier_should_contain_something) {
  // Arrange
  RegexSearch r;
  std::string s;

  // Act
  s = "abc{}";

  // Assert
  ASSERT_ANY_THROW(r.SetRegex(s));
}

//
// Copy constructor & operator=
//

TEST(RegexSearchTest, can_use_copy_constructor) {
  // Arrange
  RegexSearch r1;
  std::string s;

  // Act
  s = "a*bc{5}";
  r1.SetRegex(s);

  // Assert
  ASSERT_NO_THROW(RegexSearch r2(r1));
}

TEST(RegexSearchTest, copy_contructor_works_properly) {
  // Arrange
  RegexSearch r1;
  std::string s;

  // Act
  s = "a*bc{5}";
  r1.SetRegex(s);
  RegexSearch r2(r1);

  // Assert
  EXPECT_EQ(r2.GetRegex(), s);
}

TEST(RegexSearchTest, can_use_operator_equal) {
  // Arrange
  RegexSearch r1, r2;
  std::string s;

  // Act
  s = "a*bc{5}";
  r2.SetRegex(s);

  // Assert
  ASSERT_NO_THROW(r1 = r2);
}

TEST(RegexSearchTest, can_assign_regexp_to_itself) {
  // Arrange
  RegexSearch r;
  std::string s;

  // Act
  s = "a*bc{5}";
  r.SetRegex(s);

  // Assert
  ASSERT_NO_THROW(r = r);
}

TEST(RegexSearchTest, operator_equal_works_properly) {
  // Arrange
  RegexSearch r1, r2;
  std::string s;

  // Act
  s = "a*bc{5}";
  r2.SetRegex(s);
  r1 = r2;

  // Assert
  EXPECT_EQ(r1.GetRegex(), s);
}

//
// Search
//

TEST(RegexSearchFindTest, cant_find_in_too_long_string) {
  // Arrange
  RegexSearch r;
  std::string s;

  // Act
  for (int i = 0; i <= RegexSearch::kMaxStringLength; ++i)
    s += "a";

  // Assert
  ASSERT_ANY_THROW(r.Find(s));
}

TEST(RegexSearchFindTest, cant_find_anything_in_empty_string) {
  // Arrange
  RegexSearch r;
  std::string s1, s2;

  // Act
  s1 = "abc?d";
  s2 = "";
  r.SetRegex(s1);

  // Assert
  ASSERT_ANY_THROW(r.Find(s2));
}

TEST(RegexSearchFindTest, empty_regex_matches_the_whole_string) {
  // Arrange
  RegexSearch r;
  std::string s1, s2;
  std::vector<int> rr, rr_target;

  // Act
  s1 = "";
  s2 = "someteststring";
  r.SetRegex(s1);
  rr = r.Find(s2);
  rr_target.push_back(0);
  rr_target.push_back(s2.size());

  // Assert
  EXPECT_EQ(rr, rr_target);
}

TEST(RegexSearchFindTest,
regex_consists_only_of_parentheses_matches_the_whole_string) {
  // Arrange
  RegexSearch r;
  std::string s1, s2;
  std::vector<int> rr, rr_target;

  // Act
  s1 = "()";
  s2 = "someteststring";
  r.SetRegex(s1);
  rr = r.Find(s2);
  rr_target.push_back(0);
  rr_target.push_back(s2.size());

  // Assert
  EXPECT_EQ(rr, rr_target);
}

TEST(RegexSearchFindTest, search_when_regex_consists_of_a_single_char) {
  // Arrange
  RegexSearch r;
  std::string s1, s2;
  std::vector<int> rr, rr_target;

  // Act
  s1 = "b";
  s2 = "beta";
  r.SetRegex(s1);
  rr = r.Find(s2);
  rr_target.push_back(0);
  rr_target.push_back(1);

  // Assert
  EXPECT_EQ(rr, rr_target);
}

TEST(RegexSearchFindTest, search_when_regex_consists_of_several_chars) {
  // Arrange
  RegexSearch r;
  std::string s1, s2;
  std::vector<int> rr, rr_target;

  // Act
  s1 = "str";
  s2 = "test string.";
  r.SetRegex(s1);
  rr = r.Find(s2);
  rr_target.push_back(5);
  rr_target.push_back(3);

  // Assert
  EXPECT_EQ(rr, rr_target);
}

TEST(RegexSearchFindTest, search_when_regex_contains_parentheses) {
  // Arrange
  RegexSearch r;
  std::string s1, s2;
  std::vector<int> rr, rr_target;

  // Act
  s1 = "t(es)(t)t";
  s2 = "testt string.";
  r.SetRegex(s1);
  rr = r.Find(s2);
  rr_target.push_back(0);
  rr_target.push_back(5);

  // Assert
  EXPECT_EQ(rr, rr_target);
}

TEST(RegexSearchFindTest, search_when_regex_contains_some_symbols_with_slash) {
  // Arrange
  RegexSearch r;
  std::string s1, s2;
  std::vector<int> rr, rr_target;

  // Act
  s1 = "t\\e\\s\\t";
  s2 = "123test!";
  r.SetRegex(s1);
  rr = r.Find(s2);
  rr_target.push_back(3);
  rr_target.push_back(4);

  // Assert
  EXPECT_EQ(rr, rr_target);
}

TEST(RegexSearchFindTest, search_when_regex_contains_question_mark_quantifier) {
  // Arrange
  RegexSearch r;
  std::string s1, s2;
  std::vector<int> rr, rr_target;

  // Act
  s1 = "tes?t";
  s2 = "123tet!";
  r.SetRegex(s1);
  rr = r.Find(s2);
  rr_target.push_back(3);
  rr_target.push_back(3);

  // Assert
  EXPECT_EQ(rr, rr_target);
}

TEST(RegexSearchFindTest, search_when_regex_contains_asterisk_quantifier) {
  // Arrange
  RegexSearch r;
  std::string s1, s2;
  std::vector<int> rr, rr_target;

  // Act
  s1 = "abc*d";
  s2 = "12345abde";
  r.SetRegex(s1);
  rr = r.Find(s2);
  rr_target.push_back(5);
  rr_target.push_back(3);

  // Assert
  EXPECT_EQ(rr, rr_target);
}

TEST(RegexSearchFindTest, search_when_regex_contains_plus_quantifier) {
  // Arrange
  RegexSearch r;
  std::string s1, s2;
  std::vector<int> rr, rr_target;

  // Act
  s1 = "abc+d";
  s2 = "123abcccde";
  r.SetRegex(s1);
  rr = r.Find(s2);
  rr_target.push_back(3);
  rr_target.push_back(6);

  // Assert
  EXPECT_EQ(rr, rr_target);
}

TEST(RegexSearchFindTest, search_when_regex_contains_custom_quantifier) {
  // Arrange
  RegexSearch r;
  std::string s1, s2;
  std::vector<int> rr, rr_target;

  // Act
  s1 = "ab{3}c";
  s2 = "123abbbcd";
  r.SetRegex(s1);
  rr = r.Find(s2);
  rr_target.push_back(3);
  rr_target.push_back(5);

  // Assert
  EXPECT_EQ(rr, rr_target);
}

TEST(RegexSearchFindTest, search_when_regex_contains_several_quantifiers) {
  // Arrange
  RegexSearch r;
  std::string s1, s2;
  std::vector<int> rr, rr_target;

  // Act
  s1 = "a?bc*";
  s2 = "123bde";
  r.SetRegex(s1);
  rr = r.Find(s2);
  rr_target.push_back(3);
  rr_target.push_back(1);

  // Assert
  EXPECT_EQ(rr, rr_target);
}

TEST(RegexSearchFindTest,
search_when_regex_contains_question_mark_quantifier_after_parentheses) {
  // Arrange
  RegexSearch r;
  std::string s1, s2;
  std::vector<int> rr, rr_target;

  // Act
  s1 = "te(s)?t";
  s2 = "123tet!";
  r.SetRegex(s1);
  rr = r.Find(s2);
  rr_target.push_back(3);
  rr_target.push_back(3);

  // Assert
  EXPECT_EQ(rr, rr_target);
}

TEST(RegexSearchFindTest,
search_when_regex_contains_asterisk_quantifier_after_parentheses) {
  // Arrange
  RegexSearch r;
  std::string s1, s2;
  std::vector<int> rr, rr_target;

  // Act
  s1 = "(abc)*";
  s2 = "aabcabcabc";
  r.SetRegex(s1);
  rr = r.Find(s2);
  rr_target.push_back(1);
  rr_target.push_back(9);

  // Assert
  EXPECT_EQ(rr, rr_target);
}

TEST(RegexSearchFindTest,
search_when_regex_contains_plus_quantifier_after_parentheses) {
  // Arrange
  RegexSearch r;
  std::string s1, s2;
  std::vector<int> rr, rr_target;

  // Act
  s1 = "(abc)+";
  s2 = "123abcabcabde";
  r.SetRegex(s1);
  rr = r.Find(s2);
  rr_target.push_back(3);
  rr_target.push_back(6);

  // Assert
  EXPECT_EQ(rr, rr_target);
}

TEST(RegexSearchFindTest,
search_when_regex_contains_custom_quantifier_after_parentheses) {
  // Arrange
  RegexSearch r;
  std::string s1, s2;
  std::vector<int> rr, rr_target;

  // Act
  s1 = "(abc){3}";
  s2 = "test abcabcabcab";
  r.SetRegex(s1);
  rr = r.Find(s2);
  rr_target.push_back(5);
  rr_target.push_back(9);

  // Assert
  EXPECT_EQ(rr, rr_target);
}

TEST(RegexSearchFindTest, it_can_find_all_matches) {
  // Arrange
  RegexSearch r;
  std::string s1, s2;
  std::vector<int> rr, rr_target;

  // Act
  s1 = "1?2?3?";
  s2 = "numbers: 0,1,2,3,4,5.";
  r.SetRegex(s1);
  rr = r.Find(s2);
  rr_target.push_back(11);
  rr_target.push_back(1);
  rr_target.push_back(13);
  rr_target.push_back(1);
  rr_target.push_back(15);
  rr_target.push_back(1);

  // Assert
  EXPECT_EQ(rr, rr_target);
}

TEST(RegexSearchFindTest, no_matches_when_it_is_really_no_matches) {
  // Arrange
  RegexSearch r;
  std::string s1, s2;
  std::vector<int> rr;

  // Act
  s1 = "nothattext!";
  s2 = "another text";
  r.SetRegex(s1);
  rr = r.Find(s2);

  // Assert
  EXPECT_EQ(rr[0], RegexSearch::errorNotFound);
}
