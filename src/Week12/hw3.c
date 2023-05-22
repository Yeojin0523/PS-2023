#include <stdio.h>
#include <stdlib.h>

void pick(int *items,int n, int *picked, 
        int m, int toPick, int exchange) {
    int lastIndex, i, smallest;
    int sum=0;

    if(toPick==0) {
        for(i=0; i<m; i++)
            sum = sum + items[picked[i]];
        if(sum == exchange) {
            for(i=0; i<m; i++)
                printf("%d ", items[picked[i]]);
            printf("\n");
        }
        return;
    }

    lastIndex = m - toPick -1; 
    for(i=0; i<=lastIndex; i++) 
        sum = sum + items[picked[i]];

    if(sum>exchange)
        return;

    if(m==toPick)
        smallest = 0;
    else
        smallest = picked[lastIndex];

    for(i=smallest; i<n; i++) {
        picked[lastIndex+1] = i;
        pick(items,n, picked, m, toPick-1, exchange);
    }
}

int main() {
    int items[] = { 1000, 5000, 10000, 0};
    int *picked;
    int picked_size;
    int exchange;

    scanf("%d", &exchange);

    picked_size = exchange/1000;
    picked = (int*) malloc(sizeof(int)*picked_size);

    pick(items,4, picked,picked_size, 
            picked_size, exchange);

    free(picked);
    return 0;
}
