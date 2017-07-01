// Copyright 2017 Kiparenko Ilya

#include "include/interpolation_search.h"
#include "include/interpolation_search_app.h"

#include <stdlib.h>
#include <cstdint>
#include <limits>
#include <string>
#include <vector>

InterpolationSearchApp::InterpolationSearchApp() : message_("") {}

void InterpolationSearchApp::help(const char* appname, const char* message) {
  message_ =
    std::string(message) +
    "This is a interpolation search app\n" +
    "Use \n\t$ " + appname + " <array> <item>\n" +
    "Where <array> is array of integers, and <item> is what you want to find\n";
}

bool InterpolationSearchApp::validateNumberOfArguments(int argc,
                                                       const char** argv) {
  if (argc == 1) {
    help(argv[0]);
    return false;
  } else if (argc < 3) {
    help(argv[0], "ERROR: Should be at least 2 arguments.\n\n");
    return false;
  }
  return true;
}

int parseInt(const char* arg) {
  char* end = 0;
  int64_t value = strtol(arg, &end, 10);
  if (end[0] != 0 ||
    value < std::numeric_limits<int>::min() ||
    value > std::numeric_limits<int>::max()) {
    throw std::string("ERROR: Wrong number format! ") + arg;
  }

  return static_cast<int>(value);
}

std::string InterpolationSearchApp::operator()(int argc, const char** argv) {
  if (!validateNumberOfArguments(argc, argv)) {
    return message_;
  }

  int key;
  int length = argc - 2;
  std::vector<int> data(length);

  try {
    for (int i = 0; i < length; i++)
      data[i] = parseInt(argv[i + 1]);

    key = parseInt(argv[length + 1]);
  }
  catch(std::string& str) {
    return str;
  }

  bool isSorted = InterpolationSearch::isArrayValid(&data[0], length);
  if (!isSorted) {
    return "ERROR: Array is unsorted\n";
  }

  int result = InterpolationSearch::Search(key, &data[0], length);
  return "Result = " + std::to_string(result);
}
