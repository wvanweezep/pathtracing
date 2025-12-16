#include <iostream>

#include "camera.h"
#include "image.h"
#include "scene.h"
#include "mesh/mesh.h"
#include "mesh/sphere.h"

int main() {
    std::cout << "Hello, World!\n";

    constexpr int width = 2560;
    constexpr int height = 1440;
    Image image(width, height);

    Camera camera(glm::vec3(0, 0, 0), glm::ivec2(width, height));

    std::vector<std::unique_ptr<Mesh>> objects;
    objects.push_back(std::make_unique<Sphere>(glm::vec3(0,-1001,0), 1000.0f));
    objects.push_back(std::make_unique<Sphere>(glm::vec3(1,0,-3), 1.0f));
    objects.push_back(std::make_unique<Sphere>(glm::vec3(-1.5,.5f,-3.3f), 1.5f));

    Scene scene(camera, std::move(objects));

    scene.render(image, 1);
    image.writeToPPM("_results/highres_test.ppm");

    return 0;
}
