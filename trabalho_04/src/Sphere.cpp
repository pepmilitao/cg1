#include "../include/Sphere.h"

Sphere::Sphere(double radius, Vec3 center, Color color) : radius{radius}, center{center}, Shape(color) {};
bool Sphere::intercepts(Ray& ray, Interseption& interseption) {
    Vec3 diff = ray.origin - center;
    double a = ray.direction.dot(ray.direction);
    double b = 2 * diff.dot(ray.direction);
    double c = diff.dot(diff) - radius * radius;
    double delta = b * b - 4 * a * c;
    if (delta < 0.0) return false;

    double sqrt_delta = sqrt(delta) ;
    double t1 = (-b - sqrt_delta) / (2.0 * a);
    double t2 = (-b + sqrt_delta) / (2.0 * a);
    double t = lowerNotNegative(t1, t2);
    if (t < 0) return false;
    interseption.t = t;
    interseption.point = ray.at(interseption.t);
    interseption.normal = (interseption.point - center).norm();
    return true;
};
