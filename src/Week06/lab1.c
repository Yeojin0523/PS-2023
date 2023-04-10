#include <stdio.h>

void pick(char* balls, int n, int *picked, int m, int toPick) {
    int lastIndex, smallest, i;

    if(toPick==0) {
        for(i=0; i<m; i++)
            //printf("%d ", picked[i]);
            printf("%c ", balls[picked[i]]);
        printf("\n");
        return;
    }
    
    lastIndex = m - toPick -1;
    if(toPick == m)
        smallest = 0;
    else
        smallest = picked[lastIndex] + 1;

    for(i=smallest; i<n; i++) {
        picked[lastIndex+1] = i;
        pick(balls, n, picked, m, toPick-1);
    }
}

int main() {
    char balls[] = "ABCDEFGH";
    int picked[3];

    pick(balls,8, picked,3, 3);

    return 0;
}
