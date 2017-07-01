// Copyright 2017 Kiparenko Ilya

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/interpolation_search_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class InterpolationSearchAppTest : public ::testing::Test {
 protected:
  void Act(vector<string> args_) {
    vector<const char*> options;

    options.push_back("appname");
    for (size_t i = 0; i < args_.size(); ++i) {
      options.push_back(args_[i].c_str());
    }

    const char** argv = &options.front();
    int argc = static_cast<int>(args_.size()) + 1;

    output_ = app_(argc, argv);
  }

  void Assert(std::string expected) {
    EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
  }

 private:
  InterpolationSearchApp app_;
  string output_;
};

TEST_F(InterpolationSearchAppTest, Do_Print_Help_Without_Arguments) {
  vector<string> args = {};

  Act(args);

  Assert("This is a interpolation search app.*");
}

TEST_F(InterpolationSearchAppTest, Is_Checking_Number_Of_Arguments) {
  vector<string> args = {"1"};

  Act(args);

  Assert("ERROR: Should be at least 2 arguments.*");
}

TEST_F(InterpolationSearchAppTest, Can_Detect_Wrong_Number_Format) {
  vector<string> args = {"1a", "2"};

  Act(args);

  Assert("ERROR: Wrong number format.*");
}

TEST_F(InterpolationSearchAppTest, Can_Detect_Unsorted_Array) {
  vector<string> args = {"3", "2", "1", "1"};

  Act(args);

  Assert("ERROR: Array is unsorted.*");
}

TEST_F(InterpolationSearchAppTest, Can_Return_Missing) {
  vector<string> args = {"1", "2", "3", "4"};

  Act(args);

  Assert("Result = -1.*");
}

TEST_F(InterpolationSearchAppTest, Can_Return_Mid) {
  vector<string> args = {"1", "2", "3", "2"};

  Act(args);

  Assert("Result = 1.*");
}
