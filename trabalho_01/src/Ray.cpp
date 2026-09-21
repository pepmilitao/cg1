#include "../include/Ray.h"

Ray::Ray(Vec3 sp, Vec3 dv) {
    start_point = sp;
    dir_vec = dv / dv.mag();
}
Vec3 Ray::getStartPoint() { return start_point; }
Vec3 Ray::getDirVec() { return dir_vec; }
