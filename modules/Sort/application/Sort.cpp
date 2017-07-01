// Copyright 2017 Kalinin Vladimir

#include <stdio.h>
#include <stdlib.h>
#include <string>

#include "include/Sort_app.h"

int main(int argc, const char** argv) {
  SortApp app;
  std::string output = app(argc, argv);
  printf("%s\n", output.c_str());
  return 0;
}
