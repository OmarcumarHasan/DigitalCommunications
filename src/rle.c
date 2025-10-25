/*
 * Title: RLE Compression Function
 * Student ID: B00159813
 * Name: Omar Hasan
 */

#include <stdio.h>
#include <string.h>
#include "../include/rle.h"

// Performs Run-Length Encoding (RLE) compression and writes output into 'output' buffer
// Returns the length of the compressed string
int rle_compress(const char *input, char *output) {
    int count = 1;
    int j = 0;

    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == input[i + 1]) {
            count++;
        } else {
            j += sprintf(&output[j], "%c%d", input[i], count);
            count = 1;
        }
    }
    return j;
}
