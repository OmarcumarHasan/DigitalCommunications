/*
 * Title: RLE Compression Function
 * Student ID: B00159813
 * Name: Omar Hasan
 *
 * What this does (Run‑Length Encoding):
 *   - Replaces repeated characters with: <character><repeat_count>
 *   - Example: "AAABCCCCDD" -> "A3B1C4D2"
 *
 * Assumptions/simplifications:
 *   - `input` is a valid, null‑terminated C string.
 *   - `output` has enough space (no bounds checking; keep it larger than input).
 *   - Only simple ASCII characters are expected.
 */

#include <stdio.h>    // sprintf
#include <string.h> 
#include "../include/rle.h"

// Performs Run-Length Encoding (RLE) compression and writes output into 'output' buffer
// Returns the number of bytes written (not including a '\0').
int rle_compress(const char *input, char *output) {
    int count = 1;  // how many times the current character repeats
    int j = 0;      // write position inside `output`

    // Loop through each character (we look ahead one char to detect a change)
    // Note: this uses strlen(input) in the loop condition for clarity;
    // for very long strings you could cache the length in a local variable.
    for (int i = 0; i < strlen(input); i++) {
        if (input[i] == input[i + 1]) {
            // Same as the next character -> keep counting
            count++;
        } else {
            // Sequence ended -> write character and count, e.g., 'A3'
            j += sprintf(&output[j], "%c%d", input[i], count);
            count = 1;  // reset for the next sequence
        }
    }
    return j; // return number of bytes written
}
