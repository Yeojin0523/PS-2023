#include <stdio.h>

/*
int sorted_seq_search(int key, int arr[], int n) {
    int i;

    for(i=0; i<n; i++) {
        if( arr[i] == key )
            return i;
    }
    return -1;
}
*/

int sorted_seq_search(int key, int arr[], int low, int high) {
    int i;

    for(i=low; i<=high; i++) {
        if( arr[i] == key )
            return i;
    }
    return -1;
}

int main() {
    int arr[] = {2,3,5,7,8,9};
    int key;

    scanf("%d", &key);
    printf("%d\n", sorted_seq_search(key, arr, 0, sizeof(arr)/sizeof(int)-1));

    return 0;
}