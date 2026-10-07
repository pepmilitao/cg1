#pragma once
#include "Vec3.h"
#include "Ray.h"
#include "Color.h"
#include "Interseption.h"

class Shape {
    public:
        Color color;
        Shape(Color color);
        virtual ~Shape();
        double lowerNotNegative(double t1, double t2);
        virtual bool intercepts(Ray& ray, Interseption& interseption) = 0;
};
