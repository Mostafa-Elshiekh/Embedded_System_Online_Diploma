/*
 ============================================================================
 Name        : EX2_VOWEL_OR_CONSONANT.c
 Author      : Mostafa Elshiekh
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	char TestChar;
	int i;
	char arr[11]={'A','a','E','e','I','i','O','o','U','u'};//define array include all vowel characters
	printf("Enter an alphabet: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%c",&TestChar);
	for(i=0;i<10;i++)
	{
		if(TestChar==arr[i])
		{
			printf("%c is a vowel. \n",arr[i]);
			return EXIT_SUCCESS; //to end the programe if char is vowel
		}
	}
	printf("%c is a consonant. \n",TestChar);
	return EXIT_SUCCESS;
}
