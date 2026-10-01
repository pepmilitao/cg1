#include "../include/Sphere.h"

Sphere::Sphere(double radius, Vec3 center, Color color) : radius{radius}, center{center}, Shape(color) {};
Vec3 Sphere::getNormal(Vec3& point) { return (point - center).norm(); }
double Sphere::intercepts(Ray& ray) {
    Vec3 diff = ray.origin - center;
    double b = 2 * diff.dot(ray.direction);
    double c = diff.dot(diff) - radius * radius;
    double delta = b * b - 4 * c;
    if (delta < 0.0) {
        return -1.0;
    } else {
        return (-b - sqrt(delta)) / 2.0;
    }
};
