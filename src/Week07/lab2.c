#include <stdio.h>
#include <stdlib.h> // rand, srand
#include <time.h> // time

void selectionSort(int *A, int n) {
    int i,j,max,max_idx;

    for(i=0; i<n-1; i++) {
        max = A[0];
        max_idx = 0;

        for(j=1; j<n-i ;j++) {
            if(max<A[j]) {
                max=A[j];
                max_idx=j;
            }
        }

        //swap A[max_idx] <-> A[n-1-i]
        A[max_idx] = A[n-1-i];
        A[n-1-i] = max;
    }
}

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
    for(i=0; i<n; i++) {
        A[i] = rand() % 1000;
    }

    for(i=0; i<n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    selectionSort(A,n);

    for(i=0; i<n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    free(A);
    return 0;
}
