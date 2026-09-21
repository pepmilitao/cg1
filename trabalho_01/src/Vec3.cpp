#include "../include/Vec3.h"

Vec3::Vec3() : x{0}, y{0}, z{0} {}
Vec3::Vec3(double x, double y, double z) : x{x}, y{y}, z{z} {}
Vec3 Vec3::operator+(const Vec3& b) {
    return Vec3(
        x + b.x,
        y + b.y,
        z + b.z
    );
}
Vec3 Vec3::operator-(const Vec3& b) {
    return Vec3(
        x - b.x,
        y - b.y,
        z - b.z
    );
}
Vec3 Vec3::operator*(const double& n) {
    return Vec3(
        x * n,
        y * n,
        z * n
    );
}
Vec3 Vec3::operator/(const double& n) {
    return Vec3(
        x / n,
        y / n,
        z / n
    );
}
double Vec3::dot(Vec3 b) {
    return x * b.x + y * b.y + z * b.z;
}
double Vec3::mag() {
    return std::sqrt(x * x + y * y + z * z);
}
