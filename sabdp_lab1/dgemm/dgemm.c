#include "dgemm.h"
#define MIN(X, Y) (((X) < (Y)) ? (X) : (Y))

void dgemm(int N, int C[N][N]){
    int A[N][N];
    int B[N][N];
    matgen(A, N);
    matgen(B, N);

    /*
    Write your DGEMM implementation here.

    DGEMM is:

        C = (ALPHA * A * B) + BETA*C
    
    Where A, B, C are all square matrixes NxN, ALPHA and BETA are scalar constants.

    For this laboratory, ALPHA and BETA will be set to 1.

    All the matrixes have been initialized to random values.

    You can access the element of any matrix X on the i-th row, j-th column with the c notion:

        X[i][j]

    The result must be stored in the C matrix.
    */



    /*End of student code, do not write anything outside the area delimited by these comments.*/ 

    return;
};

int main(int argc, char* argv[]){
    if(argc != 2){
        fprintf(stdout, "Command line format wrong, type ./dgemm N, where N is the dimension of the square matrix.\n");
        return 1;
    }
    int N;

    sscanf(argv[1], "%d", &N);

    int C[N][N];

    time_t seed = time(NULL);

    srand(seed);
    matgen(C, N);

    dgemm(N, C);

    valcheck(N, C, (long) seed);

    for(int i = 0; i < 10; i++){
        fprintf(stdout, "\nDoing dgemm %d...\n", i);
        matgen(C, N);
        dgemm(N, C);
    }
        

}



