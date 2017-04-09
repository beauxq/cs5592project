//
// Created by doug on 4/8/17.
//

#ifndef CS5592PROJECT_CATEGORIES_H
#define CS5592PROJECT_CATEGORIES_H

#include <string>
#include <vector>

struct Category {
    int number;
    std::string name;

    double (*getCost)(const EdgeWeight&);

    Category(int _number, const std::string& _name, double (*_getCost)(const EdgeWeight&))
            : number(_number), name(_name), getCost(_getCost) {}
};

const std::vector<Category> CATEGORIES = {
        Category(1, "mean", [](const EdgeWeight& edge){ return edge.getMean(); }),
        Category(2, "optimist", [](const EdgeWeight& edge){ return edge.getMean() - sqrt(edge.getVariance()); }),
        Category(3, "pessimist", [](const EdgeWeight& edge){ return edge.getMean() + sqrt(edge.getVariance()); }),
        Category(4, "double pessimist", [](const EdgeWeight& edge){ return edge.getMean() + 2 * sqrt(edge.getVariance()); }),
        Category(5, "stable", [](const EdgeWeight& edge){ return edge.getC_square(); })
};

#endif //CS5592PROJECT_CATEGORIES_H
