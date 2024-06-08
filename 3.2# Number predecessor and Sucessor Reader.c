#include <stdio.h>

int main() {
// Reading the chosen number
 int number;
 printf("Enter a number: ");
 scanf("%d", &number);
 //Calculation and display of what comes before and after
 printf("Predecessor: %d\n", number - 1);
 printf("Successor: %d\n", number + 1);
 return 0;
}
