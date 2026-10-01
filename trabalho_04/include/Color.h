#pragma once
#include "Vec3.h"

class Color {
    public:
        Vec3 k_dif;
        Vec3 k_esp;
        Vec3 k_amb;
        double alpha;
        Color(Vec3 k_dif, Vec3 k_esp, Vec3 k_amb, double alpha);
};
