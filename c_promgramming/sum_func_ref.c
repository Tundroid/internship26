#include <stdio.h>

int sum(int *a, int b) {
    *a = *a + b;
    return *a + b;
}

int main() {
    int num1, num2, result;
    printf("Enter two integers: ");
    scanf("%d %d", &num1, &num2);
    
    result = sum(&num1, num2);
    printf("Sum: %d\n", result);
    printf("Value of a after sum function: %d\n", num1);
    
    return 0;
}