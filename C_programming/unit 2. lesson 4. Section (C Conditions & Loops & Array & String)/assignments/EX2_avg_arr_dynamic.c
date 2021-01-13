/*
 ============================================================================
 Name        : EX2_avg_arr_dynamic.c
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
	float *ptr,sum=0;
	int num,i;
	printf("Enter the number of data: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&num);
	ptr=(float*)malloc(num*sizeof(float)); //dynamic allocation to scanning the size from user

	for(i=0;i<num;i++)                     //scanning the elements from user
	{
		printf("%d. Enter number: ",i+1);
		fflush(stdin);fflush(stdout);
		scanf("%f",&ptr[i]);
		sum+=ptr[i];
	}
	printf("Average = %0.2f",sum/num);  //print the average
	free(ptr);                          //free the memory
	return EXIT_SUCCESS;
}
