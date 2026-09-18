#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct student;

struct Student {
    int id;
    char name[50];
    float average;
};

void add_student(struct Student **students, int *count, int *capacity);
void list_students(struct Student *students, int count);
struct Student *search_student(struct Student *students, int count, int id);
void update_student(struct Student *students, int count, int id);
void delete_student(struct Student **students, int *count, int id);
void show_statistics(struct Student *students, int count);
void clear_input(void);


void clear_input(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

void add_student(struct Student **students, int *count, int *capacity)
{
    if (*count == *capacity) {
        int new_capacity = (*capacity == 0) ? 2 : (*capacity * 2);
        struct Student *bigger = realloc(*students, new_capacity * sizeof(struct Student));

        if (bigger == NULL) {
            printf("Memory allocation failed. Cannot add student.\n");
            return;
        }
        *students = bigger; 
        *capacity = new_capacity;
    }

    struct Student *s = &(*students)[*count];

    printf("Enter ID: ");
    scanf("%d", &s->id);
    clear_input();

    printf("Enter name: ");
    fgets(s->name, sizeof(s->name), stdin);
    s->name[strcspn(s->name, "\n")] = '\0'; 

    printf("Enter average: ");
    scanf("%f", &s->average);
    clear_input();

    (*count)++;
    printf("Student added. (%d/%d slots used)\n", *count, *capacity);
}

void list_students(struct Student *students, int count)
{
    if (count == 0) {
        printf("No students in the database.\n");
        return;
    }

    printf("\n%-6s %-20s %-10s\n", "ID", "Name", "Average");
    printf("--------------------------------------\n");
    for (int i = 0; i < count; i++) {
        struct Student *s = &students[i];
        printf("%-6d %-20s %-10.2f\n", s->id, s->name, s->average);
    }
}


struct Student *search_student(struct Student *students, int count, int id)
{
    struct Student *end = students + count;

    for (struct Student *student = students; student < end; student++) {
        if (student->id == id)
            return student;
    }
    return NULL;
}

void update_student(struct Student *students, int count, int id)
{
    struct Student *s = search_student(students, count, id);

    if (s == NULL) {
        printf("No student with ID %d found.\n", id);
        return;
    }

    printf("Found: %s (average %.2f)\n", s->name, s->average);

    printf("Enter new name: ");
    fgets(s->name, sizeof(s->name), stdin);
    s->name[strcspn(s->name, "\n")] = '\0';

    printf("Enter new average: ");
    scanf("%f", &s->average);
    clear_input();

    printf("Student %d updated.\n", id);
}

void delete_student(struct Student **students, int *count, int id)
{
    struct Student *s = search_student(*students, *count, id);

    if (s == NULL) {
        printf("No student with ID %d found.\n", id);
        return;
    }

    struct Student *end = *students + *count;
    for (struct Student *p = s; p + 1 < end; p++)
        *p = *(p + 1);

    (*count)--;
    printf("Student %d deleted.\n", id);

    
    if (*count > 0) {
        struct Student *smaller = realloc(*students, (*count) * sizeof(struct Student));
        if (smaller != NULL)
            *students = smaller; 
    }
}

void show_statistics(struct Student *students, int count)
{
    if (count == 0) {
        printf("No students in the database.\n");
        return;
    }

    float sum = students[0].average;
    float min = students[0].average;
    float max = students[0].average;

    for (int i = 1; i < count; i++) {
        float avg = students[i].average;
        sum += avg;
        if (avg < min) min = avg;
        if (avg > max) max = avg;
    }

    printf("\n--- Statistics (%d students) ---\n", count);
    printf("Average of averages: %.2f\n", sum / count);
    printf("Lowest average:      %.2f\n", min);
    printf("Highest average:     %.2f\n", max);
}


int main(void)
{
    struct Student *students = NULL; 
    int count = 0;
    int capacity = 0;
    int choice;

    for (;;) {
        printf("\nSTUDENT DATABASE\n");
        printf("1. Add student\n");
        printf("2. List students\n");
        printf("3. Search student\n");
        printf("4. Update student\n");
        printf("5. Delete student\n");
        printf("6. Show statistics\n");
        printf("7. Exit\n");
        printf("Choice: ");

        if (scanf("%d", &choice) != 1) {
            clear_input();
            printf("Please enter a number.\n");
            continue;
        }
        clear_input();

        switch (choice) {
            case 1:
                add_student(&students, &count, &capacity);
                break;

            case 2:
                list_students(students, count);
                break;

            case 3: {
                int id;
                printf("Enter ID to search: ");
                scanf("%d", &id);
                clear_input();

                struct Student *s = search_student(students, count, id);
                if (s != NULL)
                    printf("Found: ID %d, %s, average %.2f\n", s->id, s->name, s->average);
                else
                    printf("No student with ID %d found.\n", id);
                break;
            }

            case 4: {
                int id;
                printf("Enter ID to update: ");
                scanf("%d", &id);
                clear_input();
                update_student(students, count, id);
                break;
            }

            case 5: {
                int id;
                printf("Enter ID to delete: ");
                scanf("%d", &id);
                clear_input();
                delete_student(&students, &count, id);
                break;
            }

            case 6:
                show_statistics(students, count);
                break;

            case 7:
                free(students);
                printf("Goodbye.\n");
                return 0;

            default:
                printf("Invalid option.\n");
        }
    }

    return 0;
}