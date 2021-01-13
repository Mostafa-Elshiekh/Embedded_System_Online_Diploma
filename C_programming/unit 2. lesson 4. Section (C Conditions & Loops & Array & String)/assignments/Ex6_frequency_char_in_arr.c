/*
 ============================================================================
 Name        : Ex6_frequency_char_in_arr.c
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
	int i,count=0;
	char arr[100],TestChar;
	printf("Enter a string : ");
	fflush(stdout);fflush(stdout);
	gets(arr);
	printf("Enter a character to find frequency: ");  //scanning the element which user want count frequency it
	fflush(stdout);fflush(stdout);
	scanf("%c",&TestChar);
	for(i=0;i<strlen(arr);i++)                       //loop on array if it found it plus the count
	{
		if(arr[i]==TestChar)
			count++;                                 //count number of frequency
	}
	printf("Frequency of %c = %d",TestChar,count);


	return EXIT_SUCCESS;
}
