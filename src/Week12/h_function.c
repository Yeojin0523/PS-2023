#include <stdio.h>

int H(int n) {
    int i=0;
    int j=0;
    int sum=0;

    if( n==0 || n==1 ) return 1;

    /*
    for(i=0; i<n; i++)
        sum = sum + H(i)*H(n-1-i);*/
    for(i=0,j=n-1; i<n; i++,j--)
        sum = sum + H(i)*H(j);
    return sum;
}

int main() {
    int n;
    printf("0보다 큰 정수:");
    scanf("%d", &n);
    printf("결과는 %d\n", H(n));
    return 0;
}
