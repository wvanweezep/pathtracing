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

    [[nodiscard]] float r() const {
        return rgba.x;
    }

    [[nodiscard]] float g() const {
        return rgba.y;
    }

    [[nodiscard]] float b() const {
        return rgba.z;
    }

    [[nodiscard]] float a() const {
        return rgba.w;
    }
};

#endif //COLOR_H
