#pragma once
#include "Vec3.h"
#include "Ray.h"
#include "Shape.h"
#include <cmath>

class Plane : public Shape{
    private:
        Vec3 normal;
    public:
        Vec3 known_point;
        Plane(Vec3 known_point, Vec3 normal, Color color);
        bool intercepts(Ray& ray, Interseption& interseption) override;
};
