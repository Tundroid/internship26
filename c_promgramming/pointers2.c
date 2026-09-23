#include <stdio.h>

int main(){
    int arr[] = {0, 10, 60, 100, -1};
    printf("Address of array: %34lld", arr);
    printf("\nAddress of array first element: %20lld", arr+1);
    printf("\nAddress of array first element: %20lld", arr+2);
    // using HEX
    
    printf("\nAddress of array: %34p", arr);
    printf("\nAddress of array first element: %20p", arr+1);
    printf("\nAddress of array first element: %20p", arr+2);

    return 0;
}