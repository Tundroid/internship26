#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

typedef struct Student {
    int id;
    char name[50];
    float average;
} Student;

void add_student(Student **students, int *count);
void delete_student(Student **students, int *count);
Student *find_student(Student *students, int count, int id);
void print_menu();
void list_students(Student *students, int count);
void update_student(Student *students, int count);
void show_statistics(Student *students, int count);

int main() {
    Student *students = NULL;
    int count = 0;
    int choice;

    do{
        print_menu();
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice)
        {
        case 1:
            add_student(&students, &count);
            break;
        case 2:
            list_students(students, count);
            break;
        case 3:
            int id;
            printf("Enter student ID to search: ");
            scanf("%d", &id);
            Student *found_student = find_student(students, count, id);
            if (found_student != NULL) {
                printf("Student found: ID: %d, Name: %s, Average: %.2f\n", found_student->id, found_student->name, found_student->average);
            } else {
                printf("Student with ID %d not found.\n", id);
            }
            break;
        case 4:
            update_student(students, count);
            break;
        case 5:
            delete_student(&students, &count);
            break;
        case 6:
            show_statistics(students, count);
            break;
        case 7:
            printf("Exiting the program.\n");
            free(students);
            exit(150);
            break;
        default:
            printf("Invalid choice. Please try again.\n");
            break;
        }
    }while(true);

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

void list_students(Student *students, int count) {
    if (count == 0) {
        printf("No students in the database.\n");
        return;
    }

    printf("Student List:\n");
    for (int i = 0; i < count; i++) {
        printf("ID: %d, Name: %s, Average: %.2f\n", students[i].id, students[i].name, students[i].average);
    }
}

// add_student using malloc or realloc to dynamically allocate memory for the students array
void add_student(Student **students, int *count) {
    Student new_student;
    printf("Enter student ID: ");
    scanf("%d", &new_student.id);
    printf("Enter student name: ");
    scanf(" %[^\n]%*c", new_student.name); // Read string with spaces
    printf("Enter student average: ");
    scanf("%f", &new_student.average);

    // Allocate or reallocate memory for the students array (include extra null student to indicate end of array)
    if (*count == 0) {
        *students = (Student *)malloc(2 * sizeof(Student));
    } else {
        *students = (Student *)realloc(*students, (*count + 1 + 1)  * sizeof(Student));
    }

    if (*students == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }

    (*students)[*count] = new_student; // imagine arr[count] = new_student;
    (*students)[*count + 1] = (Student){0}; // Initialize the null student
    (*count)++;
    printf("Student added successfully!\n");
}


Student *find_student(Student *student, int count, int id) {
    while (student != NULL && student->id != 0) {
        if (student->id == id)
            return student;
        student++;
    }
    return NULL;
}

void update_student(Student *students, int count) {
    int id;
    printf("Enter student ID to update: ");
    scanf("%d", &id);
    Student *student = find_student(students, count, id);
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

void delete_student(Student **students, int *count) {
    int id;
    printf("Enter student ID to delete: ");
    scanf("%d", &id);
    Student *student = find_student(*students, *count, id);
    if (student != NULL) {
        // Shift students down to overwrite the deleted student
        for (int i = 0; i < *count; i++) {
            if ((*students)[i].id == id) {
                for (int j = i; j < *count - 1; j++) {
                    (*students)[j] = (*students)[j + 1];
                }
                break;
            }
        }
        (*count)--;
        // Reallocate memory to shrink the array
        *students = (Student *)realloc(*students, (*count + 1) * sizeof(Student));
        if (*students == NULL && *count > 0) {
            printf("Memory reallocation failed!\n");
            exit(1);
        }
        printf("Student deleted successfully!\n");
    } else {
        printf("Student with ID %d not found.\n", id);
    }
}

void show_statistics(Student *students, int count) {
    if (count == 0) {
        printf("No students in the database to show statistics.\n");
        return;
    }

    float total_average = 0.0;
    for (int i = 0; i < count; i++) {
        total_average += students[i].average;
    }
    float average_of_averages = total_average / count;

    printf("Statistics:\n");
    printf("Total Students: %d\n", count);
    printf("Average of Averages: %.2f\n", average_of_averages);
}