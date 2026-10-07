#pragma once
#include "Vec3.h"
#include "Mat3.h"
#include "Ray.h"
#include "Shape.h"
#include "Plane.h"
#include <cmath>

class Cilinder : public Shape{
    private:
        bool cilindric_surface(Ray& ray, Interseption& interseption);
        bool base(Ray& ray, Interseption& interseption);
        bool top(Ray& ray, Interseption& interseption);
    public:
        double radius;
        Vec3 center_base;
        Vec3 direction;
        Vec3 center_top;
        double height;
        bool is_base;
        bool is_top;
        Cilinder(double radius, Vec3 center_base, Vec3 direction, double height, bool is_base, bool is_top, Color color);
        bool intercepts(Ray& ray, Interseption& interseption) override;
};
