//
//  seamcarving.c
//  Project_2
//
//  Created by Peishuo Cai on 2021-04-05.
//

#include <stdio.h>
#include "seamcarving.h"
#include <math.h>
#define MIN(a,b) (((a)<(b))?(a):(b))


size_t square(size_t num){
    return (num)*(num);
}

void calc_energy(struct rgb_img *im, struct rgb_img **grad){
    create_img(grad, im->height, im->width);
//    printf("%d\n", im->width);
    for (int i = 0; i < im->height; i++){
        for(int j = 0; j < im->width; j++){
            double horizontal;
            double vertical;
            if (i==0 && j == 0){
                horizontal = square(get_pixel(im, i, j+1, 0) - get_pixel(im, i, im->width-1, 0)) + square(get_pixel(im, i, j+1, 1) - get_pixel(im, i, im->width-1, 1)) + square(get_pixel(im, i, j+1, 2) - get_pixel(im, i, im->width-1, 2));
                vertical = square(get_pixel(im, i+1, j, 0) - get_pixel(im, im->height-1, j, 0)) + square(get_pixel(im, i+1, j, 1) - get_pixel(im, im->height-1, j, 1)) + square(get_pixel(im, i+1, j, 2) - get_pixel(im, im->height-1, j, 2));
            }
            else if (i == im->height-1 && j == im->width-1){
                horizontal = square(get_pixel(im, i, 0, 0) - get_pixel(im, i, j-1, 0)) + square(get_pixel(im, i, 0, 1) - get_pixel(im, i, j-1, 1)) + square(get_pixel(im, i, 0, 2) - get_pixel(im, i, j-1, 2));
                vertical = square(get_pixel(im, 0, j, 0) - get_pixel(im, i-1, j, 0)) + square(get_pixel(im, 0, j, 1) - get_pixel(im, i-1, j, 1)) + square(get_pixel(im, 0, j, 2) - get_pixel(im, i-1, j, 2));
            }
            else if (i == 0 && j == im->width-1){
                horizontal = square(get_pixel(im, i, 0, 0) - get_pixel(im, i, j-1, 0)) + square(get_pixel(im, i, 0, 1) - get_pixel(im, i, j-1, 1)) + square(get_pixel(im, i, 0, 2) - get_pixel(im, i, j-1, 2));
                vertical = square(get_pixel(im, i+1, j, 0) - get_pixel(im, im->height-1, j, 0)) + square(get_pixel(im, i+1, j, 1) - get_pixel(im, im->height-1, j, 1)) + square(get_pixel(im, i+1, j, 2) - get_pixel(im, im->height-1, j, 2));
            }
            else if (i == im->height-1 && j == 0){
                horizontal = square(get_pixel(im, i, j+1, 0) - get_pixel(im, i, im->width-1, 0)) + square(get_pixel(im, i, j+1, 1) - get_pixel(im, i, im->width-1, 1)) + square(get_pixel(im, i, j+1, 2) - get_pixel(im, i, im->width-1, 2));
                vertical = square(get_pixel(im, 0, j, 0) - get_pixel(im, i-1, j, 0)) + square(get_pixel(im, 0, j, 1) - get_pixel(im, i-1, j, 1)) + square(get_pixel(im, 0, j, 2) - get_pixel(im, i-1, j, 2));
            }
            else if (i == 0){
                horizontal = square(get_pixel(im, i, j+1, 0) - get_pixel(im, i, j-1, 0)) + square(get_pixel(im, i, j+1, 1) - get_pixel(im, i, j-1, 1)) + square(get_pixel(im, i, j+1, 2) - get_pixel(im, i, j-1, 2));
                vertical = square(get_pixel(im, i+1, j, 0) - get_pixel(im, im->height-1, j, 0)) + square(get_pixel(im, i+1, j, 1) - get_pixel(im, im->height-1, j, 1)) + square(get_pixel(im, i+1, j, 2) - get_pixel(im, im->height-1, j, 2));
//                printf("%lf\n", horizontal);
//                printf("%lf\n", vertical);
            }
            else if (j == 0){
                horizontal = square(get_pixel(im, i, j+1, 0) - get_pixel(im, i, im->width-1, 0)) + square(get_pixel(im, i, j+1, 1) - get_pixel(im, i, im->width-1, 1)) + square(get_pixel(im, i, j+1, 2) - get_pixel(im, i, im->width-1, 2));
                vertical = square(get_pixel(im, i+1, j, 0) - get_pixel(im, i-1, j, 0)) + square(get_pixel(im, i+1, j, 1) - get_pixel(im, i-1, j, 1)) + square(get_pixel(im, i+1, j, 2) - get_pixel(im, i-1, j, 2));
            }
            else if (i == im->height-1){
                horizontal = square(get_pixel(im, i, j+1, 0) - get_pixel(im, i, j-1, 0)) + square(get_pixel(im, i, j+1, 1) - get_pixel(im, i, j-1, 1)) + square(get_pixel(im, i, j+1, 2) - get_pixel(im, i, j-1, 2));
                vertical = square(get_pixel(im, 0, j, 0) - get_pixel(im, i-1, j, 0)) + square(get_pixel(im, 0, j, 1) - get_pixel(im, i-1, j, 1)) + square(get_pixel(im, 0, j, 2) - get_pixel(im, i-1, j, 2));
            }
            else if (j == im->width-1){
                horizontal = square(get_pixel(im, i, 0, 0) - get_pixel(im, i, j-1, 0)) + square(get_pixel(im, i, 0, 1) - get_pixel(im, i, j-1, 1)) + square(get_pixel(im, i, 0, 2) - get_pixel(im, i, j-1, 2));
                vertical = square(get_pixel(im, i+1, j, 0) - get_pixel(im, i-1, j, 0)) + square(get_pixel(im, i+1, j, 1) - get_pixel(im, i-1, j, 1)) + square(get_pixel(im, i+1, j, 2) - get_pixel(im, i-1, j, 2));
            }
            else{
                horizontal = square(get_pixel(im, i, j+1, 0) - get_pixel(im, i, j-1, 0)) + square(get_pixel(im, i, j+1, 1) - get_pixel(im, i, j-1, 1)) + square(get_pixel(im, i, j+1, 2) - get_pixel(im, i, j-1, 2));
//                printf("%d\n",get_pixel(im, i, j+1, 2));
//                printf("%d\n",get_pixel(im, i, j-1, 2));
//                printf("%zu\n",square(get_pixel(im, i, j+1, 2) - get_pixel(im, i, j-1, 2)));
                vertical = square(get_pixel(im, i+1, j, 0) - get_pixel(im, i-1, j, 0)) + square(get_pixel(im, i+1, j, 1) - get_pixel(im, i-1, j, 1)) + square(get_pixel(im, i+1, j, 2) - get_pixel(im, i-1, j, 2));
//                uint8_t energy = (sqrt(horizontal + vertical))/10;
//                printf("%u\n",energy);
            }
            uint8_t energy = (sqrt(horizontal + vertical))/10;
            set_pixel(*grad, i, j, energy, energy, energy);
        }
    }
}

