cmake_minimum_required(VERSION 3.6)
project(cs5592project)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
        main.cpp
        InputParser.cpp
        EdgeWeight.cpp
        Graph.cpp
        DataInputException.h
        HeapItem.h
        Dijkstra.cpp
        image/Pixel.h
        image/ImageData.cpp
        GraphVisualizer.cpp
        image/Coordinate.h
        PerformanceMeasures.cpp
        Categories.h)
add_executable(cs5592project ${SOURCE_FILES})