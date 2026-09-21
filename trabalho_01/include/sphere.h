#pragma once
#include "vec3.h"
#include "ray.h"

class sphere {
    private:
        double radius;
        vec3 center;

    public:
        sphere(double radius, vec3 center) : radius{radius}, center{center} {};
        bool intercepts(ray ray) {
            vec3 diff = ray.getStartPoint() - center;
            double b = diff.dot(ray.getDirVec());
            double c = diff.dot(diff) - radius * radius;
            double delta = b * b - 4 * c;
            if (delta >= 0) return true;
            return false;
        }
};
