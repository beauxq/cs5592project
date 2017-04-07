// struct for cartesian coordinates

#ifndef CS5592PROJECT_COORDINATE_H
#define CS5592PROJECT_COORDINATE_H

struct Coordinate {
    double x;
    double y;

    Coordinate() : x(0), y(0) {}
    Coordinate(double _x, double _y) : x(_x), y(_y) {}
};

#endif //CS5592PROJECT_COORDINATE_H
