// Copyright 2017 Simonyan Vaginak

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/weight_converter_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;


class WeightConverterAppTest : public ::testing::Test {
 protected:
    void Act(vector<string> args_) {
        vector<const char *> options;

        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char **argv = &options.front();
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

TEST_F(WeightConverterAppTest, Do_Print_Help_Without_Arguments) {
    std::vector<std::string> args = {};

    Act(args);

    Assert("This is a weight converter application\\..*");
}

TEST_F(WeightConverterAppTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = {"0.45", "KG"};

    Act(args);

    Assert("ERROR: Should be 3 arguments\\..*");
}

TEST_F(WeightConverterAppTest, Is_Checking_Weight_Argument) {
    vector<string> args = { "-0.45", "KG", "G" };

    Act(args);

    Assert("Wrong number format!");
}

TEST_F(WeightConverterAppTest, Is_Checking_Weight_Type_Argument) {
    vector<string> args = { "0.45", "25", "G" };

    Act(args);

    Assert("Wrong weight's type format!");
}

TEST_F(WeightConverterAppTest, Can_Convert_From_MG_To_G) {
    vector<string> args = { "10", "MG", "G" };

    Act(args);

    Assert("Weight = 0.01");
}
