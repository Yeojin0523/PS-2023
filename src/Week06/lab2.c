#include <stdio.h>

void pick(char* actors[], int n, int *picked, int m, int toPick) {
    int lastIndex, smallest, i;

    if(toPick==0) {
        for(i=0; i<m; i++)
            //printf("%d ", picked[i]);
            printf("%s ", actors[picked[i]]);
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
        pick(actors, n, picked, m, toPick-1);
    }
}

int main() {
    char *actors[] = { "공유", "수현", 
        "송중기", "지성", "현빈"}; 
    int picked[3];

    pick(actors,5, picked,3, 3);

    return 0;
}
