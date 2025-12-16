#include "scene.h"

bool Scene::collide(const Ray &ray, float tMin, float tMax, HitInfo &hitInfo) const {
    hitInfo.t = tMax + .01f;
    for (const auto& obj : _objects) {
        HitInfo dummy{};
        if (!obj->collide(ray, 0.001f, 1000.0f, dummy)) continue;
        if (hitInfo.t <= dummy.t) continue;

        hitInfo.point = dummy.point;
        hitInfo.normal = dummy.normal;
        hitInfo.t = dummy.t;
    }
    return hitInfo.t < tMax;
}

glm::vec3 Scene::trace(const Ray& ray) const {
    HitInfo hitInfo{};

    if (!collide(ray, 0.001f, 1000.0f, hitInfo))
        return Camera::rayToColor(ray).rgb();

    return trace(Ray(hitInfo.point + hitInfo.normal * 0.001f, glm::reflect(ray.direction(), hitInfo.normal))) * .8f;
}

void Scene::render(Image& output, int samples) const {
    for (int y = 0; y < output.height() - 1; y++) {
        for (int x = 0; x < output.width(); x++) {
            glm::vec3 colorVal{};
            for (int i = 0; i < samples; i++)
                colorVal += trace(_camera.pixelToRay(x, y));
            colorVal /= samples;
            output.setPixel(x, y, Color(colorVal));
        }
    }
}






