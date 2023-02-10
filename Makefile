all:

tests:
	g++ -Wall -Wextra -Werror -std=c++17 test/main.cpp test/test.cpp graph.cpp matrix/matrix.cpp graph_algorithms.cpp -o test_out -lgtest

debug:
	g++ -Wall -Wextra -Werror -std=c++17 test/main.cpp test/test.cpp graph.cpp matrix/matrix.cpp graph_algorithms.cpp -o test_out -lgtest -g

clean:
	rm -rf test_out