//
//  PerformanceMeasures.cpp
//  Dijkstra's shortest uncertain path algorithm
//
//  Created by Ting Xia on 4/7/17.
//  Copyright © 2017 Ting. All rights reserved.
//

#include "PerformanceMeasures.hpp"

void PerformanceMeasures::processCategory(Table& outputTable,
                                          std::list<size_t>& outputPath,
                                          Dijkstra& algorithm,
                                          const Category& category,
                                          std::unordered_map<std::string, std::vector<std::string>>& edgeMap,
                                          std::unordered_map<std::string, std::vector<bool>>& edgeSelMap)
{
#ifdef _WIN32
    // unicode buggy in windows
    const std::string rightArrow = "->";
#else  // not windows
    const std::string rightArrow = "→";
#endif

    double tableData[CATEGORIES.size()];
    // initialize to zero
    for (size_t i = 0; i < CATEGORIES.size(); ++i) {
        tableData[i] = 0;
    }

    algorithm.findPath(category.number);
    std::cout << "Result for " << category.name << ":" << std::endl;
    std::cout << "Shortest path: " << algorithm.getShortestPathString() << std::endl;
    std::cout << "Shortest distance: " << algorithm.getShortestDistance() << std::endl;
    outputPath = algorithm.getShortestPath();

    auto pathEdgeEndIter = outputPath.begin();
    pathEdgeEndIter++;
    for (auto pathEdgeBeginIter = outputPath.begin();
         pathEdgeEndIter != outputPath.end();
         ++pathEdgeBeginIter, ++pathEdgeEndIter)
    {
        std::string edgeString = std::to_string(*pathEdgeBeginIter) + rightArrow + std::to_string(*pathEdgeEndIter);
        if (! edgeMap.count(edgeString))
            edgeMap[edgeString] = std::vector<std::string>();
        edgeMap[edgeString].push_back(category.name);
        EdgeWeight edge = algorithm.getGraph().getAdjacencyMatrix()[*pathEdgeBeginIter][*pathEdgeEndIter];

        for (size_t i = 0; i < CATEGORIES.size(); ++ i) {
            tableData[i] += CATEGORIES[i].getCost(edge);
        }
    }

    for (size_t i = 0; i < CATEGORIES.size(); ++i) {
        outputTable.push_back({CATEGORIES[i].functionString, tableData[i]});
    }
}

void PerformanceMeasures::ComparePathsAndCheckEdge(Graph graph){
    Dijkstra algorithm(graph);

    std::vector<Table> allTables(CATEGORIES.size());
    std::vector < std::list < size_t > > allPaths(CATEGORIES.size());

    // map for edge information
    std::unordered_map<std::string, std::vector<std::string>> edgeMap;
    // map for edge selection
    std::unordered_map<std::string, std::vector<bool>> edgeSelMap;

    for (size_t i = 0; i < CATEGORIES.size(); ++i) {
        processCategory(allTables[i], allPaths[i], algorithm, CATEGORIES[i], edgeMap, edgeSelMap);
    }

    // print the two table
    // performance table
    std::cout << center("Criteria", 18);
    for (size_t i = 0; i < CATEGORIES.size(); ++i) {
        std::cout << center(CATEGORIES[i].functionString, 18);
    }
    std::cout << center("hops", 10) << std::endl;

    for (size_t categoryIndex = 0; categoryIndex < CATEGORIES.size(); ++categoryIndex) {
        std::cout << center(CATEGORIES[categoryIndex].name, 18);
        for (int i = 0; i < allTables[categoryIndex].size(); ++i) {
            std::cout << center(std::to_string(allTables[categoryIndex][i].second), 17) << " ";
        }
        // hops
        std::cout << center(std::to_string(allPaths[categoryIndex].size()), 10) << std::endl;
    }

    // print edge table
    for (auto iter = edgeMap.begin(); iter != edgeMap.end(); ++iter) {
        // vector for edge information
        std::vector<bool> edgeSelection(5, false);
        for (int i = 0; i < iter->second.size(); i++) {
            for (size_t categoryIndex = 0; categoryIndex < CATEGORIES.size(); ++ categoryIndex) {
                if (iter->second[i] == CATEGORIES[categoryIndex].name) {
                    edgeSelection[categoryIndex] = true;
                    break;
                }
            }
        }
        edgeSelMap[iter->first] = edgeSelection;
    }

    std::cout << center("Edge", 10);
    for (size_t categoryIndex = 0; categoryIndex < CATEGORIES.size(); ++categoryIndex) {
        std::cout << center(CATEGORIES[categoryIndex].name, 15);
    }
    std::cout << std::endl;

    for (auto iter = edgeSelMap.begin(); iter != edgeSelMap.end(); iter++) {
        std::cout << center(iter->first, 10);
        for (int i = 0; i < CATEGORIES.size(); ++i) {
            std::cout << center(std::to_string(iter->second[i]), 14) << " ";
        }
        std::cout << std::endl;
    }
}

std::string PerformanceMeasures::center(std::string s, const int& w) {
    while (s.size() <= w - 2) {
        s = " " + s + " ";
    }

    if (s.size() < w) {
        s += " ";
    }

    return s;
}
