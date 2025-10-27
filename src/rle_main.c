#include <stdio.h>
#include <string.h>
#include "../include/rle.h"

int main(int argc, char** argv) {
    const char* input = (argc > 1) ? argv[1] : "AAABCCCCDD";
    char output[1024];
    int len = rle_compress(input, output);
    output[len] = '\0';
    printf("%s\n", output);
    return 0;
}
