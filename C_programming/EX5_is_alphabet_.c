/*
 ============================================================================
 Name        : EX5_is_alphabet.c
 Author      : Mostafa Elshiekh
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include<string.h>

int main(void)
{
	char TestChar;
	printf("Enter a character: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%c",&TestChar);
	if(isalpha(TestChar)==1)  //isalpha() return 1 if alphabet,and return 0 if not
		printf("%c is an alphabet",TestChar);
	else
		printf("%c is not an alphabet",TestChar);
	return EXIT_SUCCESS;
}
