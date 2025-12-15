#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <vector>

#include "color.h"
#include "glm/vec2.hpp"

class Image {
    const glm::vec2 size;
    std::vector<Color> pixels;

public:
    Image(int width, int height) : size(width, height), pixels(width * height) {}

    glm::vec2 getSize() const {
        return size;
    }

    Color getPixel(int x, int y) const {
        return pixels[y * size.x + x];
    }

    void setPixel(int x, int y, const Color& color) {
        pixels[y * size.x + x] = color;
    }

    void writeToFile(std::string path);
};

#endif //IMAGE_H
