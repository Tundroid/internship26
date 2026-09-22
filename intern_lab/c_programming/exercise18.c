#include <stdio.h>

int main(void)
{
    int x;
    int *ptr = &x;
    *ptr = 50;
    printf("%d\n", *ptr);

    return 0;
}