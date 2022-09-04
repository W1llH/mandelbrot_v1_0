#include <stdio.h>
#include <math.h>
#include <complex.h>
#include <malloc.h>
#include "mandelbrot.h"
#include "bmp.h"
#include <time.h>

int main() {

    clock_t start, end;
    double time_taken;

    start = clock();

    int width  = 2000, height = 2000, dpi = 100;

    struct rgb_data *pixels;

    pixels = (struct rgb_data *) malloc(width*height*sizeof(struct rgb_data));

    unsigned int iterations = 80;

    MandBMPpixels(width,height,-3,3,-3,3, iterations, pixels);

    save_bmp("mandelbrot_double.bmp", width, height, dpi, pixels);

    free(pixels);

    end = clock();

    time_taken = ((double)end - start)/CLOCKS_PER_SEC;
    printf("The program took %lf seconds to complete.\n",time_taken);

    return 0;
}
