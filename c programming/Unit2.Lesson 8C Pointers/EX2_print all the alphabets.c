/*
 ============================================================================
 Name        : EX3_print.c
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
	char *ptr;
	char arr[]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
	ptr=arr;
	printf("The Alphabets are: \n");
	for(ptr=arr;ptr<&arr[sizeof(arr)];ptr++)
	{
		printf("%c ",*ptr);
	}
	return EXIT_SUCCESS;
}
