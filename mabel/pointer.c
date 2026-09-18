// #include <stdio.h>
// int main(){
//      int score = 50;
//      int *ptr_score = &score;
//      printf("The initial score: %d\n", score );
//      *ptr_score = 100; 
//       printf("The final score: %d\n", *ptr_score);
//       *ptr_score = 150;
//       printf("The challenge score: %d\n", **&ptr_score);

//     int age = 25;
//     int *ptr = &age;
//     printf("The value of age: %d\n", age );
//     printf ("The address of age: %p\n", &age);
//     printf ("The value stored in the pointer: %p\n",ptr);
//     printf("The value obtained from dereferencing the pointer: %d\n", *ptr);
//     return 0;
// }



// #include <stdio.h>
// void min_max(int *arr, int size, int *min, int *max){
// *min = *arr;
// *max = *arr;
// for(int i = 1; i < size; i++){
//     if(*(arr + i) < *min){
//         *min = *(arr + i);
//     }
//     if(*(arr + i) > *max){
//         *max = *(arr + i);
//     }
//   }
// }
// int main(){
//     int numbers[] = {34, 12, 89, 5, 67,23};
//     int min, max;
//     min_max(numbers, sizeof(numbers)/sizeof(numbers[0]), &min, &max);
//     printf("Minimum: %d\n", min);
//     printf("Maximum: %d\n", max);
    
// }

// #include <stdio.h>
// void count(int *arr, int n, int *even, int *odd){
//   *even =0;
//   *odd = 0;
//   for (int i = 0; i < n; i++){
//     if (*(arr + i) %2 == 0){
//       (*even)++;
//     } else {
//       (*odd)++;
//     }
//   }
// }

// int main(){
// int arr[] = {10, 3, 7, 8, 12, 15, 20};
// int n = sizeof(arr) / sizeof(arr[0]);
// int even, odd;
// count(arr, n, &even, &odd);
// printf("Even numbers: %d\n", even);
// printf("Odd numbers: %d\n", odd);
// }

//  #include <stdio.h>
//  int word_length(char *ptr){
//   int length = 0;
//   while (*ptr != '\0') {
//     length++;
//     ptr++;  
//  }

//  return length;
//  }
//  int main() {
//   char str[] = "Hello World";
//   int length = word_length(str);
//   printf("Length of the string: %d\n", length);
//   return 0;
//  }
//  #include <stdio.h>
//  void string_copy(char *source, char *destination){
//     while (*source != '\0') {
//         *destination = *source;
//         source++;
//         destination++;
//     }
//     *destination = '\0';
//   }
//   int main(){
//     char source[] = "Tundroid";
//     char destination[20];
//     string_copy(source, destination);
//     printf("Copied string: %s\n", destination);
//     return 0;
//   }


  // #include <stdio.h>
  // void reverse_string(char *str){
  //   char *start = str;
  //   char *end = str;
  //   while (*end != '\0') {
  //       end++;
  //   }
  //   end--;
  //   while (start < end) {
  //       char temp = *start;
  //       *start = *end;
  //       *end = temp;
  //       start++;
  //       end--;
  //   }
  // }
  // int main(){
  //   char str[] = "hello ";
  //   printf("Original string: %s\n", str);
  //   reverse_string(str);  
  //   printf("Reversed string: %s\n", str);
  //   return 0;
  // }

  //  #include <stdio.h>
  //  void count_char(char *str, int *letters, int *digits, int *spaces){
    
  //   *letters = 0;
  //   *digits = 0;
  //   *spaces = 0;

  //   while (*str != '\0') {
  //       if ((*str >= 'A' && *str <= 'Z') || (*str >= 'a' && *str <= 'z')) {
  //           (*letters)++;
  //       } else if (*str >= '0' && *str <= '9') {
  //           (*digits)++;
  //       } else if (*str == ' ') {
  //           (*spaces)++;
  //       }
  //       str++;
  //   }
  //  }
  //  int main(){
  //   char str[] = "Hello 123 World";
  //   int letters, digits, spaces;
  //   count_char(str, &letters, &digits, &spaces);
  //   printf("Letters: %d\n", letters);
  //   printf("Digits: %d\n", digits);
  //   printf("Spaces: %d\n", spaces);
  //   return 0;
  //  }