double min_3(size_t a, size_t b, size_t c){
    
    return MIN(MIN(a,b),c);
}

void dynamic_seam(struct rgb_img *grad, double **best_arr){
    *best_arr = malloc(sizeof(double)*((grad->height)*(grad->width)));
    for (int i = 0; i < grad->height; i++){
        for(int j = 0; j < grad->width; j++){
            if (i == 0){
                (*best_arr)[(i*(grad->width))+j] = get_pixel(grad, i, j, 0);
            }
            else if (j == grad->width-1){
                (*best_arr)[(i*(grad->width))+j] = MIN(get_pixel(grad, i-1, j-1, 0), get_pixel(grad, i-1, j, 0)) + get_pixel(grad, i, j, 0);
            }
            else if (j == 0){
                (*best_arr)[(i*(grad->width))+j] = MIN(get_pixel(grad, i-1, j+1, 0), get_pixel(grad, i-1, j, 0)) + get_pixel(grad, i, j, 0);
            }
            else{
                (*best_arr)[(i*(grad->width))+j] = min_3(get_pixel(grad, i-1, j-1, 0), get_pixel(grad, i-1, j, 0), get_pixel(grad, i-1, j+1, 0)) + get_pixel(grad, i, j, 0);
            }
            if (i != 1 && i != 0 && j == grad->width-1){
                (*best_arr)[(i*(grad->width))+j] = (*best_arr)[(i*(grad->width))+j] - MIN(get_pixel(grad, i-1, j-1, 0), get_pixel(grad, i-1, j, 0)) + MIN((*best_arr)[((i-1)*(grad->width))+j], (*best_arr)[((i-1)*(grad->width))+j-1]);
            }
            else if (i != 1 && i != 0 && j == 0){
                (*best_arr)[(i*(grad->width))+j] = (*best_arr)[(i*(grad->width))+j] - MIN(get_pixel(grad, i-1, j-1, 0), get_pixel(grad, i-1, j, 0)) + MIN((*best_arr)[((i-1)*(grad->width))+j], (*best_arr)[((i-1)*(grad->width))+j+1]);
            }
            else if (i != 1 && i != 0){
                (*best_arr)[(i*(grad->width))+j] = (*best_arr)[(i*(grad->width))+j] - min_3(get_pixel(grad, i-1, j-1, 0), get_pixel(grad, i-1, j, 0), get_pixel(grad, i-1, j+1, 0)) + min_3((*best_arr)[((i-1)*(grad->width))+j], (*best_arr)[((i-1)*(grad->width))+j-1], (*best_arr)[((i-1)*(grad->width))+j+1]);
            }
//            printf("%lf\n", (*best_arr)[(i*(grad->width))+j]);
        }
    }
}

