#include "../graph.h"
#include "../graph_algorythms.h"
#include "gtest/gtest.h"
#include "test_data/test_arrays.h"

TEST(graph_test, case_11_nodes_graph) {
	int nodes = 11;
	TL::Graph graph;
	TL::Matrix test_matrix(nodes, nodes);
	TestArrays arrays_one;
	for (int i = 0; i < nodes; ++i) {
		for (int j = 0; j < nodes; ++j) {
			double d = arrays_one.first_arr[i][j];
			test_matrix.set_value(d, i, j);
		}
	}
	graph.LoadGraphFromFile("test/test_data/1.txt");
	TL::Matrix* current_data = graph.get_pointer();
  EXPECT_TRUE(current_data->EqMatrix(test_matrix));
}

TEST(graph_test, case_4_nodes_graph) {
	int nodes = 4;
	TL::Graph graph;
	TL::Matrix test_matrix(nodes, nodes);
	TestArrays arrays_one;
	for (int i = 0; i < nodes; ++i) {
		for (int j = 0; j < nodes; ++j) {
			double d = arrays_one.second_arr[i][j];
			test_matrix.set_value(d, i, j);
		}
	}
	graph.LoadGraphFromFile("test/test_data/2.txt");
	TL::Matrix* current_data = graph.get_pointer();
	EXPECT_TRUE(current_data->EqMatrix(test_matrix));
}

TEST(graph_test, case_5_nodes_graph) {
	int nodes = 5;
	TL::Graph graph;
	TL::Matrix test_matrix(nodes, nodes);
	TestArrays arrays_one;
	for (int i = 0; i < nodes; ++i) {
		for (int j = 0; j < nodes; ++j) {
			double d = arrays_one.third_arr[i][j];
			test_matrix.set_value(d, i, j);
		}
	}
	graph.LoadGraphFromFile("test/test_data/3.txt");
	TL::Matrix* current_data = graph.get_pointer();
	EXPECT_TRUE(current_data->EqMatrix(test_matrix));
}

TEST(graph_test, case_8_nodes_graph) {
	int nodes = 8;
	TL::Graph graph;
	TL::Matrix test_matrix(nodes, nodes);
	TestArrays arrays_one;
	for (int i = 0; i < nodes; ++i) {
		for (int j = 0; j < nodes; ++j) {
			double d = arrays_one.fourth_arr[i][j];
			test_matrix.set_value(d, i, j);
		}
	}
	graph.LoadGraphFromFile("test/test_data/4.txt");
	TL::Matrix* current_data = graph.get_pointer();
	EXPECT_TRUE(current_data->EqMatrix(test_matrix));
}

TEST(algorythms_dts_test, case_4_nodes_1_vertex) {
	TL::Graph graph;
	graph.LoadGraphFromFile("test/test_data/2.txt");
	TL::GraphAlgorythms algorythms;
	std::vector<int> current_path = algorythms.DepthFirstSearch(graph, 1);
	TestArrays arrays;
	EXPECT_TRUE(arrays.case_4_nodes_1_vertex == current_path);
}

TEST(algorythms_dts_test, case_4_nodes_2_vertex) {
	TL::Graph graph;
	graph.LoadGraphFromFile("test/test_data/2.txt");
	TL::GraphAlgorythms algorythms;
	std::vector<int> current_path = algorythms.DepthFirstSearch(graph, 2);
	TestArrays arrays;
	EXPECT_TRUE(arrays.case_4_nodes_2_vertex == current_path);
}

TEST(algorythms_dts_test, case_4_nodes_3_vertex) {
	TL::Graph graph;
	graph.LoadGraphFromFile("test/test_data/2.txt");
	TL::GraphAlgorythms algorythms;
	std::vector<int> current_path = algorythms.DepthFirstSearch(graph, 3);
	TestArrays arrays;
	EXPECT_TRUE(arrays.case_4_nodes_3_vertex == current_path);
}

TEST(algorythms_dts_test, case_4_nodes_4_vertex) {
	TL::Graph graph;
	graph.LoadGraphFromFile("test/test_data/2.txt");
	TL::GraphAlgorythms algorythms;
	std::vector<int> current_path = algorythms.DepthFirstSearch(graph, 4);
	TestArrays arrays;
	EXPECT_TRUE(arrays.case_4_nodes_4_vertex == current_path);
}

