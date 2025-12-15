#ifndef COLOR_H
#define COLOR_H

#include <glm/glm.hpp>
#include <glm/vec4.hpp>

struct Color {
    glm::vec4 rgba{0.0f, 0.0f, 0.0f, 1.0f};

    constexpr Color() = default;

    constexpr Color(float r, float g, float b, float a = 1.0f)
        : rgba(glm::clamp(glm::vec4{r, g, b, a}, 0.0f, 1.0f)) {}

    explicit constexpr Color(const glm::vec3& rgb, float a = 1.0f)
        : rgba(glm::clamp(rgb, 0.0f, 1.0f), glm::clamp(a, 0.0f, 1.0f)) {}

    explicit constexpr Color(const glm::vec4& rgba)
    : rgba(glm::clamp(rgba, 0.0f, 1.0f)) {}
};

#endif //COLOR_H
