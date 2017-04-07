//
// Created by Doug on 4/7/2017.
//

#ifndef CS5592PROJECT_GRAPHVISUALIZER_H
#define CS5592PROJECT_GRAPHVISUALIZER_H

#include <cstddef>
#include <vector>

#include "image/ImageData.h"
#include "Graph.hpp"
#include "image/Coordinate.h"

class GraphVisualizer {
private:
    static const size_t WIDTH = 500;
    static const size_t HEIGHT = 300;

    ImageData image;
    Graph* graph;

    std::vector<Coordinate> getNodeCoordinates();
public:
    GraphVisualizer(Graph& _graph);

    void createImage(const std::string& fileName);
};


#endif //CS5592PROJECT_GRAPHVISUALIZER_H
