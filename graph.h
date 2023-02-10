#ifndef _SRC_GRAPH_H
#define _SRC_GRAPH_H

#include <fstream>
#include <iostream>
#include <string>
#include <vector>

#include "matrix/matrix.h"

namespace TL {
class Graph {
 public:
  Graph() = default;
  Graph(Graph& other) = default;
  Graph(Graph&& other) = delete;
  Graph& operator=(const Graph& other) = default;
  Graph operator=(Graph&& other) = delete;
  ~Graph();

  void LoadGraphFromFile(std::string filename);
  void ExportGraphToDot(std::string filename);
  int get_size() { return graph_size_; }
  bool IsEmpty();
  inline Matrix* get_pointer() {  // debug method, should be deleted
    return adjacency_matrix_;
  }

 private:
  class Parser {
   public:
    explicit Parser(std::string filename);
    Parser(const Parser& other) = delete;
    Parser(Parser&& other) = delete;
    Parser& operator=(const Parser& other) = delete;
    Parser operator=(Parser&& other) = delete;
    ~Parser();

    std::string p_filename_;
    Matrix* p_matrix_ = nullptr;
    std::fstream p_file_;
    bool p_IsMatrixExist_ = false;
    std::string p_line_;
    int p_size_ = 0;

    void BuildMatrix();
    std::vector<int> ParseLine();
    bool MatrixInitialize();
    void FillTheRow(std::vector<int> row, int row_iterator);
  };
  class Exporter {
   public:
    explicit Exporter(std::string filename, Matrix* matrix, int size);
    Exporter(const Exporter&& other) = delete;
    Exporter(Exporter&& other) = delete;
    Exporter& operator=(const Exporter& other) = delete;
    Exporter operator=(Exporter&& other) = delete;
    ~Exporter() = default;

    std::string e_filename_;
    Matrix* e_matrix_ = nullptr;
    int e_size_;
    std::ofstream e_file_;

    std::string set_graphname();
    void Writer();
  };
  int graph_size_ = 0;
  Matrix* adjacency_matrix_ = nullptr;
};
};

#endif  // _SRC_GRAPH_H
