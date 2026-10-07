#pragma once
#include "Vec3.h"
#include "Mat3.h"
#include "Ray.h"
#include "Shape.h"
#include "Plane.h"
#include <cmath>

class Cone : public Shape{
    private:
        bool conic_surface(Ray& ray, Interseption& interseption);
        bool base(Ray& ray, Interseption& interseption);
    public:
        double radius;
        Vec3 center_base;
        Vec3 direction;
        Vec3 vertice;
        double height;
        bool is_base;
        Cone(double radius, Vec3 center_base, Vec3 direction, double height, bool is_base, Color color);
        bool intercepts(Ray& ray, Interseption& interseption) override;
};
