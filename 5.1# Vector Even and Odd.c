//Fill a Vector with 100 Numbers, Placing 0 in Even and 1 in Odd Positions

#include <stdio.h>

int main() {
    int vector[100];

    // Fill the vector
    for (int i = 0; i < 100; i++) {
        if (i % 2 == 0) {
            vector[i] = 0; // Even index
        } else {
            vector[i] = 1; // Odd index
        }
    }

    // Print the vector to verify the result
    printf("Vector with 0s in even positions and 1s in odd positions:\n");
    for (int i = 0; i < 100; i++) {
        printf("%d ", vector[i]);
    }
    printf("\n");

    return 0;
}
