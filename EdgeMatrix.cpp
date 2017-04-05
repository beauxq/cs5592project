//
//  EdgeMatrix.cpp
//  Dijkstra's shortest uncertain path algorithm
//
//  Created by Ting Xia on 4/2/17.
//  Copyright © 2017 Ting. All rights reserved.
//

#include "EdgeMatrix.hpp"

#include <vector>

#include "EdgeWeight.hpp"

int EdgeMatrix::getSource() const {
    return source;
}

void EdgeMatrix::setSource(int s){
    source = s;
}

int EdgeMatrix::getDestination() const {
    return destination;
}

void EdgeMatrix::setDestination(int d){
    destination = d;
}

int EdgeMatrix::getNumOfNodes() const {
    return numOfNodes;
}

void EdgeMatrix::setNumOfNodes(int n){
    numOfNodes = n;
}

const std::vector<std::vector<EdgeWeight>>& EdgeMatrix::getE() const {
    return E;
}

void EdgeMatrix::setE(const std::vector<std::vector<EdgeWeight>>& e){
    E = e;
}
