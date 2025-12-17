#pragma once

#include <string>
#include <vector>

#include "graphics/color.h"
#include "glm/vec2.hpp"


class Image {
    glm::ivec2 _size{};
    std::vector<Color> _pixels;

public:
    Image(int width, int height) : _size(width, height), _pixels(width * height) {}

    explicit Image(const std::string& path);

    [[nodiscard]] glm::ivec2 size() const {
        return _size;
    }

    [[nodiscard]] int width() const {
        return _size.x;
    }

    [[nodiscard]] int height() const {
        return _size.y;
    }

    [[nodiscard]] Color getPixel(int x, int y) const {
        return _pixels[y * _size.x + x];
    }

    void setPixel(int x, int y, const Color& color) {
        _pixels[y * _size.x + x] = color;
    }

    void writeToPPM(const std::string& path) const;
};
