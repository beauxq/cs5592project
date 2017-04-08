// bmp pixel
// default color white

#ifndef CS5592PROJECT_PIXEL_H
#define CS5592PROJECT_PIXEL_H

struct Pixel {
    unsigned char r;
    unsigned char g;
    unsigned char b;

    Pixel() : r(255), g(255), b(255) {};
    Pixel(unsigned char _r, unsigned char _g, unsigned char _b) : r(_r), g(_g), b(_b) {};
};

#endif //CS5592PROJECT_PIXEL_H
