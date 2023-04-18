#include <stdio.h>
int calDigits(int n)
{
	int result = 1;
	int i;
	while (n != 0) {
		n /= 10;
		result *= 10;
	}
	return result / 10;
}

int main(void)
{
	int n;
	int count = 0;
	int tmpNum, nextDigit, tmpNum2;
	int jarisu;
	scanf("%d", &n);

	jarisu = calDigits(n * 9);
	tmpNum = tmpNum2 = n * 9;
	do {
		nextDigit = tmpNum2 / jarisu;
		printf("%d ", nextDigit);
		tmpNum2 %= jarisu;
		jarisu /= 10;
		tmpNum /= 10;
	} while (tmpNum != 0);
    return 0;
}
