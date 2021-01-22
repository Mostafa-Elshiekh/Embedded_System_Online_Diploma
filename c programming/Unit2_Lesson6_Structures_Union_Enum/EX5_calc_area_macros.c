/*
 ============================================================================
 Name        : EX5_calc_area_macros.c
 Author      : Mostafa Elshiekh
 Version     :
 Copyright   : Your copyright notice
 Description : Hello World in C, Ansi-style
 ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

#define area(radius) (3.14*radius*radius)
int main(void)
{

	float radius;
	printf("Enter the radius: ");
	fflush(stdin);fflush(stdout);
	scanf("%f",&radius);
	printf("Area = %.2f",area(radius));
	return EXIT_SUCCESS;
}
