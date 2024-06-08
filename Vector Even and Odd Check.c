//Check the Number of Even and Odd Numbers in a Vector with 100 Integer Values

#include <stdio.h>

int main() {
    int vector[100];
    int even_count = 0;
    int odd_count = 0;

    // Fill the vector with some values
    for (int i = 0; i < 100; i++) {
        vector[i] = i; //Just an example to fill with numbers 0 to 99
    }

    // Count even and odd numbers
    for (int i = 0; i < 100; i++) {
        if (vector[i] % 2 == 0) {
            even_count++;
        } else {
            odd_count++;
        }
    }

    // Print the counts
    printf("Number of even numbers: %d\n", even_count);
    printf("Number of odd numbers: %d\n", odd_count);

    return 0;
}
