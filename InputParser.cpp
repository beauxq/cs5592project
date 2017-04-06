//
//  InputParser.cpp
//  Dijkstra's shortest uncertain path algorithm
//
//  Created by Ting Xia on 4/2/17.
//  Copyright © 2017 Ting. All rights reserved.
//

#include "InputParser.hpp"

#include <stdio.h>
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <math.h>

#include "Graph.hpp"
#include "DataInputException.h"

Graph InputParser::getGraphFromFile(const std::string &fileName){
    Graph graph;
    std::vector<std::vector<EdgeWeight>> adjacencyMatrix;
    std::ifstream infile(fileName);
    if (! infile) {
        throw DataInputException("unable to open file");
    }
    while(infile){
        std::vector<std::string> lines;
        std::string lineFromFile;
        if(!getline(infile, lineFromFile))
            break;
        std::istringstream ss(lineFromFile);
        while (ss) {
            std::string value;
            if(!getline(ss, value, ','))
               break;
            lines.push_back(value);
        }
        if(lines.size() == 3){
            size_t numOfNodes = (size_t)stoi(lines[0]);
            graph.setNumOfNodes(numOfNodes);
            graph.setSource((size_t)(stoi(lines[1]) - 1));
            graph.setDestination((size_t)(stoi(lines[2]) - 1));
            adjacencyMatrix.resize(numOfNodes);
            for (int i = 0; i < numOfNodes; i++) {
                adjacencyMatrix[i].resize(numOfNodes);
            }
        } else if(lines.size() == 6){
            EdgeWeight entry;
            double mean, variance = 0, c_square = 0;
            int row = stoi(lines[1]) - 1;
            int col = stoi(lines[2]) - 1;

            if (row >= graph.getNumOfNodes() || col >= graph.getNumOfNodes()) {
                throw DataInputException("invalid node numbers on edges");
            }

            int type = stoi(lines[3]);
            double alpha = stod(lines[4]);
            double beta = stod(lines[5]);
            switch (type) {
                case 1:
                    mean = alpha;
                    break;
                case 2:
                    mean = (alpha + beta) / 2.0;
                    variance = pow(beta - alpha, 2.0) / 12.0;
                    c_square = (1.0 / 3.0) * ((beta - alpha) / (beta + alpha), 2.0);
                    break;
                case 3:
                    mean = 1 / alpha;
                    variance = 1.0 / pow(alpha, 2.0);
                    c_square = 1;
                    break;
                case 4:
                    mean = beta + 1.0 / alpha;
                    variance = 1.0 / pow(alpha, 2.0);
                    c_square = pow(1.0 / (1.0 + alpha * beta), 2.0);
                    break;
                case 5:
                    mean = alpha;
                    variance = beta;
                    c_square = beta / pow(alpha, 2.0);
                    break;
                case 6:
                    mean = alpha;
                    variance = pow(alpha, 2.0) * beta;
                    c_square = beta;
                    break;
                default:
                    throw DataInputException("edge type is not 1 through 6");
            }

            if (adjacencyMatrix[row][col].getEdgePresent()) {
                throw DataInputException("multiple data sets given for one edge: " +
                                         std::to_string(row) + " " + std::to_string(col));
            }

            entry.setEdgePresent(true);
            entry.setMean(mean);
            entry.setVariance(variance);
            entry.setC_square(c_square);
            adjacencyMatrix[row][col] = entry;
            adjacencyMatrix[col][row] = entry;  // information in both directions
            
        } else {
            throw DataInputException("line has wrong number of values (not 3 or 6)");
        }

    }
    graph.setAdjacencyMatrix(adjacencyMatrix);

    return graph;
}
