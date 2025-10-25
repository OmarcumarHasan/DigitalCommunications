/*
 * Title: Data Analysis Functions for RLE
 * Student ID: B00159813
 * Name: Omar Hasan
 * Description:
 *   Analyses input data before and after compression.
 *   Calculates character frequencies, finds most and least
 *   frequent characters, and determines the compression ratio.
 */

#include <stdio.h>
#include <string.h> // used for strlen
#include "analysis.h"

// Analyzes the data to find frequency, most/least frequent characters, and compression ratio
void analyze_data(const char *input, const char *compressed) {
    int freq[256] = {0}; // Frequency array for all ASCII characters
    int len_in = strlen(input); // uncompressed length
    int len_out = strlen(compressed); // compressed length

    // Count frequency of each character in input
    for (int i = 0; i < len_in; i++) {
        unsigned char c = input[i];
        freq[c]++;
    }

    // Identify most and least frequent characters
    int max = 0, min = len_in;
    unsigned char max_char = 0, min_char = 0;

    //calculate compression ratio = uncompressed size / compressed size
    for (int i = 0; i < 256; i++) {
        if (freq[i] > 0) {
            if (freq[i] > max) { max = freq[i]; max_char = i; }
            if (freq[i] < min) { min = freq[i]; min_char = i; }
        }
    }

    // Print analysis results
    printf("\n--- Analysis ---\n");
    printf("Most frequent character: '%c' (%d times)\n", max_char, max);
    printf("Least frequent character: '%c' (%d times)\n", min_char, min);
    printf("Compression ratio: %.2f\n", (float)len_in / len_out);
    printf("-----------------\n");
}
