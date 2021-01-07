/*
 ============================================================================
 Name        : EX1_SumTowMatrix.c
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
	float arr1[2][2];
	float arr2[2][2];
	float sum [2][2]={0}; //the 3st matrix
	int i,j;
	printf("Enter elements of 1st matrix:\n");
	fflush(stdin);fflush(stdout);
	for(i=0;i<2;i++)  //scanning elements of 1st matrix from user
	{
		for(j=0;j<2;j++)
		{
			printf("Enter a%d%d: ",i,j);
			fflush(stdin);fflush(stdout);
			scanf("%f",&arr1[i][j]);
		}
	}
	printf("====================\n");
	printf("Enter elements of 2st matrix:\n");
	for(i=0;i<2;i++)           //scanning elements of 2st matrix from user
	{
		for(j=0;j<2;j++)
		{
			printf("Enter b%d%d: ",i,j);
			fflush(stdin);fflush(stdout);
			scanf("%f",&arr2[i][j]);
		}
	}
	for(i=0;i<2;i++)          //sum every element in 1st matrix with another element in 2th matrix
	{
		for(j=0;j<2;j++)
		{
			sum[i][j]=arr1[i][j]+arr2[i][j];
		}
	}
	printf("====================\n");
	printf("Sum of matrix is : \n");
	for(i=0;i<2;i++)           //print the summation of tow matrix
	{
		for(j=0;j<2;j++)
		{
			printf("%0.2f  ",sum[i][j]);
		}
		printf("\n");
	}


	return EXIT_SUCCESS;
}
