// Copyright 2017 Kalinin Vladimir

#include "include/Sort_app.h"
#include "include/Sort.h"
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>
#include <fstream>
#include <iostream>

SortApp::SortApp() : message_("") {}

void SortApp::help(const char* appname, const char* message) {
  message_ = std::string(message) +
    "This is a sort application.\n\n" +
    "Please provide arguments in one of the following formats:\n\n" +
    " $ " + appname +
    " <length_> <sort_type_> <mode_> <order_> <array_elem_1> ..." +

    " <array_elem_length>\n" +
    "or\n" +
    " $ " + appname +
    " <length_> <sort_type_> <mode <order_> <file_with_array.txt path>\n\n" +

    "Where all arguments is a int-precision numbers, " +
    " and <sort_type_> is a choice of the kind of sort:\n" +
    " 1 - QuickSort\n" +
    " 2 - PasteSort\n" +
    " 3 - ChoiceSort\n" +
    " 4 - MergeSort\n\n" +
    " and <mode_> is a choice of the enter way:\n" +
    " 1 - Enter array in the console\n" +
    " 2 - Read array from the file\n\n"+
    " and <order_> is the order of sorting:\n" +
    " 1 - Ascending \n" +
    " 2 - Descending\n";
}

double parseInt(const char* args) {
  char* end = 0;
  int value = strtol(args, &end, 10);

  if (end[0]) {
    throw std::string("Wrong number format!");
  }

  return value;
}

bool SortApp::validateNumberOfSort(const char** argv) {
  if (parseInt(argv[2]) < 1 || parseInt(argv[2]) > 4) {
    help(argv[0], "Error: Sort number should be between 1 and 4.\n\n");
    return false;
  }
  return true;
}

bool SortApp::validateFileOpen(const char** argv) {
  std::string path = std::string(argv[5]);
  std::ifstream fin(path);
  if (!fin.is_open()) {
    help(argv[0], "Error: Incorrect file path.\n\n");
    return false;
  }
  return true;
}

bool SortApp::validateNumberOfMode(const char** argv) {
  if (parseInt(argv[3]) < 1 || parseInt(argv[3]) > 2) {
    help(argv[0], "Error: Mode number should be between 1 or 2.\n\n");
    return false;
  }
  return true;
}

bool SortApp::validateNumberOfOrder(const char** argv) {
  if (parseInt(argv[4]) < 1 || parseInt(argv[4]) > 2) {
    help(argv[0], "Error: Order number should be between 1 or 2.\n\n");
    return false;
  }
  return true;
}

bool SortApp::validateNumberOfArguments(int argc, const char** argv) {
  if (parseInt(argv[3]) == 1) {
    if (parseInt(argv[1]) != (argc - 5)) {
      help(argv[0],
        "Error: Arguments count should be equal array_length plus 4.\n\n");
      return false;
    }
  }
  return true;
}




std::string SortApp::operator()(int argc, const char** argv) {
  Arguments args;

  if (argc == 1) {
    help(argv[0]);
    return message_;
  }
  try {
    args.length_ = parseInt(argv[1]);
  }
  catch (std::string& str) {
    return str;
  }

  if (args.length_ < 1) {
    help(argv[0], "Error: Array can't have less then 1 elem.\n\n");
    return message_;
  }

  try {
    args.sort_type_ = parseInt(argv[2]);
  }
  catch (std::string& str) {
    return str;
  }



  try {
    args.mode_ = parseInt(argv[3]);
  }
  catch (std::string& str) {
    return str;
  }

  if (!validateNumberOfMode(argv)) {
    return message_;
  }
  if (!validateNumberOfSort(argv)) {
    return message_;
  }

  try {
    args.order_ = parseInt(argv[4]);
  }
  catch (std::string& str) {
    return str;
  }

  if (!validateNumberOfArguments(argc, argv)) {
    return message_;
  }

  if (!validateNumberOfOrder(argv)) {
    return message_;
  }

  args.array_ = new int[args.length_];

  if (args.mode_ == 1) {
    try {
      for (int i = 0; i < args.length_; i++)
        args.array_[i] = parseInt(argv[5 + i]);
    }
    catch (std::string& str) {
      return str;
    }
  } else {
    if (!validateFileOpen(argv)) {
      return message_;
    } else {
    args.path_ = std::string(argv[5]);
    std::ifstream fin(args.path_);
      try {
        for (int i = 0; i < args.length_; i++) {
          fin >> args.array_[i];
        }
        fin.close();
      }
      catch (std::string& str) {
        return str;
      }
    }
  }

  std::ostringstream stream;
  Sort sort1(args.array_, args.length_);
  float fTimeStart = clock() / static_cast<float>(CLOCKS_PER_SEC);
  switch (args.sort_type_) {
  case 1:
    sort1.QuickSort(0, args.length_ - 1);
    stream << "Sorted array: ";
    if (args.order_ == 1) {
      for (int i = 0; i < args.length_; i++)
        stream << sort1[i] << " ";
    } else {
      for (int i = args.length_ - 1; i >= 0; i--)
        stream << sort1[i] << " ";
    }
    stream << "\n";

    break;

  case 2:
    sort1.PasteSort();
    stream << "Sorted array: ";
    if (args.order_ == 1) {
      for (int i = 0; i < args.length_; i++)
        stream << sort1[i] << " ";
    } else {
      for (int i = args.length_ - 1; i >= 0; i--)
        stream << sort1[i] << " ";
    }
    stream << "\n";

    break;

  case 3:
    sort1.ChoiceSort();
    stream << "Sorted array: ";
    if (args.order_ == 1) {
      for (int i = 0; i < args.length_; i++)
        stream << sort1[i] << " ";
    }
    else {
      for (int i = args.length_ - 1; i >= 0; i--)
        stream << sort1[i] << " ";
    }
    stream << "\n";

    break;

  case 4:
    sort1.MergeSort(0, args.length_ - 1);
    stream << "Sorted array: ";
    if (args.order_ == 1) {
      for (int i = 0; i < args.length_; i++)
        stream << sort1[i] << " ";
    } else {
      for (int i = args.length_ - 1; i >= 0; i--)
        stream << sort1[i] << " ";
    }
    stream << "\n";

    break;
  }
  float fTimeStop = clock() / static_cast<float>(CLOCKS_PER_SEC);
  stream << "Time of sorting:" << fTimeStop - fTimeStart << "sec\n";
  message_ = stream.str();
  return message_;
}
