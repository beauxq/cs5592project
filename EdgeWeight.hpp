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
public:
    double getMean() const;
    double getVariance() const;
    double getC_square() const;
    void setMean(double meanValue);
    void setVariance(double varianceValue);
    void setC_square(double c_squareValue);
};

#endif /* EdgeWeight_hpp */
