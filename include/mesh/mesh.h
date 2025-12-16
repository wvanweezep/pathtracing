#ifndef MESH_H
#define MESH_H

#include "../ray.h"
#include "glm/vec3.hpp"


class HitInfo {
public:
    glm::vec3 point;
    glm::vec3 normal;
    float t;
};


class Mesh {
protected:
    glm::vec3 position;

public:
    explicit Mesh(const glm::vec3& position) : position(position) {}

    virtual ~Mesh() = default;

    virtual bool collide(const Ray& ray, float tMin, float tMax, HitInfo& hitInfo) const = 0;
};

#endif //MESH_H
