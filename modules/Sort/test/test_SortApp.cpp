// Copyright 2017 Kalinin Vladimir

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>
#include <fstream>
#include <iostream>


#include "include/Sort_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class SortAppTest : public ::testing::Test{
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
     SortApp app_;
     string output_;
};

TEST_F(SortAppTest, Do_Print_Help_Without_Arguments) {
    std::vector<string> args = {};
    Act(args);
    Assert("This is a sort application\\..*");
}

TEST_F(SortAppTest, Is_Checking_Number_Of_Arguments) {
    std::vector<string> args = {"2", "1", "1", "3", "5"};
    Act(args);
    Assert("Error: Arguments count should be equal array_length plus 4\\..*");
}

TEST_F(SortAppTest, Is_Checking_Choosen_Number_Of_Function) {
    std::vector<string> args = {"2", "5", "1", "2"};
    Act(args);
    Assert("Error: Sort number should be between 1 and 4\\..*");
}

TEST_F(SortAppTest, Is_Checking_Choosen_Number_Of_Mode) {
  std::vector<string> args = { "3", "2", "3", "1", "1", "3", "2" };
  Act(args);
  Assert("Error: Mode number should be between 1 or 2\\..*");
}

TEST_F(SortAppTest, Is_Checking_Choosen_Number_Of_Order) {
  std::vector<string> args = { "3", "2", "1", "5", "1", "3", "2" };
  Act(args);
  Assert("Error: Order number should be between 1 or 2\\..*");
}

TEST_F(SortAppTest, Is_Checking_File_Open) {
  std::vector<string> args = { "2", "1", "2", "1", "efwef" };
  Act(args);
  Assert("Error: Incorrect file path\\..*");
}

TEST_F(SortAppTest, Can_Sort_Array_From_File) {
  std :: ofstream ofs("input.txt");
  ofs << "23 38 2";
  ofs.close();
  std::vector<string> args = { "3", "1", "2", "1", "input.txt" };
  Act(args);
  std::remove("input.txt");
  Assert("Sorted array: 2 23 38");
}

TEST_F(SortAppTest, Can_Sort_In_The_Descending_Order) {
  std::vector<string> args = { "3", "1", "1", "2", "1", "3", "2" };
  Act(args);
  Assert("Sorted array: 3 2 1");
}

TEST_F(SortAppTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"2", "1", "blblbl", "1"};
    Act(args);
    Assert("Wrong number format!.*");
}

TEST_F(SortAppTest, Can_Detect_Wrong_Number_Function) {
    vector<string> args = { "2", "word", "1", "1" };
    Act(args);
    Assert("Wrong number format!.*");
}

TEST_F(SortAppTest, Can_Detect_Wrong_Array_Size) {
    vector<string> args = { "-1", "2", "1", "1" };
    Act(args);
    Assert("Error: Array can't have less then 1 elem\\..*");
}

TEST_F(SortAppTest, Can_Detect_Wrong_Format_Array_Size) {
    vector<string> args = { "asda", "2", "1", "1" };
    Act(args);
    Assert("Wrong number format!.*");
}

TEST_F(SortAppTest, Quick_Sort_Correct) {
    vector<string> args = { "3", "1", "1", "1", "1", "3", "2" };
    Act(args);
    Assert("Sorted array: 1 2 3");
}

TEST_F(SortAppTest, Paste_Sort_Correct) {
    vector<string> args = { "3", "2", "1", "1", "1", "3", "2" };

    Act(args);

    Assert("Sorted array: 1 2 3");
}

TEST_F(SortAppTest, Choice_Sort_Correct) {
    vector<string> args = { "3", "3", "1", "1", "1", "3", "2" };

    Act(args);

    Assert("Sorted array: 1 2 3");
}

TEST_F(SortAppTest, Merge_Sort_Correct) {
    vector<string> args = { "3", "4", "1", "1", "1", "3", "2" };

    Act(args);

    Assert("Sorted array: 1 2 3");
}
