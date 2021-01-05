/*
 ============================================================================
 Name        : EX8_Simple_calculator.c
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
	float num1,num2;
	char operator;
	printf("Enter operator either + or - or * or divide: \n"); //to determine the operator
	fflush(stdin);
	fflush(stdout);
	scanf("%c",&operator);
	printf("Enter tow operands: \n");
	fflush(stdin);
	fflush(stdout);
	scanf("%f %f",&num1,&num2);
	if(operator=='+')    
		printf("%0.2f + %0.2f = %0.2f",num1,num2,num1+num2);
	if(operator=='-')    
		printf("%0.2f - %0.2f = %0.2f",num1,num2,num1-num2);
	if(operator=='*')
		printf("%0.2f * %0.2f = %0.2f",num1,num2,num1*num2);
	if(operator=='/')
		printf("%0.2f / %0.2f = %0.2f",num1,num2,num1/num2);
	return EXIT_SUCCESS;
}
