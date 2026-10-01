#include "../include/Plane.h"

Plane::Plane(Vec3 known_point, Vec3 normal, Color color) : known_point{known_point}, normal{normal}, Shape(color) {}
Vec3 Plane::getNormal(Vec3 &point) { return normal; }
double Plane::intercepts(Ray& ray) {
    double top = (known_point - ray.origin).dot(normal);
    double bottom = ray.direction.dot(normal);
    if (bottom == 0.0) return -INFINITY;
    return top / bottom;
}
