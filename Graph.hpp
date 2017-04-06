//
//  Graph.hpp
//  Dijkstra's shortest uncertain path algorithm
//
//  Created by Ting Xia on 4/2/17.
//  Copyright © 2017 Ting. All rights reserved.
//

#ifndef EdgeMatrix_hpp
#define EdgeMatrix_hpp

#include <vector>
#include <cstddef>

#include "EdgeWeight.hpp"

class Graph{
private:
    size_t source;
    size_t destination;
    size_t numOfNodes;
    std::vector<std::vector<EdgeWeight>> adjacencyMatrix;
public:
    size_t getSource() const;
    void setSource(size_t s);
    size_t getDestination() const;
    void setDestination(size_t d);
    size_t getNumOfNodes() const;
    void setNumOfNodes(size_t n);
    const std::vector<std::vector<EdgeWeight>>& getAdjacencyMatrix() const;
    void setAdjacencyMatrix(const std::vector<std::vector<EdgeWeight>> &e);
};

#endif /* EdgeMatrix_hpp */
