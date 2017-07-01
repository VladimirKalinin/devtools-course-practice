// Copyright 2017 Karev Boris

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>
#include <iterator>

#include "include/ConverterCurrencyApp.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class ConverterCurrencyAppTest : public ::testing::Test {
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
    ConverterCurrencyApp app_;
    string output_;
};

TEST_F(ConverterCurrencyAppTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a converter currency application\\..*");
}

TEST_F(ConverterCurrencyAppTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"1", "RUR"};

    Act(args);

    Assert("ERROR: Should be 5 arguments\\..*");
}

TEST_F(ConverterCurrencyAppTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = {"one", "BYN", "CNY", "0", "0"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(ConverterCurrencyAppTest, Can_Detect_Wrong_Currency_Format) {
    vector<string> args = {"10", "CZK", "currency", "0", "0"};

    Act(args);

    Assert("Wrong currency format!");
}

TEST_F(ConverterCurrencyAppTest, Can_Convert_Money_With_Default_Coefficient) {
    vector<string> args = {"10", "RUR", "RUR", "0", "0"};

    Act(args);

    Assert("Result of convertation = 10");
}

TEST_F(ConverterCurrencyAppTest, Can_Convert_Money_With_New_Coefficient) {
    vector<string> args = { "10", "EUR", "RUR", "10", "0" };

    Act(args);

    Assert("Result of convertation = 100");
}

TEST_F(ConverterCurrencyAppTest, Can_Detect_Negative_Coefficient1) {
    vector<string> args = { "10", "GBP", "KZT", "-1", "0" };

    Act(args);

    Assert("Convert coefficient has to be more than 0");
}

TEST_F(ConverterCurrencyAppTest, Can_Detect_Negative_Coefficient2) {
    vector<string> args = { "10", "USD", "UAH", "0", "-1" };

    Act(args);

    Assert("Convert coefficient has to be more than 0");
}

TEST_F(ConverterCurrencyAppTest, Can_Detect_Negative_Money_Size) {
    vector<string> args = { "-10", "JPY", "KRW", "0", "0" };

    Act(args);

    Assert("Money size can't be negative");
}

TEST_F(ConverterCurrencyAppTest, Can_Convert_With_Zero_Money_Size) {
    vector<string> args = { "0", "EUR", "RUR", "0", "0" };

    Act(args);

    Assert("Result of convertation = 0");
}
