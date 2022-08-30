cmake_minimum_required(VERSION 3.22)
project(mandelbrot_v1_0 C)

set(CMAKE_C_STANDARD 99)

add_executable(mandelbrot_v1_0 main.c mandelbrot.h bmp.h)
