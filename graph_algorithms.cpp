#include "graph_algorithms.h"

std::vector<int> TL::GraphAlgorithms::DepthFirstSearch(TL::Graph& graph,
                                                   int start_vertex) {
  std::vector<int> visited;
  std::stack<int> stack;
  stack.push(start_vertex);
  int size = graph.get_size();
  TL::Matrix* matrix = graph.get_pointer();
  while (!stack.empty()) {
    int prev = stack.top();
    stack.pop();
    if (IsNotVisited(visited, prev)) visited.push_back(prev);
    for (int next = 1; next <= size; ++next) {
      if (IsNotVisited(visited, next) &&
          matrix->get_value(prev - 1, next - 1) > 0) {
        stack.push(next);
      }
    }
  }
  return visited;
}

std::vector<int> TL::GraphAlgorithms::BreadthFirstSearch(TL::Graph& graph,
                                                     int start_vertex) {
  std::vector<int> visited;
  std::queue<int> queue;
  queue.push(start_vertex);
  int size = graph.get_size();
  TL::Matrix* matrix = graph.get_pointer();
  while (!queue.empty()) {
    int current = queue.front();
    queue.pop();
    if (IsNotVisited(visited, current)) visited.push_back(current);
    for (int next = 1; next <= size; ++next) {
      if (IsNotVisited(visited, next) &&
          matrix->get_value(current - 1, next - 1))
        queue.push(next);
    }
  }
  return visited;
}

TL::Matrix TL::GraphAlgorithms::GetLeastSpanningTree(TL::Graph& graph) {
  std::vector<int> visited;
  int size = graph.get_size();
  TL::Matrix tree(size, size);
  TL::Matrix* current = graph.get_pointer();
  visited.push_back(1);
  Edge min(0, 0, 0);
  while (visited.size() != size_t(size)) {
    min.set_edge(0, 0, 0);
    for (auto elem : visited) {
      for (int j = 0; j < size; ++j) {
        if (IsNotVisited(visited, j+1)) {
        int value = current->get_value(elem-1, j);
        if ((min.weight == 0 || min.weight >= value) && value > 0) {
          min.set_edge(elem, j+1, value);
        }
        }
      }
    }
    visited.push_back(min.B);
    tree.set_value(min.weight, min.A-1, min.B-1);
    tree.set_value(min.weight, min.B-1, min.A-1);
  }
  return tree;
}

bool TL::GraphAlgorithms::IsNotVisited(std::vector<int>& visited,
                                   int current_vertex) {
  for (auto item : visited) {
    if (current_vertex == item) return false;
  }
  return true;
}
