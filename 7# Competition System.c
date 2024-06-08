// A competition organizer wishes to implement a system that has a menu with the following options:
//1. If option 1 is chosen, the system must: Read registration number, grade and names of 100 candidates and store them in a registration vector;
//2. If option 2 is chosen, the system must: Display the overall average of all candidates;
//3. If option 3 is chosen, the system must: Display the name of the candidate who had the highest and lowest score;
//4. If option 4 is chosen, the system must: Read an application number and search for this candidate by printing the name and their score; If the candidate with the name read is not found, the message “Candidate not found” must be printed;
//5. If option 0 is chosen, the system must: end its execution.

#include <stdio.h>
    printf("Grade: ");
    scanf("%f", &candidates[*numCandidates].grade);
    (*numCandidates)++;
}

// Function to calculate overall average grade
float calculateOverallAverage(struct Candidate candidates[], int numCandidates) {
    float totalGrade = 0;
    for (int i = 0; i < numCandidates; i++) {
        totalGrade += candidates[i].grade;
    }
    return totalGrade / numCandidates;
}

// Function to display candidate with highest and lowest grade
void displayMinMaxGrade(struct Candidate candidates[], int numCandidates) {
    float maxGrade = candidates[0].grade;
    float minGrade = candidates[0].grade;
    int maxIndex = 0;
    int minIndex = 0;
    for (int i = 1; i < numCandidates; i++) {
        if (candidates[i].grade > maxGrade) {
            maxGrade = candidates[i].grade;
            maxIndex = i;
        }
        if (candidates[i].grade < minGrade) {
            minGrade = candidates[i].grade;
            minIndex = i;
        }
    }
    printf("Candidate with highest grade: %s (Grade: %.2f)\n", candidates[maxIndex].name, maxGrade);
    printf("Candidate with lowest grade: %s (Grade: %.2f)\n", candidates[minIndex].name, minGrade);
}

// Function to search candidate by registration number
void searchCandidate(struct Candidate candidates[], int numCandidates, char registration_number[]) {
    int found = 0;
    for (int i = 0; i < numCandidates; i++) {
        if (strcmp(candidates[i].registration_number, registration_number) == 0) {
            printf("Candidate found:\n");
            printf("Name: %s\n", candidates[i].name);
            printf("Grade: %.2f\n", candidates[i].grade);
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Candidate not found.\n");
    }
}
