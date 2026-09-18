// #include <stdio.h>
// void calculate(int a, int b, int *sum, int *diff, int *prod, float *div){
//     *sum = a + b;
//     *diff = a - b;
//     *prod = a * b;
//     if(b != 0){
//         *div = (float)a / b;
//     } else {
//         *div = 0;
//     }
// }
// int main(){
//     int x = 20;
//     int y = 5;
//     int sum, diff, prod;
//     float div;
//     calculate(x, y, &sum, &diff, &prod, &div);
//     printf("Sum: %d\n", sum);
//     printf("Difference: %d\n", diff);
//     printf("Product: %d\n", prod);
//     printf("Division: %.2f\n", div);
    
// }

// #include <stdio.h>
// int main(){
//      int score = 50;
//      int *ptr_score = &score;
//      printf("The initial score: %d\n", score );
//      *ptr_score = 100; 
//       printf("The final score: %d\n", *ptr_score);
//       *ptr_score = 150;
//       printf("The challenge score: %d\n", **&ptr_score);
// return 0;
// }


// #include <stdio.h>
// void swap(int *a, int *b){
// int temp = *a;
// *a = *b;
// *b = temp;
// }
// int main(){
//  int x = 10;
//  int y = 20;
//  printf("Before: x = %d y = %d\n", x, y);
//  swap(&x, &y);
//  printf("After: x = %d y = %d\n", x, y);
// return 0;
// }

// #include <stdio.h>
// void calculate(int a, int b, int *sum, int *diff, int *prod, float *div){
//     *sum = a + b;
//     *diff = a - b;
//     *prod = a * b;
//     if(b != 0){
//         *div = (float)a / b;
//     } else {
//         *div = 0; 
//     }
// }
// int main(){
//     int x = 20;
//     int y = 5;
//     int sum, diff, prod;
//     float div;
//     calculate(x, y, &sum, &diff, &prod, &div);
//     printf("Sum: %d\n", sum);
//     printf("Difference: %d\n", diff);
//     printf("Product: %d\n", prod);
//     printf("Division: %.2f\n", div);
//     return 0;
// }

// #include <stdio.h>

// int main() {
//     int numbers[] = {12, 45, 67, 23, 89, 90};
//     int size = sizeof(numbers) / sizeof(numbers[0]);

//     int *ptr = numbers;


//     for (int i = 0; i < size; i++) {
//         printf(" value = %d", *(numbers + i));
//         ptr++; 
//     }
//     return 0;
// }


// #include <stdio.h>
// int main(){
//     int numbers[] = {12, 45, 67, 23, 89, 90};
//     int size = sizeof(numbers) / sizeof(numbers[0]);
//     int *p = numbers;
//     for(int i = 0; i < size; i++){
//         printf("%d\n", *p);
//         p++;
//     }
// }

// #include <stdio.h>
// int main (){
//     int num[] = {1, 2, 3, 4, 5};
//     int size = sizeof(num) / sizeof(num[0]);

//     int *left = num;
//     int *right = num + size - 1;

//     while (left < right) {
//         int temp = *left;
//         *left = *right;
//         *right = temp;

//         left++;
//         right--;
//     }
    
//     int *p = num;
//     for (int i = 0; i < size; i++) 
// {
//         printf("%d ", *p);
//         p++;                                            
//         printf("\n");
//     }

//     return 0;
// }
// #include <stdio.h>

// int main(void)
// {
//     int x;
//     int *ptr = &x;
//     *ptr = 50;
//     printf("%d\n", *ptr);

//     return 0;
// }

 #include <stdio.h> 
int *ptr = malloc(sizeof(int));
*ptr = 100;
printf("%d\n", *ptr);
free(ptr);
