// a node, its distance, and its parent

#ifndef CS5592PROJECT_HEAPITEM_H
#define CS5592PROJECT_HEAPITEM_H

#include <cstddef>

struct HeapItem {
    size_t nodeIndex;  // 0 to n-1
    double distance;  // from source
    size_t  parent;

    HeapItem()
            : nodeIndex(0), distance(0), parent(0) {};

    HeapItem(size_t _index, double _distance, size_t _parent)
            : nodeIndex(_index), distance(_distance), parent(_parent) {};

    /** less than operator for max heap, when we want min heap */
    bool operator< (const HeapItem& rhs) const { return rhs.distance < distance; }
};

#endif //CS5592PROJECT_HEAPITEM_H
