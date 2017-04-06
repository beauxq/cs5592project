//
//  EdgeWeight.hpp
//  Dijkstra's shortest uncertain path algorithm
//
//  Created by Ting Xia on 4/2/17.
//  Copyright © 2017 Ting. All rights reserved.
//

#ifndef EdgeWeight_hpp
#define EdgeWeight_hpp

class EdgeWeight{
private:
    double mean;
    double variance;
    double c_square;
    bool edgePresent;
public:
    EdgeWeight();

    double getMean() const;
    double getVariance() const;
    double getC_square() const;
    bool getEdgePresent() const;
    void setMean(double meanValue);
    void setVariance(double varianceValue);
    void setC_square(double c_squareValue);
    void setEdgePresent(bool edgePresentValue);
};

#endif /* EdgeWeight_hpp */
