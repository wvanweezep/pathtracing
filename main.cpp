#include <iostream>

#include "camera.h"
#include "image.h"
#include "scene.h"
#include "mesh/mesh.h"
#include "mesh/sphere.h"


int main() {
    constexpr int width =  800;
    constexpr int height = 600;
    Image image(width, height);

    std::cout << "Start loading hdri texture... ";
    Camera camera(glm::vec3(0, 0, 0), glm::ivec2(width, height));
    std::cout << "FINISHED\n";

    std::vector<std::unique_ptr<Mesh>> objects;
    //objects.push_back(std::make_unique<Sphere>(glm::vec3(0,-1001,0), 1000.0f));
    objects.push_back(std::make_unique<Sphere>(glm::vec3(1,0,-3), 1.0f));
    objects.push_back(std::make_unique<Sphere>(glm::vec3(-1.5,.5f,-3.3f), 1.5f));

    Scene scene(camera, std::move(objects));

    std::cout << "Start rendering... ";
    scene.render(image, 16);
    std::cout << "FINISHED\n";

    std::cout << "Start writing output... ";
    image.writeToPPM("_results/test.ppm");
    std::cout << "FINISHED\n";

    return 0;
}
