#pragma once
#include "Vec3.h"

class Camera {

    private:
        Vec3 point;

    public:
        Camera(Vec3 p);
        Vec3 getPoint();
};
