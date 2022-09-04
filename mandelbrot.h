#ifndef MANDELBROT_V1_0_MANDELBROT_H
#define MANDELBROT_V1_0_MANDELBROT_H

#include <math.h>
#include <complex.h>
#include "bmp.h"

float cmag (double complex z) {
    float magnitude = (float)sqrt(pow(creal(z),2)+pow(cimag(z),2));
    return magnitude;
}

double mandItResult (double complex c, unsigned int *no_of_it) {
    if (cmag(c) < 2) {
        unsigned char *i = (unsigned char *)malloc(sizeof(unsigned short)); // limits possible iterations to 255 for now
        *i = 0;
        double complex *z = (double complex *)malloc(sizeof(double complex));
        *z=0;
        do {
            *z = cpow(*z, 2) + c;
            (*i)++;
        }
        while (cmag((*z)) < 2 && (*i) < *no_of_it);
        float result = cmag((*z));
        free(i);
        free(z);
        return result;
    }else {
        double result = cmag(c);
        return result;
    }
}

struct rgb_data *MandBMPpixels (float imgw, float imgh, float min_x, float max_x, float min_y, float max_y, unsigned int *iterations, struct rgb_data *pixels){;
    float xIncr = (max_x - min_x)/imgw;
    float yIncr = (max_y - min_y)/imgh;

    for (unsigned int dy = 0; dy < (unsigned int)imgh; dy++){
        for (unsigned int dx = 0; dx < (unsigned int)imgw; dx++){
            unsigned int i = dy*(unsigned int)imgw + (unsigned int)dx;
            float complex c = (min_x + (float)dx*xIncr) + (min_y + (float)dy*yIncr)*I;
            if (mandItResult(c, iterations)<2){
                (pixels[i]).r = 255;
                (pixels[i]).g = 255;
                (pixels[i]).b = 255;
            } else{
                (pixels[i]).r = 0;
                (pixels[i]).g = 0;
                (pixels[i]).b = 0;
            }
        }
    }
    return pixels;
}

#endif //MANDELBROT_V1_0_MANDELBROT_H
