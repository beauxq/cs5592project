//
//  EdgeMatrix.cpp
//  Dijkstra's shortest uncertain path algorithm
//
//  Created by Ting Xia on 4/2/17.
//  Copyright © 2017 Ting. All rights reserved.
//

#include "EdgeMatrix.hpp"

#include <vector>

int EdgeMatrix::getSource(){
    return source;
}

void EdgeMatrix::setSource(int s){
    source = s;
}

int EdgeMatrix::getDestination(){
    return destination;
}

void EdgeMatrix::setDestination(int d){
    destination = d;
}

int EdgeMatrix::getNumOfNodes(){
    return numOfNodes;
}

void EdgeMatrix::setNumOfNodes(int n){
    numOfNodes = n;
}

std::vector<std::vector<EdgeWeight>> EdgeMatrix::getE(){
    return E;
}

void EdgeMatrix::setE(std::vector<std::vector<EdgeWeight>> e){
    E = e;
}
