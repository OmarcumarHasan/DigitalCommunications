/*
 * Small demo program for the RLE compressor.
 *
 * Goal: take a text string, compress it with rle_compress(),
 *       and print the compressed result to the console.
 *
 * How to run (from src):
 *   make 03            -> builds ../bin/rle.exe
 *   ../bin/rle.exe     -> runs with a default sample string
 *   ../bin/rle.exe AAAABCCDD -> runs with your own input
 */

#include <stdio.h>   // printf
#include <string.h>  // strlen (used by the library function)
#include "../include/rle.h"  // declaration of rle_compress()

int main(int argc, char** argv) {
    // 1) Pick the input string
    // If the user passed a string on the command line, use it.
    // Otherwise, use a short built-in example.
    const char* input = (argc > 1) ? argv[1] : "AAABCCCCDD";

    // 2) Provide a buffer for the compressed output
    // Make it larger than the input to be safe (no strict bound checks here).
    char output[1024];

    // 3) Call the compressor
    // rle_compress() writes the compressed text into `output` and
    // returns how many bytes it wrote (excluding the final '\0').
    int len = rle_compress(input, output);

    // 4) Add a string terminator so `output` is a valid C string
    output[len] = '\0';

    // 5) Print the compressed result
    printf("%s\n", output);

    return 0;
}
