#include "../include/Plane.h"

Plane::Plane(Vec3 known_point, Vec3 normal, Color color) : known_point{known_point}, normal{normal}, Shape(color) {}
bool Plane::intercepts(Ray& ray, Interseption& interseption) {
    double top = (known_point - ray.origin).dot(normal);
    double bottom = ray.direction.dot(normal);
    if (bottom == 0.0) return false;
    double t = top / bottom;
    if (t < 0) return false;
    interseption.point = ray.at(t);
    interseption.normal = normal;
    interseption.t = t;
    return true;
}