TEST(algorythms_dts_test, case_5_nodes_1_vertex) {
	TL::Graph graph;
	graph.LoadGraphFromFile("test/test_data/3.txt");
	TL::GraphAlgorythms algorythms;
	std::vector<int> current_path = algorythms.DepthFirstSearch(graph, 1);
	TestArrays arrays;
	EXPECT_TRUE(arrays.case_5_nodes_1_vertex == current_path);
}

TEST(algorythms_dts_test, case_5_nodes_2_vertex) {
	TL::Graph graph;
	graph.LoadGraphFromFile("test/test_data/3.txt");
	TL::GraphAlgorythms algorythms;
	std::vector<int> current_path = algorythms.DepthFirstSearch(graph, 2);
	TestArrays arrays;
	EXPECT_TRUE(arrays.case_5_nodes_2_vertex == current_path);
}

TEST(algorythms_dts_test, case_5_nodes_3_vertex) {
	TL::Graph graph;
	graph.LoadGraphFromFile("test/test_data/3.txt");
	TL::GraphAlgorythms algorythms;
	std::vector<int> current_path = algorythms.DepthFirstSearch(graph, 3);
	TestArrays arrays;
	EXPECT_TRUE(arrays.case_5_nodes_3_vertex == current_path);
}

TEST(algorythms_dts_test, case_5_nodes_4_vertex) {
	TL::Graph graph;
	graph.LoadGraphFromFile("test/test_data/3.txt");
	TL::GraphAlgorythms algorythms;
	std::vector<int> current_path = algorythms.DepthFirstSearch(graph, 4);
	TestArrays arrays;
	EXPECT_TRUE(arrays.case_5_nodes_4_vertex == current_path);
}

TEST(algorythms_dts_test, case_5_nodes_5_vertex) {
	TL::Graph graph;
	graph.LoadGraphFromFile("test/test_data/3.txt");
	TL::GraphAlgorythms algorythms;
	std::vector<int> current_path = algorythms.DepthFirstSearch(graph, 5);
	TestArrays arrays;
	EXPECT_TRUE(arrays.case_5_nodes_5_vertex == current_path);
}

TEST(algorythms_dts_test, case_8_nodes_1_vertex) {
	TL::Graph graph;
	graph.LoadGraphFromFile("test/test_data/4.txt");
	TL::GraphAlgorythms algorythms;
	std::vector<int> current_path = algorythms.DepthFirstSearch(graph, 1);
	TestArrays arrays;
	EXPECT_TRUE(arrays.case_8_nodes_1_vertex == current_path);
}

TEST(algorythms_dts_test, case_8_nodes_2_vertex) {
	TL::Graph graph;
	graph.LoadGraphFromFile("test/test_data/4.txt");
	TL::GraphAlgorythms algorythms;
	std::vector<int> current_path = algorythms.DepthFirstSearch(graph, 2);
	TestArrays arrays;
	EXPECT_TRUE(arrays.case_8_nodes_2_vertex == current_path);
}

TEST(algorythms_dts_test, case_8_nodes_3_vertex) {
	TL::Graph graph;
	graph.LoadGraphFromFile("test/test_data/4.txt");
	TL::GraphAlgorythms algorythms;
	std::vector<int> current_path = algorythms.DepthFirstSearch(graph, 3);
	TestArrays arrays;
	EXPECT_TRUE(arrays.case_8_nodes_3_vertex == current_path);
}

TEST(algorythms_dts_test, case_8_nodes_4_vertex) {
	TL::Graph graph;
	graph.LoadGraphFromFile("test/test_data/4.txt");
	TL::GraphAlgorythms algorythms;
	std::vector<int> current_path = algorythms.DepthFirstSearch(graph, 4);
	TestArrays arrays;
	EXPECT_TRUE(arrays.case_8_nodes_4_vertex == current_path);
}

TEST(algorythms_dts_test, case_8_nodes_5_vertex) {
	TL::Graph graph;
	graph.LoadGraphFromFile("test/test_data/4.txt");
	TL::GraphAlgorythms algorythms;
	std::vector<int> current_path = algorythms.DepthFirstSearch(graph, 5);
	TestArrays arrays;
	EXPECT_TRUE(arrays.case_8_nodes_5_vertex == current_path);
}

