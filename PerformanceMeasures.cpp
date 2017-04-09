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
    double muMinusTheta = 0, mu = 0, muAddTheta = 0, muAdd2Theta = 0, c_square = 0;

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
        std::string edgeString = std::to_string(*pathEdgeBeginIter) + "→" + std::to_string(*pathEdgeEndIter);
        if (! edgeMap.count(edgeString))
            edgeMap[edgeString] = std::vector<std::string>();
        edgeMap[edgeString].push_back(category.name);
        EdgeWeight edge = algorithm.getGraph().getAdjacencyMatrix()[*pathEdgeBeginIter][*pathEdgeEndIter];
        muMinusTheta += edge.getMean() - sqrt(edge.getVariance());
        mu += edge.getMean();
        muAddTheta += edge.getMean() + sqrt(edge.getVariance());
        muAdd2Theta += edge.getMean() + 2 * sqrt(edge.getVariance());
        c_square += edge.getC_square();
    }

    outputTable.push_back({"µ-σ", muMinusTheta});
    outputTable.push_back({"µ", mu});
    outputTable.push_back({"µ+σ", muAddTheta});
    outputTable.push_back({"µ+2σ", muAdd2Theta});
    outputTable.push_back({"c_square", c_square});
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
    std::cout << center("Criteria", 20) << center("µ-σ", 20) << center("µ", 23) << center("µ+σ", 23) << center("µ+2σ", 23) << center("c square", 25) << center("hops", 18) << std::endl;

    for (size_t categoryIndex = 0; categoryIndex < CATEGORIES.size(); ++categoryIndex) {
        std::cout << center(CATEGORIES[categoryIndex].name, 20);
        for (int i = 0; i < allTables[categoryIndex].size(); ++i) {
            std::cout << center(std::to_string(allTables[categoryIndex][i].second), 20) << " ";
        }
        std::cout << center(std::to_string(allPaths[categoryIndex].size()), 20) << std::endl;

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
            std::cout << center(std::to_string(iter->second[i]), 15) << " ";
        }
        std::cout << std::endl;
    }
}

std::string PerformanceMeasures::center(const std::string s, const int w){
    std::stringstream ss, spaces;
    int padding = w - s.size();                 // count excess room to pad
    for(int i=0; i<padding/2; ++i)
        spaces << " ";
    ss << spaces.str() << s << spaces.str();    // format with padding
    if(padding>0 && padding%2!=0)               // if odd #, add 1 space
        ss << " ";
    return ss.str();
}