//    #include <stdio.h>
   
// struct student;

//     void calculate_average(struct student *student, float *average);
//     void find_highest(struct student *student, int *highest);
//     void find_lowest(struct student *student, int *lowest);

//        struct student{
//     char name[50];
//     int scores[5];

//      void (*calculate_average)(struct student *student, float *average);
//     void (*find_highest)(struct student *student, int *highest);
//     void (*find_lowest)(struct student *student, int *lowest);

//        };
//     void calculate_average(struct student *student, float *average){
//     int sum = 0;
//     for (int i = 0; i < 5; i++) {
//         sum += student->scores[i];
//     }
//     *average = (float)sum / 5;
//     }
//     void find_highest(struct student *student, int *height){
//       *height = student->scores[0];
//       for (int i = 1; i < 5; i++) {
//         if (student->scores[i] > *height) {
//             *height = student->scores[i];   
//         }
//      }
//     }

//     void find_lowest(struct student *student, int *lowest){
//       *lowest = student->scores[0];
//       for (int i = 1; i < 5; i++) {
//         if (student->scores[i] < *lowest) {
//             *lowest = student->scores[i];   
//         }
//      }
//     }

//     int main(){
//     struct student s1  = {"John",
//        {70, 85, 90, 65, 80},
//        calculate_average,
//        find_highest,
//        find_lowest
//       };


//     float average;
//     int highest, lowest;

//     s1.calculate_average(&s1, &average);
//     s1.find_highest(&s1, &highest);
//     s1.find_lowest(&s1, &lowest);


//     printf("Student Name: %s\n", s1.name);

//    printf("scores: ");
//     for (int i = 0; i < 5; i++) {
//         printf("%d ", s1.scores[i]);
//     }
//     printf("\n"); 

//     printf("Highest Score: %d\n", highest);
//     printf("Lowest Score: %d\n", lowest);
//      printf("Average Score: %.2f\n", average);
//     return 0;
//    }
  
// #include <stdio.h>
// #include <string.h>

// struct product {
//     char name[50];
//     int quantity;
//     float price;
// };

// void add_stock(struct product *product, int quantity)
// {
//     if (quantity <= 0) {
//         printf("Invalid amount to add.\n");
//         return;
//     }
//     product->quantity += quantity;
//     printf("Adding %d to %s...\n", quantity, product->name);
// }

// void remove_stock(struct product *product, int quantity)
// {
//     if (quantity <= 0) {
//         printf("Invalid amount to remove.\n");
//         return;
//     }
//     if (quantity > product->quantity) {
//         printf("Not enough %s in stock (have %d, asked for %d).\n",
//                product->name, product->quantity, quantity);
//         return;
//     }
//     product->quantity -= quantity;
//     printf("Removing %d from %s...\n", quantity, product->name);
// }

// void display_stock(struct product *product)
// {
//     printf("product: %s; quantity: %d; price: %.2f;\n",
//            product->name, product->quantity, product->price);
// }

// int main(void)
// {
//     struct product inventory[3] = {
//         {"rice", 20, 15000.0f},
//         {"beans", 12,  9000.0f},
//         {"sugar",  8,  4500.0f}
//     };
//     int n = sizeof(inventory) / sizeof(inventory[0]);
//     struct product *p;

//     printf("initial stocks\n");
//     for (p = inventory; p < inventory + n; p++)
//         display_stock(p);

//     printf("\noperations on rice\n");
//     p = &inventory[0];      

//     display_stock(p);
//     add_stock(p, 10);
//     display_stock(p);
//     remove_stock(p, 5);
//     display_stock(p);

//     remove_stock(p, 1000); 



