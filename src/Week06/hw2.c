#include <stdio.h>

void pick(char* signs, int n, int *picked, int m, int toPick) {
    int lastIndex, i;

    if(toPick==0) {
        for(i=0; i<m; i++)
            //printf("%d ", picked[i]);
            printf("%c ", signs[picked[i]]);
        printf("\n");
        return;
    }
    
    lastIndex = m - toPick -1; 

    for(i=0; i<n; i++) {
        picked[lastIndex+1] = i;
        pick(signs,n, picked, m, toPick-1);
    }
}

int main() {
    char signs[] = "+-";
    int picked[3];

    pick(signs,2, picked,3, 3);

    return 0;
}
