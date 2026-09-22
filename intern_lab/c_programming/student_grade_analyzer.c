#include <stdio.h>

struct Student {
    char name[50];
    int scores[5];
};
void calculate_average(struct Student *student, float *average)
{
    int sum = 0;

    for (int i = 0; i < 5; i++)
    {
        sum += student->scores[i];
    }

    *average = (float)sum / 5;
}
void find_highest(struct Student *student, int *highest)
{
    *highest = student->scores[0];

    for (int i = 1; i < 5; i++)
    {
        if (student->scores[i] > *highest)
        {
            *highest = student->scores[i];
        }
    }
}
void find_lowest(struct Student *student, int *lowest)
{
    *lowest = student->scores[0];

    for (int i = 1; i < 5; i++)
    {
        if (student->scores[i] < *lowest)
        {
            *lowest = student->scores[i];
        }
    }
}
int main(void)
{
    struct Student student = {
        "John",
        {70, 85, 90, 65, 80}
    };

    float average;
    int highest;
    int lowest;

    calculate_average(&student, &average);
    find_highest(&student, &highest);
    find_lowest(&student, &lowest);

    printf("Student: %s\n", student.name);
    printf("Scores: ");

    for (int i = 0; i < 5; i++)
    {
        printf("%d ", student.scores[i]);
    }

    printf("\n");
    printf("Average: %.0f\n", average);
    printf("Highest: %d\n", highest);
    printf("Lowest: %d\n", lowest);

    return 0;
}