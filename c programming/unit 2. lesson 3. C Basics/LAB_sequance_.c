/*
 ============================================================================
 Name        : LAB_sequance.c
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

	for(i=0;i<10;i++)
	{
		for(j=i;j<10;j++) 
		{
			printf("%d ",j);
		}
		printf("\n");
	}
	return EXIT_SUCCESS;
}
