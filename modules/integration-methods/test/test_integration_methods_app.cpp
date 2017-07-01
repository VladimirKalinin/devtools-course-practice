// Copyright 2017 Komarov Nikolay

#include <gtest/gtest.h>

#include <string>
#include <vector>
#include <algorithm>
#include <functional>

#include "include/integration_methods_app.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class ApplicationTest : public ::testing::Test {
 protected:
    void Act(const vector<string> &args_) {
        vector<const char*> options;

        options.push_back("appname");
        for (size_t i = 0; i < args_.size(); ++i) {
            options.push_back(args_[i].c_str());
        }

        const char** argv = &options.front();
        int argc = static_cast<int>(args_.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(const std::string &expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 private:
    Application app_;
    string output_;
};

TEST_F(ApplicationTest, Can_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a Integration Methods application\\..*");
}

TEST_F(ApplicationTest, Can_Check_Number_Of_Arguments) {
    vector<string> args = { "x+5", "0", "1" };

    Act(args);

    Assert("ERROR: Should be 5 arguments\\..*");
}

TEST_F(ApplicationTest, Can_Detect_Wrong_Number_Format_For_Integer) {
    vector<string> args = { "x+5", "0", "1", "r", "6kk64h" };

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(ApplicationTest, Can_Detect_Wrong_Number_Format_For_Double) {
    vector<string> args = { "x+5", "i9k9034", "1", "r", "200" };

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(ApplicationTest, Can_Detect_Wrong_Method_Name) {
    vector<string> args = { "x+5", "0", "1", "kokfr", "200" };

    Act(args);

    Assert("Wrong method name!.*");
}

TEST_F(ApplicationTest, Can_Detect_Wrong_Integrand) {
    vector<string> args = { "jgf56jgi9o(", "0", "1", "r", "200" };

    Act(args);

    Assert("Invalid input.*");
}

TEST_F(ApplicationTest, Can_Integrate_Integrand_By_Rectangle_Method) {
    vector<string> args = { "x*x*x*x", "0", "1", "r", "50" };

    Act(args);

    Assert("The integration value of rectangle method equals 0.2.*");
}

TEST_F(ApplicationTest, Can_Integrate_Integrand_By_Trapezoid_Method) {
    vector<string> args = { "x*x*x*x", "0", "1", "t", "50" };

    Act(args);

    Assert("The integration value of trapezoid method equals 0.2.*");
}

TEST_F(ApplicationTest, Can_Integrate_Integrand_By_Simpson_Method) {
    vector<string> args = { "x*x*x*x", "0", "1", "s", "1e-6" };

    Act(args);

    Assert("The integration value of Simpson method equals 0.2.*");
}
