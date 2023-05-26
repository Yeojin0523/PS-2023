#include <stdio.h>
#include <stdlib.h>

int H(int n, int *memo) {
    int i=0;
    int j=0;
    int sum=0;

    if( memo[n] != 0 ) return memo[n];

    if( n==0 || n==1 ) return 1;

    for(i=0; i<n; i++)
        sum = sum + H(i,memo)*H(n-1-i,memo);
    memo[n] = sum;
    return memo[n];
}

int main() {
    int n,i;
    int *memo;
    printf("0보다 큰 정수:");
    scanf("%d", &n);
    memo = (int*) malloc(sizeof(int)*(n+1));
    for(i=0; i<n+1; i++)
        memo[i] = 0;

    printf("결과는 %d\n", H(n,memo));
    free(memo);
    return 0;
}
