#include <stdio.h>

typedef struct vector {
    double x, y, z;
} Vector;

typedef struct sphere {
    double radius;
    Vector origin;
} Sphere;

Sphere sphere = {
    10,
    {5, 5, 5} 
};


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



int main() {
    double product = vectorDotProduct(&sphere.origin, &sphere.origin);
    Vector sum = vectorAddition(&sphere.origin, &sphere.origin);
    Vector sub = vectorSubstraction(&sphere.origin, &sphere.origin);
    printf("%lf\n", product);

    printf("%lf %lf\n", sum.z, sub.z);
    return 1;
}
