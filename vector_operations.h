#include <stdbool.h>

#include "structures.h"

double vectorDotProduct(Vector *, Vector *);

Vector vectorSubstraction(Vector *, Vector *);

Vector vectorAddition(Vector *, Vector *);

Vector vectorScale(double, Vector *);

bool isRayIntersectsSphere(Ray *, Sphere *, double *);
