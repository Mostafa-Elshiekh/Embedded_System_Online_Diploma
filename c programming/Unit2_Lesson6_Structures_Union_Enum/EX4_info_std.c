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
	char name[50];
	int roll;
	float marks;
};

void ScanningStudent(char name[],int *roll,float *marks)
{
	struct Sstudent StudentInfo;




	printf("Enter roll: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",roll);

	printf("Enter name: ");
	fflush(stdin);fflush(stdout);
	scanf("%s",name);

	printf("Enter markes: ");
	fflush(stdin);fflush(stdout);
	scanf("%.2f",marks);

}

void PrintDate(struct Sstudent result)
{
	printf("Information for roll number %d",result.roll);
	printf("Name: %s",result.name);
	printf("Marks: %f",result.marks);
}
int main(void)
{
	struct Sstudent arr[10];
	int i;
	printf("Enter information of students: \n");
	fflush(stdin);fflush(stdout);
	for(i=0;i<3;i++)
	{
		ScanningStudent(arr[i].name,&arr[i].roll,&arr[i].marks);
	}

	printf("Displaying information of student:\n");
	for(i=0;i<3;i++)
	{
		ScanningStudent(&arr[i].name,&arr[i].roll,&arr[i].marks);
	}


	return EXIT_SUCCESS;
}
