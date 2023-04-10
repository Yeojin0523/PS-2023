#include <stdio.h>

void pick(int n, int *picked, int m, int toPick) {
    int lastIndex, i;

    if(toPick==0) {
        for(i=0; i<m; i++)
            printf("%d ", picked[i]);
        printf("\n");
        return;
    }
    
    lastIndex = m - toPick -1; 

    for(i=0; i<n; i++) {
        picked[lastIndex+1] = i;
        pick(n, picked, m, toPick-1);
    }
}

int main() {
    int picked[3];

    pick(4, picked,3, 3);

    return 0;
}
