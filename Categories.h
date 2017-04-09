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

    Category(int _number, const std::string& _name) : number(_number), name(_name) {}
};

const std::vector<Category> CATEGORIES = {
        Category(1, "mean"),
        Category(2, "optimist"),
        Category(3, "pessimist"),
        Category(4, "double pessimist"),
        Category(5, "stable")
};

#endif //CS5592PROJECT_CATEGORIES_H
