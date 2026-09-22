#include <stdio.h>

int main(void)
{
    int score = 50;
    int *ptr = &score;

    printf("Before modification: %d\n", score);

    *ptr = 100;

    printf("After modification: %d\n", score);

    *ptr = 150;

    printf("After changing through pointer again: %d\n", score);

    return 0;
}