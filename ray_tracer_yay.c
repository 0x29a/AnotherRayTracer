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


void saveppm(char * filename, unsigned char * image, unsigned int width, unsigned int height) {
    FILE * imageFile = fopen(filename, "wb");
    fprintf(imageFile, "P6 %d %d %d\n", width, height, 255);
    fwrite(image, 3, width * height, imageFile);
    fclose(imageFile);
}

int main() {
    Ray ray = {
        {0, 0, 0},
        {0, 0, 1},
    };

    Sphere sphere = {
        100,
        {200, 200, 200}
    };

    char image[160000 * 3];


    unsigned int counter = 0;


    for (int y=0; y<400; y++) {
        ray.start.y = y;
        for (int x=0; x<400; x++) {
            ray.start.x = x;
            image[counter] = (isRayIntersectsSphere(&ray, &sphere)) ? 255: 0;
            image[counter + 1] = 0;
            image[counter + 2] = 0;
            counter += 3;
        }
        printf("\n");
    }

    saveppm("test.ppm", image, 400, 400);

    return 1;
}
