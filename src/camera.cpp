#include "camera.h"

# define M_PI           3.14159265358979323846

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
    return {position, pixelCenter - position};
}

Color Camera::rayToColor(const Ray &ray) const {
    const glm::vec3 normalDir = normalize(ray.direction());
    const float u = 0.5f + static_cast<float>(atan2(normalDir.z, normalDir.x) / (2.0f * M_PI));
    const float v = 0.5f - static_cast<float>(asin(normalDir.y) / M_PI);
    return hdri.getPixel(
        static_cast<int>(u * static_cast<float>(hdri.width())),
        static_cast<int>(v * static_cast<float>(hdri.height())));
}

