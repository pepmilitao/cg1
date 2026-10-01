#pragma once
#include "Vec3.h"
#include "Ray.h"
#include "Color.h"

class Shape {
    public:
        Color color;
        Shape(Color color);
        virtual ~Shape();
        virtual Vec3 getNormal(Vec3& point) = 0;
        virtual double intercepts(Ray& ray) = 0;
};
