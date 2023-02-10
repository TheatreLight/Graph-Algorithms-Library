#pragma once

#include "graph.h"

#include <stack>
#include <queue>

namespace TL {
struct Edge {
  explicit Edge(int A_, int B_, int weight_) {
    set_edge(A_, B_, weight_);
  };
  int A;
  int B;
  int weight;
  inline void set_edge(int A_, int B_, int weight_) {
    if (A_ >= 0 && B_ >= 0 && weight_ >= 0) {
      A = A_;
      B = B_;
      weight = weight_;
    } else {
      throw std::out_of_range("Wrong parameters");
    }
  }
};

class GraphAlgorithms {
 public:
  GraphAlgorithms() = default;
  GraphAlgorithms(const GraphAlgorithms& other) = delete;
  GraphAlgorithms(GraphAlgorithms&& other) = delete;
  GraphAlgorithms& operator=(const GraphAlgorithms& other) = delete;
  GraphAlgorithms operator=(GraphAlgorithms&& other) = delete;
  ~GraphAlgorithms() = default;

  std::vector<int> DepthFirstSearch(Graph& graph, int start_vertex);
  std::vector<int> BreadthFirstSearch(Graph& graph, int start_vertex);
  Matrix GetLeastSpanningTree(Graph &graph);

 private:
  bool IsNotVisited(std::vector<int>&, int);
};
};
