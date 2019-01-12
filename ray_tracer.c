#include <stdio.h>

#include "vector_operations.h"

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
    }

    saveppm("test.ppm", image, 400, 400);

    return 1;
}
