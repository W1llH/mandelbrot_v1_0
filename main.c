#include <stdio.h>
#include <math.h>
#include <complex.h>
#include <malloc.h>
#include "mandelbrot.h"
#include "bmp.h"
// width of terminal=120 character

int main() {

    int width  = 200, height = 200, dpi = 100;

    struct rgb_data *pixels;

    pixels = (struct rgb_data *) malloc(width*height*sizeof(struct rgb_data));

    MandBMPpixels(width,height,-1,0,0,1,pixels);

    save_bmp("mandelbrot_after.bmp", width, height, dpi, pixels);

    free(pixels);
}
