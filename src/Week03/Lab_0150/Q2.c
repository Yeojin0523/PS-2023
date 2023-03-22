#include<stdio.h>
#include<stdint.h>

unsigned long long reverse_number( unsigned long long n ){
    uint64_t ret = 0;
    int remainder = 0;

    while( n != 0 ) {
        remainder = n % 10;
        ret = ret * 10;
        ret = ret + remainder;
        n = n/10;
    }

    return ret;
}

void main() {
    unsigned long long number1,number2;
    unsigned long long input_number;
    int count = 0;

    scanf( "%llu", &input_number );

    number1 = input_number;

    number2 = reverse_number( number1 );
    while( number1 != number2 ) {
        count++;
        number1 = number2 + number1;
        number2 = reverse_number( number1 );
        if( count > 1000 ) {
            printf("NaN\n");
            return;
        }

    }

    printf( "%d %llu\n", count, number1 );
}
