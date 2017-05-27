// Copyright 2017 Kalinin Vladimir

#include "include/dijkstra_app.h"
#include "include/Graph.h"

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <string>
#include <sstream>

Dijkstra_app::Dijkstra_app() : message_("") {}

void Dijkstra_app::help(const char* appname, const char* message) {
  message_ =
    std::string(message) +
    "This is a dijkstra algorithm application.\n\n" +
    "Please provide arguments in the following format:\n\n" +

    "  $ " + appname + " <Graph size> <Number of edges> <Start node>\n" +
    "<First node> <Second node> <Weight of the edge>\n" +
    "...\n"+
    "<First node> <Second node> <Weight of the edge>\n\n" +
    "Where all arguments are integer numbers";
}

std::string Dijkstra_app::operator()(int argc, const char** argv) {
  if (argc < 4) {
    help(argv[0]);
    return message_;
  }
  int size = atoi(argv[1]);
  int edgenum = atoi(argv[2]);
  int startNode = atoi(argv[3]);
  if (argc != 3 + 3 * edgenum) {
    help(argv[0]);
    return message_;
  }
  Graph gr(size);
  int key1, key2, weight;
  for (int i = 0; i < edgenum; i++) {
    key1 = atoi(argv[4+3*i]);
    key2 = atoi(argv[5 + 3 * i]);
    weight = atoi(argv[6 + 3 * i]);
    gr.AddEdge(key1, key2, weight);
  }
  int *answer = gr.Dijkstra(startNode);
  std::ostringstream stream;
  for (int i = 0; i < size; i++) {
    stream << "Weight to node " <<
      i << " = " << answer[i] << "\n";
  }
  message_ = stream.str();
  return message_;
}

