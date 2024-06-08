#include <stdio.h> 

int main(Ages) {
int age, oldest_age = 0, youngest_age = 100; 

 printf("Lets find out who is the oldest and youngest. \nEnter the people's age (or 0 to stop):\n"); 

 do { //Start of the do-while loop, it will run AT LEAST once, to guarantee an age

 printf("Age: ");
 scanf("%d", &age);

 if (age != 0) { //Check if its 0 to interrupt the code
 if (age > oldest_age) { //Checks if the age is greater than the 'oldest'
 oldest_age = age;
 }

 if (age < youngest_age) { //Now the other way around, if the age is younger than the 'youngest'
 youngest_age = age;
 }
 }
 } while (age != 0); //As long as the age is different from 0, the loop will be alive, otherwise, it will break.

 printf("Age of the oldest person: %d\n", oldest_age);
 printf("Age of the youngest person: %d\n", youngest_age);
 
return 0;
}
