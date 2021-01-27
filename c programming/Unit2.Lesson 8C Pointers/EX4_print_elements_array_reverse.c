/*
 ============================================================================
 Name        : EX4_print_elements_array_reverse.c
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
	int arr[15];
	int num;
	int i;
	int *ptr;


	printf("Input the number of elements to store in the array (max 15): ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);
	ptr=arr;

	for(i=0;i<num;i++)
	{
		printf("ememnt -%d :",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%d",ptr);
		ptr++;
	}
	printf("\n");
	printf("The elements of array in reverse order are :\n");
	ptr=&arr[num]-1;
	for(i=num;i>0;i--)
	{
		printf("ememnt -%d : %d\n",i,*ptr);
		ptr--;
	}
	return EXIT_SUCCESS;
}
