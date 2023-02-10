#pragma once

#include <vector>

struct TestArrays {

	// Load graphs from files

	int first_arr[11][11] = { {0, 29, 20, 21, 16, 31, 100, 12, 4, 31, 18},
						{29, 0, 15, 29, 28, 40, 72, 21, 29, 41, 12},
						{20, 15, 0, 15, 14, 25, 81, 9, 23, 27, 13},
						{21, 29, 15, 0, 4, 12, 92, 12, 25, 13, 25},
						{16, 28, 14, 4, 0, 16, 94, 9, 20, 16, 22},
						{31, 40, 25, 12, 16, 0, 95, 24, 36, 3, 37},
						{100, 72, 81, 92, 94, 95, 0, 90, 101, 99, 84},
						{12, 21, 9, 12, 9, 24, 90, 0, 15, 25, 13},
						{4, 29, 23, 25, 20, 36, 101, 15, 0, 35, 18},
						{31, 41, 27, 13, 16, 3, 99, 25, 35, 0, 38},
						{18, 12, 13, 25, 22, 37, 84, 13, 18, 38, 0} };

	int second_arr[4][4] = { {0, 50, 50, 0},
							{50, 0, 0, 0},
							{50, 0, 0, 50},
							{0, 0, 50, 0} };

	int third_arr[5][5] = { {0, 1, 1, 0, 0},
							{1, 0, 0, 0, 0},
							{1, 0, 0, 1, 1},
							{0, 0, 1, 0, 0},
							{0, 0, 1, 0, 0} };

	int fourth_arr[8][8] = { {0, 1, 1, 0, 0, 0, 0, 1},
							{1, 0, 0, 1, 1, 1, 0, 0},
							{1, 0, 0, 1, 0, 0, 0, 0},
							{0, 1, 1, 0, 0, 0, 0, 0},
							{0, 1, 0, 0, 0, 0, 1, 1},
							{0, 1, 0, 0, 0, 0, 1, 0},
							{0, 0, 0, 0, 1, 1, 0, 0},
							{1, 0, 0, 0, 1, 0, 0, 0} };

	// Depth First Search

	std::vector<int> case_4_nodes_1_vertex{ 1, 3, 4, 2 };
	std::vector<int> case_4_nodes_2_vertex{ 2, 1, 3, 4 };
	std::vector<int> case_4_nodes_3_vertex{ 3, 4, 1, 2 };
	std::vector<int> case_4_nodes_4_vertex{ 4, 3, 1, 2 };

	std::vector<int> case_5_nodes_1_vertex{ 1, 3, 5, 4, 2 };
	std::vector<int> case_5_nodes_2_vertex{ 2, 1, 3, 5, 4 };
	std::vector<int> case_5_nodes_3_vertex{ 3, 5, 4, 1, 2 };
	std::vector<int> case_5_nodes_4_vertex{ 4, 3, 5, 1, 2 };
	std::vector<int> case_5_nodes_5_vertex{ 5, 3, 4, 1, 2 };

	std::vector<int> case_8_nodes_1_vertex{ 1, 8, 5, 7, 6, 2, 4, 3 };
	std::vector<int> case_8_nodes_2_vertex{ 2, 6, 7, 5, 8, 1, 3, 4 };
	std::vector<int> case_8_nodes_3_vertex{ 3, 4, 2, 6, 7, 5, 8, 1 };
	std::vector<int> case_8_nodes_4_vertex{ 4, 3, 1, 8, 5, 7, 6, 2 };
	std::vector<int> case_8_nodes_5_vertex{ 5, 8, 1, 3, 4, 2, 6, 7 };
	std::vector<int> case_8_nodes_6_vertex{ 6, 7, 5, 8, 1, 3, 4, 2 };
	std::vector<int> case_8_nodes_7_vertex{ 7, 6, 2, 5, 8, 1, 3, 4 };
	std::vector<int> case_8_nodes_8_vertex{ 8, 5, 7, 6, 2, 4, 3, 1 };

	// Breadth First Search

	std::vector<int> bfs_case_4_nodes_1_vertex{ 1, 2, 3, 4 };
	std::vector<int> bfs_case_4_nodes_2_vertex{ 2, 1, 3, 4 };
	std::vector<int> bfs_case_4_nodes_3_vertex{ 3, 1, 4, 2 };
	std::vector<int> bfs_case_4_nodes_4_vertex{ 4, 3, 1, 2 };

	std::vector<int> bfs_case_5_nodes_1_vertex{ 1, 2, 3, 4, 5 };
	std::vector<int> bfs_case_5_nodes_2_vertex{ 2, 1, 3, 4, 5 };
	std::vector<int> bfs_case_5_nodes_3_vertex{ 3, 1, 4, 5, 2 };
	std::vector<int> bfs_case_5_nodes_4_vertex{ 4, 3, 1, 5, 2 };
	std::vector<int> bfs_case_5_nodes_5_vertex{ 5, 3, 1, 4, 2 };

	std::vector<int> bfs_case_8_nodes_1_vertex{ 1, 2, 3, 8, 4, 5, 6, 7 };
	std::vector<int> bfs_case_8_nodes_2_vertex{ 2, 1, 4, 5, 6, 3, 8, 7 };
	std::vector<int> bfs_case_8_nodes_3_vertex{ 3, 1, 4, 2, 8, 5, 6, 7 };
	std::vector<int> bfs_case_8_nodes_4_vertex{ 4, 2, 3, 1, 5, 6, 8, 7 };
	std::vector<int> bfs_case_8_nodes_5_vertex{ 5, 2, 7, 8, 1, 4, 6, 3 };
	std::vector<int> bfs_case_8_nodes_6_vertex{ 6, 2, 7, 1, 4, 5, 3, 8 };
	std::vector<int> bfs_case_8_nodes_7_vertex{ 7, 5, 6, 2, 8, 1, 4, 3 };
	std::vector<int> bfs_case_8_nodes_8_vertex{ 8, 1, 5, 2, 3, 7, 4, 6 };

};