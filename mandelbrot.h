#ifndef MANDELBROT_V1_0_MANDELBROT_H
#define MANDELBROT_V1_0_MANDELBROT_H

#include <math.h>
#include <complex.h>
#include "bmp.h"

double cmag (double complex z) {
    double magnitude = sqrt(pow(creal(z),2)+pow(cimag(z),2));
    return magnitude;
}

double mandItResult (double complex c) {
    int no_of_it = 80;
    double complex z = 0;
    int i = 0;
    while (i<no_of_it){
        z = cpow(z,2)+c;
        i++;
    }
    double result = cmag(z);
    return result;
}

struct rgb_data *MandBMPpixels (double imgw, double imgh, double min_x, double max_x, double min_y, double max_y, struct rgb_data *pixels){
    double xIncr = (max_x - min_x)/imgw;
    double yIncr = (max_y - min_y)/imgh;
 //testing
    int image_size = imgw*imgh;

    for (double dy = 0; dy < imgh; dy++){
        for (double dx = 0; dx < imgw; dx++){
            int i = dy*imgw + dx;
            double complex z = (min_x + dx*xIncr) + (max_y-dy*yIncr)*I;
            if (mandItResult(z)<2){
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