TEST(algorythms_dts_test, case_8_nodes_6_vertex) {
	TL::Graph graph;
	graph.LoadGraphFromFile("test/test_data/4.txt");
	TL::GraphAlgorythms algorythms;
	std::vector<int> current_path = algorythms.DepthFirstSearch(graph, 6);
	TestArrays arrays;
	EXPECT_TRUE(arrays.case_8_nodes_6_vertex == current_path);
}

TEST(algorythms_dts_test, case_8_nodes_7_vertex) {
	TL::Graph graph;
	graph.LoadGraphFromFile("test/test_data/4.txt");
	TL::GraphAlgorythms algorythms;
	std::vector<int> current_path = algorythms.DepthFirstSearch(graph, 7);
	TestArrays arrays;
	EXPECT_TRUE(arrays.case_8_nodes_7_vertex == current_path);
}

TEST(algorythms_dts_test, case_8_nodes_8_vertex) {
	TL::Graph graph;
	graph.LoadGraphFromFile("test/test_data/4.txt");
	TL::GraphAlgorythms algorythms;
	std::vector<int> current_path = algorythms.DepthFirstSearch(graph, 8);
	TestArrays arrays;
	EXPECT_TRUE(arrays.case_8_nodes_8_vertex == current_path);
}

TEST(algorythms_bts_test, case_4_nodes_1_vertex) {
	TL::Graph graph;
	graph.LoadGraphFromFile("test/test_data/2.txt");
	TL::GraphAlgorythms algorythms;
	std::vector<int> current_path = algorythms.BreadthFirstSearch(graph, 1);
	TestArrays arrays;
	EXPECT_TRUE(arrays.bfs_case_4_nodes_1_vertex == current_path);
}

TEST(algorythms_bts_test, case_4_nodes_2_vertex) {
	TL::Graph graph;
	graph.LoadGraphFromFile("test/test_data/2.txt");
	TL::GraphAlgorythms algorythms;
	std::vector<int> current_path = algorythms.BreadthFirstSearch(graph, 2);
	TestArrays arrays;
	EXPECT_TRUE(arrays.bfs_case_4_nodes_2_vertex == current_path);
}

TEST(algorythms_bts_test, case_4_nodes_3_vertex) {
	TL::Graph graph;
	graph.LoadGraphFromFile("test/test_data/2.txt");
	TL::GraphAlgorythms algorythms;
	std::vector<int> current_path = algorythms.BreadthFirstSearch(graph, 3);
	TestArrays arrays;
	EXPECT_TRUE(arrays.bfs_case_4_nodes_3_vertex == current_path);
}

TEST(algorythms_bts_test, case_4_nodes_4_vertex) {
	TL::Graph graph;
	graph.LoadGraphFromFile("test/test_data/2.txt");
	TL::GraphAlgorythms algorythms;
	std::vector<int> current_path = algorythms.BreadthFirstSearch(graph, 4);
	TestArrays arrays;
	EXPECT_TRUE(arrays.bfs_case_4_nodes_4_vertex == current_path);
}

TEST(algorythms_bts_test, case_5_nodes_1_vertex) {
	TL::Graph graph;
	graph.LoadGraphFromFile("test/test_data/3.txt");
	TL::GraphAlgorythms algorythms;
	std::vector<int> current_path = algorythms.BreadthFirstSearch(graph, 1);
	TestArrays arrays;
	EXPECT_TRUE(arrays.bfs_case_5_nodes_1_vertex == current_path);
}

TEST(algorythms_bts_test, case_5_nodes_2_vertex) {
	TL::Graph graph;
	graph.LoadGraphFromFile("test/test_data/3.txt");
	TL::GraphAlgorythms algorythms;
	std::vector<int> current_path = algorythms.BreadthFirstSearch(graph, 2);
	TestArrays arrays;
	EXPECT_TRUE(arrays.bfs_case_5_nodes_2_vertex == current_path);
}

TEST(algorythms_bts_test, case_5_nodes_3_vertex) {
	TL::Graph graph;
	graph.LoadGraphFromFile("test/test_data/3.txt");
	TL::GraphAlgorythms algorythms;
	std::vector<int> current_path = algorythms.BreadthFirstSearch(graph, 3);
	TestArrays arrays;
	EXPECT_TRUE(arrays.bfs_case_5_nodes_3_vertex == current_path);
}