void recover_path(double *best, int height, int width, int **path){
    *path = malloc(sizeof(int)*height);
//    printf("dub%lf\n\n", best[3]);
    for (int i = height-1; i > -1; i--){
        if (i == height-1){
            int small = best[(i*(width))];
            for(int j = width-1; j > -1; j--){
                small = MIN(small,best[(i*(width) + j)]);
            }
            for(int j = width-1; j > -1; j--){
                if (small == best[(i*(width) + j)]){
                    (*path)[i] = j;
                }
            }
        }
        else{
            int small;
            if ((*path)[i+1] == (width-1)){
                small = MIN(best[(i*(width) + ((*path)[i+1])-1)], best[(i*(width) + (*path)[i+1])]);
            }
            else if ((*path)[i+1] == 0){
                small = MIN(best[(i*(width) + ((*path)[i+1])+1)], best[(i*(width) + (*path)[i+1])]);
            }
            else{
                small = min_3(best[(i*(width) + ((*path)[i+1])-1)], best[(i*(width) + (*path)[i+1]+1)], best[(i*(width) + (*path)[i+1])]);
            }
//            printf("%d\n", small);
//            printf("thing%lf\n", best[(i*(width) + (*path)[i+1])]);
            for (int m = -1; m < 2; m++){
//                printf("%lf\n", best[(i*(width) + (*path)[i+1]+m)]);
                if (best[(i*(width) + (*path)[i+1]+m)] == small){
//                    printf("good\n");
//                    printf("th%d\n", (*path)[i+1]+m);
                    (*path)[i] = ((*path)[i+1]+m);
                }
            }
        }
//        printf("%d\n", (*path)[i]);
    }
}

void remove_seam(struct rgb_img *src, struct rgb_img **dest, int *path){
    create_img(dest, src->height, src->width-1);
    for (int i = 0; i < src->height; i++){
        int k = 0;
        for(int j = 0; j < src->width; j++){
            if (j == (path[i])){
                j = j + 1;
            }
            set_pixel(*dest, i, k, get_pixel(src, i, j, 0), get_pixel(src, i, j, 1), get_pixel(src, i, j, 2));
            k++;
        }
    }
}

