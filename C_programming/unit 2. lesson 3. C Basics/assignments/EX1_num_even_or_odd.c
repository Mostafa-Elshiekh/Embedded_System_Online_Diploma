/*
 ============================================================================
 Name        : EX1_num_even_or_odd.c
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
	int TestNum;
	printf("Enter an integer you want to check: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&TestNum);
	if(TestNum%2==0)
		printf("%d is even.\n",TestNum);
	else
		printf("%d is odd.\n",TestNum);
	return EXIT_SUCCESS;
}
