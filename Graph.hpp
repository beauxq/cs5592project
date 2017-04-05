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
#include "EdgeWeight.hpp"

class Graph{
private:
    int source;
    int destination;
    int numOfNodes;
    std::vector<std::vector<EdgeWeight>> adjacencyMatrix;
public:
    int getSource() const;
    void setSource(int s);
    int getDestination() const;
    void setDestination(int d);
    int getNumOfNodes() const;
    void setNumOfNodes(int n);
    const std::vector<std::vector<EdgeWeight>>& getAdjacencyMatrix() const;
    void setAdjacencyMatrix(const std::vector<std::vector<EdgeWeight>> &e);
};

#endif /* EdgeMatrix_hpp */
