//
//  picelsCal.c
//  adv.algo1
//
//  Created by Nic Pu on 1/28/19.
//  Copyright © 2019 Nic Pu. All rights reserved.
//

#include <stdio.h>
#include "imageio.h"

/*******************************************************************************
 print_img() prints the pix value matrix of image.
 Primarily for test.
 *******************************************************************************/
int print_img(unsigned char **image,int rows, int cols){
    printf("rows:%d,cols:%d\n",rows,cols);
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            printf("%d ", (unsigned char)image[i][j]);
        }
        printf("\n");
    }
    return 0;
}

/*******************************************************************************
 pixelsCalculator() calculates the required data in the project.
 *******************************************************************************/
int pixelsCalculator(unsigned char **image,int rows, int cols){
    int pixels = rows*cols;
    int darkest = 255;
    int lightest = 0;
    int mean;
    int pixelsCount = 0;
    for(int i=0;i<rows;i++){
        for(int j=0;j<cols;j++){
            if (image[i][j]>lightest){
                lightest = (int)image[i][j];
            }
            if (image[i][j]<darkest){
                darkest = (int)image[i][j];
            }
            pixelsCount += (int)image[i][j];
        }
    }
    mean = pixelsCount/pixels;
    printf("Minimum  = %d\n",darkest);
    printf("Maximum  = %d\n",lightest);
    printf("Average  = %d\n",mean);
    return 0;
}
