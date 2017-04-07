// implementation fo ImageData class

#include "ImageData.h"

#include <iostream>
#ifdef _WIN32
#include <windows.h>
#endif
#include <cstring>
#include <fstream>
#include <algorithm>

#ifdef _WIN32
/**
 *  this function from
 *  http://stackoverflow.com/questions/18838553/c-how-to-create-a-bitmap-file
 */
void ImageData::writeHeaderBMP(std::ostream& out, size_t width, size_t height){
    if (width % 4 != 0) {
        std::cerr << "ERROR: There is a windows-imposed requirement on BMP that the width be a multiple of 4.\n";
        std::cerr << "Your width does not meet this requirement, hence this will fail.  You can fix this\n";
        std::cerr << "by increasing the width to a multiple of 4." << std:: endl;
        exit(1);
    }

    BITMAPFILEHEADER tWBFH;
    tWBFH.bfType = 0x4d42;
    tWBFH.bfSize = 14 + 40 + (width*height*3);
    tWBFH.bfReserved1 = 0;
    tWBFH.bfReserved2 = 0;
    tWBFH.bfOffBits = 14 + 40;

    BITMAPINFOHEADER tW2BH;
    memset(&tW2BH,0,40);
    tW2BH.biSize = 40;
    tW2BH.biWidth = (LONG)width;
    tW2BH.biHeight = (LONG)height;
    tW2BH.biPlanes = 1;
    tW2BH.biBitCount = 24;
    tW2BH.biCompression = 0;

    out.write((char*)(&tWBFH),14);
    out.write((char*)(&tW2BH),40);
}
#endif

void ImageData::writeHeaderPPM(std::ostream& out, size_t width, size_t height){
    out << "P3\n" << width << std::endl << height << std::endl << "255" << '\n';
}

/** http://stackoverflow.com/questions/874134/find-if-string-ends-with-another-string-in-c */
bool ImageData::endsWith(const std::string& value, const std::string& ending)
{
    if (ending.size() > value.size()) return false;
    return std::equal(ending.rbegin(), ending.rend(), value.rbegin());
}


ImageData::ImageData(size_t _width, size_t _height) {
    width = _width;
    height = _height;
    for (size_t i = height; i > 0; --i) {
        pixels.emplace_back(width);
    }
}

Pixel& ImageData::get(size_t xLocation, size_t yLocation) {
    return pixels[yLocation][xLocation];
}

#ifdef _WIN32
void ImageData::writeFileBMP(std::string fileName) {
    if (! endsWith(fileName, ".bmp"))
        fileName += ".bmp";

    std::ofstream ofs;
    ofs.open(fileName);
    writeHeaderBMP(ofs, width, height);

    for(auto pixelRowI = pixels.begin(); pixelRowI != pixels.end(); ++pixelRowI) {
        for (auto pixelI = pixelRowI->begin(); pixelI != pixelRowI->end(); ++ pixelI) {
            ofs << pixelI->b << pixelI->g << pixelI->r;
        }
    }
}
#endif  // _WIN32

void ImageData::writeFilePPM(std::string fileName) {
    if (! endsWith(fileName, ".ppm"))
        fileName += ".ppm";

    std::ofstream ofs;
    ofs.open(fileName);
    writeHeaderPPM(ofs, width, height);

    for(auto pixelRowI = pixels.rbegin(); pixelRowI != pixels.rend(); ++pixelRowI) {
        for (auto pixelI = pixelRowI->begin(); pixelI != pixelRowI->end(); ++ pixelI) {
            ofs << (int)pixelI->r << ' ' << (int)pixelI->g << ' ' << (int)pixelI->b << '\n';
        }
    }
}
