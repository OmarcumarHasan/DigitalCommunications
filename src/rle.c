#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Run-Length Encoding function
// Returns the length of the encoded data
int rle_encode(const char *input, int input_len, char *output, int max_output_len) {
    if (input == NULL || output == NULL || input_len <= 0) {
        return -1;
    }
    
    int out_idx = 0;
    int i = 0;
    
    while (i < input_len) {
        char current = input[i];
        int count = 1;
        
        // Count consecutive identical characters
        while (i + count < input_len && input[i + count] == current && count < 255) {
            count++;
        }
        
        // Check if we have enough space in output buffer
        if (out_idx + 2 > max_output_len) {
            return -1;  // Buffer overflow
        }
        
        // Store count and character
        output[out_idx++] = (char)count;
        output[out_idx++] = current;
        
        i += count;
    }
    
    return out_idx;
}

// Run-Length Decoding function
// Returns the length of the decoded data
int rle_decode(const char *input, int input_len, char *output, int max_output_len) {
    if (input == NULL || output == NULL || input_len <= 0 || input_len % 2 != 0) {
        return -1;
    }
    
    int out_idx = 0;
    
    for (int i = 0; i < input_len; i += 2) {
        int count = (unsigned char)input[i];
        char character = input[i + 1];
        
        // Check if we have enough space in output buffer
        if (out_idx + count > max_output_len) {
            return -1;  // Buffer overflow
        }
        
        // Write the character 'count' times
        for (int j = 0; j < count; j++) {
            output[out_idx++] = character;
        }
    }
    
    return out_idx;
}

// Example usage
int main() {
    const char *test_string = "AAAAAABBBCCCCCCDDEEEE";
    char encoded[256];
    char decoded[256];
    
    printf("Original: %s\n", test_string);
    printf("Original length: %zu\n\n", strlen(test_string));
    
    // Encode
    int encoded_len = rle_encode(test_string, strlen(test_string), encoded, sizeof(encoded));
    if (encoded_len < 0) {
        fprintf(stderr, "Encoding failed!\n");
        return 1;
    }
    
    printf("Encoded length: %d\n", encoded_len);
    printf("Encoded (hex): ");
    for (int i = 0; i < encoded_len; i++) {
        printf("%02X ", (unsigned char)encoded[i]);
    }
    printf("\n\n");
    
    // Decode
    int decoded_len = rle_decode(encoded, encoded_len, decoded, sizeof(decoded));
    if (decoded_len < 0) {
        fprintf(stderr, "Decoding failed!\n");
        return 1;
    }
    
    decoded[decoded_len] = '\0';
    printf("Decoded: %s\n", decoded);
    printf("Decoded length: %d\n", decoded_len);
    
    return 0;
}