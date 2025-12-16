#ifndef RAY_H
#define RAY_H

#include "glm/vec3.hpp"

class Ray {
    glm::vec3 orig;
    glm::vec3 dir;

public:
    Ray(const glm::vec3& origin, const glm::vec3& direction) : orig(origin), dir(glm::normalize(direction)) {}

    [[nodiscard]] const glm::vec3& origin() const {
        return orig;
    }

    [[nodiscard]] const glm::vec3& direction() const {
        return dir;
    }

    void set (const glm::vec3& origin, const glm::vec3& direction) {
        orig = origin;
        dir = direction;
    }

    [[nodiscard]] glm::vec3 at(float t) const {
        return orig + dir * t;
    }
};

#endif //RAY_H
