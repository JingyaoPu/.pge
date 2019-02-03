//
//  main.c
//  adv.algo1
//
//  Created by Jingyao Pu on 1/28/19.
//  Copyright © 2019 Jingyao Pu. All rights reserved.
//

#include <stdio.h>
#include <time.h>
#include "imageio.h"
#include "picelsCal.h"
int main(int argc, const char * argv[]) {
    clock_t start, end;
    double cpu_time_used;
    
    unsigned char **image;
    unsigned char **image2;
    int rows,cols;
    char infilename[] = "blocks.pgm";
    start = clock();
    clock_t readStart = clock();
    read_pgm_image(infilename, &image, &rows, &cols);
    clock_t readEnd = clock();
    cpu_time_used = ((double) (readEnd - readStart)) / CLOCKS_PER_SEC;
    printf("Reading %s took %f seconds to execute\n", infilename, cpu_time_used);
    printf("The size of %s is %d pixels\n",infilename,rows*cols);
    clock_t CalStart = clock();
    pixelsCalculator(image, rows, cols);
    clock_t CalEnd = clock();
    cpu_time_used = ((double) (CalEnd - CalStart)) / CLOCKS_PER_SEC;
    printf("Computing %s took %f seconds to execute\n", infilename, cpu_time_used);
    free_image(image, rows);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%s took %f seconds to execute\n", infilename, cpu_time_used);
    
    start = clock();
    char infilename2[] = "building.pgm";
    readStart = clock();
    read_pgm_image(infilename2, &image2, &rows, &cols);
    readEnd = clock();
    cpu_time_used = ((double) (readEnd - readStart)) / CLOCKS_PER_SEC;
    printf("Reading %s took %f seconds to execute\n", infilename2, cpu_time_used);
    printf("The size of %s is %d pixels\n",infilename2,rows*cols);
    CalStart = clock();
    pixelsCalculator(image2, rows, cols);
    CalEnd = clock();
    cpu_time_used = ((double) (CalEnd - CalStart)) / CLOCKS_PER_SEC;
    printf("Computing %s took %f seconds to execute\n", infilename, cpu_time_used);
    free_image(image2, rows);
    end = clock();
    cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    printf("%s took %f seconds to execute\n", infilename2, cpu_time_used);
    return 0;
}

