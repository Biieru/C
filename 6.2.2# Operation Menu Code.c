//Write an algorithm, in C, that presents a menu with four options: 1 – Sum, 2 – Subtraction, 3 – Multiplication and 4 – Leave

#include <stdio.h>

int main() {
    int choice;
    int num1, num2;
    int result;

    do {
        // Display the menu
        printf("\nMenu:\n");
        printf("1 - Sum\n");
        printf("2 - Subtraction\n");
        printf("3 - Multiplication\n");
        printf("4 - Leave\n");
        
        // Get the user's choice
        printf("Enter your choice: ");
        scanf("%d", &choice);

        // Perform the corresponding operation based on the choice
        switch (choice) {
            case 1:
                // Sum operation
                printf("Enter the first number: ");
                scanf("%d", &num1);
                printf("Enter the second number: ");
                scanf("%d", &num2);
                result = num1 + num2;
                printf("The result of the sum is: %d\n", result);
                break;

            case 2:
                // Subtraction operation
                printf("Enter the first number: ");
                scanf("%d", &num1);
                printf("Enter the second number: ");
                scanf("%d", &num2);
                result = num1 - num2;
                printf("The result of the subtraction is: %d\n", result);
                break;

            case 3:
                // Multiplication operation
                printf("Enter the first number: ");
                scanf("%d", &num1);
                printf("Enter the second number: ");
                scanf("%d", &num2);
                result = num1 * num2;
                printf("The result of the multiplication is: %d\n", result);
                break;

            case 4:
                // Leave
                printf("Exiting the program.\n");
                break;

            default:
                printf("Invalid choice. Please choose a valid option.\n");
                break;
        }
    } while (choice != 4);

    return 0;
}
