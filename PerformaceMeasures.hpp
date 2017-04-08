//
//  PerformaceMeasures.hpp
//  Dijkstra's shortest uncertain path algorithm
//
//  Created by Ting Xia on 4/7/17.
//  Copyright © 2017 Ting. All rights reserved.
//

#ifndef PerformaceMeasures_hpp
#define PerformaceMeasures_hpp

#include <stdio.h>
#include "Graph.hpp"
#include "Dijkstra.h"
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <cmath>
#include <unordered_map>
#include <iomanip>
#include <sstream>

class PerformaceMeasures{
public:
    void ComparePathsAndCheckEdge(Graph graph);
    std::string center(const std::string s, const int w);
};
#endif /* PerformaceMeasures_hpp */
