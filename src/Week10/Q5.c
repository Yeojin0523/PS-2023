#include <stdio.h>
#include <stdlib.h>

int seq_search(int key, int *arr, int n) {
    int i;

    for(i=0; i<n; i++) {
        if( arr[i] == key )
            return i;
    }
    return -1;
}

int main() {
    int n,k,i,l;
    int *A, *B;

    scanf("%d", &n);
    scanf("%d", &k);
    scanf("%d", &l);

    A = (int*) malloc(sizeof(int)*n);
    B = (int*) malloc(sizeof(int)*k);

    for(i=0; i<n; i++)
        A[i] = i;

    for(i=0; i<k; i++)
        scanf("%d", &B[i]);
    //print A, B..

    for(i=0; i<k; i++) {
        int tmp;
        int pos = seq_search(B[i], A, n);
        // print pos
        // swap( A[pos] <-> A[pos-1]
        if(pos!=0){
            tmp = A[pos];
            A[pos] = A[pos-1];
            A[pos-1] = tmp;
        }
        // print A
    }

    printf("%d\n", A[l]);

    free(A);
    free(B);
    return 0;
}
