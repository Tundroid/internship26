#include <stdio.h>
#include <stdlib.h>
int main(void)
{
    int size;

printf("Enter the number of integers: ");
scanf("%d", &size);

int *numbers = malloc(size * sizeof(int));
if (numbers == NULL)
{
    printf("Memory allocation failed.\n");
    return 1;
}
int sum = 0;
for (int i = 0; i < size; i++)
{
    printf("Enter number %d: ", i + 1);
    scanf("%d", &numbers[i]);
    sum += numbers[i];
    
}
float average = (float)sum / size;
int min = numbers[0];
int max = numbers[0];

for (int i = 1; i < size; i++)
{
    if (numbers[i] < min)
    {
        min = numbers[i];
    }

    if (numbers[i] > max)
    {
        max = numbers[i];
    }
}
printf("\nSum: %d\n", sum);
printf("Average: %.2f\n", average);
printf("Minimum: %d\n", min);
printf("Maximum: %d\n", max);
free(numbers);

return 0;

    
}