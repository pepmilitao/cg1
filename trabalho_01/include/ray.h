#pragma once
#include "vec3.h"

class ray {
    private:
        vec3 start_point;
        vec3 dir_vec;
    public:
        ray(vec3 sp, vec3 dv) {
            start_point = sp;
            dir_vec = dv / dv.mag();
        }
        vec3 getStartPoint() { return start_point; }
        vec3 getDirVec() { return dir_vec; }
};
