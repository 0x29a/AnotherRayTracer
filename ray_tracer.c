#include <math.h>
#include <stdio.h>

#include "vector_operations.h"
#include "utils.h"

#define min(a, b) (((a) < (b) ? (a) : (b)))

#define IMAGE_WIDTH 800
#define IMAGE_HEIGHT 600

int main() {
    Ray ray;

    Material materials[] = {
        {
            {1, 0, 0}, // diffusion, rgb
            0.2 // reflection
        },
        {
            {0, 1, 0},
            0.5
        },
        {
            {0, 0, 1},
            0.9
        }
    };

    Sphere spheres[] = {
        {
            {200, 300, 0}, // position in space
            100, // radius
            0 // material id
        },
        {
            {400, 400, 0},
            100,
            1
        },
        {
            {500, 140, 0},
            100,
            2
        }
    };

    Light lights[] = {
        {
            {0, 240, -100}, // position
            {1, 1, 1} // intensity
        },
        {
            {3200, 3000, -1000},
            {0.6, 0.7, 1}
        },
        {
            {600, 0, -100},
            {0.3, 0.5, 1}
        }
    };

    char image[3 * IMAGE_WIDTH * IMAGE_HEIGHT];

    for (int y = 0; y < IMAGE_HEIGHT; y++) {
        for (int x = 0; x < IMAGE_WIDTH; x++) {
            double red = 0;
            double green = 0;
            double blue = 0;

            int level = 0;
            double coef = 1.0;

            ray.start.x = x;
            ray.start.y = y;
            ray.start.z = -2000;

            ray.direction.x = 0;
            ray.direction.y = 0;
            ray.direction.z = 1;

            do {
                double root = 20000.0;
                int currentSphere = -1;

                unsigned int i;
                for (i = 0; i < 3; i++) {
                    if (isRayIntersectsSphere(&ray, &spheres[i], &root))
                        currentSphere = i;
                }
                if (currentSphere == -1)
                    break;

                Vector scaled = vectorScale(root, &ray.direction);
                Vector newStart = vectorAddition(&ray.start, &scaled);

                // Find normal for this point of ray and sphere intersection
                Vector normal = vectorSubstraction(&newStart, &spheres[currentSphere].origin);
                double temp = vectorDotProduct(&normal, &normal);
                if (temp == 0)
                    break;
                temp = 1.0 / sqrtf(temp);
                normal = vectorScale(temp, &normal);

                // Find material to determine the color
                Material currentMaterial = materials[spheres[currentSphere].material];

                // Find the value of light at this point
                unsigned int j;
                for(j=0; j < 3; j++){
                    Light currentLight = lights[j];
                    Vector distance = vectorSubstraction(&currentLight.position, &newStart);
                    if(vectorDotProduct(&normal, &distance) <= 0.0) continue;
                    double t = sqrtf(vectorDotProduct(&distance, &distance));
                    if(t <= 0.0) continue;

                    Ray lightRay;
                    lightRay.start = newStart;
                    lightRay.direction = vectorScale((1/t), &distance);

                    // Lambert diffusion
                    double lambert = vectorDotProduct(&lightRay.direction, &normal) * coef; 
                    red += lambert * currentLight.intensity.red * currentMaterial.diffusion.red;
                    green += lambert * currentLight.intensity.green * currentMaterial.diffusion.green;
                    blue += lambert * currentLight.intensity.blue * currentMaterial.diffusion.blue;
                }

                // Iterate over the reflection
                coef *= currentMaterial.reflection;

                // The reflected ray start and direction
                ray.start = newStart;
                double reflect = 2.0 * vectorDotProduct(&ray.direction, &normal);
                Vector tmp = vectorScale(reflect, &normal);
                ray.direction = vectorSubstraction(&ray.direction, &tmp);

                level++;
            }
            while ((coef > 0.00) && (level < 15));

            image[(x + y * IMAGE_WIDTH) * 3 + 0] = (unsigned char) min(red * 255.0, 255.0);
            image[(x + y * IMAGE_WIDTH) * 3 + 1] = (unsigned char) min(green * 255.0, 255.0);
            image[(x + y * IMAGE_WIDTH) * 3 + 2] = (unsigned char) min(blue * 255.0, 255.0);
        }
    }

    saveppm("picture.ppm", image, IMAGE_WIDTH, IMAGE_HEIGHT);

    return 0;
}
