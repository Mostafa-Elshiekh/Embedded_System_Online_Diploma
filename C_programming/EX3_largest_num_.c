/*
 ============================================================================
 Name        : EX3_largest_num.c
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
	float num1,num2,num3;
	printf("Enter three numbers: ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f %f %f",&num1,&num2,&num2);
	if(num1>=num2 && num1>=num3)  //in this case num1 is the largest number
		printf("Largest number = %0.3f",num1);
	if(num2>num1 && num2>=num3)  //in this case num2 is the largest number
		printf("Largest number = %0.3f",num2);
	if(num3>=num1 && num3>num2)  //in this case num3 is the largest number
		printf("Largest number = %0.3f",num3);
	return EXIT_SUCCESS;
}
