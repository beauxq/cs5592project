//
//  EdgeMatrix.hpp
//  Dijkstra's shortest uncertain path algorithm
//
//  Created by Ting Xia on 4/2/17.
//  Copyright © 2017 Ting. All rights reserved.
//

#ifndef EdgeMatrix_hpp
#define EdgeMatrix_hpp

#include <stdio.h>
#include <vector>
#include "EdgeWeight.hpp"

class EdgeMatrix{
private:
    int source;
    int destination;
    int numOfNodes;
    std::vector<std::vector<EdgeWeight>> E;
public:
    int getSource();
    void setSource(int s);
    int getDestination();
    void setDestination(int d);
    int getNumOfNodes();
    void setNumOfNodes(int n);
    std::vector<std::vector<EdgeWeight>> getE();
    void setE(std::vector<std::vector<EdgeWeight>> e);
};

#endif /* EdgeMatrix_hpp */
