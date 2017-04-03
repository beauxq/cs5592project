#include <iostream>
#include "InputParser.hpp"

int main(int argc, const char * argv[]) {
    std::string inputString = "/Users/Ting/Desktop/CS5592SP17StochasticShortestPath3.txt";
    InputParser IP;
    EdgeMatrix E = IP.parser(inputString);
    std::cout << "No. of nodes: " << E.getNumOfNodes() << '\n';
    std::cout << "Source: " << E.getSource() << '\n';
    std::cout << "Destination: " << E.getDestination() << '\n';
    std::cout << "E matrix" << '\n';
    std::vector<std::vector<EdgeWeight>> edge_weight = E.getE();
    for (int i = 0; i < edge_weight.size(); i++) {
        for (int j = 0; j < edge_weight[i].size(); j++) {
            std::cout << "(";
            std::cout << edge_weight[i][j].getMean() <<" ";
            std::cout << edge_weight[i][j].getVariance() <<" ";
            std::cout << edge_weight[i][j].getC_square() <<")";
        }
        std::cout << '\n';
    }
    return 0;
}
