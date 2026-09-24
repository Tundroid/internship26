#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>


typedef struct StudentList {
    int id;
    char name[50];
    float average;
    struct StudentList *next;
} StudentList;

void add_student(StudentList **students, int *count);
void delete_student(StudentList **students, int *count);
StudentList *find_student(StudentList *students, int id);
void print_menu();
void list_students(StudentList *students);
void update_student(StudentList *students);
void show_statistics(StudentList *students, int count);

int main(void) {
    StudentList *students = NULL;
    int count = 0;
    int choice;

    do {
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
        case 1:
            add_student(&students, &count);
            break;
        case 2:
            list_students(students);
            break;
        case 3: {
            int id;

            printf("Enter student ID to search: ");
            scanf("%d", &id);

            StudentList *found_student = find_student(students, id);
            if (found_student != NULL) {

                printf("Student found: ID: %d, Name: %s, Average: %.2f\n",
                    found_student->id,
                    found_student->name,
                    found_student->average);
            } else {
                printf("Student with ID %d not found.\n", id);
            }
            break;
        }
        case 4:
            update_student(students);
            break;
        case 5:
            delete_student(&students, &count);
            break;
        case 6:
            show_statistics(students, count);
            break;
        case 7:
            printf("Exiting the program.\n");
            exit(0);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    } while (true);

    return 0;
}

void print_menu() {
    printf("Student Database Menu:\n");
    printf("1. Add Student\n");
    printf("2. List Students\n");
    printf("3. Search Student\n");
    printf("4. Update Student\n");
    printf("5. Delete Student\n");
    printf("6. Show Statistics\n");
    printf("7. Exit\n");
}

void list_students(StudentList *students) {
    if (students == NULL) {
        printf("No students in the database.\n");
        return;
    }

    StudentList *current = students;

    printf("Student List:\n");

    while (current != NULL) {
        printf("ID: %d, Name: %s, Average: %.2f\n",
             current->id,
             current->name,
             current->average);

         current = current->next;
    }
}

// add_student allocates a new node and appends it to the linked list
void add_student(StudentList **students, int *count) {
    StudentList *new_student = malloc(sizeof(StudentList));

    if (new_student == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    printf("Enter student ID: ");
    scanf("%d", &new_student->id);

    printf("Enter student name: ");
    scanf(" %[^\n]%*c", new_student->name);
     // Read string with spaces
    printf("Enter student average: ");
    scanf("%f", &new_student->average);


    new_student->next = NULL;

    if (*students == NULL) {
        *students = new_student;
    } else {
        StudentList *current = *students;

        while (current->next != NULL) {
            current = current->next;
        }
        current->next = new_student;
    }
    (*count)++;
    printf("Student added successfully!\n");
}


StudentList *find_student(StudentList *students, int id) {
   StudentList *current = students;

   while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void update_student(StudentList *students) {

    int id;

    printf("Enter student ID to update: ");
    scanf("%d", &id);

    StudentList *student = find_student(students, id);

    if (student != NULL) {

        printf("Enter new name: ");
        scanf(" %[^\n]%*c", student->name);

        printf("Enter new average: ");
        scanf("%f", &student->average);

        printf("Student updated successfully!\n");
    } else {
        printf("Student with ID %d not found.\n", id);
    }
}

void delete_student(StudentList **students, int *count) {
    int id;

    printf("Enter student ID to delete: ");
    scanf("%d", &id);

    StudentList *current = *students;
    StudentList *prev = NULL;

    while (current != NULL && current->id != id) {
        prev = current;
        current = current->next;
    }
    if (current == NULL) {
        printf("Student with ID %d not found.\n", id);
        return;
    }

    if (prev == NULL) {
        *students = current->next;
    }
    else {
        prev->next = current->next;
    }
    free(current);

    (*count)--;

     printf("Student deleted successfully!\n");
}

void show_statistics(StudentList *students, int count) {
    if (count == 0) {
        printf("No students in the database to show statistics.\n");

        return;
    }

    float total_average = 0.0;

    StudentList *current = students;

    while (current != NULL) {

        total_average += current->average;
        current = current->next;
    }
    float average_of_averages = total_average / count;

    printf("Statistics:\n");
    printf("Total Students: %d\n", count);
    printf("Average of Averages: %.2f\n", average_of_averages);
}