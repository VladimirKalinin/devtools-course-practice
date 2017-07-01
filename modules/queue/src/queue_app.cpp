// Copyright 2017 Mironova Anna

#include <stdlib.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>
#include <string>
#include <sstream>

#include "include/queue.h"
#include "include/queue_app.h"

QueueApp::QueueApp() : message_("") {}

void QueueApp::help(const char* appname, const char* message) {
    message_ =
        std::string(message) +
        "This is a queue application.\n\n" +
        "Please provide arguments in the following format:\n\n" +
        "  $ " + appname + " <operation> <element if push>\n\n " +
        "Where element is int-precision number, " +
        "and <operation> is one of 'push', 'pop', 'top'.\n";
}

bool QueueApp::validateNumberOfArguments(int argc, const char** argv) {
    if (argc == 1) {
        help(argv[0]);
        return false;
    } else if (argc > 3) {
        help(argv[0], "ERROR: Should be 1 or 2 arguments.\n\n");
        return false;
    }
    return true;
}

double parseInt(const char* arg) {
    char* end;
    int value = strtod(arg, &end);

    if (end[0]) {
        throw std::string("Wrong number format!");
    }

    return value;
}

int parseOperation(const char* arg) {
    int op = 0;
    if (strcmp(arg, "push") == 0) {
        op = 1;
    } else if (strcmp(arg, "pop") == 0) {
        op = 2;
    } else if (strcmp(arg, "top") == 0) {
        op = 3;
    } else {
        throw std::string("Wrong operation format!");
    }
    return op;
}

std::string QueueApp::operator()(int argc, const char** argv) {
    Arguments args;
    std::ostringstream stream;

    if (!validateNumberOfArguments(argc, argv)) {
        return message_;
    }
    try {
        args.operation = parseOperation(argv[1]);
        if ( args.operation == 1 ) {
            if (argc == 2) {
                stream << "Enter item to insert!";
            } else {
                args.element = parseInt(argv[2]);
            }
        }
    }
    catch (std::string &str) {
        return str;
    }

    switch (args.operation) {
    case 1:
        queue.Push(args.element);
        stream << "element pushed";
        break;
    case 2:
        if (!queue.IsEmpty()) {
            stream << "element = " << queue.Pop() << " ";
        } else {
            stream << "Queue is empty!";
        }
        break;
    case 3:
        if (!queue.IsEmpty()) {
            stream << "element = " << queue.Top() << " ";
        } else {
            stream << "Queue is empty!";
        }
        break;
    }

    message_ = stream.str();

    return message_;
}
