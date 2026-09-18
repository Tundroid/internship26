Exercise 1  Inspect an address
code:
#include <stdio.h>
int main(){
    int age = 25;
    int *ptr = &age;
    printf("The value of age: %d\n", age );
    printf ("The address of age: %p\n", &age);
    printf ("The value stored in the pointer: %p\n",ptr);
    printf("The value obtained from dereferencing the pointer: %d\n", *ptr);

    return 0;
}
output: 
The value of age: 25
The address of age: 0x7ffe2530e934
The value stored in the pointer: 0x7ffe2530e934
The value obtained from dereferencing the pointer: 25

challenge: The ptr and the &age has thesame value because the ptr stores the address of age and the &age find thesame address.


Exercise 2 Modifying through a pointer
code:
#include <stdio.h>
int main(){
     int score = 50;
     int *ptr_score = &score;
     printf("The initial score: %d\n", score );
     *ptr_score = 100; 
      printf("The final score: %d\n", *ptr_score);
      *ptr_score = 150;
      printf("The challenge score: %d\n", **&ptr_score);
return 0;
}
output: 
The initial score: 50
The final score: 100
The challenge score: 150

challenge: 
you start by uqdating the score by 100
&ptr_score finds the memory address of the pointer itself
*&ptr_score the * dereferences it by printing the updated value
**&ptr_score the ** dereferences it agan and prints the final vaue.

Exercise 3 swap two numbers
code:
#include <stdio.h>
void swap(int *a, int *b){
int temp = *a;
*a = *b;
*b = temp;
}
int main(){
 int x = 10;
 int y = 20;
 printf("Before: x = %d y = %d\n", x, y);
 swap(&x, &y);
 printf("After: x = %d y = %d\n", x, y);
}

output:
Before: x = 10 y = 20
After: x = 20 y = 10


Exercise 4: calculator with pointers
code:
#include <stdio.h>
void calculate(int a, int b, int *sum, int *diff, int *prod, float *div){
    *sum = a + b;
    *diff = a - b;
    *prod = a * b;
    if(b != 0){
        *div = (float)a / b;
    } else {
        *div = 0; 
    }
}
int main(){
    int x = 20;
    int y = 5;
    int sum, diff, prod;
    float div;
    calculate(x, y, &sum, &diff, &prod, &div);
    printf("Sum: %d\n", sum);
    printf("Difference: %d\n", diff);
    printf("Product: %d\n", prod);
    printf("Division: %.2f\n", div);
}

output: 
Sum: 25
Difference: 15
Product: 100
Division: 4.00


Exercise 5: find min and max value

code: 
#include <stdio.h>
void min_max(int *arr, int size, int *min, int *max){
*min = *arr;
*max = *arr;
for(int i = 1; i < size; i++){
    if(*(arr + i) < *min){
        *min = *(arr + i);
    }
    if(*(arr + i) > *max){
        *max = *(arr + i);
    }
  }
}
int main(){
    int numbers[] = {34, 12, 89, 5, 67,23};
    int min, max;
    min_max(numbers, sizeof(numbers)/sizeof(numbers[0]), &min, &max);
    printf("Minimum: %d\n", min);
    printf("Maximum: %d\n", max);
    
}

output:
Minimum: 5
Maximum: 89


Exercise 6: count even and odd numbers

code: 
#include <stdio.h>
void count(int *arr, int n, int *even, int *odd){
  *even =0;
  *odd = 0;
  for (int i = 0; i < n; i++){
    if (*(arr + i) %2 == 0){
      (*even)++;
    } else {
      (*odd)++;
    }
  }
}

int main(){
int arr[] = {10, 3, 7, 8, 12, 15, 20};
int n = sizeof(arr) / sizeof(arr[0]);
int even, odd;
count(arr, n, &even, &odd);
printf("Even numbers: %d\n", even);
printf("Odd numbers: %d\n", odd);
}

output:
Even numbers: 4
Odd numbers: 3


Exercise 7: traverse an array using pointers

code:
#include <stdio.h>

int main() {
    int numbers[] = {12, 45, 67, 23, 89, 90};
    int size = sizeof(numbers) / sizeof(numbers[0]);

    int *ptr = numbers;


    for (int i = 0; i < size; i++) {
        printf(" value = %d", *(numbers + i));
        ptr++; 
    }
    return 0;
    output:
     value = 12 value = 45 value = 67 value = 23 value = 89 value = 90
}

challenge:

#include <stdio.h>
int main(){
    int numbers[] = {12, 45, 67, 23, 89, 90};
    int size = sizeof(numbers) / sizeof(numbers[0]);
    int *p = numbers;
    for(int i = 0; i < size; i++){
        printf("%d\n", *p);
        p++;
    }
}

