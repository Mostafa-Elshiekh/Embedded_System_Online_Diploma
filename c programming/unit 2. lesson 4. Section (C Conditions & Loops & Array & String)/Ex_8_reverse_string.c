/*
 ============================================================================
 Name        : Ex_8_reverse_string.c
 Author      : Mostafa Elshiekh
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
	int i=0,j;
	char temp;
	char str[100];
	printf("Enter a string: ");
	fflush(stdout);fflush(stdout);
	gets(str);
	j=strlen(str)-1;
	while(i<j)                //swapping from the end and start
	{
		temp=str[i];
		str[i]=str[j];
		str[j]=temp;
		i++;
		j--;
	}

printf("Reverse string is: %s",str);



	return EXIT_SUCCESS;
}
