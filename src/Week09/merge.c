#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int *A, int p, int q, int r, int *temp) {
    int i,j,t;

    i = p;
    j = q+1;
    t = p;

    while( i<=q && j<=r ) {
        if( A[i] < A[j] ) {
            temp[t] = A[i];
            t++; i++;
        }
        else {
            temp[t] = A[j];
            t++; j++;
        }
    }

    if(j>r) {
        for( ; i<=q; i++, t++)
            temp[t] = A[i];
    }
    else{
        for( ; j<=r; j++, t++)
            temp[t] = A[j];
    }

    for(i=p; i<=r; i++)
        A[i] = temp[i];
}

int main() {
    int A[] = {10, 20, 30, 70, 80, 11, 33, 44, 55, 66};
    int *temp;
    int i;

    temp = (int*) malloc(sizeof(int)*10);
    if(temp==NULL) {
        return 0;
    }

    merge(A,0,4,9,temp);

    for(i=0; i<10; i++) 
        printf("%d ", A[i] );
    printf("\n");

    free(temp);
    return 0;
}
