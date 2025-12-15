#include "camera.h"

void Camera::initialize() {
    constexpr float viewport_height = 2.0f;
    const float viewport_width = viewport_height * (static_cast<float>(size.x) / static_cast<float>(size.y));
    const glm::vec3 viewportU(viewport_width, 0, 0);
    constexpr glm::vec3 viewportV(0, -viewport_height, 0);

    pixelDeltaX = viewportU / static_cast<float>(size.x);
    pixelDeltaY = viewportV / static_cast<float>(size.y);
    topLeft = position - glm::vec3(0, 0, focalLength) - viewportU / 2.0f - viewportV / 2.0f
        + 0.5f * (pixelDeltaX + pixelDeltaY);
}

Ray Camera::pixelToRay(int x, int y) const {
    const auto pixelCenter = topLeft + pixelDeltaX * static_cast<float>(x)
        + pixelDeltaY * static_cast<float>(y);
    return Ray(position, pixelCenter - position);
}

Color Camera::rayToColor(const Ray &ray) {
    const glm::vec3 normalDir = normalize(ray.direction());
    const float a = 0.5f * (normalDir.y + 1.0f);
    return Color((1.0f - a) * glm::vec3(1.0f, 1.0f, 1.0f) + a * glm::vec3(0.3f, 0.6f, 1.0f));
}

