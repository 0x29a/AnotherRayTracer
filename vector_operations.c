#include <stdbool.h>

#include "structures.h"

double vectorDotProduct(Vector *first, Vector *second) {
    return first->x*second->x + first->y*second->y + first->z*second->z;
}

Vector vectorSubstraction(Vector *first, Vector *second) {
    return (Vector) {
        first->x - second->x, first->y - second->y, first->z - second->z
    };
}

Vector vectorAddition(Vector *first, Vector *second) {
    return (Vector) {
        first->x + second->x, first->y + second->y, first->z + second->z
    };
}

bool isRayIntersectsSphere(Ray *ray, Sphere *sphere) {
    double A = vectorDotProduct(&(ray->direction), &(ray->direction));

    Vector distance = vectorSubstraction(&(ray->start), &(sphere->origin));

    double B = 2 * vectorDotProduct(&(ray->direction), &distance);

    double C = vectorDotProduct(&distance, &distance) - sphere->radius * sphere-> radius;

    double discriminant = B * B - 4 * A * C;

    if (discriminant < 0)
        return false;
    else
        return true;
}