output: 
12
45
67
23
89
90

Exercise 8: reverse an array

code: 

#include <stdio.h>
int main (){
    int num[] = {1, 2, 3, 4, 5};
    int size = sizeof(num) / sizeof(num[0]);

    int *left = num;
    int *right = num + size - 1;

    while (left < right) {
        int temp = *left;
        *left = *right;
        *right = temp;

        left++;
        right--;
    }
    
    int *p = num;
    for (int i = 0; i < size; i++) 
{
        printf("%d ", *p);
        p++;                                            
        printf("\n");
    }

    return 0;
}

Exercise 9: summation of array using pointers

code:
 #include <stdio.h>
int array_sum(int *numbers, int size){
int sum = 0;

for (int i = 0; i< size; i ++){
  sum += *numbers;
  numbers++;
}
return sum;
}
int main(){
int mynumber[] = {5, 10, 15, 20};
int size = sizeof(mynumber)/ sizeof(mynumber[0]);

int result = array_sum(mynumber, size);

printf("sum of array is: %d\n", result);
return 0;
}

challenge:
#include <stdio.h>
int array_sum(int *numbers, int size, double *average){
int sum = 0;

for (int i = 0; i< size; i ++){
  sum += *numbers;
  numbers++;
}

*average = (double)sum / size;
return sum;
}
int main(){
int mynumber[] = {5, 10, 15, 20};
int size = sizeof(mynumber)/ sizeof(mynumber[0]);
double average;

int result = array_sum(mynumber, size, &average);

printf("sum of array is: %d\n", result);
printf("average of array is: %.2f\n", average);
return 0;
}

output:
sum of array is: 50
average of array is: 12.50


Exercise 10: string length

code:
 #include <stdio.h>
 int word_length(char *ptr){
  int length = 0;
  while (*ptr != '\0') {
    length++;
    ptr++;  
 }

 return length;
 }
 int main() {
  char str[] = "Hello World";
  int length = word_length(str);
  printf("Length of the string: %d\n", length);
  return 0;
 }

 output:
 Length of the string: 11



Exercise 11: string copy

code:
#include <stdio.h>
 void string_copy(char *source, char *destination){
    while (*source != '\0') {
        *destination = *source;
        source++;
        destination++;
    }
    *destination = '\0';
  }
  int main(){
    char source[] = "Tundroid";
    char destination[20];
    string_copy(source, destination);
    printf("Copied string: %s\n", destination);
    return 0;
  }

  output:
   Copied string: Tundroid


   Exercise 12: reverse a string

code:

  #include <stdio.h>
  void reverse_string(char *str){
    char *start = str;
    char *end = str;
    while (*end != '\0') {
        end++;
    }
    end--;
    while (start < end) {
        char temp = *start;
        *start = *end;
        *end = temp;
        start++;
        end--;
    }
  }
  int main(){
    char str[] = "hello ";
    printf("Original string: %s\n", str);
    reverse_string(str);  
    printf("Reversed string: %s\n", str);
    return 0;
  }

  output:
Original string: hello 
Reversed string:  olleh


Exercise 13: count characters

code:
   #include <stdio.h>
   void count_char(char *str, int *letters, int *digits, int *spaces){
    
    *letters = 0;
    *digits = 0;
    *spaces = 0;

    while (*str != '\0') {
        if ((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z')) {
            (*letters)++;
        } else if (*str >= '0' && *str <= '9') {
            (*digits)++;
        } else if (*str == ' ') {
            (*spaces)++;
        }
        str++;
    }
   }
   int main(){
    char str[] = "Hello 123 World";
    int letters, digits, spaces;
    count_char(str, &letters, &digits, &spaces);
    printf("Letters: %d\n", letters);
    printf("Digits: %d\n", digits);
    printf("Spaces: %d\n", spaces);
    return 0;
   }

   output:
   Letters: 10
   Digits: 3
   Spaces: 2


   Exercise 14: student grade analyzer

   code: 
    #include <stdio.h>
struct student;
    void calculate_average(struct student *student, float *average);
    void find_highest(struct student *student, int *highest);
    void find_lowest(struct student *student, int *lowest);

       struct student{
    char name[50];
    int scores[5];

     void (*calculate_average)(struct student *student, float *average);
    void (*find_highest)(struct student *student, int *highest);
    void (*find_lowest)(struct student *student, int *lowest);

       };
    void calculate_average(struct student *student, float *average){
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        sum += student->scores[i];
    }
    *average = (float)sum / 5;
    }
    void find_highest(struct student *student, int *height){
      *height = student->scores[0];
      for (int i = 1; i < 5; i++) {
        if (student->scores[i] > *height) {
            *height = student->scores[i];   
        }
     }
    }

    void find_lowest(struct student *student, int *lowest){
      *lowest = student->scores[0];
      for (int i = 1; i < 5; i++) {
        if (student->scores[i] < *lowest) {
            *lowest = student->scores[i];   
        }
     }
    }

    int main(){
    struct student s1  = {"John",
       {70, 85, 90, 65, 80},
       calculate_average,
       find_highest,
       find_lowest
      };


    float average;
    int highest, lowest;

    s1.calculate_average(&s1, &average);
    s1.find_highest(&s1, &highest);
    s1.find_lowest(&s1, &lowest);


    printf("Student Name: %s\n", s1.name);

    
   printf("scores: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", s1.scores[i]);
    }
    printf("\n"); 
    printf("Highest Score: %d\n", highest);
    printf("Lowest Score: %d\n", lowest);
     printf("Average Score: %.2f\n", average);
    return 0;
   }

