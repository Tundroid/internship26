#include <stdio.h>

void calculate(int a, int b, int *sum, int *difference, int *product)
{
    *sum = a + b;
    *difference = a - b;
    *product = a * b;
}

int main(void)
{
    int a = 20;
    int b = 5;
    int sum, difference, product;

    calculate(a, b, &sum, &difference, &product);

    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", difference);
    printf("Product: %d\n", product);

    if (b != 0)
    {
        printf("Division: %.2f\n", (float)a / b);
    }
    else
    {
        printf("Division: Cannot divide by zero\n");
    }

    return 0;
}