//     return 0;
// }

// #include <stdio.h>
// #include <stdlib.h>

// void allocate_number(int **ptr)
// {
//     *ptr = malloc(sizeof(int));   
//     if (*ptr == NULL) {
//         fprintf(stderr, "malloc failed\n");
//         exit(1);
//     }
// }

// int main(void)
// {
//     int *number = NULL;
//     allocate_number(&number);
//     *number = 42;
//     printf("%d\n", *number);
//     free(number);
//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
//     int n;
//     int *numbers;
//     int sum = 0, minimum, maximum;
//     double average;

//     printf("How many numbers? ");
//     if (scanf("%d", &n) != 1 || n <= 0) {
//         printf("Please enter a positive whole number.\n");
//         return 1;
//     }

//     numbers = malloc(n * sizeof(int));

//     if (numbers == NULL) {
//         fprintf(stderr, "malloc failed\n");
//         return 1;
//     }

//     for (int i = 0; i < n; i++) {
//         printf("Enter number %d: ", i + 1);
//         scanf("%d", &numbers[i]);
//     }

//     sum = numbers[0];
//     minimum= numbers[0];
//     maximum = numbers[0];

//     for (int i = 1; i < n; i++) {
//         sum += numbers[i];
//         if (numbers[i] < minimum)
//             minimum = numbers[i];
//         if (numbers[i] > maximum)
//             maximum= numbers[i];
//     }

//     average = (double) sum / n;

//     printf("\nSum: %d\n", sum);
//     printf("Average: %.2f\n", average);
//     printf("Minimum: %d\n", minimum);
//     printf("Maximum: %d\n", maximum);

//     free(numbers);
//     return 0;
// }


// #include <stdio.h>
// #include <stdlib.h>

// int main(void)
// {
//     int n;
//     int *numbers;
//     int sum, min, max;
//     double average;

//     printf("How many numbers? ");
//     if (scanf("%d", &n) != 1 || n <= 0) {
//         printf("Please enter a positive whole number.\n");
//         return 1;
//     }

//     numbers = malloc(n * sizeof(int));

//     if (numbers == NULL) {
//         fprintf(stderr, "malloc failed\n");
//         return 1;
//     }

//     for (int i = 0; i < n; i++) {
//         printf("Enter number %d: ", i + 1);
//         scanf("%d", &numbers[i]);
//     }
//     int extra;
//     printf("\nHow many more numbers would you like to add? ");
//     if (scanf("%d", &extra) != 1 || extra < 0)
//         extra = 0;

//     if (extra > 0) {
//         int new_n = n + extra;
//         int *bigger = realloc(numbers, new_n * sizeof(int));

//         if (bigger == NULL) {
//             fprintf(stderr, "realloc failed, keeping original %d numbers\n", n);
//         } else {
//             numbers = bigger;  

//             for (int i = n; i < new_n; i++) {
//                 printf("Enter number %d: ", i + 1);
//                 scanf("%d", &numbers[i]);
//             }
//             n = new_n; 
//         }
//     }

//     sum = numbers[0];
//     min = numbers[0];
//     max = numbers[0];

//     for (int i = 1; i < n; i++) {
//         sum += numbers[i];
//         if (numbers[i] < min)
//             min = numbers[i];
//         if (numbers[i] > max)
//             max = numbers[i];
//     }

//     average = (double) sum / n;

//     printf("\nfinal array (%d numbers)\n", n);
//     for (int i = 0; i < n; i++)
//         printf("%d ", numbers[i]);
//     printf("\n");

//     printf("\nSum: %d\n", sum);
//     printf("Average: %.2f\n", average);
//     printf("Min: %d\n", min);
//     printf("Max: %d\n", max);

//     free(numbers);
//     return 0;
// }
//  #include <stdio.h>
// int get_number(void)
// {
//     int number = 50;
//     return number;
// }

// int main(void)
// {
//     int n = get_number();
//     printf("%d\n", n);
//     return 0;
// }









