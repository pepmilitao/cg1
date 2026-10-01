#pragma once
#include "Vec3.h"

class Color {
    public:
        Vec3 k_dif;
        Vec3 k_esp;
        double alpha;
        Color(Vec3 k_dif, Vec3 k_esp, double alpha);
};
