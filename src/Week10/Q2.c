#include<stdio.h>
#include<stdlib.h>

int isSeq(int *A, int n) {
    int diff;
    int i;
    if(n==1)
        return 1;

    diff = A[1] - A[0];

    for(i=1; i<n-1; i++)
        if(diff != (A[i+1] - A[i]) )
            return 0;

    return 1;
}

void pick(int n, int *bucket, int m, int toPick,
        int Na, int *A, int Nb, int *B, int *seq, int *sum) {
    int lastIndex, i;
    if(toPick==0) {
        // B -> seq
        for(i=0; i<Nb; i++)
            seq[i] = B[i];

        // i = 0; A[0] -> seq[bucket[0]]
        // i = 1; A[1] -> seq[bucket[1]]
        // ...
        //      ; A[i] -> seq[bucket[i]]
        for(i=0; i<m; i++)
            seq[bucket[i]]=A[i];

        if(isSeq(seq, Nb) == 1) {
            int tmp  = 0;
            for(i=0; i<Nb; i++){
                printf("%d ", seq[i]);
                tmp = tmp + seq[i];
            }

            printf("(");
            for(i=0; i<m; i++)
                printf("%d ", bucket[i]);
            printf(")\n");
            // sum <- tmp
            // sum[0] = tmp;
            *sum = tmp;
        }
        return;
    }

    lastIndex = m - toPick - 1;

    for(i=0; i<n; i++) {
        int j; int flag=0;
        for(j=0; j<=lastIndex; j++) {
            if(bucket[j] == i){ //중복
                flag=1;
                break;
            }
        }
        if(flag==1) continue; //중복이면 다음 루프로.
        bucket[lastIndex+1] = i;
        pick(n, bucket,m, toPick-1, Na, A, Nb, B, seq, sum);
    }
}
int main() {
    int Na, Nb;
    int *A, *B;
    int *bucket, *seq;
    int i;
    int sum = -1;

    scanf("%d", &Na);
    A = (int*) malloc(sizeof(int)*Na);
    bucket = (int*) malloc(sizeof(int)*Na);
    for(i=0; i<Na; i++)
        scanf("%d", &A[i]);

    scanf("%d", &Nb);
    B = (int*) malloc(sizeof(int)*Nb);
    seq = (int*) malloc(sizeof(int)*Nb);
    for(i=0; i<Nb; i++)
        scanf("%d", &B[i]);

    pick(Nb, bucket,Na, Na, Na,A, Nb,B, seq, &sum);
    printf("Sum = %d\n", sum);

    free(A);
    free(B);
    free(bucket);
    free(seq);
    return 0;
}
