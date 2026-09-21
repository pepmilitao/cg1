#pragma once
#include <cmath>
class vec3 {
    private:
        double x;
        double y;
        double z;
    public:
        vec3() : x{0}, y{0}, z{0} {} // constructor
        vec3(double x, double y, double z) : x{x}, y{y}, z{z} {} // constructor

        vec3 operator+(const vec3& b) {
            return vec3(
                x + b.x,
                y + b.y,
                z + b.z
            );
        }
        vec3 operator-(const vec3& b) {
            return vec3(
                x - b.x,
                y - b.y,
                z - b.z
            );
        }
        vec3 operator*(const double& n) {
            return vec3(
                x * n,
                y * n,
                z * n
            );
        }
        vec3 operator/(const double& n) {
            return vec3(
                x / n,
                y / n,
                z / n
            );
        }
        double dot(vec3 b) {
            return x * b.x + y * b.y + z * b.z;
        }
        double mag() {
            return std::sqrt(x * x + y * y + z * z);
        }
};
