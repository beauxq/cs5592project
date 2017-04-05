//
//  Graph.cpp
//  Dijkstra's shortest uncertain path algorithm
//
//  Created by Ting Xia on 4/2/17.
//  Copyright © 2017 Ting. All rights reserved.
//

#include "Graph.hpp"

#include <vector>

#include "EdgeWeight.hpp"

int Graph::getSource() const {
    return source;
}

void Graph::setSource(int s){
    source = s;
}

int Graph::getDestination() const {
    return destination;
}

void Graph::setDestination(int d){
    destination = d;
}

int Graph::getNumOfNodes() const {
    return numOfNodes;
}

void Graph::setNumOfNodes(int n){
    numOfNodes = n;
}

const std::vector<std::vector<EdgeWeight>>& Graph::getAdjacencyMatrix() const {
    return adjacencyMatrix;
}

void Graph::setAdjacencyMatrix(const std::vector<std::vector<EdgeWeight>> &e){
    adjacencyMatrix = e;
}
