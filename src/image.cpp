#include "image.h"

#include <fstream>
#include <iostream>

void Image::writeToPPM(const std::string& path) const {
    std::ofstream file(path);
    if (!file) throw std::runtime_error("Failed to create file: " + path);
    file << "P3\n" << size.x << ' ' << size.y << "\n255\n";

    std::cout << "Writing Image...\n";
    for (int y = 0; y < size.y; y++) {
        for (int x = 0; x < size.x; x++) {
            const glm::vec4 c = glm::clamp(pixels[y * size.x + x].rgba * 255.0f, 0.0f, 255.0f);
            file << static_cast<int>(c.r) << ' ' << static_cast<int>(c.g) << ' ' << static_cast<int>(c.b) << ' ';
        }
    }

    std::cout << "Finished writing image to \"" + path + '"';
}

