#include "circle.h"
#include <cmath>

double distance(const Circle * c, const Point * p) {
    return std::sqrt(std::pow(p->x - c->centre.x, 2) + std::pow(p->y - c->centre.y, 2));
}

std::string CheckPointInCircle(double selisih) {
    if (selisih < -EPSILON) {
        return "Inside";
    } else if (selisih > EPSILON) {
        return "Outside";
    } else {
        return "On Circle";
    }
}