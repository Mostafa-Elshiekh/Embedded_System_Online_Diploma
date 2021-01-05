/*
 ============================================================================
 Name        : Ex6_summation.c
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
	int num,sum=0,i;
	printf("Enter an integer number: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&num);
	for(i=1;i<=num;i++)
	{
		sum=sum+i;
	}
	printf("sum=%d",sum);
	return EXIT_SUCCESS;
}
