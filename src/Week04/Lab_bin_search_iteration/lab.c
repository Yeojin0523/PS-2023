#include <stdio.h>

/*
int bin_search_loop(int key, int arr[], int n) {
    int middle, low, high;

    low = 0;
    high = n-1;

    do{
        middle = (low + high) / 2;
        if( arr[middle] == key )
            return middle;
        else if ( arr[middle] > key )
            high = middle -1;
        else
            low = middle + 1;
    }while( low <= high );
    
    return -1;
}
*/

int bin_search_loop(int key, int arr[], int low, int high) {
    int middle;

    do{
        middle = (low + high) / 2;
        if( arr[middle] == key )
            return middle;
        else if ( arr[middle] > key )
            high = middle -1;
        else
            low = middle + 1;
    }while( low <= high );

    return -1;
}

int main() {
    int arr[] = {2,3,5,7,8,9};
    int key;

    scanf("%d", &key);
    printf("%d\n", bin_search_loop(key, arr, 0, sizeof(arr)/sizeof(int)-1));

    return 0;
}