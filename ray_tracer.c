#include "vector_operations.h"
#include "utils.h"

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
            double temp = 200000.0;
            image[counter] = (isRayIntersectsSphere(&ray, &sphere, &temp)) ? 255: 0;
            image[counter + 1] = 0;
            image[counter + 2] = 0;
            counter += 3;
        }
    }

    saveppm("test.ppm", image, 400, 400);

    return 1;
}
