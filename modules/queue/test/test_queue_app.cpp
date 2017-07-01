// Copyright 2017 Mironova Anna

#include <gtest/gtest.h>
#include <vector>
#include <string>

#include "include/queue_app.h"
#include "include/queue.h"

using ::testing::internal::RE;
using std::vector;
using std::string;

class QueueAppTest : public ::testing::Test {
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
    QueueApp app_;
    string output_;
};

TEST_F(QueueAppTest, Do_Print_Help_Without_Arguments) {
    vector<string> args = {};

    Act(args);

    Assert("This is a queue application\\..*");
}

TEST_F(QueueAppTest, Is_Checking_Number_Of_Arguments) {
    vector<string> args = { "push", "2", "3" };

    Act(args);

    Assert("ERROR: Should be 1 or 2 arguments\\..*");
}

TEST_F(QueueAppTest, Can_Detect_Wrong_Number_Format) {
    vector<string> args = { "push", "e"};

    Act(args);

    Assert("Wrong number format!.*");
}

TEST_F(QueueAppTest, Can_Detect_Wrong_Operation_Format) {
    vector<string> args = { "include" };

    Act(args);

    Assert("Wrong operation format!*");
}

TEST_F(QueueAppTest, Can_Push) {
    vector<string> args = { "push", "4" };

    Act(args);

    Assert("element pushed*");
}

TEST_F(QueueAppTest, Can_Not_Push_Empty_Item) {
    vector<string> args = { "push" };

    Act(args);

    Assert("Enter item to insert.*");
}

TEST_F(QueueAppTest, Can_Pop) {
    vector<string> args = { "push", "3" };
    vector<string> args1 = { "pop" };

    Act(args);
    Assert("element pushed*");
    Act(args1);

    Assert("element = 3*");
}

TEST_F(QueueAppTest, Can_Not_Pop_From_Empty_Queue) {
    vector<string> args = { "pop" };

    Act(args);

    Assert("Queue is empty.*");
}

TEST_F(QueueAppTest, Can_Top) {
    vector<string> args = { "push", "3" };
    vector<string> args1 = { "top" };

    Act(args);
    Assert("element pushed*");
    Act(args1);

    Assert("element = 3*");
}

TEST_F(QueueAppTest, Can_Not_Top_From_Empty_Queue) {
    vector<string> args = { "top" };

    Act(args);

    Assert("Queue is empty.*");
}
