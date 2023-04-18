#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int n, k;
    char str_number1[64];
    char str_number2[64];
    int i = 0;
    int str_len;

    scanf("%d %d", &n, &k);

    memset( str_number1, 0x00, 64 );
    memset( str_number2, 0x00, 64 );

    while( n != 0 ) {
        if( k == 16 && n % k >= 10 )
            str_number1[i] = n % k + 'A';
        else
            str_number1[i] = n % k + '0'; 
        n = n / k;
        i++;
    }

    str_len = i;

    for( i=0; i<str_len; i++ )
        str_number2[i] = str_number1[str_len-i-1];
    
    printf("%s\n", str_number1);
    printf("%s\n", str_number2);

    printf("%d\n", !strcmp(str_number1, str_number2) );
    return 0;
}
