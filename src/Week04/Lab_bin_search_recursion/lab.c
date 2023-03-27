#include <stdio.h>

int bin_search_recursion(int key, int arr[], int low, int high) {
    int middle;

    if( low > high )
        return -1;

    middle = (low + high) / 2;
    
    if( arr[middle] == key )
        return middle;
    else if ( arr[middle] > key )
        return bin_search_recursion(key, arr, low, middle -1);
    else
        return bin_search_recursion(key, arr, middle + 1, high);
}

int main() {
    int arr[] = {2,3,5,7,8,9};
    int key;

    scanf("%d", &key);
    printf("%d\n", bin_search_recursion(key, arr, 0, sizeof(arr)/sizeof(int)-1));

    return 0;
}