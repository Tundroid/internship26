#include <stdio.h>

int main(){
    int number = 100;
    int *ptr_number = &number;
    printf("Size of number: %zu\n", sizeof(number));
    printf("Size of pointer: %zu\n", sizeof(ptr_number));
    printf("Address of number: %p\n", &number);
    printf("Again, address of number: %p\n", ptr_number);
    printf("Again, address of number: %d\n", (long)ptr_number);
    return 0;
}