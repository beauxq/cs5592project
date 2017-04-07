// the algorithm to find paths

#ifndef CS5592PROJECT_DIJKSTRA_H
#define CS5592PROJECT_DIJKSTRA_H

#include <list>
#include <cstddef>
#include <vector>
#include <string>

#include "HeapItem.h"
#include "Graph.hpp"

class Dijkstra {
private:
    static const double infinity;

    Graph graph;
    std::list<size_t> shortestPath;  // after it's found, it's stored here
    double shortestDistance;  // distance of shortest path stored here after it's found

    void makeShortestPathList(const std::vector<size_t> &shortestPathGraph);
public:
    Dijkstra(const Graph& _graph);

    void findPath(int category);

    double getShortestDistance() const;
    const std::list<size_t>& getShortestPath() const;
    std::string getShortestPathString() const;
};


#endif //CS5592PROJECT_DIJKSTRA_H
