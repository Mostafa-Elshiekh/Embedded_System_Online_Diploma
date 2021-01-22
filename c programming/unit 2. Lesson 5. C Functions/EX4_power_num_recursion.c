/*
 ============================================================================
 Name        : EX4_power_num_recursion.c
 Author      : Mostafa Elshiekh
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int CalcPower(int num,int power);
/*parameters: base number (num) , power number
 *function  : calculate the power for base number by using recursion
 *return    : the the factorial  */

int main(void)
{
	int num,power;
	printf("Enter base number: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);
        printf("Enter power number (positive integer): ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&power);
	printf("%d^%d = %d",num,power,CalcPower(num,power));

	return EXIT_SUCCESS;
}
int CalcPower(int num,int power)
{
	if (power==0)
		return 1;
	else
	{
		power--;       //decrement the power
		return num*CalcPower(num,power);  //recursion by call CalcPower but new power value
	}


}
