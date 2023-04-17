#include <stdio.h>
#include <stdlib.h> // rand, srand
#include <time.h> // time

int main() {
    int n,i;
    int *A;

    scanf("%d", &n);
    if(n<=0){ 
        return 0;
    }

    A = (int*) malloc(sizeof(int)*n);
    if(A==NULL) {
        return 0;
    }

    srand(time(NULL));
    //srand(404);
    for(i=0; i<n; i++) {
        A[i] = rand() % 1000;
    }

    for(i=0; i<n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    free(A);
    return 0;
}
