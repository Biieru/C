#include <stdio.h> 
  int main(Choosing_Table) { 
  int number, i; 

 printf("Enter a number to generate your multiplication table from 1 to 10: ");
 scanf("%d", &number); 

 printf("Table of %d:\n", number); 

//math
 
  for (i = 1; i <= 10; i++) {
  printf("%d x %d = %d\n", number, i, number * i); 
 }
 return 0;
}
