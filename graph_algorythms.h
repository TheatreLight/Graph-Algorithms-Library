#pragma once

#include "graph.h"

#include <stack>
#include <queue>

namespace TL {
class GraphAlgorythms {
 public:
  GraphAlgorythms() = default;
  GraphAlgorythms(const GraphAlgorythms& other) = delete;
  GraphAlgorythms(GraphAlgorythms&& other) = delete;
  GraphAlgorythms& operator=(const GraphAlgorythms& other) = delete;
  GraphAlgorythms operator=(GraphAlgorythms&& other) = delete;
  ~GraphAlgorythms() = default;

  std::vector<int> DepthFirstSearch(Graph& graph, int start_vertex);
  std::vector<int> BreadthFirstSearch(Graph& graph, int start_vertex);
  Matrix GetLeastSpanningTree(Graph &graph);

 private:
  bool IsNotVisited(std::vector<int>&, int);
};
};
