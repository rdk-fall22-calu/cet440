/**
 * @file lab3.c
 * @author Distint Howie (email@pennwest.edu)
 * @author Robert Krency (kre1188@pennwest.edu)
 * @author Anthony Stepich (email@pennwest.edu)
 * @brief Lab 3 for CET 440
 * @date 2022-09-12
 *
 */

#define ASCII_OFFSET 32
#define ASCII_CHARS 95

#include <stdio.h>
#include <time.h>
#include "cipher.h"

int main() {

    int *cipher;
    cipher = getCipher();
    printCipher(cipher);

    // Exit
    return 0;
}