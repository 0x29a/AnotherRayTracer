#include <stdio.h>

void saveppm(char * filename, unsigned char * image, unsigned int width, unsigned int height) {
    FILE * imageFile = fopen(filename, "wb");
    fprintf(imageFile, "P6 %d %d %d\n", width, height, 255);
    fwrite(image, 3, width * height, imageFile);
    fclose(imageFile);
}
