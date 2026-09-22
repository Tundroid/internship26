#include <stdio.h>

void reverse(int *numbers, int size)
{
    int *left = numbers;
    int *right = numbers + size - 1;

    while (left < right)
    {
        int temp = *left;
        *left = *right;
        *right = temp;

        left++;
        right--;
    }
}

int main(void)
{
    int numbers[] = {1, 2, 3, 4, 5};
    int size = 5;

    reverse(numbers, size);

    for (int *ptr = numbers; ptr < numbers + size; ptr++)
    {
        printf("%d ", *ptr);
    }
    printf("\n");

    return 0;
}