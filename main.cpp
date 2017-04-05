#include <iostream>

#include "InputParser.hpp"
#include "EdgeMatrix.hpp"

void test(const std::string& fileName) {
    EdgeMatrix graph = InputParser::getGraphFromFile(fileName);
    std::cout << "No. of nodes: " << graph.getNumOfNodes() << '\n';
    std::cout << "Source: " << graph.getSource() << '\n';
    std::cout << "Destination: " << graph.getDestination() << '\n';
    std::cout << "adjacency matrix:" << std::endl;
    std::vector<std::vector<EdgeWeight>> matrix = graph.getE();
    for (int row = 0; row < matrix.size(); row++) {
        for (int col = 0; col < matrix[row].size(); col++) {
            std::cout << "(";
            std::cout << matrix[row][col].getMean() << " ";
            std::cout << matrix[row][col].getVariance() << " ";
            std::cout << matrix[row][col].getC_square() << ")";
        }
        std::cout << std::endl;
    }
}

int main(int argc, const char * argv[]) {
    test("input/CS5592SP17StochasticShortestPath3.txt");
    test("input/CS5592SP17StochasticShortestPath4.txt");

    return 0;
}
