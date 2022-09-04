#include <stdio.h>
#include <math.h>
#include <complex.h>
#include <malloc.h>
#include "mandelbrot.h"
#include "bmp.h"
#include <time.h>

int main() {

    clock_t start, end;
    long time_taken;

    start = clock()

    int width  = 500, height = 500, dpi = 100;

    struct rgb_data *pixels;

    pixels = (struct rgb_data *) malloc(width*height*sizeof(struct rgb_data));

    int *iterations_ptr = (int *) malloc(sizeof(int));

    *iterations_ptr = 80;

    MandBMPpixels(width,height,-1,0,0,1,iterations_ptr, pixels);

    save_bmp("mandelbrot.bmp", width, height, dpi, pixels);

    free(pixels);
    free(iterations_ptr);

    end = clock();

    time_taken = (end - start)/CLOCKS_PER_SEC;
    printf("The program took %l seconds to complete.",time_taken);

    return 0;
}
