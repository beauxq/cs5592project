// implementation for Dijkstra class

#include "Dijkstra.h"

#include <cstddef>
#include <limits>
#include <list>
#include <queue>
#include <cmath>

#include "Graph.hpp"

constexpr double Dijkstra::infinity = std::numeric_limits<double>::max();

void Dijkstra::makeShortestPathList(const std::vector<size_t> &shortestPathGraph) {
    size_t index = graph.getDestination();
    shortestPath.clear();
    
    // put final destination at the end
    shortestPath.push_back(index);
    
    while (index != graph.getSource()) {
        // move index to parent
        index = shortestPathGraph[index];
        // put current node in front
        shortestPath.push_front(index);
    }
}

Dijkstra::Dijkstra(const Graph& _graph) {
    graph = _graph;
}

void Dijkstra::findPath(int category) {
    // set all distances to infinity
    std::vector<double> distances(graph.getNumOfNodes(), infinity);
    // set source distance to zero
    distances[graph.getSource()] = 0;

    std::priority_queue<HeapItem> heap;
    std::vector<size_t> shortestPathGraph(graph.getNumOfNodes());  // parent of each node
    std::vector<bool> visited(graph.getNumOfNodes());  // (color black)

    // put source in the heap
    heap.emplace(graph.getSource(), distances[graph.getSource()], graph.getSource());
    while (! heap.empty()) {
        HeapItem currentNode;
        // pull nodes from the heap until finding one that is not visited
        do {
            currentNode = heap.top();
            heap.pop();
        } while (visited[currentNode.nodeIndex]);
        // this is the next shortest path

        // now we know this node's parent
        shortestPathGraph[currentNode.nodeIndex] = currentNode.parent;

        if (currentNode.nodeIndex == graph.getDestination()) {
            shortestDistance = currentNode.distance;
            makeShortestPathList(shortestPathGraph);
            return;
        }

        visited[currentNode.nodeIndex] = true;

        // update adjacent distances
        for (size_t i = 0; i < graph.getNumOfNodes(); ++i) {
            if ((! visited[i]) && graph.getAdjacencyMatrix()[currentNode.nodeIndex][i].getEdgePresent()) {
                // cost depends on category
                double cost;
                EdgeWeight edge = graph.getAdjacencyMatrix()[currentNode.nodeIndex][i];
                switch (category) {
                    case 1:
                        cost = edge.getMean();
                        break;
                    case 2:
                        cost = edge.getMean() - sqrt(edge.getVariance());
                        break;
                    case 3:
                        cost = edge.getMean() + sqrt(edge.getVariance());
                        break;
                    case 4:
                        cost = edge.getMean() + 2 * sqrt(edge.getVariance());
                        break;
                    case 5:
                        cost = edge.getC_square();
                        break;
                    default:
                        throw 1;  // TODO: make exception
                }

                if (distances[currentNode.nodeIndex] + cost < distances[i]) {
                    distances[i] = distances[currentNode.nodeIndex] + cost;
                    heap.emplace(i, distances[i], currentNode.nodeIndex);
                }
            }
        }
    }

    // if we get here there is no path (graph not connected?)
    shortestPath.clear();
    shortestDistance = infinity;
}

const std::list<size_t>& Dijkstra::getShortestPath() const {
    return shortestPath;
}

double Dijkstra::getShortestDistance() const {
    return shortestDistance;
}

std::string Dijkstra::getShortestPathString() const {
    std::string toReturn;
    for (auto iter = shortestPath.begin(); iter != shortestPath.end(); ++iter) {
        toReturn += std::to_string(*iter);
        if (*iter != graph.getDestination()) {
            toReturn += ", ";
        }
    }

    return toReturn;
}
