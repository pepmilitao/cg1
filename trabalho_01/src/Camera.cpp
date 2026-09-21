#include "../include/Camera.h"

Camera::Camera(Vec3 p) : point{p}{}
Vec3 Camera::getPoint() { return point; };
