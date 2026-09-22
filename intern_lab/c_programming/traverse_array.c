#include <stdio.h>

int main(void)
{
    int numbers[] = {10, 20, 30, 40, 50};
    int size = 5;
    int *ptr = numbers;

    while (ptr < numbers + size)
    {
        printf("%d\n", *ptr);
        ptr++;
    }

    return 0;
}