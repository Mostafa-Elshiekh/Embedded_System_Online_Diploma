/*
 ============================================================================
 Name        : EX3_transpose_matrix.c
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
	int i,j;
	int NumRows,NumColumns;
	int arr[5][5];
	printf("Enter number rows and columns of matrix: ");
	fflush(stdin);fflush(stdout);
	scanf("%d%d",&NumRows,&NumColumns);   //scanning NumRows and NumColumns
	printf("Enter elements of matrix: \n");
	for(i=0;i<NumRows;i++)
	{
		for(j=0;j<NumColumns;j++)        //scanning the elements of matrix
		{
			printf("Enter element a%d%d: ",i,j);
			fflush(stdin);fflush(stdout);
			scanf("%d",&arr[i][j]);
		}
	}
	printf("====================\n");
	printf("Entered matrix: \n");
	for(i=0;i<NumRows;i++)                  //print Transpose of matrix
	{
		for(j=0;j<NumColumns;j++)
		{
			printf("%d  ",(arr[i][j]));
		}
		printf("\n\n");
	}
	printf("====================\n");
	printf("Transpose of matrix: \n");         //print Transpose of matrix
	for(i=0;i<NumColumns;i++)
	{
		for(j=0;j<NumRows;j++)
		{
			printf("%d  ",(arr[j][i]));
		}
		printf("\n\n");
	}

	return EXIT_SUCCESS;
}
