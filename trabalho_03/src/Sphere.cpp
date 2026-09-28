#include "../include/Sphere.h"
#include <cmath>

Sphere::Sphere(double radius, Vec3 center, Vec3 k_dif, Vec3 k_esp, double alpha) : radius{radius}, center{center}, k_dif{k_dif}, k_esp{k_esp}, alpha{alpha} {};
Vec3 Sphere::getNormal(Vec3& point) { return (point - center).norm(); }
Vec3& Sphere::getKDif() { return k_dif; };
Vec3& Sphere::getKEsp() { return k_esp; };
double Sphere::getAlpha() {return alpha; };
double Sphere::intercepts(Ray& ray) {
    Vec3 diff = ray.getOrigin() - center;
    double b = 2 * diff.dot(ray.getDirection());
    double c = diff.dot(diff) - radius * radius;
    double delta = b * b - 4 * c;
    if (delta < 0.0) {
        return -1.0;
    } else {
        return (-b - sqrt(delta)) / 2.0;
    }
};
