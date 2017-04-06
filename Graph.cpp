//
//  Graph.cpp
//  Dijkstra's shortest uncertain path algorithm
//
//  Created by Ting Xia on 4/2/17.
//  Copyright © 2017 Ting. All rights reserved.
//

#include "Graph.hpp"

#include <vector>
#include <cstddef>

#include "EdgeWeight.hpp"

size_t Graph::getSource() const {
    return source;
}

void Graph::setSource(size_t s){
    source = s;
}

size_t Graph::getDestination() const {
    return destination;
}

void Graph::setDestination(size_t d){
    destination = d;
}

size_t Graph::getNumOfNodes() const {
    return numOfNodes;
}

void Graph::setNumOfNodes(size_t n){
    numOfNodes = n;
}

const std::vector<std::vector<EdgeWeight>>& Graph::getAdjacencyMatrix() const {
    return adjacencyMatrix;
}

void Graph::setAdjacencyMatrix(const std::vector<std::vector<EdgeWeight>> &e){
    adjacencyMatrix = e;
}
