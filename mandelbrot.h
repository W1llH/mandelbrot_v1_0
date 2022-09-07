#ifndef MANDELBROT_V1_0_MANDELBROT_H
#define MANDELBROT_V1_0_MANDELBROT_H

#include <math.h>
#include <complex.h>
#include <memory.h>

double cmag2 (const double complex z) {
    double magnitude = pow(creal(z),2)+pow(cimag(z),2);
    return magnitude;
}

struct rgb_data{
    unsigned char r, g, b; //24 bit pixel
};

void save_mand_bmp(const char *file_name, const int width, const int height, const int dpi, const double min_x, const double max_x, const double min_y, const double max_y, const unsigned iterations){
    FILE *image;

    int image_size = width*height; //number of pixels

    int file_size = 54 + 3*image_size; /*in bytes, 14 for file header, 40 for image header and
                                         3 bytes per pixel for 24 bit pixel */
    int ppm = dpi*(int)39.37; //pixels per meter


    struct bmp_file_header{           //file header, 14 bytes
        unsigned char bitmap_type[2]; //2 bytes
        int           file_size;      //4 bytes
        short         reserved1;      //2 bytes
        short         reserved2;      //2 bytes
        unsigned int  offset_bits;    //4 bytes
    } bfh;

    struct bmp_image_header{           //image header, 40 bytes
        unsigned int header_size;      //in bytes, 40 for this header
        unsigned int width;            //4 bytes, in pixels
        unsigned int height;           //4 bytes, in pixels
        short int    colour_planes;     //2 bytes, has to be 1
        short int    bits_per_pixel;    //2 bytes, normally 24
        unsigned int compression_type; //default 0
        unsigned int image_size;       //4 bytes, same as file
        unsigned int ppm_x;            //4 bytes, pixels per metre horizontally
        unsigned int ppm_y;            //4 bytes, pixels per metre vertically
        unsigned int clr_used;         //4 bytes, colours used in the colour palette, 0 for default
        unsigned int clr_important;    //4 bytes, number of important colours used, 0 when every colour is important
    } bih;

    memcpy(&bfh.bitmap_type,"BM",2);
    bfh.file_size   = file_size;
    bfh.reserved1   = 0;
    bfh.reserved2   = 0;
    bfh.offset_bits = 0;

    bih.header_size      = sizeof(bih);
    bih.width            = width;
    bih.height           = height;
    bih.colour_planes    = 1;
    bih.bits_per_pixel   = 24;
    bih.compression_type = 0;
    bih.image_size       = file_size;
    bih.ppm_x            = ppm;
    bih.ppm_y            = ppm;
    bih.clr_used         = 0;
    bih.clr_important    = 0;

    image = fopen(file_name, "wb");
    fwrite(&bfh,14,1,image);
    fwrite(&bih, sizeof(bih), 1, image);

    double xIncr = (max_x - min_x)/width;
    double yIncr = (max_y - min_y)/height;

    for (unsigned int dy = (unsigned int)height; dy--;){
        for (unsigned int dx = (unsigned int)width; dx--;){
            double complex c = (max_x - (double)dx*xIncr) + (max_y - (double)dy*yIncr)*I;
            unsigned int itr = 0;
            double complex z=0;
            do {
                z = cpow(z, 2) + c;
                itr++;
            }
            while (cmag2(z) < 4 && itr < iterations);
            unsigned char red = (unsigned char)(((float)itr/(float)iterations)*255);
            unsigned char green = (unsigned char)(((float)itr/(float)iterations)*255);
            unsigned char blue = (unsigned char)(((float)itr/(float)iterations)*255);

            unsigned char colour[3] = {blue, green, red};

            fwrite(colour, sizeof(colour), 1, image);
            }
        }
    fclose(image);
}

#endif //MANDELBROT_V1_0_MANDELBROT_H