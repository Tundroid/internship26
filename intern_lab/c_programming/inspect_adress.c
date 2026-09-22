#include <stdio.h>

int main(void)
{
    int age = 25;
    int *ptr = &age;

    printf("Value of age: %d\n", age);
    printf("Address of age: %p\n", (void *)&age);
    printf("Value stored in ptr: %p\n", (void *)ptr);
    printf("Value obtained by dereferencing ptr: %d\n", *ptr);

    return 0;
}