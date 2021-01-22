/*
 ============================================================================
 Name        : EX5_search_in_array.c
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
	int arr[20],size,i,SearchedNum,count=11;
	printf("Enter number of elements: ");    //scanning the size of array
	fflush(stdout);fflush(stdout);
	scanf("%d",&size);
	for(i=0;i<size;i++)                      //put element in array start by 11 and pulse 11 in each period
	{
		arr[i]=count;
		count+=11;
	}
	for(i=0;i<size;i++)                      //print array after full
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	printf("Enter the number to be searched : ");  //scanning element which user want search it
	fflush(stdout);fflush(stdout);
	scanf("%d",&SearchedNum);
	for(i=0;i<size;i++)                            //loop on array and compare all element with the number
	{
		if(arr[i]==SearchedNum)
		{
			printf("Number found at the location = %d \n",i);
			return EXIT_SUCCESS;                  //if it founded end the program
		}
	}

	printf("Number not found\n");
	return EXIT_SUCCESS;
}
