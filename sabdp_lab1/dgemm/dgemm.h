#ifndef DGEMM_H
#define DGEMM_H
#define ALPHA 1
#define BETA 1

#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int valcheck(int N, int C[N][N], long seed){
    FILE* f = fopen("file", "w");

    if(f == NULL){
        fprintf(stdout, "\nImpossible to open file.\n");
        exit(1);
    }
    
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            fprintf(f, "%d ", C[i][j]);
        }
    }

    fclose(f);

    char commandline[1000];
    sprintf(commandline, "./valcheck %d %ld", N, seed);

    int check = 1;
    check = system(commandline);

    if(check){
        fprintf(stdout, "\nERROR IN DGEMM, please correct your implementation\n");
    }
    else{
        fprintf(stdout, "\nImplementation correct! Evaluate performance using a profiler.\n");
    }

    system("rm file");

};

void matgen(int* A, int N){
    for(int i = 0; i < N * N; i++){
        A[i] = rand()/100000000;
    }
};

#endif
