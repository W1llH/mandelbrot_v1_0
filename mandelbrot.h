#ifndef MANDELBROT_V1_0_MANDELBROT_H
#define MANDELBROT_V1_0_MANDELBROT_H

#include <math.h>
#include <complex.h>
#include "bmp.h"

double cmag (const double complex z) {
    double magnitude = sqrt(pow(creal(z),2)+pow(cimag(z),2));
    return magnitude;
}

double mandItResult (const double complex c, const unsigned int no_of_it) {
    if (cmag(c) < 2) {
        unsigned int i = 1;
        double complex z=c;
        do {
            z = cpow(z, 2) + c;
            (i)++;
        }
        while (cmag((z)) < 2 && (i) < (no_of_it));
        double result = cmag((z));
        return result;
    }else {
        double result = cmag(c);
        return result;
    }
}

struct rgb_data *MandBMPpixels (double imgw, double imgh, double min_x, double max_x, double min_y, double max_y, const unsigned int iterations, struct rgb_data *pixels){
    double xIncr = (max_x - min_x)/imgw;
    double yIncr = (max_y - min_y)/imgh;

    for (unsigned int dy = (unsigned int)imgh; dy--;){
        for (unsigned int dx = (unsigned int)imgw; dx--;){
            unsigned int px = dy*(unsigned int)imgw + dx;
            double complex c = (min_x + (double)dx*xIncr) + (min_y + (double)dy*yIncr)*I;
            unsigned int i = 0;
            double complex z=0;
            do {
                z = cpow(z, 2) + c;
                i++;
            }
            while (cmag(z) < 2 && i < iterations);
            pixels[px].r = (unsigned char)(((float)i/(float)iterations)*255);
            pixels[px].g = (unsigned char)(((float)i/(float)iterations)*255);
            pixels[px].b = (unsigned char)(((float)i/(float)iterations)*255);
        }
    }
    return pixels;
}

#endif //MANDELBROT_V1_0_MANDELBROT_H