#include <stdio.h>

int main(){
    int age;
    int *ptr_age = &age;
    printf("Initial value of age: %d\n", age);
    printf("Enter your age: ");
    scanf("%d", &age);
    printf("Your age is: %d\n", age);
    printf("\nA few moments later...\n");
    printf("Enter your new age: ");
    scanf("%d", ptr_age);
    printf("Your new age is: %d\n", *ptr_age);    
    printf("Your new age is: %d\n", **&ptr_age);
    return 0;
}