#pragma once
#include "Vec3.h"

class Mat3 {
    public:
        Vec3 a;
        Vec3 b;
        Vec3 c;
        Mat3(Vec3 a, Vec3 b, Vec3 c);
        Mat3 operator+(const Mat3& m);
        Mat3 operator-(const Mat3& m);
        Mat3 operator*(const double& n);
        Vec3 operator*(const Vec3& v);
        Mat3 operator*(const Mat3& v);
        Mat3 operator/(const double& n);
        Mat3 transpose();
};
