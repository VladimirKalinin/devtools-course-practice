// Copyright 2017 Alexander Gaivanuk

#include <gtest/gtest.h>

#include <string>
#include <vector>

#include "include/statistical_calculator.h"
#include "include/statistical_moments.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class StatisticalCalculatorTest : public ::testing::Test {
 protected:
    void Act(const vector<string> &args) {
        vector<const char *> options;

        options.push_back("appname");
        for (size_t i = 0; i < args.size(); i++) {
            options.push_back(args[i].c_str());
        }

        const char **argv = &options.front();
        int argc = static_cast<int>(args.size()) + 1;

        output_ = app_(argc, argv);
    }

    void Assert(const string &expected) {
        EXPECT_TRUE(RE::PartialMatch(output_, RE(expected)));
    }

 protected:
    StatisticalCalculator app_;
    string output_;
};

TEST_F(StatisticalCalculatorTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = { };

    Act(args);

    Assert("This is a statistical moments calculator.*");
}

TEST_F(StatisticalCalculatorTest, Can_Handle_Wrong_Number_Of_Arguments_Case1) {
    vector<string> args = { "-exp", "-v", "1" };

    Act(args);

    Assert("ERROR: too few arguments.*");
}

TEST_F(StatisticalCalculatorTest, Can_Handle_Wrong_Number_Of_Arguments_Case2) {
    vector<string> args = { "-moment", "-v", "1", "-p", "2" };

    Act(args);

    Assert("ERROR: too few arguments.*");
}

TEST_F(StatisticalCalculatorTest, Can_Handle_Wrong_Order) {
    vector<string> args = {"-moment", "one", "2", "-v", "1", "-p", "0.2"};

    Act(args);

    Assert("ERROR: unrecognized argument one.*");
}

TEST_F(StatisticalCalculatorTest, Can_Handle_Wrong_Offset) {
    vector<string> args = { "-moment", "1", "two", "-v", "1", "-p", "0.2" };

    Act(args);

    Assert("ERROR: unrecognized argument two.*");
}

TEST_F(StatisticalCalculatorTest, Can_Handle_Negative_Argument) {
    vector<string> args = { "-moment", "1", "-2", "-v", "1", "-prob", "0.1" };

    Act(args);

    Assert("ERROR: specified value -2 is less than zero.*");
}

TEST_F(StatisticalCalculatorTest, Can_Handle_Wrong_Probs_Argument) {
    vector<string> args = { "-exp", "-v", "1", "-prob", "0.1" };

    Act(args);

    Assert("ERROR: unrecognized argument -prob.*");
}

TEST_F(StatisticalCalculatorTest, Can_Handle_Wrong_Values_Argument) {
    vector<string> args = { "-exp", "-val", "1", "-p", "0.3" };

    Act(args);

    Assert("ERROR: unrecognized argument -val.*");
}

TEST_F(StatisticalCalculatorTest, Can_Handle_Wrong_Lists_Length) {
    vector<string> args = { "-disp", "-v", "1", "2", "-p", "0.5" };

    Act(args);

    Assert("ERROR: values and probabilities lists must have the same length.*");
}

TEST_F(StatisticalCalculatorTest, Can_Handle_Aborted_List) {
    vector<string> args = { "-disp", "-v", "1", "2", "3" };

    Act(args);

    Assert("ERROR: two few arguments.*");
}

TEST_F(StatisticalCalculatorTest, Can_Handle_Wrong_Operation) {
    vector<string> args = { "-n", "-v", "1", "-p", "0.4" };

    Act(args);

    Assert("ERROR: unrecognized argument -n.*");
}

TEST_F(StatisticalCalculatorTest, Can_Handle_Wrong_Probs) {
    vector<string> args = { "-exp", "-v", "1", "-p", "1.2" };

    Act(args);

    Assert("ERROR: One of chances is out of range.*");
}

TEST_F(StatisticalCalculatorTest, Can_Calc_Expectancy) {
    vector<double> values = { 1.2, 2.4, 3.1 };
    vector<double> probabilities = { 0.1, 0.4, 0.5 };
    vector<string> args = { "-exp", "-v", "1.2", "2.4", "3.1",
                            "-p", "0.1", "0.4", "0.5" };

    Act(args);
    string result = std::to_string(
        StatisticalMoments::GetExpectancy(values, probabilities));

    EXPECT_EQ(result, output_);
}

TEST_F(StatisticalCalculatorTest, Can_Calc_Dispersion) {
    vector<double> values = { 2.1, 1.43, 33.3, 2.56 };
    vector<double> probabilities = { 0.2, 0.1, 0.3, 0.4 };
    vector<string> args = { "-disp", "-v", "2.1", "1.43", "33.3",
                            "2.56", "-p", "0.2", "0.1", "0.3", "0.4" };

    Act(args);
    string result = std::to_string(
        StatisticalMoments::GetDispersion(values, probabilities));

    EXPECT_EQ(result, output_);
}

TEST_F(StatisticalCalculatorTest, Can_Calc_Custom_Moment) {
    vector<double> values = { 1.1, 1.3, 3.3, 2.6 };
    vector<double> probabilities = { 0.4, 0.2, 0.1, 0.3 };
    unsigned order = 3;
    unsigned offset = 1488;
    vector<string> args = { "-moment", "3", "1488", "-v", "1.1", "1.3", "3.3",
                           "2.6", "-p", "0.4", "0.2", "0.1", "0.3" };

    Act(args);
    string result = std::to_string(StatisticalMoments::GetCustomMoment(
        values, probabilities, order, offset));

    EXPECT_EQ(result, output_);
}
