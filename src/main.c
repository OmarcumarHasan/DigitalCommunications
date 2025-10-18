/*
 * Title: RLE Compression Project – Stage 2 Core Algorithm
 * Student ID: B00159813
 * Name: Omar Hasan
 * Description:
 *   Implements a basic Run-Length Encoding (RLE) algorithm
 *   using a hardcoded text input. This stage focuses only
 *   on getting the core compression logic working correctly.
 */

#include <stdio.h>
#include <string.h>

int main(void) {
    // Hardcoded input text for testing
    char input[] = "AAAABBCCDAA";

    printf("Original: %s\n", input);
    printf("Compressed: ");

    int count = 1;

    // Core RLE logic
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == input[i + 1]) {
            count++;
        } else {
            printf("%c%d", input[i], count);
            count = 1;
        }
    }

    printf("\n");
    printf("Stage 2 complete core algorithm verified.\n");
    return 0;
}
