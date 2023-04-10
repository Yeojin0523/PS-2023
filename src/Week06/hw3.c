#include <stdio.h>

void pick(int *items,int n, int *picked, int m, int toPick) {
    int lastIndex, i, smallest;

    if(toPick==0) {
        for(i=0; i<m; i++)
            //printf("%d ", picked[i]);
            printf("%d ", items[picked[i]]);
        printf("\n");
        return;
    }
    
    lastIndex = m - toPick -1; 
    if(m==toPick)
        smallest = 0;
    else
        smallest = picked[lastIndex];

    for(i=smallest; i<n; i++) {
        picked[lastIndex+1] = i;
        pick(items,n, picked, m, toPick-1);
    }
}

int main() {
    int items[] = { 1000, 5000, 10000, 0};
    int picked[6];

    pick(items,4, picked,6, 6);

    return 0;
}
