#include <iostream>

#include "camera.h"
#include "image.h"

int main() {
    std::cout << "Hello, World!\n";

    constexpr int width = 800;
    constexpr int height = 600;
    Image img(width, height);
    Camera camera(glm::vec3(0, 0, 0), glm::ivec2(width, height));

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            auto ray = camera.pixelToRay(x, y);
            auto color = camera.rayToColor(ray);
            img.setPixel(x, y, color);
        }
    }
    img.writeToPPM("_results/test.ppm");

    return 0;
}
