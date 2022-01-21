//
//  main.c
//  Project_2
//
//  Created by Peishuo Cai on 2021-04-05.
//

#include <stdio.h>
#include "seamcarving.h"

int main() {
//    struct rgb_img *grad;
//    struct rgb_img *im;
//    double *best;
//    int *path;
//
//    read_in_img(&im, "6x5.bin");
//    print_grad(im);
//
//    calc_energy(im,  &grad);
//
//    print_grad(grad);
//    dynamic_seam(grad, &best);
//    recover_path(best, grad->height, grad->width, &path);
//    for (int i = 0; i < grad->height; i++){
//        printf("%d\n", path[i]);
//    }
    struct rgb_img *im;
    struct rgb_img *cur_im;
    struct rgb_img *grad;
    double *best;
    int *path;

    read_in_img(&im, "HJoceanSmall.bin");
       
    for(int i = 0; i < 5; i++){
        printf("i = %d\n", i);
        calc_energy(im,  &grad);
        dynamic_seam(grad, &best);
        recover_path(best, grad->height, grad->width, &path);
        remove_seam(im, &cur_im, path);
        
        char filename[200];
        sprintf(filename, "img%d.bin", i);
        write_img(cur_im, filename);


        destroy_image(im);
        destroy_image(grad);
        free(best);
        free(path);
        im = cur_im;
       }
       destroy_image(im);
}
