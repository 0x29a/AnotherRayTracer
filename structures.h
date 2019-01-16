#ifndef STRUCTURES_H
#define STRUCTURES_H
// https://en.wikipedia.org/wiki/Include_guard


typedef struct vector {
    double x, y, z;
} Vector;

typedef struct sphere {
    Vector origin;
    double radius;
    int material;
} Sphere;

typedef struct ray {
    Vector start;
    Vector direction;
} Ray;

typedef struct colour {
    double red, green, blue;
} Colour;

typedef struct material {
    Colour diffusion;
    double reflection;
} Material;

typedef struct light {
    Vector position;
    Colour intensity;
} Light;

#endif /* STRUCTURES_H */
