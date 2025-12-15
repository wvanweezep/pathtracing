#ifndef CAMERA_H
#define CAMERA_H

#include "color.h"
#include "ray.h"
#include "glm/vec2.hpp"
#include "glm/vec3.hpp"


class Camera {

    glm::vec3 position;
    glm::ivec2 size;
    float focalLength = 1.0f;

    glm::vec3 topLeft;
    glm::vec3 pixelDeltaX;
    glm::vec3 pixelDeltaY;

    void initialize();

public:
    Camera(const glm::vec3& position, const glm::ivec2& imageSize) : position(position), size(imageSize) {
        initialize();
    }

    [[nodiscard]] Ray pixelToRay(int x, int y) const;

    // Skybox
    [[nodiscard]] Color rayToColor(const Ray &ray);
};

#endif //CAMERA_H
