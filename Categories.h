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
    std::string functionString;

    double (*getCost)(const EdgeWeight&);

    Category(int _number,
             const std::string& _name,
             const std::string& _functionString,
             double (*_getCost)(const EdgeWeight&))
        : number(_number),
          name(_name),
          functionString(_functionString),
          getCost(_getCost) {}
};

#ifdef _WIN32
// unicode is buggy in windows
const std::vector<std::string> functionNames = {
        "mean",
        "mean - std",
        "mean + std",
        "mean + 2 std",
        "c squared"
};
#else  // not windows
const std::vector<std::string> functionNames = {
        "µ",
        "µ-σ",
        "µ+σ",
        "µ+2σ",
        "c squared"
};
#endif

const std::vector<Category> CATEGORIES = {
        Category(1, "mean", functionNames[0], [](const EdgeWeight& edge){ return edge.getMean(); }),
        Category(2, "optimist", functionNames[1], [](const EdgeWeight& edge){ return edge.getMean() - sqrt(edge.getVariance()); }),
        Category(3, "pessimist", functionNames[2], [](const EdgeWeight& edge){ return edge.getMean() + sqrt(edge.getVariance()); }),
        Category(4, "double pessimist", functionNames[3], [](const EdgeWeight& edge){ return edge.getMean() + 2 * sqrt(edge.getVariance()); }),
        Category(5, "stable", functionNames[4], [](const EdgeWeight& edge){ return edge.getC_square(); })
};

#endif //CS5592PROJECT_CATEGORIES_H
