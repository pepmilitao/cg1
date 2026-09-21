#pragma once
#include "Vec3.h"
#include "Ray.h"

class Sphere {

    private:
        double radius;
        Vec3 center;

    public:
        Sphere(double radius, Vec3 center);
        bool intercepts(Ray ray);
};
