// implementation of GraphVisualizer class

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

    size_t numOfNodesOnEachArc = ((graph->getNumOfNodes()) - 1) / 2;
    bool needSingleNodeOnOtherEnd = graph->getNumOfNodes() == 2 + (2 * numOfNodesOnEachArc);

    // find perpendicular bisector to left and mid-bottom
    Coordinate leftMid(WIDTH * .25, (HEIGHT * .5 + topBottomMargin) / 2.0);
    double slope = -1.0 / ((topBottomMargin - HEIGHT * .5) / (WIDTH * .5));
    // y = slope * x + b
    // b = y - slope * x

    Coordinate upperCircleCenter(WIDTH * .5, slope * WIDTH * .5 + (leftMid.y - slope * leftMid.x));
    Coordinate lowerCircleCenter(WIDTH * .5, HEIGHT * .5 - (upperCircleCenter.y - HEIGHT * .5));

    double circleRadius = sqrt(pow(WIDTH * .5, 2) + pow(upperCircleCenter.y - HEIGHT * .5, 2));

    double totalAngle = 2 * asin(WIDTH * .5 / circleRadius);

    double angleForEachNode = totalAngle / (numOfNodesOnEachArc + 1);

    // polar coordinates, angle 0 is east
    double currentAngle = .5 * pi + (totalAngle * .5);

    Coordinate currentTopNode;
    Coordinate currentBottomNode;

    for (int i = (int)numOfNodesOnEachArc; i > 0; --i) {
        currentAngle -= angleForEachNode;

        // convert polar coordinates to cartesian
        currentTopNode.x = lowerCircleCenter.x + circleRadius * cos(currentAngle);
        currentTopNode.y = lowerCircleCenter.y + circleRadius * sin(currentAngle);

        // top arc is symmetric to bottom
        currentBottomNode.x = currentTopNode.x;
        currentBottomNode.y = HEIGHT * .5 - (currentTopNode.y - HEIGHT * .5);

        toReturn.push_back(currentTopNode);
        toReturn.push_back(currentBottomNode);
    }

    if (needSingleNodeOnOtherEnd)
        toReturn.emplace_back(WIDTH * .98, HEIGHT * .5);

    return toReturn;
}

void GraphVisualizer::drawEdge(const Coordinate &from, const Coordinate &to, uint8_t varyingColor, bool pathColor) {
    Pixel color(varyingColor,  //(unsigned char)(127 * varyingColor / 2),
                (unsigned char)(127 + (255 - varyingColor) / 2),
                (unsigned char)(pathColor ? 255 : 0));

    image.drawLine(from, to, color, pathColor ? 2 : 1);
}


void GraphVisualizer::drawNode(size_t x, size_t y) {
    Pixel black(0, 0, 0);

    for (size_t xi = x - 3; xi < x + 4; ++xi) {
        for (size_t yi = y - 3; yi < y + 4; ++yi) {
            image.get(xi, yi) = black;
        }
    }

    // middle back to white
    image.get(x, y) = Pixel();
}


void GraphVisualizer::scaleColor() {
    minEdgeValue = INFINITY;
    maxEdgeValue = 0;

    for (auto matrixRowI = graph->getAdjacencyMatrix().begin();
         matrixRowI != graph->getAdjacencyMatrix().end();
         ++ matrixRowI)
    {
        for (auto edgeI = matrixRowI->begin(); edgeI != matrixRowI->end(); ++edgeI) {
            if (edgeI->getEdgePresent()) {
                if (edgeI->getMean() < minEdgeValue)
                    minEdgeValue = edgeI->getMean();
                if (edgeI->getMean() > maxEdgeValue)
                    maxEdgeValue = edgeI->getMean();
            }
        }
    }

    difference = maxEdgeValue - minEdgeValue;
}

uint8_t GraphVisualizer::scaleColor(size_t edgeNodeA, size_t edgeNodeB) {
    double mean = graph->getAdjacencyMatrix()[edgeNodeA][edgeNodeB].getMean();
    return (uint8_t)((mean - minEdgeValue) / difference * 255);
}

GraphVisualizer::GraphVisualizer(Graph& _graph, const std::list<size_t>& _shortestPath) : image(WIDTH, HEIGHT) {
    graph = &_graph;
    shortestPath = _shortestPath;
}

void GraphVisualizer::createImage(const std::string &fileName, bool showShortest=false) {
    auto nodeCoordinates = getNodeCoordinates();
    scaleColor();

    // draw edges
    for (size_t matrixRow = 0; matrixRow < graph->getNumOfNodes(); ++matrixRow) {
        for (size_t matrixCol = matrixRow + 1; matrixCol < graph->getNumOfNodes(); ++matrixCol) {
            if (graph->getAdjacencyMatrix()[matrixRow][matrixCol].getEdgePresent()) {
                drawEdge(nodeCoordinates[matrixRow],
                         nodeCoordinates[matrixCol],
                         scaleColor(matrixRow, matrixCol),
                         false);

            }
        }
    }

    // draw shortest path
    if (showShortest && (! shortestPath.empty())) {
        auto nodeI = shortestPath.begin();
        size_t previousNode = *nodeI;
        ++nodeI;

        while (nodeI != shortestPath.end()) {
            drawEdge(nodeCoordinates[previousNode],
                     nodeCoordinates[*nodeI],
                     127,
                     true);

            previousNode = *nodeI;
            ++nodeI;
        }
    }

    // draw nodes
    for (auto nodeI = nodeCoordinates.begin(); nodeI != nodeCoordinates.end(); ++nodeI) {
        size_t x = (size_t)round(nodeI->x);
        size_t y = (size_t)round(nodeI->y);

        drawNode(x, y);
    }
#ifdef _WIN32
    image.writeFileBMP(fileName);
#else
    image.writeFilePPM(fileName);
#endif
}
