#include "../include/Light.h"

Light::Light() : position{Vec3 {0, 0, 0}}, intensity{1, 1, 1} {};
Light::Light(Vec3 position) : position{position}, intensity{1, 1, 1} {}
Light::Light(Vec3 position, Vec3 intensity) : position{position}, intensity{intensity} {}
Vec3& Light::getPosition() { return position; }
Vec3& Light::getIntensity() { return intensity; }
