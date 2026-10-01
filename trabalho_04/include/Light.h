#pragma once
#include "Vec3.h"

class Light {
    public:
        Vec3 position;
        Vec3 intensity;
        Light();
        Light(Vec3 position);
        Light(Vec3 position, Vec3 intensity);
};
