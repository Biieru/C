// The city of Recife carried out a survey at Faculdade SENAC with 1000 students, collecting data on salary and number of children. The city council wants to know: 
// a) average salary of the population; b) average number of children; c) highest and lowest salary; d) percentage of inhabitants with more than 2 children.

#include <stdio.h>

#define TOTAL_STUDENTS 1000

int main() {
    float salary[TOTAL_STUDENTS];
    int children[TOTAL_STUDENTS];
    float total_salary = 0;
    int total_children = 0;
    float highest_salary = 0;
    float lowest_salary = 0;
    int more_than_2_children = 0;

    // Initialize with some example data
    for (int i = 0; i < TOTAL_STUDENTS; i++) {
        // Example data: salary range 1000-5000, children range 0-5
        salary[i] = (float)(rand() % 4001 + 1000); // Random salary between 1000 and 5000
        children[i] = rand() % 6; // Random number of children between 0 and 5
    }

    // Initialize highest and lowest salary with the first student's salary
    highest_salary = salary[0];
    lowest_salary = salary[0];

    // Analyze the data
    for (int i = 0; i < TOTAL_STUDENTS; i++) {
        total_salary += salary[i];
        total_children += children[i];

        if (salary[i] > highest_salary) {
            highest_salary = salary[i];
        }
        if (salary[i] < lowest_salary) {
            lowest_salary = salary[i];
        }
        if (children[i] > 2) {
            more_than_2_children++;
        }
    }

    // Calculate averages
    float average_salary = total_salary / TOTAL_STUDENTS;
    float average_children = (float)total_children / TOTAL_STUDENTS;
    float percentage_more_than_2_children = (float)more_than_2_children / TOTAL_STUDENTS * 100;

    // Print the results
    printf("Average salary of the population: %.2f\n", average_salary);
    printf("Average number of children: %.2f\n", average_children);
    printf("Highest salary: %.2f\n", highest_salary);
    printf("Lowest salary: %.2f\n", lowest_salary);
    printf("Percentage of inhabitants with more than 2 children: %.2f%%\n", percentage_more_than_2_children);

    return 0;
}
