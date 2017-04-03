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

using namespace std;

class EdgeMatrix{
private:
    int source;
    int destination;
    int numOfNodes;
    vector<vector<EdgeWeight>> E;
public:
    int getSource();
    void setSource(int s);
    int getDestination();
    void setDestination(int d);
    int getNumOfNodes();
    void setNumOfNodes(int n);
    vector<vector<EdgeWeight>> getE();
    void setE(vector<vector<EdgeWeight>> e);
};
#endif /* EdgeMatrix_hpp */
