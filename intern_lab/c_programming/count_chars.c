#include <stdio.h>

void count_chars(char *str, int *letters, int *digits, int *spaces)
{
    *letters = 0;
    *digits = 0;
    *spaces = 0;

    while (*str != '\0')
    {
        if ((*str >= 'A' && *str <= 'Z') ||
            (*str >= 'a' && *str <= 'z'))
        {
            (*letters)++;
        }
        else if (*str >= '0' && *str <= '9')
        {
            (*digits)++;
        }
        else if (*str == ' ')
        {
            (*spaces)++;
        }

        str++;
    }
}

int main(void)
{
    char str[] = "Hello 123 World";
    int letters, digits, spaces;

    count_chars(str, &letters, &digits, &spaces);

    printf("Letters: %d\n", letters);
    printf("Digits: %d\n", digits);
    printf("Spaces: %d\n", spaces);

    return 0;
}