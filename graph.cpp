#include "graph.h"

TL::Graph::~Graph() {
  if (adjacency_matrix_ != nullptr) delete adjacency_matrix_;
}

void TL::Graph::LoadGraphFromFile(std::string filename) {
  if (filename.empty()) throw std::out_of_range("File doesn't exist");
  Parser parser(filename);
  adjacency_matrix_ = parser.p_matrix_;
  graph_size_ = parser.p_size_;
}

void TL::Graph::ExportGraphToDot(std::string filename) {
  if (IsEmpty()) throw std::out_of_range("Graph is empty");
  Exporter exporter(filename, adjacency_matrix_, graph_size_);
}

bool TL::Graph::IsEmpty() { return !adjacency_matrix_ ? true : false; }

TL::Graph::Parser::Parser(std::string filename) : p_filename_(filename) {
  BuildMatrix();
}

TL::Graph::Parser::~Parser() { p_matrix_ = nullptr; }

void TL::Graph::Parser::BuildMatrix() {
  p_file_.open(p_filename_, std::ios::in);
  if (!p_file_) {
    throw std::out_of_range("File doesn't exist");
  }
  int iterator = 0;
  while (std::getline(p_file_, p_line_)) {
    if (!p_IsMatrixExist_) {
      if (!(p_IsMatrixExist_ = MatrixInitialize()))
        throw std::out_of_range("Wrong file");
    } else {
      FillTheRow(ParseLine(), iterator);
      iterator++;
    }
  }
  p_file_.close();
}

std::vector<int> TL::Graph::Parser::ParseLine() {
  int pos = 0;
  std::vector<int> tmp;
  while ((pos = p_line_.find(" ", 0)) != -1) {
    tmp.emplace_back(stoi(p_line_.substr(0, pos)));
    p_line_.erase(0, pos + 1);
  }
  tmp.emplace_back(stoi(p_line_));
  return tmp;
}

bool TL::Graph::Parser::MatrixInitialize() {
  p_size_ = std::stoi(p_line_);
  if (p_size_ <= 0) return false;
  if (p_matrix_ != nullptr) throw std::out_of_range("Something is wrong");
  p_matrix_ = new TL::Matrix(p_size_, p_size_);
  return true;
}

void TL::Graph::Parser::FillTheRow(std::vector<int> row, int row_iterator) {
  int matrix_row_size = p_matrix_->get_columns();
  if (matrix_row_size != static_cast<int>(row.size()))
    throw std::out_of_range("Wrong file");
  for (int j = 0; j < matrix_row_size; ++j) {
    p_matrix_->set_value(row[j], row_iterator, j);
  }
}

TL::Graph::Exporter::Exporter(std::string filename, TL::Matrix* matrix, int size)
    : e_filename_(filename), e_matrix_(matrix), e_size_(size) {
  Writer();
}

std::string TL::Graph::Exporter::set_graphname() {
  int pos = e_filename_.find(".", 0);
  return e_filename_.substr(0, pos);
}

void TL::Graph::Exporter::Writer() {
  e_file_.open(e_filename_, std::ios::out);
  if (e_file_.is_open()) {
    e_file_ << "graph " << set_graphname() << " {" << std::endl;
    for (int i = 1; i <= e_size_; ++i) {
      e_file_ << i << ";" << std::endl;
    }
    for (int i = 0; i < e_size_; ++i) {
      for (int j = 0; j < e_size_; ++j) {
        auto x = e_matrix_->get_value(i, j);
        if (x != 0) {
          e_file_ << i + 1 << " -- " << j + 1 << " [label=" << x << "];"
                  << std::endl;
        }
      }
    }
    e_file_ << "}";
  } else {
    throw std::out_of_range("Can't open the file");
  }
}
