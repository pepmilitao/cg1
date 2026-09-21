#pragma once
#include <cmath>

class Vec3 {

    private:
        double x;
        double y;
        double z;

    public:
        Vec3();
        Vec3(double x, double y, double z);
        Vec3 operator+(const Vec3& b);
        Vec3 operator-(const Vec3& b);
        Vec3 operator*(const double& n);
        Vec3 operator/(const double& n);
        double dot(Vec3 b);
        double mag();
};
