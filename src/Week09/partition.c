#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int *A, int p, int r){
    int i,j;
    int t;

    i=p-1;

    for(j=p; j<r; j++){
        if( A[j] < A[r] ) {
            i++;
            //A[i] <-> A[j]
            t = A[i];
            A[i] = A[j];
            A[j] = t;
        }
    }

    i++;
    t = A[i];
    A[i] = A[r];
    A[r] = t;
    return i;
}

int main() {
    int A[] = {0, 20, 55, 66, 10, 40, 88, 77, 30, 49};
    int i;

    partition(A,0,9);

    for(i=0; i<10; i++) 
        printf("%d ", A[i] );
    printf("\n");

    return 0;
}
