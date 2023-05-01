#include <stdio.h>
int main(void)
{
	int M, N;
	int location;
	char a[10][10];
	int i, j;

	scanf("%d", &M); // 6
	scanf("%d", &N); // 3
	scanf("%d", &location);

	for (i = 0; i < N; i++)
		scanf("%s", a[i]);

	for (i = 0; i < N; i++) {
		if (location - 1 >= 0 && a[i][location - 1] == '1') 
			location--;
		else if (location < M - 1 && a[i][location] == '1')
			location++;
	}
	printf("%d\n", location);
    return 0;
}
