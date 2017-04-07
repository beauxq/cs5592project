//
// Created by Doug on 4/7/2017.
//

#ifndef CS5592PROJECT_GRAPHVISUALIZER_H
#define CS5592PROJECT_GRAPHVISUALIZER_H

#include <cstddef>
#include <vector>
#include <list>

#include "image/ImageData.h"
#include "Graph.hpp"
#include "image/Coordinate.h"

class GraphVisualizer {
private:
    static const size_t WIDTH = 500;
    static const size_t HEIGHT = 300;

    ImageData image;
    Graph* graph;
    std::list<size_t> shortestPath;

    // for scaling color of edges
    double minEdgeValue;
    double maxEdgeValue;
    double difference;

    std::vector<Coordinate> getNodeCoordinates();

    void drawLine(const Coordinate& from, const Coordinate& to, uint8_t varyingColor, bool pathColor);

    /** find min and max values */
    void scaleColor();
    /** get color based off min and max values */
    uint8_t scaleColor(size_t edgeNodeA, size_t edgeNodeB);
public:
    GraphVisualizer(Graph& _graph, const std::list<size_t>& _shortestPath);

    void createImage(const std::string& fileName, bool showShortest);
};


#endif //CS5592PROJECT_GRAPHVISUALIZER_H
