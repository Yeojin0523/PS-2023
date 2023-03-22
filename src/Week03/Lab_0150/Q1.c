#include<stdio.h>

void main() {
    int number1, number2;
    int remainder1, remainder2;
    int carry = 0;
    int carry_count = 0;

    scanf( "%d %d", &number1, &number2 );

    while( number1 != 0 || number2 != 0 ) {
        remainder1 = number1 % 10;
        remainder2 = number2 % 10;

        if( remainder1 + remainder2 + carry >= 10 ) {
            carry = 1;
            carry_count++;
        }
        else 
            carry = 0;

        number1 = number1 / 10;
        number2 = number2 / 10;
    }

    printf( "%d\n", carry_count );
}