//
//  InputParser.hpp
//  Dijkstra's shortest uncertain path algorithm
//
//  Created by Ting Xia on 4/2/17.
//  Copyright © 2017 Ting. All rights reserved.
//

#ifndef InputParser_hpp
#define InputParser_hpp

#include <string>

#include "EdgeMatrix.hpp"

class InputParser{
public:
    static EdgeMatrix getGraphFromFile(const std::string &fileName);
};

#endif /* InputParser_hpp */
