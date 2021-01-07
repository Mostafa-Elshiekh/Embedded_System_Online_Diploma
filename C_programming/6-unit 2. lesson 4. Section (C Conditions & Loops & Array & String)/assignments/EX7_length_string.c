/*
 ============================================================================
 Name        : EX7_length_string.c
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
	int count=0,i;
	char str[100];
	printf("Enter a string: ");
	fflush(stdout);fflush(stdout);
	gets(str);
	for(i=0;str[i]!='\0';i++)
	{
		count++;
	}
	printf("Length of string: %d\n",count);

	return EXIT_SUCCESS;
}
