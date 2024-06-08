#include <stdio.h>
int main() {
 int total_votes, blank_votes, null_votes, valid_votes;
 float blank_percentage, null_percentage, valid_percentage;
 // Message to appear
 printf("Enter the total number of votes: ");
 scanf("%d", &total_votes);

 printf("Enter the number of blank votes: ");
 scanf("%d", &blank_votes);

 printf("Enter the number of invalid votes: ");
 scanf("%d", &null_votes);

 printf("Enter the total number of valid votes: ");
 scanf("%d", &valid_votes);

 // Math bellow
 blank_percentage = (float)blank_votes / total_votes * 100;
 null_percentage = (float)null_votes / total_votes * 100;
 valid_percentage = (float)valid_votes/ total_votes* 100;

 // Results
 printf("Percentage of blank: %.2f%%\n", blank_percentage);
 printf("Percentage of nulls: %.2f%%\n", null_percentage);
 printf("Percentage of valid: %.2f%%\n", valid_percentage);
 return 0;
}
