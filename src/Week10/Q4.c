#include <stdio.h>
#include <stdlib.h> // rand, srand
#include <limits.h>  // INT_MIN

void pick(char* ops, int n, int *bucket, int m, int toPick,
        int *A, int *global_sum) {
    int i, lastIndex;

    if( toPick == 0) {
        int sum = 0;
        for(i=0; i<m; i++)
            printf("%c%d ", ops[bucket[i]], A[i]);
        for(i=0; i<m; i++) {
            if( ops[bucket[i]] == '+' )
                sum = sum + A[i];
            else if( ops[bucket[i]] == '-' )
                sum = sum - A[i];
            else if( ops[bucket[i]] == '*' )
                sum = sum * A[i];
        }
        printf(" = %d\n", sum);

        if( *global_sum < sum ) // global_sum[0]
            *global_sum = sum;
        return;
    }

    lastIndex = m - toPick - 1;

    for(i=0; i<n; i++) {
        if( m==toPick && i == 2) continue;
        bucket[lastIndex+1] = i;
        pick(ops,n, bucket,m, toPick-1, A, global_sum);
    }
}

int main() {
    int n,i;
    int *A, *bucket;
    char ops[] = "+-*";
    int global_sum;

    scanf("%d", &n);

    A = (int*) malloc(sizeof(int)*n);
    bucket = (int*) malloc(sizeof(int)*n);

    for(i=0; i<n; i++) 
        scanf("%d", &A[i]);

    global_sum = INT_MIN;
    pick(ops,3, bucket,n, n, A, &global_sum); 
    printf("%d\n", global_sum);

    /*
    for(i=0; i<n; i++)
        printf("%d ", A[i]);
    printf("\n");
    */


    free(A);
    free(bucket);
    return 0;
}
