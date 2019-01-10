#include <stdio.h>
#include <stdbool.h>


typedef struct vector {
    double x, y, z;
} Vector;

typedef struct sphere {
    double radius;
    Vector origin;
} Sphere;

typedef struct ray {
    Vector start;
    Vector direction;
} Ray;

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

int main() {
    Ray ray = {
        {0, 0, 0},
        {0, 0, 1},
    };

    Sphere sphere = {
        10,
        {20, 20, 20}
    };

    for (int y=0; y<40; y++) {
        ray.start.y = y;
        for (int x=0; x<40; x++) {
            ray.start.x = x;

            if (isRayIntersectsSphere(&ray, &sphere)) {
                printf("++");
            }
            else {
                printf("--");
            }
        }
        printf("\n");
    }
    return 1;
}
