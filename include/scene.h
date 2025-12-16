#pragma once

#include <memory>
#include <vector>

#include "camera.h"
#include "image.h"
#include "mesh/mesh.h"


/**
 * Class for holding an environment used for rendering, where the Camera
 * can be moved to create different outputs.
 */
class Scene {
    /** Camera used for rendering the Scene */
    Camera _camera;

    /** List of objects in the Scene */
    std::vector<std::unique_ptr<Mesh>> _objects;

    /**
     * Find the collision of the ray and stores the result in the provided HitInfo.
     * @param ray ray to check for collision
     * @param tMin minimum distance for the ray to travel
     * @param tMax maximum distance for the ray to travel
     * @param hitInfo container for storing the hit result, if any
     * @return true, if a collision occurred with any object in the Scene
     */
    bool collide(const Ray& ray, float tMin, float tMax, HitInfo& hitInfo) const;

    /**
     * Traces the ray to find its color, might call itself.
     * @param ray ray to trace
     * @return rgb value found by the ray
     */
    [[nodiscard]] glm::vec3 trace(const Ray& ray) const;

public:
    /**
     * Instantiates an instance of a Scene with a defined Camera and list of Objects
     * @param camera Camera used for rendering the Scene
     * @param objects Objects in the Scene
     */
    explicit Scene(const Camera& camera, std::vector<std::unique_ptr<Mesh>>&& objects) :
        _camera(camera), _objects(std::move(objects)) {}

    /**
     * Getter for the Camera in the Scene.
     * @return reference to the Camera of the Scene
     */
    [[nodiscard]] Camera& camera() {
        return _camera;
    }

    /**
     * Getter for the objects in the Scene.
     * @return readonly-list of objects in the Scene
     */
    [[nodiscard]] const std::vector<std::unique_ptr<Mesh>>& objects() const {
        return _objects;
    }

    /**
     * Renders the Scene objects to an Image according to the Camera's orientation.
     * @param output reference to image for the output
     * @param samples number of rays per pixel
     */
    void render(Image& output, int samples = 2) const;
};
