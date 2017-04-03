#include <iostream>
#include "InputParser.hpp"

int main(int argc, const char * argv[]) {
    string inputString = "/Users/Ting/Desktop/CS5592SP17StochasticShortestPath3.txt";
    InputParser IP;
    EdgeMatrix E = IP.parser(inputString);
    cout << "No. of nodes: " << E.getNumOfNodes() << '\n';
    cout << "Source: " << E.getSource() << '\n';
    cout << "Destination: " << E.getDestination() << '\n';
    cout << "E matrix" << '\n';
    vector<vector<EdgeWeight>> edge_weight = E.getE();
    for (int i = 0; i < edge_weight.size(); i++) {
        for (int j = 0; j < edge_weight[i].size(); j++) {
            cout << "(";
            cout << edge_weight[i][j].getMean() <<" ";
            cout << edge_weight[i][j].getVariance() <<" ";
            cout << edge_weight[i][j].getC_square() <<")";
        }
        cout << '\n';
    }
    return 0;
}
