#ifndef IMAGE_H
#define IMAGE_H

#include <string>
#include <vector>

#include "color.h"
#include "glm/vec2.hpp"


class Image {
    const glm::ivec2 size;
    std::vector<Color> pixels;

public:
    Image(int width, int height) : size(width, height), pixels(width * height) {}

    [[nodiscard]] glm::ivec2 getSize() const {
        return size;
    }

    [[nodiscard]] Color getPixel(int x, int y) const {
        return pixels[y * size.x + x];
    }

    void setPixel(int x, int y, const Color& color) {
        pixels[y * size.x + x] = color;
    }

    void writeToPPM(const std::string& path) const;
};

#endif //IMAGE_H
