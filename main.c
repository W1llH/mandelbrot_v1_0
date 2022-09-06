#include <stdio.h>
#include "mandelbrot.h"
#include <time.h>

int main() {

    clock_t start, end;
    double time_taken;

    start = clock();

    int width  = 2000, height = 2000, dpi = 100;

    unsigned int iterations = 255;

    save_mand_bmp("mandelbrot_testing255.bmp", width, height, dpi, -2, -1, -0.5, 0.5, iterations);

    end = clock();

    time_taken = ((double)end - start)/CLOCKS_PER_SEC;
    printf("The program took %lf seconds to complete.\n",time_taken);

    return 0;
}
