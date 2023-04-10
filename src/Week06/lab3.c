#include <stdio.h>

void pick(char* actors[], int n, int *picked, int m, int toPick) {
    int lastIndex, smallest, i;

    if(toPick==0) {
        for(i=0; i<m; i++)
            printf("%d ", picked[i]);
        printf("\n");
        return;
    }
    
    lastIndex = m - toPick -1; 
    smallest = 0;

    for(i=smallest; i<n; i++) {
        int j=0; int flag=0;
        for(j=0; j<=lastIndex; j++)
            if(picked[j]==i) flag = 1;
        if(flag==1) continue;

        picked[lastIndex+1] = i;
        pick(actors, n, picked, m, toPick-1);
    }
}

int main() {
    char *actors[] = { "공유", "수현", 
        "송중기", "지성", "현빈"}; 
    int picked[2];

    pick(actors,5, picked,2, 2);

    return 0;
}
