//
//  InputParser.hpp
//  Dijkstra's shortest uncertain path algorithm
//
//  Created by Ting Xia on 4/2/17.
//  Copyright © 2017 Ting. All rights reserved.
//

#ifndef InputParser_hpp
#define InputParser_hpp

#include <stdio.h>
#include "EdgeMatrix.hpp"
#include <sstream>
#include <fstream>
#include <math.h>

class InputParser{
public:
    EdgeMatrix parser(const std::string& fileName);
};

#endif /* InputParser_hpp */
