// the algorithm to find paths

#ifndef CS5592PROJECT_DIJKSTRA_H
#define CS5592PROJECT_DIJKSTRA_H

#include <queue>
#include <list>
#include <cstddef>

#include "HeapItem.h"
#include "Graph.hpp"

class Dijkstra {
private:
    Graph graph;
    std::priority_queue<HeapItem> heap;
    std::list<size_t> shortestPath;  // after it's found, it's stored here
    double shortestDistance;  // distance of shortest path stored here after it's found

    void makeShortestPathList(const std::vector<size_t> &shortestPathGraph);
public:
    Dijkstra(const Graph& _graph);

    void findPath(int category);
};


#endif //CS5592PROJECT_DIJKSTRA_H
