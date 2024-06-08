//A function that raises any integer to a power. The number and power must be provided by the user.

#include <stdio.h>

// Function to calculate power
int power(int base, int exponent) {
    int result = 1;
    for (int i = 0; i < exponent; i++) {
        result *= base;
    }
    return result;
}

int main() {
    int base, exponent;

    // Get input from the user
    printf("Enter the base number: ");
    scanf("%d", &base);

    printf("Enter the exponent: ");
    scanf("%d", &exponent);

    // Handle the case when the exponent is negative
    if (exponent < 0) {
        printf("This program does not handle negative exponents.\n");
    } else {
        // Calculate the power using the power function
        int result = power(base, exponent);

        // Print the result
        printf("%d raised to the power of %d is: %d\n", base, exponent, result);
    }

    return 0;
}
