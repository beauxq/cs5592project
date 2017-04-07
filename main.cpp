#include <iostream>

#include "InputParser.hpp"
#include "Graph.hpp"
#include "Dijkstra.h"
#include "image/ImageData.h"
#include "GraphVisualizer.h"

void testImage() {
    ImageData img(200, 100);
    img.writeFile("white200x100");
}

void testGraphImage(const std::string& fileName) {
    Graph graph = InputParser::getGraphFromFile(fileName);

    Dijkstra algorithm(graph);
    algorithm.findPath(1);
    std::cout << algorithm.getShortestPathString() << std::endl;
    std::cout << algorithm.getShortestDistance() << std::endl;

    GraphVisualizer gv(graph);
    gv.createImage(fileName);
}

void test(const std::string& fileName) {
    Graph graph = InputParser::getGraphFromFile(fileName);
    std::cout << "No. of nodes: " << graph.getNumOfNodes() << '\n';
    std::cout << "Source: " << graph.getSource() << '\n';
    std::cout << "Destination: " << graph.getDestination() << '\n';
    std::cout << "adjacency matrix:" << std::endl;
    std::vector<std::vector<EdgeWeight>> matrix = graph.getAdjacencyMatrix();
    for (int row = 0; row < matrix.size(); row++) {
        for (int col = 0; col < matrix[row].size(); col++) {
            std::cout << "(";
            std::cout << matrix[row][col].getMean() << " ";
            std::cout << matrix[row][col].getVariance() << " ";
            std::cout << matrix[row][col].getC_square() << ")";
        }
        std::cout << std::endl;
    }

    Dijkstra algorithm(graph);
    algorithm.findPath(1);
    std::cout << algorithm.getShortestPathString() << std::endl;
    std::cout << algorithm.getShortestDistance() << std::endl;
}

int main(int argc, const char * argv[]) {
    test("input/CS5592SP17StochasticShortestPath3.txt");
    test("input/CS5592SP17StochasticShortestPath4.txt");

    testGraphImage("input/CS5592SP17StochasticShortestPath3.txt");

    return 0;
}
