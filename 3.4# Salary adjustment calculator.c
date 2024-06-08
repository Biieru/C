#include <stdio.h>
int main() {
 float salary, percentage, new_salary;
 // Request the current salary
 printf("Enter the employee's current salary: ");
 scanf("%f", &salary);
// And the adjustment percentage
 printf("Enter the adjustment percentage (in percentage): ");
 scanf("%f", &percentage);
// Here comes the math
 new_salary = salary + salary * (percentage / 100);
// And the new salary
 printf("The employee's new salary will be: %.2f\n", new_salary);
 return 0;

}
