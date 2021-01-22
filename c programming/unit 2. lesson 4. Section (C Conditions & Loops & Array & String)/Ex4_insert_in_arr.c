/*
 ============================================================================
 Name        : EX4_insert_element_in_arr.c
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
	int i;
	int arr[20],size,location,InsertedNum;
	printf("Enter number of elements: ");
	fflush(stdout);fflush(stdout);
	scanf("%d",&size);
	for(i=0;i<size;i++)  //put elements in array from 1 to size
	{
		arr[i]=i+1;
	}
	for(i=0;i<size;i++) //print elements
	{
		printf("%d ",arr[i]);
	}
	printf("\n");
	printf("Enter element to be inserted: ");  //scanning element from user to insert it in array
	fflush(stdout);fflush(stdout);
	scanf("%d",&InsertedNum);                  //scanning location of element
	printf("Enter the location: ");
	fflush(stdout);fflush(stdout);
	scanf("%d",&location);

	for(i=size;i>=location;i--)               //shift each all element from location to end one index
	{
		arr[i]=arr[i-1];
	}

	arr[location-1]=InsertedNum;              //insert the number in his location
	for(i=0;i<size+1;i++)                     //print array after inserted
	{
		printf("%d ",arr[i]);
	}
	return EXIT_SUCCESS;
}
