#include <stdio.h>

int string_length(char *str)
{
    int length = 0;

    while (*str != '\0')
    {
        length++;
        str++;
    }

    return length;
}

int main(void)
{
    char str[] = "Hello World";

    int length = string_length(str);

    printf("Length: %d\n", length);

    return 0;
}