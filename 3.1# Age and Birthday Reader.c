#include <stdio.h> 

int main() { 
    int year_birth; 
    printf("Type the year you were born: "); 
    scanf("%d", &year_birth);      
    int age = 2024 - year_birth; //Change the '2024' to the present year.  
    printf("Your age in 2024 is: %d years old\n", age);  //Same thing, the year. 
    return 0; 
} 
