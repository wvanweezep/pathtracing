#include "image.h"

#include <fstream>
#include <iostream>

#define STB_IMAGE_IMPLEMENTATION
#include "stb/stb_image.h"

Image::Image(const std::string &path) {
    int width, height, channels;
    stbi_uc *data = stbi_load(path.c_str(), &width, &height, &channels, 3);
    _size = glm::ivec2(width, height);
    _pixels = std::vector<Color>(width * height);
    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            const int i = (y * width + x) * 3;
            setPixel(x, y, Color(
                 static_cast<float>(data[i + 0]) / 255.0f,
                 static_cast<float>(data[i + 1]) / 255.0f,
                 static_cast<float>(data[i + 2]) / 255.0f));
        }
    } stbi_image_free(data);
}

void Image::writeToPPM(const std::string& path) const {
    std::ofstream file(path, std::ios::binary);
    if (!file) throw std::runtime_error("Failed to create file: " + path);
    file << "P6\n" << _size.x << ' ' << _size.y << "\n255\n";

    for (int y = 0; y < _size.y; y++) {
        for (int x = 0; x < _size.x; x++) {
            const glm::vec4 c = glm::clamp(_pixels[y * _size.x + x].rgba * 255.0f, 0.0f, 255.0f);
            unsigned char rgb[3] = {
                static_cast<unsigned char>(c.r),
                static_cast<unsigned char>(c.g),
                static_cast<unsigned char>(c.b)};
            file.write(reinterpret_cast<char*>(rgb), 3);
        }
    }

}

