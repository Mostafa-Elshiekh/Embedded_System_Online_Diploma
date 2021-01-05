/*
 ============================================================================
 Name        : EX7_factorial.c
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
	int num,i,fact=1;
	printf("Enter an integer : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d",&num);
	if(num==0 || num==1) //if num is 0 or one , fact equal one
		printf("Factorial = 1");
	if(num<0)
		printf("Error!!! factorial of negative number doesn't exit. \n");
	if(num>1)
	{
		for(i=num;i>0;i--)
		{
			fact*=i;
		}
		printf("Factorial %d",fact);
	}
	return 0;
}
