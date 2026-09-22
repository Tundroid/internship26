#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    float average;
};

int main(void)
{
    struct Student *students = NULL;
    int count = 0;
    int choice;

    do
    {
        printf("\n===== STUDENT DATABASE =====\n");
        printf("1. Add student\n");
        printf("2. List students\n");
        printf("3. Search student\n");
        printf("4. Update student\n");
        printf("5. Delete student\n");
        printf("6. Show statistics\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                
    students = realloc(students, (count + 1) * sizeof(struct Student));

    if (students == NULL)
    {
        printf("Memory allocation failed.\n");
        return 1;
    }

    printf("Enter student ID: ");
    scanf("%d", &students[count].id);

    printf("Enter student name: ");
    scanf(" %[^\n]", students[count].name);

    printf("Enter student average: ");
    scanf("%f", &students[count].average);

    count++;

    printf("Student added successfully.\n");
    break;
            case 2:
                
    if (count == 0)
    {
        printf("No students available.\n");
    }
    else
    {
        printf("\n===== STUDENT LIST =====\n");

        for (int i = 0; i < count; i++)
        {
            printf("ID: %d\n", students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("Average: %.2f\n", students[i].average);
            printf("------------------------\n");
        }
    }
    break;

            case 3:
                
{
    int search_id;
    int found = 0;

    printf("Enter student ID to search: ");
    scanf("%d", &search_id);

    for (int i = 0; i < count; i++)
    {
        if (students[i].id == search_id)
        {
            printf("\n===== STUDENT FOUND =====\n");
            printf("ID: %d\n", students[i].id);
            printf("Name: %s\n", students[i].name);
            printf("Average: %.2f\n", students[i].average);

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Student not found.\n");
    }

    break;
}

            case 4:
            
{
    int update_id;
    int found = 0;

    printf("Enter student ID to update: ");
    scanf("%d", &update_id);

    for (int i = 0; i < count; i++)
    {
        if (students[i].id == update_id)
        {
            printf("Enter new student name: ");
            scanf(" %[^\n]", students[i].name);

            printf("Enter new student average: ");
            scanf("%f", &students[i].average);

            printf("Student updated successfully.\n");

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Student not found.\n");
    }

    break;
}

            case 5:
        
{
    int delete_id;
    int found = 0;

    printf("Enter student ID to delete: ");
    scanf("%d", &delete_id);

    for (int i = 0; i < count; i++)
    {
        if (students[i].id == delete_id)
        {
            for (int j = i; j < count - 1; j++)
            {
                students[j] = students[j + 1];
            }

            count--;

            if (count == 0)
            {
                free(students);
                students = NULL;
            }
            else
            {
                students = realloc(students, count * sizeof(struct Student));
            }

            printf("Student deleted successfully.\n");

            found = 1;
            break;
        }
    }

    if (!found)
    {
        printf("Student not found.\n");
    }

    break;
}

            case 6:
{
    if (count == 0)
    {
        printf("No students available.\n");
    }
    else
    {
        float total = 0;
        float highest = students[0].average;
        float lowest = students[0].average;

        for (int i = 0; i < count; i++)
        {
            total += students[i].average;

            if (students[i].average > highest)
            {
                highest = students[i].average;
            }

            if (students[i].average < lowest)
            {
                lowest = students[i].average;
            }
        }

        printf("\n===== STUDENT STATISTICS =====\n");
        printf("Total students: %d\n", count);
        printf("Average of all students: %.2f\n", total / count);
        printf("Highest average: %.2f\n", highest);
        printf("Lowest average: %.2f\n", lowest);
    }

    break;
}

            case 7:
                printf("Exiting...\n");
                break;

            default:
                printf("Invalid choice.\n");
        }

    } while (choice != 7);

    free(students);

    return 0;
}