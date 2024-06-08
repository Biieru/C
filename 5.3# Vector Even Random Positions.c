//Fill a Vector with 100 Elements with random values and print values in Even positions

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    int vector[100];

    // Seed the rng
    srand(time(NULL));

    // Fill the vector
    for (int i = 0; i < 100; i++) {
        vector[i] = rand() % 1000; // Random values between 0 and 999
    }

    // Print the values at even positions (2, 4, 6, etc...)
    printf("Values at even positions (1-based index):\n");
    for (int i = 1; i < 100; i += 2) { // Start from index 1 (2nd position)
        printf("vector[%d] = %d\n", i + 1, vector[i]);
    }

    return 0;
}
