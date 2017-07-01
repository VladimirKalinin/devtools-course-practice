// Copyright 2017 Kulygina Julia

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/temperature-converter-app.h"

using std::vector;
using std::string;
using ::testing::internal::RE;

class TemperatureConverterAppTest : public ::testing::Test {
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

 public:
     TemperatureConverterApp app_;
     string output_;
};

TEST_F(TemperatureConverterAppTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a temperature converter app*");
}

TEST_F(TemperatureConverterAppTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = { "C", "2.5" };

    Act(args);

    Assert("ERROR: Should be 3 arguments*");
}

TEST_F(TemperatureConverterAppTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = { "C", "1,0", "F"};

    Act(args);

    Assert("Wrong format!.*");
}

TEST_F(TemperatureConverterAppTest, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = { "Celsius", "1.0", "F" };

    Act(args);

    Assert("Wrong format!.*");
}

TEST_F(TemperatureConverterAppTest, Can_Convert_Celsius_To_Fahrenheit) {
    vector<string> args = { "C", "26.0", "F" };

    Act(args);

    Assert("Result = 78.8");
}

TEST_F(TemperatureConverterAppTest,
    Cant_Convert_Celsius_To_Newton_Temeprature_Less_Than_Absolute_Zero) {
    vector<string> args = { "C", "-274.0", "N" };

    Act(args);

    Assert("Temperature can't be less than absolute zero");
}

TEST_F(TemperatureConverterAppTest,
    Cant_Convert_Celsius_To_Fahrenheit_Temeprature_Less_Than_Absolute_Zero) {
    vector<string> args = { "C", "-274.0", "F" };

    Act(args);

    Assert("Temperature can't be less than absolute zero");
}

TEST_F(TemperatureConverterAppTest,
    Cant_Convert_Celsius_To_Kelvin_Temeprature_Less_Than_Absolute_Zero) {
    vector<string> args = { "C", "-274.0", "K" };

    Act(args);

    Assert("Temperature can't be less than absolute zero");
}

TEST_F(TemperatureConverterAppTest, Can_Convert_Celsius_To_Newton) {
    vector<string> args = { "C", "26.0", "N" };

    Act(args);

    Assert("Result = 8.58");
}

TEST_F(TemperatureConverterAppTest, Can_Convert_Celsius_To_Kelvin) {
    vector<string> args = { "C", "26.0", "K" };

    Act(args);

    Assert("Result = 299.15");
}

TEST_F(TemperatureConverterAppTest, Can_Convert_Kelvin_To_Newton) {
    vector<string> args = { "K", "26.0", "N" };

    Act(args);

    Assert("Result = -81.5595");
}

TEST_F(TemperatureConverterAppTest, Can_Convert_Kelvin_To_Celsius) {
    vector<string> args = { "K", "26.0", "C" };

    Act(args);

    Assert("Result = -247.15");
}

TEST_F(TemperatureConverterAppTest, Can_Convert_Kelvin_To_Fahrenheit) {
    vector<string> args = { "K", "26.0", "F" };

    Act(args);

    Assert("Result = -412.87");
}

TEST_F(TemperatureConverterAppTest, Can_Convert_Newton_To_Kelvin) {
    vector<string> args = { "N", "26.0", "K" };

    Act(args);

    Assert("Result = 351.938");
}

TEST_F(TemperatureConverterAppTest, Can_Convert_Newton_To_Celsius) {
    vector<string> args = { "N", "26.0", "C" };

    Act(args);

    Assert("Result = 78.7879");
}

TEST_F(TemperatureConverterAppTest, Can_Convert_Newton_To_Fahrenheit) {
    vector<string> args = { "N", "26.0", "F" };

    Act(args);

    Assert("Result = 173.818");
}

TEST_F(TemperatureConverterAppTest, Can_Convert_Fahrenheit_To_Kelvin) {
    vector<string> args = { "F", "26.0", "K" };

    Act(args);

    Assert("Result = 269.817");
}

TEST_F(TemperatureConverterAppTest, Can_Convert_Fahrenheit_To_Newton) {
    vector<string> args = { "F", "26.0", "N" };

    Act(args);

    Assert("Result = -1.1");
}

TEST_F(TemperatureConverterAppTest, Can_Convert_Fahrenheit_To_Celsius) {
    vector<string> args = { "F", "26.0", "C" };

    Act(args);

    Assert("Result = -3.33333");
}

TEST_F(TemperatureConverterAppTest,
    Cant_Convert_Fahrenheit_To_Newton_Temeprature_Less_Than_Absolute_Zero) {
    vector<string> args = { "F", "-460.0", "N" };

    Act(args);

    Assert("Temperature can't be less than absolute zero");
}

TEST_F(TemperatureConverterAppTest,
    Cant_Convert_Fahrenheit_To_Celsius_Temeprature_Less_Than_Absolute_Zero) {
    vector<string> args = { "F", "-460.0", "C" };

    Act(args);

    Assert("Temperature can't be less than absolute zero");
}

TEST_F(TemperatureConverterAppTest,
    Cant_Convert_Fahrenheit_To_Kelvin_Temeprature_Less_Than_Absolute_Zero) {
    vector<string> args = { "F", "-460.0", "K" };

    Act(args);

    Assert("Temperature can't be less than absolute zero");
}

TEST_F(TemperatureConverterAppTest,
    Cant_Convert_Newton_To_Celsius_Temeprature_Less_Than_Absolute_Zero) {
    vector<string> args = { "N", "-91.0", "C" };

    Act(args);

    Assert("Temperature can't be less than absolute zero");
}

TEST_F(TemperatureConverterAppTest,
    Cant_Convert_Newton_To_Fahrenheit_Temeprature_Less_Than_Absolute_Zero) {
    vector<string> args = { "N", "-91.0", "F" };

    Act(args);

    Assert("Temperature can't be less than absolute zero");
}

TEST_F(TemperatureConverterAppTest,
    Cant_Convert_Newton_To_Kelvin_Temeprature_Less_Than_Absolute_Zero) {
    vector<string> args = { "N", "-91.0", "K" };

    Act(args);

    Assert("Temperature can't be less than absolute zero");
}

TEST_F(TemperatureConverterAppTest,
    Cant_Convert_Kelvin_To_Newton_Temeprature_Less_Than_Absolute_Zero) {
    vector<string> args = { "K", "-1.0", "N" };

    Act(args);

    Assert("Temperature can't be less than absolute zero");
}

TEST_F(TemperatureConverterAppTest,
    Cant_Convert_Kelvin_To_Fahrenheit_Temeprature_Less_Than_Absolute_Zero) {
    vector<string> args = { "K", "-1.0", "F" };

    Act(args);

    Assert("Temperature can't be less than absolute zero");
}

TEST_F(TemperatureConverterAppTest,
    Cant_Convert_Kelvin_To_Celsius_Temeprature_Less_Than_Absolute_Zero) {
    vector<string> args = { "K", "-1.0", "C" };

    Act(args);

    Assert("Temperature can't be less than absolute zero");
}
