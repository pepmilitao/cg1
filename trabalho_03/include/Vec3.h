#pragma once
#include <cmath>

class Vec3 {
    public:
        double x;
        double y;
        double z;

        Vec3();
        Vec3(double x, double y, double z);
        Vec3 operator+(const Vec3& b);
        Vec3 operator-(const Vec3& b);
        Vec3 operator*(const double& n);
        Vec3 operator/(const double& n);
        double dot(Vec3& b);
        Vec3 cross(Vec3& b);
        Vec3 cross_at(Vec3& b);
        double mag();
        Vec3 norm();
};
