#include <stdio.h>
#include <stdlib.h>
void allocate_number(int **ptr)
{
    *ptr = malloc(sizeof(int));
}
int main(void)
{
    int *number = NULL;

    allocate_number(&number);

    *number = 42;

    printf("%d\n", *number);

    free(number);

    return 0;
}