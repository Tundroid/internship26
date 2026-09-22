#include <stdio.h>
int get_number(void)
{
    int number = 50;
    return number;
}

int main(void)
{
    int n = get_number();
    printf("%d\n", n);
    return 0;
}

