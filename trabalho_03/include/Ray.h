#pragma once
#include "Vec3.h"

class Ray {

    private:
        Vec3 origin;
        Vec3 direction;

    public:
        Ray(Vec3 origin, Vec3 direction);
        Vec3& getOrigin();
        Vec3& getDirection();
        Vec3 at(double t);
};
