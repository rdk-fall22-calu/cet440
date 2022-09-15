/**
 * @file cipher.c
 * @author Distint Howie (email@pennwest.edu)
 * @author Robert Krency (kre1188@pennwest.edu)
 * @author Anthony Stepich (email@pennwest.edu)
 * @brief Lab 3 for CET 440
 * @date 2022-09-12
 *
 */

#include <stdio.h>
#include <time.h>
#include "cipher.h"

#define ASCII_CHARS 95
#define ASCII_OFFSET 32

int * getCipher(){

    time_t t;
    srand((unsigned) time(&t));

    static int cipher[ASCII_CHARS];
    for  (int i = 0; i < ASCII_CHARS; i++)
    {
        cipher[i] = i;
    }

    // Perform a Fisher-Yates shuffle to randomise the cipher
    for (int i = ASCII_CHARS - 1, j, k; i >= 1; i-- )
    {
        j = rand() % (i+1);
        k = cipher[i];
        cipher[i] = cipher[j];
        cipher[j] = k;
    }

    return cipher;
}

void printCipher(int cipher[])
{
    // Print the cipher
    for (int i = 0; i < ASCII_CHARS; i++)
    {
        printf("[%c,%c]", i+ASCII_OFFSET, cipher[i]+ASCII_OFFSET);
    }
}