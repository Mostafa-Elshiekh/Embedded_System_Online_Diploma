/*
 ============================================================================
 Name        : EX3_reverse_string.c
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
	char arr[100];
	char *ptr;
	int i;
	printf("Enter the string\n");
	fflush(stdin);fflush(stdout);
	gets(arr);
	ptr=&arr[strlen(arr)-1];


	printf("\nReverse of the string is: \n");
	for(i=0;i<strlen(arr);i++)
	{
		printf("%c",*ptr);
		ptr--;
	}
	return EXIT_SUCCESS;
}
