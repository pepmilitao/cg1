#pragma once
#include "Vec3.h"
#include "Ray.h"

class Sphere {

    private:
        double radius;
        Vec3 center;
        Vec3 k_dif;
        Vec3 k_esp;
        double alpha;

    public:
        Sphere(double radius, Vec3 center, Vec3 k_dif, Vec3 k_esp, double alpha);
        Vec3& getKDif();
        Vec3& getKEsp();
        double getAlpha();
        Vec3 getNormal(Vec3& point);
        double intercepts(Ray& ray);
};
