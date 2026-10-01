#pragma once
#include "Vec3.h"
#include "Ray.h"
#include "Shape.h"
#include <cmath>

class Sphere : public Shape{
    public:
        double radius;
        Vec3 center;
        Sphere(double radius, Vec3 center, Color color);
        Vec3 getNormal(Vec3& point) override;
        double intercepts(Ray& ray) override;
};
