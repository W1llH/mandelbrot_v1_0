#ifndef MANDELBROT_V1_0_MANDELBROT_H
#define MANDELBROT_V1_0_MANDELBROT_H

#include <math.h>
#include <complex.h>
#include "bmp.h"

double cmag (const double complex z) {
    double magnitude = sqrt(pow(creal(z),2)+pow(cimag(z),2));
    return magnitude;
}

double mandItResult (const double complex c, const unsigned int *no_of_it) {
    if (cmag(c) < 2) {
        unsigned int i = 0;
        double complex z=c;
        do {
            z = cpow(z, 2) + c;
            (i)++;
        }
        while (cmag((z)) < 2 && (i) < (*no_of_it)-1);
        double result = cmag((z));
        return result;
    }else {
        double result = cmag(c);
        return result;
    }
}

struct rgb_data *MandBMPpixels (double imgw, double imgh, double min_x, double max_x, double min_y, double max_y, const unsigned int *iterations, struct rgb_data *pixels){;
    double xIncr = (max_x - min_x)/imgw;
    double yIncr = (max_y - min_y)/imgh;

    for (unsigned int dy = (unsigned int)imgh-1; dy--;){
        for (unsigned int dx = (unsigned int)imgw-1; dx--;){
            unsigned int i = dy*(unsigned int)imgw + dx;
            double complex c = (min_x + (double)dx*xIncr) + (min_y + (double)dy*yIncr)*I;
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
