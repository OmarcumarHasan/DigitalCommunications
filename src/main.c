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
#include "rle.h"
#include "analysis.h"
#include "input.h"

int main(int argc, char *argv[]) {
    char input[1000];
    char compressed[2000];
    memset(input, 0, sizeof(input));
    memset(compressed, 0, sizeof(compressed));

    // -------------------------------
    // 1. Input Handling
    // -------------------------------
    if (argc > 1) {
        if (strstr(argv[1], ".txt")) {
            read_file_input(input, argv[1], sizeof(input));
        } else {
            strncpy(input, argv[1], sizeof(input) - 1);
        }
    } else {
        strcpy(input, "AAAABBCCDAA"); // Default hardcoded string
    }

    // -------------------------------
    // 2. Compression
    // -------------------------------
    printf("Original: %s\n", input);
    int comp_len = rle_compress(input, compressed);
    compressed[comp_len] = '\0';
    printf("Compressed: %s\n", compressed);

    // -------------------------------
    // 3. Analysis
    // -------------------------------
    analyze_data(input, compressed);

    return 0;
}