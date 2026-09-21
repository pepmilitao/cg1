#include "../include/Sphere.h"

Sphere::Sphere(double radius, Vec3 center) : radius{radius}, center{center} {};
bool Sphere::intercepts(Ray ray) {
    Vec3 diff = ray.getStartPoint() - center;
    double b = 2 * diff.dot(ray.getDirVec());
    double c = diff.dot(diff) - radius * radius;
    double delta = b * b - 4 * c;
    if (delta >= 0) return true;
    return false;
}
