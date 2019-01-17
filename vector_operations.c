#include <stdbool.h>
#include <math.h>

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

Vector vectorScale(double factor, Vector *vector) {
    return (Vector) {
        vector->x * factor, vector->y * factor, vector->z * factor
    };
}

bool isRayIntersectsSphere(Ray *ray, Sphere *sphere, double * root) {
    bool intersects;

    double A = vectorDotProduct(&(ray->direction), &(ray->direction));

    Vector distance = vectorSubstraction(&(ray->start), &(sphere->origin));

    double B = 2 * vectorDotProduct(&(ray->direction), &distance);

    double C = vectorDotProduct(&distance, &distance) - sphere->radius * sphere-> radius;

    double discriminant = B * B - 4 * A * C;

    if (discriminant < 0)
        intersects = false;
    else {
        double sqrtDiscr = sqrtf(discriminant);
        double firstRoot = (-B - sqrtDiscr) / (2 * A);
        double secondRoot = (-B + sqrtDiscr) / (2 * A);

        if (firstRoot > secondRoot)
            firstRoot = secondRoot;

        if ((firstRoot > 0.001f) && (firstRoot < *root)) {
            *root = firstRoot;
            intersects = true;
        } else
            intersects = false;
    }

    return intersects;
}
