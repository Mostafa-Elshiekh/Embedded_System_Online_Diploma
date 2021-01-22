/*
 ============================================================================
 Name        : EX1_Student_structure.c
 Author      : Mostafa Elshiekh
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */
#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)

struct Sstudent
{
	char name[50];
	int roll;
	float marks;
};

struct Sstudent ScaningValues(char *ptr,int *roll,float *marks)
{
	struct Sstudent result;
	printf("Enter name: ");
	fflush(stdin);fflush(stdout);
	gets(result.name);
	printf("Enter roll: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",&result.roll);
	printf("Enter markes: ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&result.marks);
	return result;
}

void PrintValues(struct Sstudent result)
{
	printf("\nDisplaying information: \n");
	printf("Name: %s\n",result.name);
	printf("Roll: %d\n",result.roll);
	printf("Marks: %.3f\n",result.marks);
}
int main(void)
{
	struct Sstudent std1;
	std1=ScaningValues(std1.name,&std1.roll,&std1.marks);
	PrintValues(std1);



	return EXIT_SUCCESS;
}
