#include <stdio.h>
#include <stdlib.h> // rand, srand
#include <time.h> // time

void selectionSortByAsc(int *A, int n, int k) {
    int i,j,max,max_idx;

    for(i=0; i<k; i++) {
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

void selectionSortByDesc(int *A, int n, int k) {
    int i,j,min,min_idx;

    for(i=0; i<k; i++) {
        min = A[0];
        min_idx = 0;

        for(j=1; j<n-i ;j++) {
            if(min>A[j]) {
                min=A[j];
                min_idx=j;
            }
        }

        //swap A[min_idx] <-> A[n-1-i]
        A[min_idx] = A[n-1-i];
        A[n-1-i] = min;
    }
}


int main() {
    int n,k,i;
    int *A, *B;
    int sum = 0;

    scanf("%d", &n);
    scanf("%d", &k);
    if(n<=0 || n<k){ 
        return 0;
    }

    A = (int*) malloc(sizeof(int)*n);
    B = (int*) malloc(sizeof(int)*n);
    if(A==NULL || B==NULL) {
        return 0;
    }

    for(i=0; i<n; i++) 
        scanf("%d", &A[i]);

    for(i=0; i<n; i++) 
        scanf("%d", &B[i]);

    /*
    for(i=0; i<n; i++)
        printf("%d ", A[i]);
    printf("\n");

    for(i=0; i<n; i++)
        printf("%d ", B[i]);
    printf("\n");
    */

    selectionSortByAsc(A,n,k);
    selectionSortByDesc(B,n,k);

    for(i=0; i<k; i++)
        B[n-i-1] = A[n-i-1];

    for(i=0; i<n; i++)
        sum = sum + B[i];

    printf("%d\n", sum);

    
    /*
    for(i=0; i<n; i++) {
        printf("%d ", B[i]);
    }
    printf("\n");*/

    free(A);
    free(B);
    return 0;
}