output:
scores: 70 85 90 65 80 
Student Name: John
Highest Score: 90
Lowest Score: 65
Average Score: 78.00



exercise 15: simple investory systems

code: 
#include <stdio.h>
#include <string.h>

struct product {
    char name[50];
    int quantity;
    float price;
};

void add_stock(struct product *product, int quantity)
{
    if (quantity <= 0) {
        printf("Invalid amount to add.\n");
        return;
    }
    product->quantity += quantity;
    printf("Adding %d to %s...\n", quantity, product->name);
}

void remove_stock(struct product *product, int quantity)
{
    if (quantity <= 0) {
        printf("Invalid amount to remove.\n");
        return;
    }
    if (quantity > product->quantity) {
        printf("Not enough %s in stock (have %d, asked for %d).\n",
               product->name, product->quantity, quantity);
        return;
    }
    product->quantity -= quantity;
    printf("Removing %d from %s...\n", quantity, product->name);
}

void display_stock(struct product *product)
{
    printf("product: %s; quantity: %d; price: %.2f;\n",
           product->name, product->quantity, product->price);
}

int main(void)
{
    struct product inventory[3] = {
        {"rice", 20, 15000.0f},
        {"beans", 12,  9000.0f},
        {"sugar",  8,  4500.0f}
    };
    int n = sizeof(inventory) / sizeof(inventory[0]);
    struct product *p;

    printf("initial stock\n");
    for (p = inventory; p < inventory + n; p++)
        display_stock(p);

    printf("\n operations on rice\n");
    p = &inventory[0];      

    display_stock(p);
    add_stock(p, 10);
    display_stock(p);
    remove_stock(p, 5);
    display_stock(p);

    remove_stock(p, 1000); 



    return 0;
}
output:
initial stocks
product: rice; quantity: 20; price: 15000.00;
product: beans; quantity: 12; price: 9000.00;
product: sugar; quantity: 8; price: 4500.00;

operations on rice
product: rice; quantity: 20; price: 15000.00;
Adding 10 to rice...
product: rice; quantity: 30; price: 15000.00;
Removing 5 from rice...
product: rice; quantity: 25; price: 15000.00;
Not enough rice in stock (have 25, asked for 1000).


exercise 16: modify a pointer

code:
#include <stdio.h>
#include <stdlib.h>

void allocate_number(int **ptr)
{
    *ptr = malloc(sizeof(int));   
    if (*ptr == NULL) {
        fprintf(stderr, "malloc failed\n");
        exit(1);
    }
}

int main(void)
{
    int *number = NULL;
    allocate_number(&number);
    *number = 42;
    printf("%d\n", *number);
    free(number);
    return 0;
}

output:
42
&number is an int ** because number itself is declared int *number — it's a variable whose job is to hold the address of an int. Right now it holds NULL.The whole point of calling allocate_number is that it needs to change what number points to — to make it point at the freshly allocated memory instead of NULL.

Exercise 17: Dynamic array

