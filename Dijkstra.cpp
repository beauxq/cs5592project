// implementation for Dijkstra class

#include "Dijkstra.h"

#include <cstddef>
#include <limits>
#include <list>

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
    std::vector<double> distances(graph.getNumOfNodes(), std::numeric_limits<double>::max());
    // set source distance to zero
    distances[graph.getSource()] = 0;

    std::vector<size_t> shortestPathGraph(graph.getNumOfNodes());  // parent of each node

    // put source in the heap
    heap.push(HeapItem(graph.getSource(), distances[graph.getSource()], graph.getSource()));
    while (! heap.empty()) {
        HeapItem currentNode = heap.top();  // this is the next shortest path
        shortestPathGraph[currentNode.nodeIndex] = currentNode.parent;

        if (currentNode.nodeIndex == graph.getDestination()) {
            shortestDistance = currentNode.distance;
            makeShortestPathList(shortestPathGraph);
            return;
        }

        heap.pop();

        // TODO: update adjacent distances
    }

    shortestPath.clear();
}
