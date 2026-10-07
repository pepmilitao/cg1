#include "../include/Mat3.h"
#include "../include/Vec3.h"

Mat3::Mat3(Vec3 a, Vec3 b, Vec3 c) : a{a}, b{b}, c{c} {}
Mat3 Mat3::operator+(const Mat3& m) {
    return Mat3(
        a + m.a,
        b + m.b,
        c + m.c
    );
}
Mat3 Mat3::operator-(const Mat3& m) {
    return Mat3(
        a - m.a,
        b - m.b,
        c - m.c
    );
}
Mat3 Mat3::operator*(const double& n) {
    return Mat3(
        a * n,
        b * n,
        c * n
    );
}
Vec3 Mat3::operator*(const Vec3& v) {
    Vec3 temp = v;
    return Vec3(
        a.dot(temp),
        b.dot(temp),
        c.dot(temp)
    );
}
Mat3 Mat3::operator*(const Mat3& v) {
    Mat3 temp = v;
    temp = temp.transpose();
    return Mat3(
        *this * temp.a,
        *this * temp.b,
        *this * temp.c
    ).transpose();
}
Mat3 Mat3::operator/(const double& n) {
    return Mat3(
        a / n,
        b / n,
        c / n
    );
}
Mat3 Mat3::transpose() {
    return Mat3(
        Vec3 {a.x, b.x, c.x},
        Vec3 {a.y, b.y, c.y},
        Vec3 {a.z, b.z, c.z}
    );
}
