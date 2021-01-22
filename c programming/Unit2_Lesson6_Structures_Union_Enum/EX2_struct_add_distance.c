/*
 ============================================================================
 Name        : EX2_Struct_add_ditance.c
 Author      : Mostafa Elshiekh
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>
#pragma pack(1)

struct Sdistance
{
	int feet;
	float inch;
};

void ScanningDistance(int *ptr1, float *ptr2)
{
	static int count;
	count++;
	printf("Enter information for %dst distance: \n",count);
	printf("Enter feet: ");
	fflush(stdin);fflush(stdout);
	scanf("%d",ptr1);

	printf("Enter insh: ");
	fflush(stdin);fflush(stdout);
	scanf("%f",ptr2);
}

struct Sdistance AddDistance(struct Sdistance des1,struct Sdistance des2)
{
	struct Sdistance result;
	result.feet=des1.feet+des2.feet;
	result.inch=des1.inch+des2.inch;
	return result;
}

void PrintValues(struct Sdistance result)
{
	printf("Sum of tow distance = %d feet + %.2f inch\n",result.feet,result.inch);
}

int main(void)
{
 struct Sdistance des1,des2,result;
 ScanningDistance(&des1.feet,&des1.inch);
 ScanningDistance(&des2.feet,&des2.inch);
 result=AddDistance(des1,des2);
 PrintValues(result);

	return EXIT_SUCCESS;
}
