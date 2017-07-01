// Copyright 2017 Mironova Anna

#ifndef MODULES_QUEUE_INCLUDE_QUEUE_APP_H_
#define MODULES_QUEUE_INCLUDE_QUEUE_APP_H_

#include <string>
#include "../include/queue.h"

class QueueApp {
 public:
    QueueApp();
    std::string operator()(int argc, const char** argv);

 private:
    void help(const char* appname, const char* message = "");
    bool validateNumberOfArguments(int argc, const char** argv);
    std::string message_;
    typedef struct {
        int element;
        int operation;
    } Arguments;
    Queue<int> queue;
};

#endif  // MODULES_QUEUE_INCLUDE_QUEUE_APP_H_
