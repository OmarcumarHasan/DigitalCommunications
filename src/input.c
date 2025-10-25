/*
 * Title: File Input Handler for RLE
 * Student ID: B00159813
 * Name: Omar Hasan
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/input.h"

// Reads text input from a file into a buffer
void read_file_input(char *buffer, const char *filename, int max_length) {
    FILE *file = fopen(filename, "r");
    // If fopen returns NULL, it means the file could not be opened (maybe it doesn’t exist)
    if (file == NULL) {
        printf("Error: Could not open file '%s'\n", filename);
        exit(1);
    }

    int i = 0;
    char c;
    // Read each character one by one using fgetc()
    // Keep reading until we reach End-Of-File (EOF)
    while ((c = fgetc(file)) != EOF && i < max_length - 1) {
        buffer[i++] = c;
    }
    buffer[i] = '\0'; // add a null terminator so that 'buffer' becomes a proper C string
    fclose(file);
}
