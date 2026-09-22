#include <stdio.h>

void string_copy(char *destination, char *source)
{
    while (*source != '\0')
    {
        *destination = *source;
        destination++;
        source++;
    }

    *destination = '\0';
}

int main(void)
{
    char source[] = "Tundroid";
    char destination[20];

    string_copy(destination, source);

    printf("Source: %s\n", source);
    printf("Destination: %s\n", destination);

    return 0;
}