#include <stdio.h>
#include <time.h>
#include <malloc.h>
#include "mandelbrot.h"

int main() {

    clock_t start, end;
    double time_taken;

    start = clock();

    struct mand_bmp_parameters *mandp = (struct mand_bmp_parameters *)malloc(sizeof(struct mand_bmp_parameters));

    mandp->ptr_file_name = "mandelbrot_testing80_-1_0_0_1.bmp";
    mandp->width = 2000;
    mandp->height = 2000;
    mandp->dpi = 100;
    mandp->min_x = -1;
    mandp->max_x = 0;
    mandp->min_y = 0;
    mandp->max_y = 1;
    mandp->iterations = 80;

    save_mand_bmp(mandp);

    end = clock();

    time_taken = ((double)end - start)/CLOCKS_PER_SEC;
    printf("The program took %lf seconds to complete.\n",time_taken);

    return 0;
}
