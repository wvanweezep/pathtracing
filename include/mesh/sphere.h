#ifndef SPHERE_H
#define SPHERE_H

#include "mesh.h"

class Sphere final : public Mesh {
    float radius;

public:
    Sphere(const glm::vec3& position, float radius) : Mesh(position), radius(radius) {}

    bool collide(const Ray &ray, float tMin, float tMax, HitInfo &hitInfo) const override {
        const glm::vec3 oc = ray.origin() - position;

        const float a = glm::dot(ray.direction(), ray.direction());
        const float b = 2 * glm::dot(ray.direction(), oc);
        const float c = glm::dot(oc, oc) - radius * radius;

        const float d = b * b - 4 * a * c;
        if (d < 0) return false;

        float sqrtd = std::sqrt(d);
        float t = (-b - sqrtd) / (2 * a);
        if (t <= tMin || t >= tMax) {
            t = (-b + sqrtd) / (2 * a);
            if (t <= tMin || t >= tMax)
                return false;
        }

        hitInfo.t = t;
        hitInfo.point = ray.at(t);
        hitInfo.normal = (hitInfo.point - position) / radius;

        return 0 <= d;
    }
};

#endif //SPHERE_H
