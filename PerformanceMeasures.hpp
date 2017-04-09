//
//  PerformanceMeasures.hpp
//  Dijkstra's shortest uncertain path algorithm
//
//  Created by Ting Xia on 4/7/17.
//  Copyright © 2017 Ting. All rights reserved.
//

#ifndef PerformanceMeasures_hpp
#define PerformanceMeasures_hpp

#include <stdio.h>
#include <iostream>
#include <vector>
#include <string>
#include <utility>
#include <cmath>
#include <unordered_map>
#include <iomanip>
#include <sstream>

#include "Graph.hpp"
#include "Dijkstra.h"
#include "Categories.h"

typedef std::vector<std::pair<std::string, double>> Table;

class PerformanceMeasures{
public:
    static void processCategory(Table& outputTable,
                                std::list<size_t>& outputPath,
                                Dijkstra& algorithm,
                                const Category& category,
                                std::unordered_map<std::string, std::vector<std::string>>& edgeMap,
                                std::unordered_map<std::string, std::vector<bool>>& edgeSelMap);

    static void ComparePathsAndCheckEdge(Graph graph);
    static std::string center(std::string s, const int& w);
};

#endif /* PerformaceMeasures_hpp */
