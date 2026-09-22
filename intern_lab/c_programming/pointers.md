Exercise 1 — Inspect an Address

Challenge

Why do `ptr` and `&age` have the same value?

They have the same value because `ptr` was initialized with the address of `age`:

```c
int *ptr = &age;
```
Therefore, `ptr` stores thesame memory adress as `&age`.


Exercise 2 — Modify Through a Pointer

Challenge Answer

We used the pointer `ptr` to modify the value of `score` by accessing its memory address. First, we set `*ptr = 100`, changing `score` from 50 to 100. Then we set `*ptr = 150`, so `score` became 150. In summary, using a pointer allows us to change the original variable indirectly by modifying the value at its address.


Exercise 4 — Calculator Using Pointers

Challenge

Add division and handle division by zero.

Division was added using an `if` statement to check that the second number is not zero before performing the division. This prevents the program from attempting to divide by zero.

```c
if (b != 0)
{
    printf("Division: %.2f\n", (float)a / b);
}
else
{
    printf("Division: Cannot divide by zero\n");
}
```


Exercise 7 — Traverse an Array Using Pointers

Challenge

Rewrite it so that you don't even use `i`: `int *ptr = numbers;` and move the pointer through the array.

I removed the index variable `i` and used a pointer to move through the array.

```c
int *ptr = numbers;

while (ptr < numbers + size)
{
    printf("%d\n", *ptr);
    ptr++;
}
```

The pointer `ptr` starts at the first element of the array. `*ptr` accesses the current value, while `ptr++` moves the pointer to the next element. The loop continues until the pointer reaches the position after the last element.


Exercise 9 — Array Sum

Challenge

Calculate the average using the same function or additional pointer-based logic.

The average can be calculated using the sum returned by the pointer-based `array_sum()` function:

```c
int sum = array_sum(numbers, size);
float average = (float)sum / size;



Exercise 11 - Inventory System

Challenge

Prevent removing more stock than is available.

I used an if statement:

if (quantity <= product->quantity)

If enough stock is available, the quantity is reduced. Otherwise, the program displays an error and leaves the stock unchanged.

For example, when the stock was 30 and I tried to remove 31, the program produced:

Error: Not enough stock available.
Product: Rice
Quantity: 30
Price: 15000

The quantity remained 30, proving that the program prevented the inventory from becoming negative.


Exercise 16

Explain why &number is an int **.

number is declared as:

int *number = NULL;

Therefore, number is a pointer to an integer, so its type is int *.

When I use:

&number

I am getting the address of the pointer variable itself. Therefore, its type is int **, which means a pointer to a pointer to an integer.



Exercise 18: Debugging

1) The pointer is not initialised, so it's not pointing to any memory adress.

2) It crashes because the ptr is dereferenced without being initialised.

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



Exercise 19

1) A function is defined in another function which c does not support nested function and the
function is returning the adress of a local variable.

2) It is dangerous because a local variable's storage doesn't belong to it anymore once the function returns

3) code:
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



Exercise 20 - Memory Leak

int *ptr = malloc(sizeof(int));

*ptr = 100;

printf("%d\n", *ptr);

1.	What’s missing? 

free(ptr);

2.	What happens if this function is called 1,000,000 times without free()?

If the function is called 1,000,000 times without free(), the memory allocated by malloc() is not released. The program will keep using more and more memory, which causes a memory leak. If enough memory is lost, the program may eventually run out of available memory and become slower or fail







