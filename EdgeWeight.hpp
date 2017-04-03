//
//  EdgeWeight.hpp
//  Dijkstra's shortest uncertain path algorithm
//
//  Created by Ting Xia on 4/2/17.
//  Copyright © 2017 Ting. All rights reserved.
//

#ifndef EdgeWeight_hpp
#define EdgeWeight_hpp

#include <stdio.h>

class EdgeWeight{
private:
    double mean;
    double variance;
    double c_square;
public:
    double getMean();
    double getVariance();
    double getC_square();
    void setMean(double meanValue);
    void setVariance(double varianceValue);
    void setC_square(double c_squareValue);
};

#endif /* EdgeWeight_hpp */
