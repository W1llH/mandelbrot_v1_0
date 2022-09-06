#include <stdio.h>
#include <malloc.h>
#include "mandelbrot.h"
#include <time.h>

int main() {

    clock_t start, end;
    double time_taken;

    start = clock();

    int width  = 1000, height = 1000, dpi = 100;

    struct rgb_data *pixels;

    pixels = (struct rgb_data *) malloc(width*height*sizeof(struct rgb_data));

    unsigned int iterations = 255;

    save_mand_bmp("mandelbrot_double1.bmp", width, height, dpi, -2, 2, -2, 2, iterations, pixels);

    free(pixels);

    end = clock();

    time_taken = ((double)end - start)/CLOCKS_PER_SEC;
    printf("The program took %lf seconds to complete.\n",time_taken);

    return 0;
}
