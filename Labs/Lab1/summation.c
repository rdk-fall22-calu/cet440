/*
 *  @author Robert Krency, kre1188@pennwest.edu
 *  @date 8/26/22
 * 
 *  Summation.c - A simple recursive program for summing all positive integers
 *    up to and including the input integer from a user.
 *  
 */

#include <stdio.h>
#include <stdlib.h>

long long summation (long long i) {
	return (i == 0) ? 0 : i + summation(i - 1);
}

int main()
{
	long long number, sum=0;

	printf("Summation Calculator\n");
	printf("Please enter a nonnegative integer (0 - 2147483647): ");

	// Credit for input error handling loop:
	//		https://stackoverflow.com/a/26583890
	// Reason for usage:
	//		Scanf requires many error checking edge cases that cannot all
	//		be handled elegantly, or even guaranteed to be found.
	char *p, s[100];
	while (fgets(s, sizeof(s), stdin)) {
        number = strtoll(s, &p, 10);
		// Limit to 261984, as that was stack limit on test machine
        if (p == s || *p != '\n'|| number < 0 || number > 261984) {
			printf("Invalid entry.\n");
            printf("Please enter a nonnegative integer (0 - 261984): ");
        } else break;
    }

	printf("Calculating summation for %lld.\n", number);
	
	sum = summation(number);
	
	printf( "The summation of %lld is %lld.\n", number, sum);
	return 0;
}