TEST(algorythms_bts_test, case_5_nodes_4_vertex) {
	TL::Graph graph;
	graph.LoadGraphFromFile("test/test_data/3.txt");
	TL::GraphAlgorythms algorythms;
	std::vector<int> current_path = algorythms.BreadthFirstSearch(graph, 4);
	TestArrays arrays;
	EXPECT_TRUE(arrays.bfs_case_5_nodes_4_vertex == current_path);
}

TEST(algorythms_bts_test, case_5_nodes_5_vertex) {
	TL::Graph graph;
	graph.LoadGraphFromFile("test/test_data/3.txt");
	TL::GraphAlgorythms algorythms;
	std::vector<int> current_path = algorythms.BreadthFirstSearch(graph, 5);
	TestArrays arrays;
	EXPECT_TRUE(arrays.bfs_case_5_nodes_5_vertex == current_path);
}

TEST(algorythms_bts_test, case_8_nodes_1_vertex) {
	TL::Graph graph;
	graph.LoadGraphFromFile("test/test_data/4.txt");
	TL::GraphAlgorythms algorythms;
	std::vector<int> current_path = algorythms.BreadthFirstSearch(graph, 1);
	TestArrays arrays;
	EXPECT_TRUE(arrays.bfs_case_8_nodes_1_vertex == current_path);
}

TEST(algorythms_bts_test, case_8_nodes_2_vertex) {
	TL::Graph graph;
	graph.LoadGraphFromFile("test/test_data/4.txt");
	TL::GraphAlgorythms algorythms;
	std::vector<int> current_path = algorythms.BreadthFirstSearch(graph, 2);
	TestArrays arrays;
	EXPECT_TRUE(arrays.bfs_case_8_nodes_2_vertex == current_path);
}

TEST(algorythms_bts_test, case_8_nodes_3_vertex) {
	TL::Graph graph;
	graph.LoadGraphFromFile("test/test_data/4.txt");
	TL::GraphAlgorythms algorythms;
	std::vector<int> current_path = algorythms.BreadthFirstSearch(graph, 3);
	TestArrays arrays;
	EXPECT_TRUE(arrays.bfs_case_8_nodes_3_vertex == current_path);
}

TEST(algorythms_bts_test, case_8_nodes_4_vertex) {
	TL::Graph graph;
	graph.LoadGraphFromFile("test/test_data/4.txt");
	TL::GraphAlgorythms algorythms;
	std::vector<int> current_path = algorythms.BreadthFirstSearch(graph, 4);
	TestArrays arrays;
	EXPECT_TRUE(arrays.bfs_case_8_nodes_4_vertex == current_path);
}

TEST(algorythms_bts_test, case_8_nodes_5_vertex) {
	TL::Graph graph;
	graph.LoadGraphFromFile("test/test_data/4.txt");
	TL::GraphAlgorythms algorythms;
	std::vector<int> current_path = algorythms.BreadthFirstSearch(graph, 5);
	TestArrays arrays;
	EXPECT_TRUE(arrays.bfs_case_8_nodes_5_vertex == current_path);
}

TEST(algorythms_bts_test, case_8_nodes_6_vertex) {
	TL::Graph graph;
	graph.LoadGraphFromFile("test/test_data/4.txt");
	TL::GraphAlgorythms algorythms;
	std::vector<int> current_path = algorythms.BreadthFirstSearch(graph, 6);
	TestArrays arrays;
	EXPECT_TRUE(arrays.bfs_case_8_nodes_6_vertex == current_path);
}

TEST(algorythms_bts_test, case_8_nodes_7_vertex) {
	TL::Graph graph;
	graph.LoadGraphFromFile("test/test_data/4.txt");
	TL::GraphAlgorythms algorythms;
	std::vector<int> current_path = algorythms.BreadthFirstSearch(graph, 7);
	TestArrays arrays;
	EXPECT_TRUE(arrays.bfs_case_8_nodes_7_vertex == current_path);
}

TEST(algorythms_bts_test, case_8_nodes_8_vertex) {
	TL::Graph graph;
	graph.LoadGraphFromFile("test/test_data/4.txt");
	TL::GraphAlgorythms algorythms;
	std::vector<int> current_path = algorythms.BreadthFirstSearch(graph, 8);
	TestArrays arrays;
	EXPECT_TRUE(arrays.bfs_case_8_nodes_8_vertex == current_path);
}
