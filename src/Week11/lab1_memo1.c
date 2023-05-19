#include <stdio.h>
#include <stdlib.h>

int fib(int n, int *memo) {
    if( n==1 || n==2)
        return 1;
    else
        if( memo[n-1] == 0)
            memo[n-1] = fib(n-1, memo);

        if( memo[n-2] == 0)
            memo[n-2] = fib(n-2, memo);
        return memo[n-1] + memo[n-2];
}

int main() {
    int n,i;
    int *memo;

    scanf("%d", &n);
    memo = (int*) malloc(sizeof(int)*(n+1));
    for(i=0; i<n+1; i++)
        memo[i]=0;

    printf("%d\n", fib(n,memo));
    free(memo);
    return 0;
}
