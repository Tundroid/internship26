#include <stdio.h>

int array_sum(int *numbers, int size)
{
    int sum = 0;
    int *ptr = numbers;

    for (int i = 0; i < size; i++)
    {
        sum += *ptr;
        ptr++;
    }

    return sum;
}

int main(void)
{
    int numbers[] = {10, 20, 30, 40, 50};
    int size = 5;

    int sum = array_sum(numbers, size);
    float average = (float)sum / size;

    printf("Sum: %d\n", sum);
    printf("Average: %.2f\n", average);

    return 0;
}