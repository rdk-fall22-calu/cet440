/**
 * @file lab3.c
 * @author Distint Howie (how4685@pennwest.edu)
 * @author Robert Krency (kre1188@pennwest.edu)
 * @author Anthony Stepich (ste4864@pennwest.edu)
 * @brief Lab 3 for CET 440
 *
 */

#define ASCII_OFFSET 32
#define ASCII_CHARS 95

#include <stdio.h>
#include <time.h>
#include <string.h>
#include "cipher.h"

int main() {

    // Setup the cipher
    int *cipher;
    cipher = getCipher();

    // Get user input
    printf("Enter text to encipher: ");
    char input[500];
    fgets(input, sizeof(input), stdin);

    // Encipher the input
    encipher(input, cipher);

    // Print the enciphered text
    printf("%s\n", input);

    // Print the cipher key
    printCipher(cipher);

    // Exit
    return 0;
}