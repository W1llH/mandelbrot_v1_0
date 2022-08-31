#include <stdio.h>
#include <math.h>
#include <complex.h>
#include <malloc.h>
#include "mandelbrot.h"
#include "bmp.h"
// width of terminal=120 character

int main() {

    int width  = 400, height = 400, dpi = 10;

    struct rgb_data *pixels = malloc(width*height*sizeof(struct rgb_data));

    MandBMPpixels(width,height,-2,1,-1.5,1.5,pixels);

    save_bmp("mandelbrot_smol.bmp", width, height, dpi, pixels);
    
    free(pixels);
}
