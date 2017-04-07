// data for bitmap file

#ifndef CS5592PROJECT_IMAGEDATA_H
#define CS5592PROJECT_IMAGEDATA_H

#include <vector>
#include <cstddef>
#include <string>

#include "Pixel.h"

class ImageData {
private:
    std::vector<std::vector<Pixel>> pixels;
    size_t width;
    size_t height;

    static void writeHeader(std::ostream &out, size_t width, size_t height);

    static bool endsWith(const std::string& value, const std::string& ending);

public:
    ImageData(size_t _width, size_t _height);

    /** get a reference to one pixel */
    Pixel& get(size_t xLocation, size_t yLocation);

    /** write bitmap file */
    void writeFile(std::string fileName);
};


#endif //CS5592PROJECT_IMAGEDATA_H
