#include <stdio.h>

int main(){
	int number, count;
	printf("Enter an integer" );
	count = scanf("%d", &number);
	printf("Value entered: %d\nScan return: %d\n", number, count);
	return 0;
}
