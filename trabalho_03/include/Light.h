#pragma once
#include "Vec3.h"

class Light {
    private:
        Vec3 position;
        Vec3 intensity;
    public:
        Light();
        Light(Vec3 position);
        Light(Vec3 position, Vec3 intensity);
        Vec3& getPosition();
        Vec3& getIntensity();
};
