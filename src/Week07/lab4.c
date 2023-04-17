#include <stdio.h>
#include <stdlib.h> // rand, srand
#include <time.h> // time

void insertionSort(int *A, int n) {
    int i,j,k;
    int tmp;

    for(i=1; i<n; i++) {
        //A[i] : to be inserted
        for(j=0; j<i; j++)
            if(A[i]<A[j])
                break;
        //j : position(index) for A[i]
        tmp = A[i];
        //movement
        for(k=i; k>j ;k--)
            A[k] = A[k-1];
            //A[j+1] = A[j]
        
        //insertion
        A[j] = tmp;
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

    insertionSort(A,n);

    for(i=0; i<n; i++) {
        printf("%d ", A[i]);
    }
    printf("\n");

    free(A);
    return 0;
}
