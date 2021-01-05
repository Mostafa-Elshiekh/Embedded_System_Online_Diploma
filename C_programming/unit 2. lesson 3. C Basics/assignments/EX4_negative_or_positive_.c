/*
 ============================================================================
 Name        : EX4_negative_or_positive.c
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
	float TestNum;
	printf("Enter a number: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f",&TestNum);
	if(TestNum>0)
		printf("%0.2f is positive. \n",TestNum);
	else if(TestNum<0)
		printf("%0.2f is negative. \n",TestNum);
	else
		printf("You enter zero. \n");

	return EXIT_SUCCESS;
}
