#include <stdio.h>

void count_even_odd(int *numbers, int size, int *even, int *odd)
{
    *even = 0;
    *odd = 0;

    for (int i = 0; i < size; i++)
    {
        if (numbers[i] % 2 == 0)
        {
            (*even)++;
        }
        else
        {
            (*odd)++;
        }
    }
}

int main(void)
{
    int numbers[] = {10, 3, 7, 8, 12, 15, 20};
    int size = 7;
    int even, odd;

    count_even_odd(numbers, size, &even, &odd);

    printf("Even: %d\n", even);
    printf("Odd: %d\n", odd);

    return 0;
}