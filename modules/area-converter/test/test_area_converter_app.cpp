// Copyright 2017 Lapin Artem

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/area_converter_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class AreaConverterAppTest : public ::testing::Test {
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
     Application app_;
     string output_;
};

TEST_F(AreaConverterAppTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};
        Act(args);
        Assert("This is a square converter application*");
}

TEST_F(AreaConverterAppTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = { "1", "Meter" };
    Act(args);
    Assert("ERROR: Should be 3 arguments.*");
}

TEST_F(AreaConverterAppTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = { "one", "Meter", "Yard"};
    Act(args);
    Assert("Wrong number format!*");
}

TEST_F(AreaConverterAppTest, Can_Detect_Wrong_Area_Format1) {
    vector<string> args = { "10", "Meter", "not meter"};
    Act(args);
    Assert("Wrong area format!");
}

TEST_F(AreaConverterAppTest, Can_Detect_Wrong_Area_Format2) {
    vector<string> args = { "10", "not meter", "Meter" };
    Act(args);
    Assert("Wrong area format!");
}

TEST_F(AreaConverterAppTest, Can_Convert_With_Equal_Area_Types) {
    vector<string> args = { "10", "Meter", "Meter"};
    Act(args);
    Assert("Converted area size:10");
}

TEST_F(AreaConverterAppTest, Can_Convert_With_Not_Equal_Area_Types) {
    vector<string> args = { "1", "Meter", "Centimeter"};
    Act(args);
    Assert("Converted area size:10000");
}

TEST_F(AreaConverterAppTest, Can_Detect_Negative_Area) {
    vector<string> args = { "-10", "Meter", "Yard"};
    Act(args);
    Assert("It is impossible to work with negative area");
}

TEST_F(AreaConverterAppTest, Inch_To_Decimeter) {
    vector<string> args = { "0", "Inch", "Decimeter" };
    Act(args);
    Assert("Converted area size:0");
}

TEST_F(AreaConverterAppTest, Acr_To_Hectare) {
    vector<string> args = { "0", "Acr", "Hectare" };
    Act(args);
    Assert("Converted area size:0");
}