code:
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    int *numbers;
    int sum = 0, minimum, maximum;
    double average;

    printf("How many numbers? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Please enter a positive whole number.\n");
        return 1;
    }

    numbers = malloc(n * sizeof(int));

    if (numbers == NULL) {
        fprintf(stderr, "malloc failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }

    sum = numbers[0];
    minimum= numbers[0];
    maximum = numbers[0];

    for (int i = 1; i < n; i++) {
        sum += numbers[i];
        if (numbers[i] < minimum)
            minimum = numbers[i];
        if (numbers[i] > maximum)
            maximum= numbers[i];
    }

    average = (double) sum / n;

    printf("\nSum: %d\n", sum);
    printf("Average: %.2f\n", average);
    printf("Minimum: %d\n", minimum);
    printf("Maximum: %d\n", maximum);

    free(numbers);
    return 0;
}

output:
How many numbers? 3
Enter number 1: 3
Enter number 2: 5
Enter number 3: 1

Sum: 9
Average: 3.00
Minimum: 1
Maximum: 5

challenge:

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    int *numbers;
    int sum, min, max;
    double average;

    printf("How many numbers? ");
    if (scanf("%d", &n) != 1 || n <= 0) {
        printf("Please enter a positive whole number.\n");
        return 1;
    }

    numbers = malloc(n * sizeof(int));

    if (numbers == NULL) {
        fprintf(stderr, "malloc failed\n");
        return 1;
    }

    for (int i = 0; i < n; i++) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &numbers[i]);
    }
    int extra;
    printf("\nHow many more numbers would you like to add? ");
    if (scanf("%d", &extra) != 1 || extra < 0)
        extra = 0;

    if (extra > 0) {
        int new_n = n + extra;
        int *bigger = realloc(numbers, new_n * sizeof(int));

        if (bigger == NULL) {
            fprintf(stderr, "realloc failed, keeping original %d numbers\n", n);
        } else {
            numbers = bigger;  

            for (int i = n; i < new_n; i++) {
                printf("Enter number %d: ", i + 1);
                scanf("%d", &numbers[i]);
            }
            n = new_n; 
        }
    }

    sum = numbers[0];
    min = numbers[0];
    max = numbers[0];

    for (int i = 1; i < n; i++) {
        sum += numbers[i];
        if (numbers[i] < min)
            min = numbers[i];
        if (numbers[i] > max)
            max = numbers[i];
    }

    average = (double) sum / n;

    printf("\nfinal array (%d numbers)\n", n);
    for (int i = 0; i < n; i++)
        printf("%d ", numbers[i]);
    printf("\n");

    printf("\nSum: %d\n", sum);
    printf("Average: %.2f\n", average);
    printf("Min: %d\n", min);
    printf("Max: %d\n", max);

    free(numbers);
    return 0;
}


output:
How many numbers? 3
Enter number 1: 5
Enter number 2: 1
Enter number 3: 0

How many more numbers would you like to add? 2
Enter number 4: 3
Enter number 5: 9

final array (5 numbers)
5 1 0 3 9 

Sum: 18
Average: 3.60
Min: 0
Max: 9
 
Exercise 18: debugging


1) the pointer is not initialized , so its not pointing to any memory address.

2) it crashes because the ptr is dereferenced without being initialized.

3) code:
#include <stdio.h>

int main(void)
{
    int x;
    int *ptr = &x;
    *ptr = 50;
    printf("%d\n", *ptr);

    return 0;
}

Exercise 19: 

1) A function is defined in another function which c does not support nested function
 and the function is returning the address of a local variable.
2) it is dangerous because a local variable's storage doesn't belong to it anymore once the function returns
3)
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

output: 50

Exercise 20: student database

code:
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




challenge:

code: 

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


#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[50];
    float average;
};
void add_student(struct Student **students, int *count);
void list_students(struct Student *students, int count);
struct Student *find_student(struct Student *students, int count, int id);
void update_student(struct Student *students, int count, int id);
void delete_student(struct Student **students, int *count);
void show_statistics(struct Student *students, int count);
void clear_input(void);



void clear_input(void)
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}


void add_student(struct Student **students, int *count)
{
    struct Student *bigger = realloc(*students, (*count + 1) * sizeof(struct Student));

    if (bigger == NULL) {
        printf("Memory allocation failed. Cannot add student.\n");
        return;
    }
    *students = bigger; 

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
    printf("Student added. (%d total)\n", *count);
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

struct Student *find_student(struct Student *students, int count, int id)
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
    struct Student *s = find_student(students, count, id);

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

void delete_student(struct Student **students, int *count)
{
    int id;
    printf("Enter ID to delete: ");
    scanf("%d", &id);
    clear_input();

    struct Student *s = find_student(*students, *count, id);

    if (s == NULL) {
        printf("No student with ID %d found.\n", id);
        return;
    }

    struct Student *end = *students + *count;
    for (struct Student *p = s; p + 1 < end; p++)
        *p = *(p + 1);

    (*count)--;
    printf("Student %d deleted.\n", id);

    if (*count == 0) {
        free(*students);
        *students = NULL;
        return;
    }

    
    struct Student *smaller = realloc(*students, (*count) * sizeof(struct Student));
    if (smaller != NULL)
        *students = smaller;  
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
                add_student(&students, &count);
                break;

            case 2:
                list_students(students, count);
                break;

            case 3: {
                int id;
                printf("Enter ID to search: ");
                scanf("%d", &id);
                clear_input();

                struct Student *s = find_student(students, count, id);
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

            case 5:
                delete_student(&students, &count);
                break;

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






