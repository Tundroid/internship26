#include <stdio.h>

void min_max(int *numbers, int size, int *min, int *max)
{
    *min = numbers[0];
    *max = numbers[0];

    for (int i = 1; i < size; i++)
    {
        if (numbers[i] < *min)
        {
            *min = numbers[i];
        }

        if (numbers[i] > *max)
        {
            *max = numbers[i];
        }
    }
}

int main(void)
{
    int numbers[] = {34, 12, 89, 5, 67, 23};
    int size = 6;
    int min, max;

    min_max(numbers, size, &min, &max);

    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);

    return 0;
}