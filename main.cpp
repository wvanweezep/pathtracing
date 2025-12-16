#include <iostream>

#include "camera.h"
#include "image.h"
#include "mesh/mesh.h"
#include "mesh/sphere.h"

int main() {
    std::cout << "Hello, World!\n";

    constexpr int width = 800;
    constexpr int height = 600;

    Image img(width, height);
    Camera camera(glm::vec3(0, 0, 0), glm::ivec2(width, height));
    Sphere sphere(glm::vec3(0, 0.0f, -3.0f), 1.0f);

    for (int y = 0; y < height; y++) {
        for (int x = 0; x < width; x++) {
            HitInfo hitInfo{};
            Ray ray = camera.pixelToRay(x, y);
            auto color = sphere.collide(ray, 0, 100, hitInfo) ?
                Color(hitInfo.normal) : camera.rayToColor(ray);
            img.setPixel(x, y, color);
        }
    }
    img.writeToPPM("_results/test.ppm");

    return 0;
}
