/*
 ============================================================================
 Name        : EX1_Prime_num.c
 Author      : Mostafa Elshiekh
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

int TestPrime(int TestNum);
/*parameters: TestNum
 *function  : Test if the TestNum prime number or not
 *return    : flag 1 if number prime and zero if not  */


int main(void)
{
	int num1,num2,i;
	printf("Enter tow number: ");
	fflush(stdin);fflush(stdout);
	scanf("%d %d",&num1,&num2);

	printf("prime number between %d and %d are: ",num1,num2);
	for(i=num1+1;i<num2;i++)  //loop on the range
	{
		if(TestPrime(i)==0)
			printf("%d ",i);
	}
	return EXIT_SUCCESS;
}

int TestPrime(int TestNum)
{
	int i,flage=0;
	for(i=2;i<TestNum;i++)
	{
		if (TestNum%i==0)
		{
			flage=1; //If the number is divisible by any number other than itself and the one
			break;
		}
	}
	return flage;
}
