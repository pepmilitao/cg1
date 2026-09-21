#pragma once
#include "Vec3.h"

class Ray {

    private:
        Vec3 start_point;
        Vec3 dir_vec;

    public:
        Ray(Vec3 sp, Vec3 dv);
        Vec3 getStartPoint();
        Vec3 getDirVec();
};
