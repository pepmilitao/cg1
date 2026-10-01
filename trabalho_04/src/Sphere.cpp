#include "../include/Sphere.h"

Sphere::Sphere(double radius, Vec3 center, Color color) : radius{radius}, center{center}, Shape(color) {};
Vec3 Sphere::getNormal(Vec3& point) { return (point - center).norm(); }
double Sphere::intercepts(Ray& ray) {
    Vec3 diff = ray.origin - center;
    double a = ray.direction.dot(ray.direction);
    double b = 2 * diff.dot(ray.direction);
    double c = diff.dot(diff) - radius * radius;
    double delta = b * b - 4 * a * c;
    if (delta < 0.0) {
        return -1.0;
    } else {
        double sqrt_delta = sqrt(delta) ;
        double t1 = (-b - sqrt_delta) / (2.0 * a);
        double t2 = (-b + sqrt_delta) / (2.0 * a);
        if (t1 >= 0 and t2 >= 0) return t1 < t2 ? t1 : t2;
        if (t1 < 0) return t2;
        return t1;
    }
};
