/*
 ============================================================================
 Name        : EX4_info_std.c
 Author      : Mostafa Elshiekh
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */


#include <stdio.h>
#include <stdlib.h>


struct Sstudent
{
	int roll;
	char name[50];
	float marks;
};

void ScanningStudent(int *roll ,char name[],float *marks)
{

	printf("Enter roll: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",roll);

	printf("Enter name: ");
	fflush(stdin);fflush(stdout);
	scanf("%s",name);

	printf("Enter markes: ");
	fflush(stdin);fflush(stdout);
	scanf("%f",marks);

}

void PrintDate(struct Sstudent result)
{
	printf("Information for roll number %d\n",result.roll);
	printf("Name: %s\n",result.name);
	printf("Marks: %f\n",result.marks);
}

int main(void)
{
	struct Sstudent arr[10];
	int i;
	printf("Enter information of students: \n");
	printf("\n");
	for(i=0;i<3;i++)
	{
		ScanningStudent(&arr[i].roll,arr[i].name,&arr[i].marks);
		printf("\n");
	}

	printf("\nDisplaying information of student:\n");
	printf("\n");
	for(i=0;i<3;i++)
	{
		PrintDate(arr[i]);
		printf("\n");
	}


	return EXIT_SUCCESS;
}
