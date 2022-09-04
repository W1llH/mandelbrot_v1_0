#ifndef MANDELBROT_V1_0_MANDELBROT_H
#define MANDELBROT_V1_0_MANDELBROT_H

#include <math.h>
#include <complex.h>
#include "bmp.h"

double cmag (double complex z) {
    double magnitude = sqrt(pow(creal(z),2)+pow(cimag(z),2));
    return magnitude;
}

double mandItResult (double complex c, int *no_of_it) {
    if (cmag(c) < 2) {
        int *i = (int *)malloc(sizeof(int));
        *i = 0;
        double complex *z = (double complex *)malloc(sizeof(double complex));
        *z=0;
        do {
            *z = cpow(*z, 2) + c;
            (*i)++;
        }
        while (cmag((*z)) < 2 && (*i) < *no_of_it);
        double result = cmag((*z));
        free(i);
        free(z);
        return result;
    }else {
        double result = cmag(c);
        return result;
    }
}

struct rgb_data *MandBMPpixels (double imgw, double imgh, double min_x, double max_x, double min_y, double max_y, int *iterations, struct rgb_data *pixels){;
    double xIncr = (max_x - min_x)/imgw;
    double yIncr = (max_y - min_y)/imgh;

    for (int dy = 0; dy < imgh; dy++){
        for (int dx = 0; dx < imgw; dx++){
            int i = dy*imgw + dx;
            double complex c = (min_x + dx*xIncr) + (min_y + dy*yIncr)*I;
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
