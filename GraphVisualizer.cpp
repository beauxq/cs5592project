//
// Created by Doug on 4/7/2017.
//

#include "GraphVisualizer.h"

#include <cmath>

std::vector<Coordinate> GraphVisualizer::getNodeCoordinates() {
    const double topBottomMargin = 30.0;
    const double pi = 3.1415926535897;

    std::vector<Coordinate> toReturn;

    if (! (graph->getNumOfNodes()))
        return toReturn;

    // node 0, probably usually the source
    toReturn.emplace_back(10, HEIGHT * .5);

    int numOfNodesOnEachArc = ((graph->getNumOfNodes()) - 1) / 2;
    bool needSingleNodeOnOtherEnd = graph->getNumOfNodes() == 2 + (2 * numOfNodesOnEachArc);

    // find perpendicular bisector to left and mid-top
    Coordinate leftMid(WIDTH * .25, (HEIGHT * .5 + topBottomMargin) / 2.0);
    double slope = -1.0 / ((topBottomMargin - HEIGHT * .5) / (WIDTH * .5));
    // y = slope * x + b
    // b = y - slope * x

    Coordinate lowerCircleCenter(WIDTH * .5, slope * WIDTH * .5 + (leftMid.y - slope * leftMid.x));
    Coordinate upperCircleCenter(WIDTH * .5, HEIGHT * .5 - (lowerCircleCenter.y - HEIGHT * .5));

    double circleRadius = sqrt(pow(WIDTH * .5, 2) + pow(lowerCircleCenter.y - HEIGHT * .5, 2));

    double totalAngle = 2 * asin(WIDTH * .5 / circleRadius);

    double angleForEachNode = totalAngle / (numOfNodesOnEachArc + 1);

    // polar coordinates, angle 0 is east
    double currentAngle = .5 * pi + (totalAngle * .5);

    Coordinate currentBottomNode;
    Coordinate currentTopNode;

    for (int i = numOfNodesOnEachArc; i > 0; --i) {
        currentAngle -= angleForEachNode;

        // convert polar coordinates to cartesian
        currentBottomNode.x = upperCircleCenter.x + circleRadius * cos(currentAngle);
        currentBottomNode.y = upperCircleCenter.y + circleRadius * sin(currentAngle);

        // top arc is symmetric to bottom
        currentTopNode.x = currentBottomNode.x;
        currentTopNode.y = HEIGHT * .5 - (currentBottomNode.y - HEIGHT * .5);

        toReturn.push_back(currentTopNode);
        toReturn.push_back(currentBottomNode);
    }

    if (needSingleNodeOnOtherEnd)
        toReturn.emplace_back(WIDTH * .98, HEIGHT * .5);

    return toReturn;
}

GraphVisualizer::GraphVisualizer(Graph& _graph) : image(WIDTH, HEIGHT) {
    graph = &_graph;
}

void GraphVisualizer::createImage(const std::string &fileName) {
    ImageData image2(WIDTH, HEIGHT);

    auto nodeCoordinates = getNodeCoordinates();

    // draw edges
    for (auto matrixRowI = graph->getAdjacencyMatrix().begin(); matrixRowI != graph->getAdjacencyMatrix().end(); ++matrixRowI) {
        
    }

    // draw nodes
    for (auto nodeI = nodeCoordinates.begin(); nodeI != nodeCoordinates.end(); ++nodeI) {
        size_t x = (size_t)round(nodeI->x);
        size_t y = (size_t)round(nodeI->y);

        image2.get(x, y).r = 0;
        image2.get(x, y).g = 0;
        image2.get(x, y).b = 0;
        image2.get(x + 1, y).r = 0;
        image2.get(x + 1, y).g = 0;
        image2.get(x + 1, y).b = 0;
        image2.get(x, y + 1).r = 0;
        image2.get(x, y + 1).g = 0;
        image2.get(x, y + 1).b = 0;
        image2.get(x - 1, y).r = 0;
        image2.get(x - 1, y).g = 0;
        image2.get(x - 1, y).b = 0;
        image2.get(x, y - 1).r = 0;
        image2.get(x, y - 1).g = 0;
        image2.get(x, y - 1).b = 0;
    }

    image2.writeFile(fileName);
}
