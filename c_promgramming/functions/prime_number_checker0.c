#include <stdio.h>

int checkPrimeNumber();

int main() {
//   int result = checkPrimeNumber();    // argument is not passed
    float sqrt = sqrt(16.0);  // calculate the square root of 16
    // x^2+10
    int x = 5;
    int x_squared = pow(x, 2);
    int result = x_squared + 10;
    // or shortly
    int res = pow(x,2) + 10;
  printf("The result of the function is: %d\n", checkPrimeNumber());  // print the result
  return 0;
}

// return type is void meaning doesn't return any value
int checkPrimeNumber() {
  int n, i, flag = 0;

  printf("Enter a positive integer: ");
  scanf("%d",&n);

  // 0 and 1 are not prime numbers    
  if (n == 0 || n == 1)
    flag = 1;

  for(i = 2; i <= n/2; ++i) {
    if(n%i == 0) {
      flag = 1;
      break;
    }
  }

  if (flag == 1){
    printf("%d is not a prime number.", n);
    return 0;  // return 0 to indicate the function has completed successfully
  }
  else {
    printf("%d is a prime number.", n);
    return 1;  // return 1 to indicate the function has completed successfully
  }
}
