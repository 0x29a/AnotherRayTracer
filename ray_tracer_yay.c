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
    printf("A %lf\n", A);


    Vector distance = vectorSubstraction(&(ray->start), &(sphere->origin));

    printf("DISTANCE %lf %lf %lf\n", distance.x, distance.y, distance.z);

    double B = 2 * vectorDotProduct(&(ray->direction), &distance);

    printf("B %lf\n", B);

    double C = vectorDotProduct(&distance, &distance) - sphere->radius * sphere-> radius;

    printf("C %lf\n", C);

    double discriminant = B * B - 4 * A * C;

    printf("Discr %lf\n", discriminant);

    if (discriminant < 0)
        return false;
    else
        return true;
}

int main() {
    Ray ray = {
        {0, 0, 0},
        {0, 9, 1},
    };

    Sphere sphere = {
        3,
        {0, 9, 5}
    };

    bool YAY = isRayIntersectsSphere(&ray, &sphere);
    printf("%d", (int) YAY);

    return 1;
}
