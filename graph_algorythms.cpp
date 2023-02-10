#include "graph_algorythms.h"

std::vector<int> TL::GraphAlgorythms::DepthFirstSearch(TL::Graph& graph,
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

std::vector<int> TL::GraphAlgorythms::BreadthFirstSearch(TL::Graph& graph,
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

TL::Matrix TL::GraphAlgorythms::GetLeastSpanningTree(TL::Graph& graph) {
  
  return TL::Matrix();
}

bool TL::GraphAlgorythms::IsNotVisited(std::vector<int>& visited,
                                   int current_vertex) {
  for (auto item : visited) {
    if (current_vertex == item) return false;
  }
  return true;
}
