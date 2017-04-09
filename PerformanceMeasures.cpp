//
//  PerformanceMeasures.cpp
//  Dijkstra's shortest uncertain path algorithm
//
//  Created by Ting Xia on 4/7/17.
//  Copyright © 2017 Ting. All rights reserved.
//

#include "PerformanceMeasures.hpp"

void PerformanceMeasures::ComparePathsAndCheckEdge(Graph graph){
    Dijkstra algorithm(graph);
    
    std::vector<std::pair<std::string, double>> meanValue, optimist, pessimist, doublyPess, stable;
    double muMinusTheta = 0, mu = 0, muAddTheta = 0, muAdd2Theta = 0, c_square = 0;
    
    // map for edge information
    std::unordered_map<std::string, std::vector<std::string>> edgeMap;
    // map for edge selection
    std::unordered_map<std::string, std::vector<bool>> edgeSelMap;
    
    // find the Mean value
    algorithm.findPath(1);
    std::cout << "Result for mean value:" << std::endl;
    std::cout << "Shortest path: " << algorithm.getShortestPathString() << std::endl;
    std::cout << "Shortest distance: " << algorithm.getShortestDistance() << std::endl;
    std::list<size_t> meanPath = algorithm.getShortestPath();
    
    auto m_iter2 = meanPath.begin();
    m_iter2++;
    for (auto iter = meanPath.begin(); m_iter2 != meanPath.end(); ++iter, m_iter2++) {
        std::string edgeString = std::to_string(*iter) + "→" + std::to_string(*m_iter2);
        if (!edgeMap.count(edgeString))
            edgeMap[edgeString] = std::vector<std::string>();
        edgeMap[edgeString].push_back("Mean value");
        EdgeWeight edge = graph.getAdjacencyMatrix()[*iter][*m_iter2];
        muMinusTheta += edge.getMean() - sqrt(edge.getVariance());
        mu += edge.getMean();
        muAddTheta += edge.getMean() + sqrt(edge.getVariance());
        muAdd2Theta += edge.getMean() + 2 * sqrt(edge.getVariance());
        c_square += edge.getC_square();
    }

    meanValue.push_back({"µ-σ", muMinusTheta});
    meanValue.push_back({"µ", mu});
    meanValue.push_back({"µ+σ", muAddTheta});
    meanValue.push_back({"µ+2σ", muAdd2Theta});
    meanValue.push_back({"c_square", c_square});
    
    muMinusTheta = 0, mu = 0, muAddTheta = 0, muAdd2Theta = 0, c_square = 0;
    
    // find optimist
    algorithm.findPath(2);
    std::cout << "Result for optimist:" << std::endl;
    std::cout << "Shortest path: " << algorithm.getShortestPathString() << std::endl;
    std::cout << "Shortest distance: " << algorithm.getShortestDistance() << std::endl;
    std::list<size_t> optimistPath = algorithm.getShortestPath();
    auto o_iter2 = optimistPath.begin();
    o_iter2++;
    for (auto iter = optimistPath.begin(); o_iter2 != optimistPath.end(); ++iter, o_iter2++) {
        std::string edgeString = std::to_string(*iter) + "→" + std::to_string(*o_iter2);
        if (!edgeMap.count(edgeString))
            edgeMap[edgeString] = std::vector<std::string>();
        edgeMap[edgeString].push_back("optimist");
        EdgeWeight edge = graph.getAdjacencyMatrix()[*iter][*o_iter2];
        muMinusTheta += edge.getMean() - sqrt(edge.getVariance());
        mu += edge.getMean();
        muAddTheta += edge.getMean() + sqrt(edge.getVariance());
        muAdd2Theta += edge.getMean() + 2 * sqrt(edge.getVariance());
        c_square += edge.getC_square();
    }
    optimist.push_back({"µ-σ", muMinusTheta});
    optimist.push_back({"µ", mu});
    optimist.push_back({"µ+σ", muAddTheta});
    optimist.push_back({"µ+2σ", muAdd2Theta});
    optimist.push_back({"c_square", c_square});
    
    muMinusTheta = 0, mu = 0, muAddTheta = 0, muAdd2Theta = 0, c_square = 0;
    
    // find pessimist
    algorithm.findPath(3);
    std::cout << "Result for pessimist:" << std::endl;
    std::cout << "Shortest path: " << algorithm.getShortestPathString() << std::endl;
    std::cout << "Shortest distance: " << algorithm.getShortestDistance() << std::endl;
    std::list<size_t> pessimistPath = algorithm.getShortestPath();
    
    auto p_iter2 = pessimistPath.begin();
    p_iter2++;
    for (auto iter = pessimistPath.begin(); p_iter2 != pessimistPath.end(); ++iter, p_iter2++) {
        std::string edgeString = std::to_string(*iter) + "→" + std::to_string(*p_iter2);
        if (!edgeMap.count(edgeString))
            edgeMap[edgeString] = std::vector<std::string>();
        edgeMap[edgeString].push_back("pessimist");
        EdgeWeight edge = graph.getAdjacencyMatrix()[*iter][*p_iter2];
        muMinusTheta += edge.getMean() - sqrt(edge.getVariance());
        mu += edge.getMean();
        muAddTheta += edge.getMean() + sqrt(edge.getVariance());
        muAdd2Theta += edge.getMean() + 2 * sqrt(edge.getVariance());
        c_square += edge.getC_square();
    }
    pessimist.push_back({"µ-σ", muMinusTheta});
    pessimist.push_back({"µ", mu});
    pessimist.push_back({"µ+σ", muAddTheta});
    pessimist.push_back({"µ+2σ", muAdd2Theta});
    pessimist.push_back({"c_square", c_square});
    
    muMinusTheta = 0, mu = 0, muAddTheta = 0, muAdd2Theta = 0, c_square = 0;
    
    // find double pessimist
    algorithm.findPath(4);
    std::cout << "Result for double pessimist:" << std::endl;
    std::cout << "Shortest path: " << algorithm.getShortestPathString() << std::endl;
    std::cout << "Shortest distance: " << algorithm.getShortestDistance() << std::endl;
    std::list<size_t> doublyPessPath = algorithm.getShortestPath();
    
    auto d_iter2 = doublyPessPath.begin();
    d_iter2++;
    for (auto iter = doublyPessPath.begin(); d_iter2 != doublyPessPath.end(); ++iter, d_iter2++) {
        std::string edgeString = std::to_string(*iter) + "→" + std::to_string(*d_iter2);
        if (!edgeMap.count(edgeString))
            edgeMap[edgeString] = std::vector<std::string>();
        edgeMap[edgeString].push_back("doubly pessimist");
        EdgeWeight edge = graph.getAdjacencyMatrix()[*iter][*d_iter2];
        muMinusTheta += edge.getMean() - sqrt(edge.getVariance());
        mu += edge.getMean();
        muAddTheta += edge.getMean() + sqrt(edge.getVariance());
        muAdd2Theta += edge.getMean() + 2 * sqrt(edge.getVariance());
        c_square += edge.getC_square();
    }
    doublyPess.push_back({"µ-σ", muMinusTheta});
    doublyPess.push_back({"µ", mu});
    doublyPess.push_back({"µ+σ", muAddTheta});
    doublyPess.push_back({"µ+2σ", muAdd2Theta});
    doublyPess.push_back({"c_square", c_square});
    
    muMinusTheta = 0, mu = 0, muAddTheta = 0, muAdd2Theta = 0, c_square = 0;
    
    // find the stable
    algorithm.findPath(5);
    std::cout << "Result for stable:" << std::endl;
    std::cout << "Shortest path: " << algorithm.getShortestPathString() << std::endl;
    std::cout << "Shortest distance: " << algorithm.getShortestDistance() << std::endl;
    std::list<size_t> stablePath = algorithm.getShortestPath();
    
    auto s_iter2 = stablePath.begin();
    s_iter2++;
    for (auto iter = stablePath.begin(); s_iter2 != stablePath.end(); ++iter, s_iter2++) {
        std::string edgeString = std::to_string(*iter) + "→" + std::to_string(*s_iter2);
        if (!edgeMap.count(edgeString))
            edgeMap[edgeString] = std::vector<std::string>();
        edgeMap[edgeString].push_back("stable");
        EdgeWeight edge = graph.getAdjacencyMatrix()[*iter][*s_iter2];
        muMinusTheta += edge.getMean() - sqrt(edge.getVariance());
        mu += edge.getMean();
        muAddTheta += edge.getMean() + sqrt(edge.getVariance());
        muAdd2Theta += edge.getMean() + 2 * sqrt(edge.getVariance());
        c_square += edge.getC_square();
    }
    stable.push_back({"µ-σ", muMinusTheta});
    stable.push_back({"µ", mu});
    stable.push_back({"µ+σ", muAddTheta});
    stable.push_back({"µ+2σ", muAdd2Theta});
    stable.push_back({"c_square", c_square});

    // print the two table
    // performance table
    std::cout << center("Criteria", 20) << center("µ-σ", 20) << center("µ", 23) << center("µ+σ", 23) << center("µ+2σ", 23) << center("c square", 25) << center("hops", 18) << std::endl;
    
    std::cout << center("Mean value", 20);
    for (int i = 0; i < meanValue.size(); i++) {
        std::cout << center(std::to_string(meanValue[i].second), 20) << " ";
    }
    std::cout << center(std::to_string(meanPath.size()), 20) << std::endl;
    
    std::cout << center("Optimist", 20);
    for (int i = 0; i < optimist.size(); i++) {
        std::cout << center(std::to_string(optimist[i].second), 20) << " ";
    }
    std::cout << center(std::to_string(optimistPath.size()), 20) << std::endl;
    
    std::cout << center("Pessimist", 20);
    for (int i = 0; i < pessimist.size(); i++) {
        std::cout << center(std::to_string(pessimist[i].second), 20) << " ";
    }
    std::cout << center(std::to_string(pessimistPath.size()), 20) << std::endl;
    
    std::cout << center("Doubly pess", 20);
    for (int i = 0; i < doublyPess.size(); i++) {
        std::cout << center(std::to_string(doublyPess[i].second), 20) << " ";
    }
    std::cout << center(std::to_string(doublyPessPath.size()), 20) << std::endl;
    
    std::cout << center("C square", 20);
    for (int i = 0; i < stable.size(); i++) {
        std::cout << center(std::to_string(stable[i].second), 20) << " ";
    }
    std::cout << center(std::to_string(stablePath.size()), 20) << std::endl;
    
    // print edge table
    for (std::unordered_map<std::string, std::vector<std::string>>:: iterator iter = edgeMap.begin(); iter != edgeMap.end(); iter++) {
        // vector for edge information
        std::vector<bool> edgeSelection(5, false);
        for (int i = 0; i < iter->second.size(); i++) {
            if (iter->second[i] == "Mean value")
                edgeSelection[0] = true;
            else if(iter->second[i] == "optimist")
                edgeSelection[1] = true;
            else if(iter->second[i] == "pessimist")
                edgeSelection[2] = true;
            else if (iter->second[i] == "doubly pessimist")
                edgeSelection[3] = true;
            else if (iter->second[i] == "stable")
                edgeSelection[4] = true;
        }
        edgeSelMap[iter->first] = edgeSelection;
    }
    std::cout << center("Edge", 10) << center("Mean value", 15) << center("Optimist", 15) << center("Pessimist", 15) << center("Doubly pess", 15) << center("Stable", 15) << std::endl;
    for (std::unordered_map<std::string, std::vector<bool>>:: iterator iter = edgeSelMap.begin(); iter != edgeSelMap.end(); iter++) {
        std::cout << center(iter->first, 10);
        for (int i = 0; i < 5; i++) {
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

