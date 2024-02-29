#include <stdio.h>

// Function to generate PRBS9 sequence of specified length
void generate_PRBS9(int *sequence, int length) {
    // Initial seed value for PRBS9
    int seed = 0x1FF; // 9 bits set to 1

    // Feedback taps for PRBS9
    int feedback_taps = 0x1FF; // 9 bits set to 1

    int i;
    for (i = 0; i < length; i++) {
        // Get the next bit by XORing the feedback taps
        int next_bit = (seed >> 8) ^ (seed >> 7) & 1;

        // Shift seed to the left and insert the next bit
        seed = ((seed << 1) | next_bit) & feedback_taps;

        // Store the generated bit in the sequence
        sequence[i] = next_bit;
    }
}

int main() {
    // Desired length of PRBS9 sequence
    int desired_length = 10; // Change this to your desired length

    // Allocate memory for sequence
    int sequence[desired_length];

    // Generate PRBS9 sequence of desired length
    generate_PRBS9(sequence, desired_length);

    // Print the generated sequence
    printf("PRBS9 Sequence (length %d):\n", desired_length);
    int i;
    for (i = 0; i < desired_length; i++) {
        printf("%d ", sequence[i]);
    }
    printf("\n");

    return 0;
}

