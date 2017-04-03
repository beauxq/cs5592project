//
//  InputParser.cpp
//  Dijkstra's shortest uncertain path algorithm
//
//  Created by Ting Xia on 4/2/17.
//  Copyright © 2017 Ting. All rights reserved.
//

#include "InputParser.hpp"
#include <iostream>

EdgeMatrix InputParser::parser(string& fileName){
    EdgeMatrix edge;
    vector<vector<EdgeWeight>> e;
    ifstream infile(fileName);
    while(infile){
        vector<string> lines;
        string s;
        if(!getline(infile, s))
            break;
        istringstream ss(s);
        while (ss) {
            string st;
            if(!getline(ss, st, ','))
               break;
            lines.push_back(st);
        }
        if(lines.size() == 3){
            int size = stoi(lines[0]);
            edge.setNumOfNodes(size);
            edge.setSource(stoi(lines[1]));
            edge.setDestination(stoi(lines[2]));
            e.resize(size);
            for (int i = 0; i < size; i++) {
                e[i].resize(size);
            }
        } else if(lines.size() == 6){
            EdgeWeight entry;
            double mean, variance = 0, c_square = 0;
            int row = stoi(lines[1]) - 1;
            int col = stoi(lines[2]) - 1;
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
                    break;
            }
            
            entry.setMean(mean);
            entry.setVariance(variance);
            entry.setC_square(c_square);
            e[row][col] = entry;
//            e[col][row] = entry;
            
        }

    }
    edge.setE(e);

    return edge;
}
