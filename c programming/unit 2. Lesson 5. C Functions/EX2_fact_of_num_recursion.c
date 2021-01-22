/*
 ============================================================================
 Name        : EX2_fact_of_num_recursion.c
 Author      : Mostafa Elshiekh
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
int fact(int num); //declaration
/*parameters: num
 *function  : calculate factorial of this number by recursion
 *return    : the the factorial  */

int main(void)
{
	int num;
	printf("Enter an positive integer: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);
	printf("Factorial of %d = %d",num,fact(num));
	return EXIT_SUCCESS;
}
int fact(int num)//definition
{
	if(num==0 || num==1)
		return 1;
	else
		return (num*fact(num-1)); //num*fact(num-1)...fact(1)
}
