//
//  EdgeWeight.cpp
//  Dijkstra's shortest uncertain path algorithm
//
//  Created by Ting Xia on 4/2/17.
//  Copyright © 2017 Ting. All rights reserved.
//

#include "EdgeWeight.hpp"

double EdgeWeight::getMean(){
    return mean;
}

void EdgeWeight::setMean(double meanValue){
    mean = meanValue;
}

double EdgeWeight::getVariance(){
    return variance;
}

void EdgeWeight::setVariance(double varianceValue){
    variance = varianceValue;
}

double EdgeWeight::getC_square(){
    return c_square;
}

void EdgeWeight::setC_square(double c_squareValue){
    c_square = c_squareValue;
}
