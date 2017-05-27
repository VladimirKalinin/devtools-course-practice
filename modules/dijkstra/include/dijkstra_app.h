// Copyright 2017 Kalinin Vladimir

#ifndef MODULES_DIJKSTRA_INCLUDE_DIJKSTRA_APP_H_
#define MODULES_DIJKSTRA_INCLUDE_DIJKSTRA_APP_H_

#include <string>

class Dijkstra_app {
public:
  Dijkstra_app();
  std::string operator()(int argc, const char** argv);

private:
  void help(const char* appname, const char* message = "");
  std::string message_;
};

#endif  // MODULES_DIJKSTRA_INCLUDE_DIJKSTRA_APP_H_