#include "../include/Shape.h"

Shape::Shape(Color color) : color{color} {}
Shape::~Shape() = default;
double Shape::lowerNotNegative(double t1, double t2) {
    if (t1 >= 0 and t2 >= 0) return t1 < t2 ? t1 : t2;
    if (t1 < 0) return t2 >= 0 ? t2 : -1.0;
    return t1;
}
